#ifndef interface
#define interface


void hienthi() {
  Serial.print("position: ");
  Serial.println(num_position);
  Serial.print("joint1: ");
  for (uint8_t i = 0; i < num_position; i++) {
    Serial.print(joint1[i]);
    Serial.print(" ");
  }
  Serial.println();
  Serial.print("joint2: ");
  for (uint8_t i = 0; i < num_position; i++) {
    Serial.print(joint2[i]);
    Serial.print(" ");
  }
  Serial.println();
  Serial.print("joint3: ");
  for (uint8_t i = 0; i < num_position; i++) {
    Serial.print(joint3[i]);
    Serial.print(" ");
  }
  Serial.println();
  Serial.print("joint4: ");
  for (uint8_t i = 0; i < num_position; i++) {
    Serial.print(joint4[i]);
    Serial.print(" ");
  }
  Serial.println();
  Serial.print("joint5: ");
  for (uint8_t i = 0; i < num_position; i++) {
    Serial.print(joint5[i]);
    Serial.print(" ");
  }
  Serial.println();
  Serial.print("speed: ");
  for (uint8_t i = 0; i < num_position; i++) {
    Serial.print(speed[i]);
    Serial.print(" ");
  }

  Serial.println();
  Serial.print("gipper: ");
  for (uint8_t i = 0; i < num_position; i++) {
    Serial.print(gipper[i]);
    Serial.print(" ");
  }
  Serial.println();
}
int get_val(String string) {
  for (int i = 0; i < string.length(); i++) {
    if (string.charAt(i) == ':') {
      return  string.substring(i + 1, string.length()).toInt();
    }
  }
}
//position:0_speed:3_joint1:20_joint2:0_joint3:0_joint4:0_joint5:0_gipper:40

void read_data() {
  int vt[7];
  while (1) {
    if (Serial.available() > 0) {
      String data = Serial.readStringUntil('\n');
      Serial.println(data);
      if (data == "out") {
        mode = 0;
        break;
      }
      else {
        int b = 0;
        for (int i = 0; i < data.length(); i++) {
          if (data.charAt(i) == '_') {
            vt[b++] = i;
          }
        }
        String string1 = data.substring(0, vt[0]);
        String string2 = data.substring(vt[0] + 1, vt[1]);
        String string3 = data.substring(vt[1] + 1, vt[2]);
        String string4 = data.substring(vt[2] + 1, vt[3]);
        String string5 = data.substring(vt[3] + 1, vt[4]);
        String string6 = data.substring(vt[4] + 1, vt[5]);
        String string7 = data.substring(vt[5] + 1, vt[6]);
        String string8 = data.substring(vt[6] + 1, data.length());

        position = get_val(string1);
        speed[position] = get_val(string2);
        joint1[position] = get_val(string3);
        joint2[position] = get_val(string4);
        joint3[position] = get_val(string5);
        joint4[position] = get_val(string6);
        joint5[position] = get_val(string7);
        gipper[position] = get_val(string8);

        Serial.print("position: ");    Serial.println(position);
        delay(10);
        Serial.print("speed:  ");      Serial.println(speed[position]);
        delay(10);
        Serial.print("nhập joint1: "); Serial.println(joint1[position]);
        delay(10);
        Serial.print("nhập joint2: "); Serial.println(joint2[position]);
        delay(10);
        Serial.print("nhập joint3: "); Serial.println(joint3[position]);
        delay(10);
        Serial.print("nhập joint4: "); Serial.println(joint4[position]);
        delay(10);
        Serial.print("nhập joint5: "); Serial.println(joint5[position]);
        delay(10);
        Serial.print("gipper: ");      Serial.println(gipper[position]);
        delay(10);
        start = 1;
        break;
      }
    }
  }
}

void data_interface() {
  if (Serial.available() > 0) {
    if (c == 1) TIMSK3 &= ~(3 << OCIE3A);
    String data = Serial.readStringUntil('\n');
    Serial.println(data);
    if (data == "start") start = 1;
    else if (data == "stop") start = 0;
    else if (data == "reset") {
      start = 0 ; reset = 1; mode = 0;
    }
    else if (data == "control") {
      mode = 1;
    }
    else if (data == "run")    {
      Serial.println("trong chế độ RUN");
      mode = 2;
    }
    else if (data == "save")   {
      Serial.print("nhập số lượng position: ");
      while (1) {
        if (Serial.available() > 0) {
          num_position = Serial.readStringUntil('\n').toInt();
          break;
        }
      }
      Serial.println(num_position);
      save();
      hienthi();
    }
  }
}



#endif
