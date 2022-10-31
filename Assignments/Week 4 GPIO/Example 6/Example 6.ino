//////////////////// Pointers ///////////////////////////
unsigned char *Bread = (unsigned char *)0x23;   // assigns *read as pin (input) for B
unsigned char *Bdir = (unsigned char *)0x24;    // assigns *dir as ddr for B
unsigned char *Bwrite = (unsigned char *)0x25;  // assigns *read as port for B

//////////////////// LED ///////////////////////////
bool led_state = 0;  // assign state of led
unsigned long prev_time;

//////////////////// Counter ///////////////////////////
unsigned int count = 0;  // assign count
bool prev = 0;           // assign prev to track if it is previously pressed
bool current = 0;        // assign current to keep track current output of *read
unsigned long press_time;

void setup() {
  Serial.begin(9600);
  *Bdir = 0b0000010;  // lets PB1 as output
}

void loop() {
  counter();
  led();
}

void counter() {
  current = (((*Bread) & 0b00000001) != 0);  // assign current to check if *read and dpin 8 is pressed
  unsigned long curr_time = millis();

  if (curr_time - press_time >= 20) {
    if (current && !prev) {   // checks if current and prev is not the same
      count = count + 1;      // increases count value
      Serial.println(count);  // prints count value
    }
    prev = current;  // makes prev and current the same value
  }
}

void led() {

  unsigned long curr_time = millis();
  if (((*Bread) & 0b0000010) == 0) {
    if (curr_time - prev_time > 2000) {
      *Bwrite |= 0b00000010;
      prev_time = curr_time;
    }
  } else {
    if (curr_time - prev_time > 2000) {
      *Bwrite &= 0b11111101;
      prev_time = curr_time;
    }
  }
  
}