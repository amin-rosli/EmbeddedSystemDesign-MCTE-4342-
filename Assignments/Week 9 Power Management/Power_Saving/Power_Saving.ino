void setup() {

  DDRB = 0b11111111;        
  DDRC = 0b11111111;
  DDRD = 0b11111111;
  ADCSRA = 0;               
}

void loop() {

  SMCR = 5;     
  MCUCR = 0b01100000;    
  MCUCR = 0b01000000;    
}
