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
  counter(); //executes counter function
  led();     //executes led function
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

  unsigned long curr_time = millis();     //updates current time
  if (((*Bread) & 0b0000010) == 0) {      //checks if *Bread and PB=LOW (checks if LED is off)
    if (curr_time - prev_time > 2000) {   //checks if last time LED was off is more than 2secs
      *Bwrite |= 0b00000010;              //mask the PB1 as high (turns on LED)
      prev_time = curr_time;              //update the prev_time as curr_time
    }
  } else {                                //if LED is on
    if (curr_time - prev_time > 2000) {   //checks last time LED was on is more than 2secs
      *Bwrite &= 0b11111101;              //mask the PB1 as low (turns off LED)
      prev_time = curr_time;              //update the prev_time as curr_time
    }
  }
  
}
