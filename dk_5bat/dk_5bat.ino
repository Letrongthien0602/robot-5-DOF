//khai báo thư viện
#include <FaBoPWM_PCA9685.h>
#include <EEPROM.h>
#include "variable.h"
#include "epprom_robot.h"
#include "button.h"
#include "interface_uart.h"
#include "create_delay.h"
#include "control_step.h"

void setup() {
  //cài đặc mode cho pin
  pinMode(pulsePin1, OUTPUT);
  pinMode(pulsePin2, OUTPUT);
  pinMode(pulsePin3, OUTPUT);
  pinMode(pulsePin4, OUTPUT);
  pinMode(pulsePin5, OUTPUT);

  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(dirPin4, OUTPUT);
  pinMode(dirPin5, OUTPUT);

  pinMode(enpin1, OUTPUT);
  pinMode(enpin2, OUTPUT);
  pinMode(enpin3, OUTPUT);
  pinMode(enpin4, OUTPUT);
  pinMode(enpin5, OUTPUT);

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
  read_epprom();
  hienthi();
}

void loop() {
  pushStart();
  pushStop();
  pushReset();
  data_interface();
  if (mode == 1) {
    while (mode == 1) {
      Serial.println("trong chế độ control");
      read_data();
      control_joint(joint1[position], joint2[position] , joint3[position]  , joint4[position] , joint5[position], gipper[position], speed[position]);
    }
  }

  if (mode == 2) {
    if (start && !reset) {
      for (uint8_t i = 0; i < num_position ; i++) {
        control_joint(joint1[i], joint2[i] , joint3[i]  , joint4[i] , joint5[i], gipper[i], speed[i]);
        delay_ms(1000);
        if (reset) break;
      }
    }
  }

  //khi nhấn reset về home
  if (reset) {
    reset = 0; start = 1;
    control_joint(0, 0 , 0 , 0  , 0 , 40 , 10);
    start = 0;
  }

}
