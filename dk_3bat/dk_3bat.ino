//khai báo thư viện
#include <FaBoPWM_PCA9685.h>
#include "variable.h"
#include "button.h"
#include "interface_uart.h"
#include "create_delay.h"
#include "control_step.h"

void setup() {
  //cài đặc mode cho pin
  pinMode(pulsePin1, OUTPUT);
  pinMode(pulsePin2, OUTPUT);
  pinMode(pulsePin3, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(enpin1, OUTPUT);
  pinMode(enpin2, OUTPUT);
  pinMode(enpin3, OUTPUT);
  pinMode(buttonStart , INPUT_PULLUP);
  pinMode(buttonStop , INPUT_PULLUP);
  pinMode(buttonReset , INPUT_PULLUP);
  
  Serial.begin(9600);
  //kiểm tra kết nối driver servo
  if (faboPWM.begin()) {
    Serial.println("Find PCA9685");
    faboPWM.init(300);
  }
 faboPWM.set_hz(50);
  set_timer1();  // tạo timer delay
  set_timer3();  // tạo timer điều chế pwm cho step
  
  start = 1;
  control_gipper(80);
  delay_ms(1000);
  start = 0;
  digitalWrite(redLed , onLed);
  digitalWrite(yellowLed , offLed);
  digitalWrite(greenLed , offLed);
}

void loop() {
  pushStart();
  pushStop();
  pushReset();
  data_interface();
  //data_interface();
  if (start && !reset) {
    control_joint(joint1, joint2 , joint3 );
    delay_ms(1000);
    control_gipper(gipper);
    delay_ms(1000);
    start = 0;
  }
  //khi nhấn reset về home
  if (reset) {
    reset = 0; start = 1;
    control_joint(95, 0 , 125 );
    control_gipper(40);
    start = 0;
  }

}
