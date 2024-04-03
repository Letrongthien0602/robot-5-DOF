//khai báo thư viện
#include "FaBoPWM_PCA9685.h"
#include "variable.h"
#include "control_step.h"
#include "create_delay.h"

void setup() {
  Serial.begin(9600);
  if (faboPWM.begin()) {
    Serial.println("Find PCA9685");
    faboPWM.init(300);
  }
  //cài đặc mode cho pin
  pinMode(pulsePin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(enpin1, OUTPUT);
  pinMode(buttonStart , INPUT_PULLUP);
  pinMode(buttonStop , INPUT_PULLUP);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  //1 tạo timer delay
  set_timer1();
  // tạo timer điều chế pwm cho step
  set_timer3();
}

void loop() {
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

  if (start) {
    control_joint(30);
    delay_ms(2000);
    control_joint(90);
    delay_ms(2000);
    control_joint(0);
    delay_ms(2000);
    start = 0;
  }
}
