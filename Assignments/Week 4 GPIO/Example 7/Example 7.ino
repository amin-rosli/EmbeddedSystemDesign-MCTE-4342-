class Blinkz {
  char port;
  int pin;
  int pinB;
  int on_time;
  int off_time;
  unsigned long prev_time;
  unsigned char *write;


public:
  Blinkz(char port, int pin, int c, int d) {
    port = port;
    pin = pin;
    on_time = c;
    off_time = d;
    prev_time = 0;

    pinB = pow(2, pin);

    switch (port) {
      case 'B': write = (unsigned char *)0x25; break;
      case 'C': write = (unsigned char *)0x28; break;
      case 'D': write = (unsigned char *)0x2b; break;
      default: Serial.println("Invalid port!"); break;
    }
  }

  void flash() {
    unsigned long curr_time = millis();

    Serial.println(pinB);

    if (((*write) & pinB) == 0) {
      if (curr_time - prev_time >= on_time) {
        *write |= pinB;
        prev_time = curr_time;
      }
    } else {
      if (curr_time - prev_time >= off_time) {
        *write &= ~pinB;
        prev_time = curr_time;
      }
    }
  }
};

Blinkz yellowLed('B', 0, 750, 350);
Blinkz redLed('B', 1, 400, 600);

void setup() {
  Serial.begin(9600);
}

void loop() {
  yellowLed.flash();
  redLed.flash();
}