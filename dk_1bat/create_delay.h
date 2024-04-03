#ifndef create_delay
#define create_delay

// tạo hàm delay
int timerDelay(int time) {
  TIMSK1 |= (1 << OCIE1A);
  if (timer >= time && start) {
    TIMSK1 &= ~(1 << OCIE1A);
    timer = 0;
    return 1;
  }
  else return 0;
}
void delay_ms(int time ){
  while(timerDelay(time) == 0);
}

void set_timer1() {
  //tạo timer1 để điều khiển delay
  noInterrupts(); // Tắt tất cả ngắt để thiết lập cấu hình timer
  TCCR1A = 0;    
  TCCR1B = 0;    
  TCNT1 = 0;     // Đặt giá trị ban đầu của timer 1
  OCR1A = 249; // 1000hz
  TCCR1B |= (1 << WGM12); // Cài đặt chế độ CTC
  TCCR1B |= (1 << CS11) | (1 << CS10) ; 
  TIMSK1 &= ~(1 << OCIE1A);
  interrupts(); // Kích hoạt lại tất cả ngắt
}
ISR(TIMER1_COMPA_vect) {
  if (start) timer++;
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
