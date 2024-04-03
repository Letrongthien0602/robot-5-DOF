//// define định danh để ngăn chặn việc define nhiều lần
#ifndef joint
#define joint

int findMax(int num1, int num2, int num3, int num4 , int num5) {
  int maxVal = num1;
  if (num2 > maxVal) maxVal = num2;
  if (num3 > maxVal) maxVal = num3;
  if (num4 > maxVal) maxVal = num4;
  if (num5 > maxVal) maxVal = num5;
  return maxVal;
}

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
void control_joint(unsigned int Angle1 , unsigned int Angle2 , unsigned int Angle3 , unsigned int Angle4 , unsigned int Angle5 , unsigned int gip , int SPEED) {
  c = 1;
  //set timer pwm cho từng joint
  timer1Enabled = true;
  timer2Enabled = true;
  timer3Enabled = true;
  timer4Enabled = true;
  timer5Enabled = true;

  control_gipper(gip);

  //lưu lại vị trí hiện tại di chuyển đến
  curAngle1 = Angle1 ;
  curAngle2 = Angle2 ;
  curAngle3 = Angle3 ;
  curAngle4 = Angle4 ;
  curAngle5 = Angle5 ;

  //hiệu vị hiện tại và vị trí tiếp theo
  int subAngle1 = curAngle1 - lastAngle1;
  int subAngle2 = curAngle2 - lastAngle2;
  int subAngle3 = curAngle3 - lastAngle3;
  int subAngle4 = curAngle4 - lastAngle4;
  int subAngle5 = curAngle5 - lastAngle5;

  //chuyển giá trị góc sang bước để điều khiển joint
  numPulse1 = map( abs(subAngle1) , 0 , Angle_joint_Max1 , 0 , step1Max);
  numPulse2 = map( abs(subAngle2) , 0 , Angle_joint_Max2 , 0 , step2Max);
  numPulse3 = map( abs(subAngle3) , 0 , Angle_joint_Max3 , 0 , step3Max);
  numPulse4 = map( abs(subAngle4) , 0 , Angle_joint_Max4 , 0 , step4Max);
  numPulse5 = map( abs(subAngle5) , 0 , Angle_joint_Max5 , 0 , step5Max);

  //điều chỉnh tốc độ cho joint
  int maxAngle = findMax(abs(subAngle1), abs(subAngle2), abs(subAngle3), abs(subAngle4) , abs(subAngle5));
  joint1_speed = base_joint_speed1 * ((double)(maxAngle) / (double)(abs(subAngle1))) * (double)SPEED * 0.50;
  joint2_speed = base_joint_speed2 * ((double)(maxAngle) / (double)(abs(subAngle2))) * (double)SPEED * 0.50;
  joint3_speed = base_joint_speed3 * ((double)(maxAngle) / (double)(abs(subAngle3))) * (double)SPEED * 0.50;
  joint4_speed = base_joint_speed4 * ((double)(maxAngle) / (double)(abs(subAngle4))) * (double)SPEED * 0.50;
  joint5_speed = base_joint_speed5 * ((double)(maxAngle) / (double)(abs(subAngle5))) * (double)SPEED * 0.50;


  //kiểm tra các joint không xoay để ngững cấp xung
  if (abs(subAngle1) == 0) timer1Enabled = false;
  if (abs(subAngle2) == 0) timer2Enabled = false;
  if (abs(subAngle3) == 0) timer3Enabled = false;
  if (abs(subAngle4) == 0) timer4Enabled = false;
  if (abs(subAngle5) == 0) timer5Enabled = false;

  // điều khiển hướng di chuyển của joint
  digitalWrite(dirPin1 , !(subAngle1 <= 0));
  digitalWrite(dirPin2 , (subAngle2 <= 0));
  digitalWrite(dirPin3 , (subAngle3 <= 0));
  digitalWrite(dirPin4 , (subAngle4 <= 0));
  digitalWrite(dirPin5 , !(subAngle5 <= 0));

  // bật timer3
  TIMSK3 |= (1 << OCIE3A);
  //đợi kết thúc hành trình của các joint
  while ((timer1Enabled == true || timer2Enabled == true || timer3Enabled == true || timer4Enabled == true || timer5Enabled == true) && !reset) {
    pushReset();
    pushStart();
    pushStop();
    data_interface();
  }
  //nếu reset ghi nhớ vị trí hiện tại mà joint dừng
  if (reset) {
    if ((curAngle1 - lastAngle1) <= 0) lastAngle1 = abs(lastAngle1  - map(countPulse1 / 2 , 0 , step1Max , 0 , Angle_joint_Max1));
    else lastAngle1 = map (countPulse1 / 2 , 0 , step1Max , 0 , Angle_joint_Max1) + lastAngle1 ;
    if ((curAngle2 - lastAngle2) <= 0) lastAngle2 = abs(lastAngle2  - map(countPulse2 / 2 , 0 , step2Max , 0 , Angle_joint_Max2));
    else lastAngle2 = map (countPulse2 / 2 , 0 , step2Max , 0 , Angle_joint_Max2) + lastAngle2 ;
    if ((curAngle3 - lastAngle3) <= 0) lastAngle3 = abs(lastAngle3  - map(countPulse3 / 2 , 0 , step3Max , 0 , Angle_joint_Max3));
    else lastAngle3 = map (countPulse3 / 2 , 0 , step3Max , 0 , Angle_joint_Max3) + lastAngle3 ;
    if ((curAngle4 - lastAngle4) <= 0) lastAngle4 = abs(lastAngle4  - map(countPulse4 / 2 , 0 , step4Max , 0 , Angle_joint_Max4));
    else lastAngle4 = map (countPulse4 / 2 , 0 , step4Max , 0 , Angle_joint_Max4) + lastAngle4 ;
    if ((curAngle5 - lastAngle5) <= 0) lastAngle5 = abs(lastAngle5  - map(countPulse5 / 2 , 0 , step5Max , 0 , Angle_joint_Max5));
    else lastAngle5 = map (countPulse5 / 2 , 0 , step5Max , 0 , Angle_joint_Max5) + lastAngle5 ;

    digitalWrite(dirPin1 , !(lastAngle1 - 0 >= 0));
    digitalWrite(dirPin2 , (lastAngle2 - 0 >= 0));
    digitalWrite(dirPin3 , (lastAngle3 - 0 >= 0));
    digitalWrite(dirPin4 , (lastAngle4 - 0 >= 0));
    digitalWrite(dirPin5 , !(lastAngle5 - 0 >= 0));

    countPulse1 = 0;
    countPulse2 = 0;
    countPulse3 = 0;
    countPulse4 = 0;
    countPulse5 = 0;
  }
  //ghi nhớ vị trí hiện tại
  else {
    lastAngle1 = curAngle1;
    lastAngle2 = curAngle2;
    lastAngle3 = curAngle3;
    lastAngle4 = curAngle4;
    lastAngle5 = curAngle5;
  }
  c = 0;
}



// hàm ngắt timer 3
ISR(TIMER3_COMPA_vect) {
  if (!reset) {
    //điều chế xung điều khiển joint 1
    if (timer1Enabled && start && !reset ) {
      if (counterTim1++ >= joint1_speed ) {
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
      if (counterTim2++ >= joint2_speed ) {
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
      if (counterTim3++ >= joint3_speed ) {
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
    //điều chế xung điều khiển joint 4
    if (timer4Enabled && start && !reset ) {
      if (counterTim4++ >= joint4_speed ) {
        counterTim4 = 0;
        digitalWrite(pulsePin4 , statePin4);
        statePin4 = !statePin4;
        if (countPulse4++ >= numPulse4 * 2) {
          countPulse4 = 0;
          statePin4 = false;
          timer4Enabled = false;
        }
      }
    }
    //điều chế xung điều khiển joint 5
    if (timer5Enabled && start && !reset ) {
      if (counterTim5++ >= joint5_speed ) {
        counterTim5 = 0;
        digitalWrite(pulsePin5 , statePin5);
        statePin5 = !statePin5;
        if (countPulse5++ >= numPulse5 * 2) {
          countPulse5 = 0;
          statePin5 = false;
          timer5Enabled = false;
        }
      }
    }

    //kiểm tra nếu tất cả các joint dừng thì tắt timer3
    if (timer1Enabled == false && timer2Enabled == false && timer3Enabled == false && timer4Enabled == false && timer5Enabled == false ) TIMSK3 &= ~(3 << OCIE3A);
  }
}

#endif
