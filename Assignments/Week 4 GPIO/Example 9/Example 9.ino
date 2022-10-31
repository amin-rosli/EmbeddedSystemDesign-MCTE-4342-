class LedBlinky {
  char port;
  int pin;
  int pinBin;
  int onDurationMs;
  int offDurationMs;
  unsigned char *writer;  // Port data register
  unsigned long previousMillis;


public:
  LedBlinky(char port, int pin, int onDur, int offDur) {
    port = port;
    pin = pin;
    onDurationMs = onDur;
    offDurationMs = offDur;

    previousMillis = 0;

    // hardcode the binary representation for now
    pinBin=pow(2,pin)+0.5;

    switch (port) {
      case 'B': writer = (unsigned char *)0x25; break;
      case 'C': writer = (unsigned char *)0x28; break;
      case 'D': writer = (unsigned char *)0x2b; break;
    }
  }
  void Run() {
    unsigned long currentTime = millis();

    if (((*writer) & pinBin) == 0)  //If the LED is currently OFF
    {
      if (currentTime - previousMillis >= offDurationMs)  // OFF duration
      {
        *writer |= pinBin;  // Turn ON LED
        previousMillis = currentTime;
      }
    } else  //LED is currently ON
    {
      if (currentTime - previousMillis >= onDurationMs)  // ON duration
      {
        // Bitwise, if pinBin is 0b00001000, then ~pinBin is 0b11110111
        *writer &= ~pinBin;  // Turn OFF Led.
        previousMillis = currentTime;
      }
    }
  }
};

LedBlinky leds[] = {
  LedBlinky('D', 5, 781, 515),
  LedBlinky('D', 6, 2014, 1348),
  LedBlinky('D', 7, 343, 573),
  LedBlinky('B', 0, 678, 1389),
  LedBlinky('B', 1, 342, 534),
  LedBlinky('B', 2, 1478, 326),
  LedBlinky('C', 1, 1859, 351),
  LedBlinky('C', 2, 777, 888),
};

int numOfLeds = sizeof(leds)/sizeof(int);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  for (int i = 0; i < numOfLeds; i++) {
    leds[i].Run();
  }
}