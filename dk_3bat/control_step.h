//// define định danh để ngăn chặn việc define nhiều lần
#ifndef joint
#define joint

void set_timer3() {
  //tạo timer3 để điều khiển step
  noInterrupts();
  TCCR3A = 0;
  TCCR3B = 0;
  TCNT3 = 0;     // Đặt giá trị ban đầu của timer 1
  OCR3A = 100; // 95 238hz
  TCCR3B |= (1 << WGM32); // Cài đặt chế độ CTC
  TCCR3B |= (1 << CS30) ; // Chọn chia tần số CPU cho timer (ở đây là 1)
  TIMSK3 &= ~(1 << OCIE3A);
  //TIMSK1 |= (1 << OCIE1A); // Kích hoạt ngắt timer 1 khi đạt ngưỡng OCR1A
  interrupts(); // Kích hoạt lại tất cả ngắt
}

void control_gipper(int distance) {
  int angle = degrees(acos((double)(distance / 2) / 40) );
  faboPWM.set_channel_value(13, map(angle + 23 , 0 , 180 , 140, 570));
}
// tạo hàm chạy cho step
void control_joint(unsigned int Angle1 , unsigned int Angle2 , unsigned int Angle3 ) {
  c = 1;
  timer1Enabled = true;
  timer2Enabled = true;
  timer3Enabled = true;

  curAngle1 = Angle1 ;
  curAngle2 = Angle2 ;
  curAngle3 = Angle3 ;

  //chuyển giá trị góc sang bước để điều khiển joint
  numPulse1 = map( abs(curAngle1 - lastAngle1) , 0 , Angle_joint_Max1 , 0 , step1Max);
  numPulse2 = map( abs(curAngle2 - lastAngle2) , 0 , Angle_joint_Max2 , 0 , step2Max);
  numPulse3 = map( abs(curAngle3 - lastAngle3) , 0 , Angle_joint_Max3 , 0 , step3Max);

  //kiểm tra các joint không xoay để ngững cấp xung
  if ((curAngle1 - lastAngle1) == 0) timer1Enabled = false;
  if ((curAngle2 - lastAngle2) == 0) timer2Enabled = false;
  if ((curAngle3 - lastAngle3) == 0) timer3Enabled = false;

  // điều khiển hướng di chuyển của joint
  digitalWrite(dirPin1 , !((curAngle1 - lastAngle1) <= 0));
  digitalWrite(dirPin2 , (curAngle2 - lastAngle2) <= 0);
  digitalWrite(dirPin3 , ((curAngle3 - lastAngle3) <= 0));

  // bật timer3
  TIMSK3 |= (1 << OCIE3A);

  //đợi kết thúc hành trình của các joint
  while ((timer1Enabled == true || timer2Enabled == true || timer3Enabled == true) && !reset) {
    pushReset();
    pushStart();
    pushStop();
  }
  if (reset) {
    if ((curAngle1 - lastAngle1) <= 0) lastAngle1 = abs(lastAngle1  - map(countPulse1 / 2 , 0 , step1Max , 0 , Angle_joint_Max1 ));
    else lastAngle1 = map (countPulse1 / 2 , 0 , step1Max , 0 , Angle_joint_Max1 ) + lastAngle1 ;
    if ((curAngle2 - lastAngle2) <= 0) lastAngle2 = abs(lastAngle2  - map(countPulse2 / 2 , 0 , step2Max , 0 , Angle_joint_Max2 ));
    else lastAngle2 = map (countPulse2 / 2 , 0 , step2Max , 0 , Angle_joint_Max2 ) + lastAngle2 ;
    if ((curAngle3 - lastAngle3) <= 0) lastAngle3 = abs(lastAngle3  - map(countPulse3 / 2 , 0 , step3Max , 0 , Angle_joint_Max3 ));
    else lastAngle3 = map (countPulse3 / 2 , 0 , step3Max , 0 , Angle_joint_Max3 ) + lastAngle3 ;
    digitalWrite(dirPin1 , !(lastAngle1 - 0 >= 0));
    digitalWrite(dirPin2 , (lastAngle2 - 0 >= 0));
    digitalWrite(dirPin3 , (lastAngle3 - 0 >= 0));

    countPulse1 = 0;
    countPulse2 = 0;
    countPulse3 = 0;   
  }

  if (!reset) {
    lastAngle1 = curAngle1;
    lastAngle2 = curAngle2;
    lastAngle3 = curAngle3;
  }
  c = 0;
}



// hàm ngắt timer 3
ISR(TIMER3_COMPA_vect) {
  if (!reset) {
    //điều chế xung điều khiển joint 1
    if (timer1Enabled && start && !reset ) {
      if (counterTim1++ >= 140 * speed) {
        counterTim1 = 0;
        digitalWrite(pulsePin1 , statePin1);
        statePin1 = !statePin1;
        if (countPulse1++ >= numPulse1 * 2) {
          countPulse1 = 0;
          statePin1 = false;
          timer1Enabled = false;
        }
      }
    }

    //điều chế xung điều khiển joint 2
    if (timer2Enabled && start && !reset ) {
      if (counterTim2++ >= 628 * speed) {
        counterTim2 = 0;
        digitalWrite(pulsePin2 , statePin2);
        statePin2 = !statePin2;
        if (countPulse2++ >= numPulse2 * 2) {
          countPulse2 = 0;
          statePin2 = false;
          timer2Enabled = false;
        }
      }
    }
    //điều chế xung điều khiển joint 3
    if (timer3Enabled && start && !reset ) {
      if (counterTim3++ >= 30 * speed) {
        counterTim3 = 0;
        digitalWrite(pulsePin3 , statePin3);
        statePin3 = !statePin3;
        if (countPulse3++ >= numPulse3 * 2) {
          countPulse3 = 0;
          statePin3 = false;
          timer3Enabled = false;
        }
      }
    }
    //kiểm tra nếu tất cả các joint dừng thì tắt timer3
    if (timer1Enabled == false && timer2Enabled == false && timer3Enabled == false ) TIMSK3 &= ~(3 << OCIE3A);
  }
}

#endif
