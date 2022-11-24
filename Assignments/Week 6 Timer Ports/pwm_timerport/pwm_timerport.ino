void setup() {
  DDRD = 0b11111111;      //set all of PortD as output
  TCCR0A = 0b10100111;    //set the timer configuration to timer control register A
                          // COM0A1,COM0A0 = 10 (clear at OCR0A during up, set OCR0A during down )
                          // COM0B1,COM0B0 = 10 (clear at OCR0B, set at OCR0A)
                          // WGM02,WGM01,WGM00 = 111 (UP to OCR0A, PWM mode)
  TCCR0B = 0b00000100;    //set the timer configuration to timer control register B
                          //CS02,CS01,CS00 = 100 (prescalar value of 256)
  OCR0A = 0b11111111;     //set output compare register A to 255
}

void loop() {
  OCR0B = 0;              //set output compare register B to 0 (0% duty cycle)
  delay(2000);
  
  OCR0B = 80;             //set output compare register B to 80 (32% duty cycle)
  delay(2000);
  
  OCR0B = 120;            //set output compare register B to 120 (47% duty cycle)
  delay(2000);
  
  OCR0B = 250;            //set output compare register B to 250 (98% duty cycle)
  delay(2000);
}
