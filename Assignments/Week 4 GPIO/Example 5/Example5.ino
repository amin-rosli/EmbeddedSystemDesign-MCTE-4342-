unsigned int count = 0;                       // assign count
bool prev;                                    // assign prev to track if it is previously pressed
unsigned char *read = (unsigned char *)0x23;  // assigns *read as port for B
unsigned char *dir = (unsigned char *)0x24;
unsigned char *write = (unsigned char *)0x25;
bool current;                                 // assign current to keep track current output of *read
unsigned long prev_time = millis();

void setup() {
  Serial.begin(9600);
  

  *dir = 0b00000000;   //assigns ddr as OUTPUT
  *write = 0b11111111; //assigns as HIGH for all ports (INPUT_PULLUP)
}

void loop() {
  unsigned long current_time = millis();
  bool current = (((*read) & 2) != 0);  // assign current to check if *read and dpin 8 is pressed
  Serial.println(current);

  if (current_time - prev_time > 20) {
    

    if (current && !prev) {   // checks if current and prev is not the same
      count = count + 1;      // increases count value
      Serial.println(count);  // prints count value
      prev_time = current_time;
    }
    prev = current;  // makes prev and current the same value
  }
}
