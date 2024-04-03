#ifndef create_delay
#define create_delay

void set_timer1() {
  //tạo timer1 để điều khiển delay
  noInterrupts(); // Tắt tất cả ngắt để thiết lập cấu hình timer
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;     // Đặt giá trị ban đầu của timer 1
  OCR1A = 249; // 1000hz
  TCCR1B |= (1 << WGM12); // Cài đặt chế độ CTC
  TCCR1B |= (1 << CS11) | (1 << CS10) ; // Chọn chia tần số CPU cho timer (ở đây là 1)
  TIMSK1 &= ~(1 << OCIE1A);
  //TIMSK1 |= (1 << OCIE1A); // Kích hoạt ngắt timer 1 khi đạt ngưỡng OCR1A
  interrupts(); // Kích hoạt lại tất cả ngắt
}

// tạo hàm delay
int timerDelay(int time) {
  if (start) {
    TIMSK1 |= (1 << OCIE1A);
    if (timer >= time && start) {
      TIMSK1 &= ~(1 << OCIE1A);
      timer = 0;
      return 1;
    }
    else return 0;
    if (!reset) {
      timer = 0;
      return 1;
    }
  }
}


void delay_ms(int time ) {
  while ((timerDelay(time) == 0) && !reset) {
    pushStart();
    pushReset();
    pushStop();
    data_interface();
  }
}

ISR(TIMER1_COMPA_vect) {
  timer++;
}
#endif
