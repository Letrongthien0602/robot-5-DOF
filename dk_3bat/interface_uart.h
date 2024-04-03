#ifndef interface
#define interface


void handle_data(int condition ) {
  while (1) {
    if (Serial.available() > 0) {
      String data = Serial.readStringUntil('\n');
      if (data.toInt() >= 0) {
        switch (condition) {
          case 0:
            speed = data.toInt();
            speed = constrain(speed , 1 , 10);
            break;
          case 1: joint1 = data.toInt();
            break;
          case 2: joint2 = data.toInt();
            break;
          case 3: joint3 = data.toInt();
            break;
          case 4:
            gipper = data.toInt();
            gipper = constrain(gipper, 10 , 80);
            break;
        }
        break;
      }
    }
  }
}

void read_data() {
  Serial.print("nhập speed: ");
  handle_data(0);
  Serial.println(speed);
  Serial.print("nhập joint1: ");
  handle_data(1);
  Serial.println(joint1);
  Serial.print("nhập joint2: ");
  handle_data(2);
  Serial.println(joint2);
  Serial.print("nhập joint3: ");
  handle_data(3);
  Serial.println(joint3);
  Serial.print("nhập khoảng cách gipper: ");
  handle_data(4);
  Serial.println(gipper);
  Serial.println("hãy nhấn start");
}

void data_interface() {
  if (Serial.available() > 0) {
    if (c == 1) TIMSK3 &= ~(3 << OCIE3A);
    Serial.println("nhập yêu cầu: ");
    String data = Serial.readStringUntil('\n');
    if (data == "start") start = 1;
    else if (data == "stop") start = 0;
    else if (data == "reset") start = 0 , reset = 1;
    else if (data == "control") {
      read_data();
    }
  }
}

#endif
