
#ifndef write_rom
#define write_rom



byte Bigbyte (int index , int joint) {
  if (joint == 0) return  0xff & (joint1[index / 2] >> 8);
  if (joint == 1) return  0xff & (joint2[index / 2] >> 8);
  if (joint == 2) return  0xff & (joint3[index / 2] >> 8);
  if (joint == 3) return  0xff & (joint4[index / 2] >> 8);
  if (joint == 4) return  0xff & (joint5[index / 2] >> 8);
}

byte Smallbyte (int index , int joint) {
  if (joint == 0) return  0xff & joint1[index / 2];
  if (joint == 1) return  0xff & joint2[index / 2];
  if (joint == 2) return  0xff & joint3[index / 2];
  if (joint == 3) return  0xff & joint4[index / 2];
  if (joint == 4) return  0xff & joint5[index / 2];
}

void save() {
  EEPROM.write(0 , num_position );

  //lưu hành trình của robot
  for (int y = 0 ; y  < 5 ; y  ++) {
    for (int x = addr + addr_offset * y * cell ; x <= addr_offset * cell * (y + 1)  ; x += cell ) {
      EEPROM.write(x , Bigbyte(x  - addr_offset * cell * y, y));
      EEPROM.write(x + 1 , Smallbyte(x  - addr_offset * cell * y, y));
    }
  }

  //lưu speed của robot
  for (int i = addr + addr_offset * cell * 5 ; i <= addr_offset * 11 ; i ++ ) {
    byte Byte = speed[i - (addr + addr_offset * cell * 5)];
    EEPROM.write(i , Byte );
  }
  //lưu gipper của robot
  for (int i = addr + addr_offset * 11; i <= addr_offset * 12  ; i ++ ) {
    byte Byte = gipper[i - (addr + addr_offset * 11)] ;
    EEPROM.write(i , Byte );
  }
}



void read_epprom() {
  //read position number
  num_position = EEPROM.read(0);
  for (int i = 1 ; i <= (addr_offset * cell ) ; i ++  ) {
    speed[i] = EEPROM.read(i);
  }
  //read angle joints
  for (int y = 0 ; y  <= 4 ; y  ++) {
    for (int x = addr + addr_offset * cell * y ; x <= addr_offset * cell * (y + 1)  ; x += cell ) {
      byte bigbyte = EEPROM.read(x) << 8;
      byte smallbyte = EEPROM.read(x + 1);

      if (y == 0) joint1[((x - 1) - y * addr_offset * cell) / 2] = bigbyte  | smallbyte ;
      if (y == 1) joint2[((x - 1) - y * addr_offset * cell) / 2] = bigbyte  | smallbyte ;
      if (y == 2) joint3[((x - 1) - y * addr_offset * cell) / 2] = bigbyte  | smallbyte ;
      if (y == 3) joint4[((x - 1) - y * addr_offset * cell) / 2] = bigbyte  | smallbyte ;
      if (y == 4) joint5[((x - 1) - y * addr_offset * cell) / 2] = bigbyte  | smallbyte ;
    }
  }
  //read speed
  for (int i = addr + addr_offset * 10; i <= addr_offset * 11  ; i ++ ) {
    speed[i - (addr + addr_offset * 10 )]  = EEPROM.read(i);
  }
  //read gipper
  for (int i = addr + addr_offset * 11; i <= addr_offset * 12  ; i ++ ) {
    gipper[i - (addr + addr_offset * 11 )]  = EEPROM.read(i);
  }
}
#endif
