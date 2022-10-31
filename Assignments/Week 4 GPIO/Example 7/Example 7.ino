class Blinkz {                //initialize class BLinkz
  char port;                  //initialize variables
  int pin;
  int pinB;
  int on_time;
  int off_time;
  unsigned long prev_time;
  unsigned char *write;


public:
  Blinkz(char port, int pin, int c, int d) {            //initialize default constructor (port letter,pin number,on duration,off duration)
    port = port;
    pin = pin;
    on_time = c;
    off_time = d;
    prev_time = 0;

    pinB = pow(2, pin);                                 //converts pin from DEC to BIN

    switch (port) {                                     //converts port letter to point address to write
      case 'B': write = (unsigned char *)0x25; break;
      case 'C': write = (unsigned char *)0x28; break;
      case 'D': write = (unsigned char *)0x2b; break;
      default: Serial.println("Invalid port!"); break;
    }
  }

  void flash() {
    unsigned long curr_time = millis();                 //initialize and updates curr_time

    if (((*write) & pinB) == 0) {                       //checks if LED is OFF
      if (curr_time - prev_time >= off_time) {          //checks if last time LED was OFF is more than off_time
        *write |= pinB;                                 //mask the pin binary as HIGH (turns on LED)
        prev_time = curr_time;                          //update the prev_time as curr_time
      }
    } else {                                            //if LED is ON
      if (curr_time - prev_time >= on_time) {           //checks if last time LED was ON is more than off_time
        *write &= ~pinB;                                //mask the pin binary as LOW (turns off LED)
        prev_time = curr_time;                          //update the prev_time as curr_time
      }
    }
  }
};

Blinkz yellowLed('B', 0, 750, 350);                     //insert variables to be constructed
Blinkz redLed('B', 1, 400, 600);

void setup() {
  Serial.begin(9600);
}

void loop() {
  yellowLed.flash();                                    //executes the flash function
  redLed.flash();
}
