// define định danh để ngăn chặn việc define nhiều lần
#ifndef joint
#define joint
#include "create_delay.h"
//điều khiển gipper
//void control_gipper(int distance) {
//  int angle = degrees(acos((double)(distance / 2) / 40) );
//  Serial.print("goc ");
//  Serial.print(angle);
//  faboPWM.set_channel_value(13, map(angle + 23 , 0 , 180 , 140, 570));
//}
// tạo hàm chạy cho step 1
void control_joint(unsigned int Angle ) {
  timer1Enabled = true;
  curAngle = Angle ;
  //if (Angle == 0) return;
  numPulse1 = map(abs(curAngle - lastAngle), 0, 210, 0, step1Max);
  if ((curAngle - lastAngle) == 0) timer1Enabled = false;
  // điều khiển hướng di chuyển
  digitalWrite(dirPin1 , !(curAngle <= lastAngle )); 
  TIMSK3 |= (1 << OCIE3A); // bật timer
  while (timer1Enabled == true);
  lastAngle = curAngle;
}
 //tạo timer3 để điều khiển step
void set_timer3() {
  noInterrupts(); // Tắt tất cả ngắt để thiết lập cấu hình timer
  TCCR3A = 0;    
  TCCR3B = 0;    
  TCNT3 = 0;     // Đặt giá trị ban đầu của timer 1
  OCR3A = 979 * 5; // 95 238hz
  TCCR3B |= (1 << WGM32); // Cài đặt chế độ CTC
  TCCR3B |= (1 << CS30) ; 
  TIMSK3 &= ~(1 << OCIE3A); 
  interrupts(); // Kích hoạt lại tất cả ngắt
}


// hàm ngắt timer 3
ISR(TIMER3_COMPA_vect) {
  Serial.print("vô");
  //tạo xung điều khiển joint1
  if (timer1Enabled && start ) {
    digitalWrite(pulsePin1 , statePin1);
    statePin1 = !statePin1;
    if (countPulse1++ >= numPulse1 * 2) {
      countPulse1 = 0;
      timer1Enabled = false;
    }
  }
  //kết thúc hành trình thì tắt timer
  if (timer1Enabled == false ) {
    timer1Enabled = false;
    TIMSK3 &= ~(3 << OCIE3A);
  }
  //nhận tính hiệu input
  if (digitalRead(buttonStart) == 0) start = 1;
  if (digitalRead(buttonStop) == 0) start = 0;
  if (start == 1) {
    digitalWrite(redLed , offLed);
    digitalWrite(greenLed , onLed);
  }
  if (start == 0) {
    digitalWrite(redLed , onLed);
    digitalWrite(greenLed , offLed);
  }
}

#endif
