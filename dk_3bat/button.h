#ifndef button
#define button

int timerDelayButton(int time) {
  TIMSK1 |= (1 << OCIE1A);
  if (timer >= time) {
    TIMSK1 &= ~(1 << OCIE1A);
    timer = 0;
    return 1;
  }
  else return 0;
}

void buttonDelay_ms(int time ) {
  while (timerDelayButton(time) == 0);
}

void pushReset() {
  if (digitalRead(buttonReset) == 0) {
    TIMSK3 &= ~(3 << OCIE3A);
    buttonDelay_ms(1);
    if (breset++ > 100) {
      breset = 0;
      Serial.println("reset");
      while ( breset < 100 ) {
        if (digitalRead(buttonReset) == 1) {
          breset++;
          buttonDelay_ms(1);
        }
        else breset = 0;
      }
      breset = 0; reset = 1; start = 0;
      digitalWrite(redLed , onLed);
      digitalWrite(yellowLed , offLed);
      digitalWrite(greenLed , offLed);
    }
  }
  else {
    breset = 0;
    if ( c == 1) TIMSK3 |= (1 << OCIE3A);
  }
}

void pushStart() {
  if (digitalRead(buttonStart) == 0) {
    TIMSK3 &= ~(3 << OCIE3A);
    buttonDelay_ms(1);
    if (bstart++ > 100) {
      bstart = 0;
      Serial.println("start");
      while ( bstart < 100 ) {
        if (digitalRead(buttonStart) == 1) {
          bstart++;
          buttonDelay_ms(1);
        }
        else bstart = 0;
      }
      bstart = 0; start = 1;
      digitalWrite(redLed , offLed);
      digitalWrite(yellowLed , offLed);
      digitalWrite(greenLed , onLed);
    }
  }
  else {
    bstart = 0;
    if ( c == 1) TIMSK3 |= (1 << OCIE3A);
  }
}


void pushStop() {
  if (digitalRead(buttonStop) == 0) {
    TIMSK3 &= ~(3 << OCIE3A);
    buttonDelay_ms(1);
    if (bstop++ > 100) {
      bstop = 0;
      Serial.println("stop");
      while ( bstop < 100 ) {
        if (digitalRead(buttonStop) == 1) {
          bstop++;
          buttonDelay_ms(1);
        }
        else bstop = 0;
      }
      if (start == 1 ) digitalWrite(yellowLed , onLed);
      digitalWrite(redLed , offLed);
      digitalWrite(greenLed , offLed);
      bstop = 0; start = 0;
    }
  }
  else {
    bstop = 0;
    if ( c == 1) TIMSK3 |= (1 << OCIE3A);
  }
}

#endif
