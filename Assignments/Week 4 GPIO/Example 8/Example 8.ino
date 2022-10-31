class Counter { //initialize class BLinkz
                //initialize variables
public:                                                 

  int pin;
  int pinB;
  int count = 0;
  int last_state;
  unsigned long prev_time;
  unsigned char *read;
  char port;

  Counter(int pin, char port) {                           //initialize default constructor (port letter,pin number,on duration,off duration)
    
    port = port;                                          
    pinB = pow(2, pin) + 0.5;                             //converts pin from DEC to BIN

    switch (port) {
      case 'B': read = (unsigned char *)0x23; break;      //converts port letter to point address to read
      case 'C': read = (unsigned char *)0x26; break;
      case 'D': read = (unsigned char *)0x29; break;
    }
  }
};

// PROGRAM PARAMETERS
Counter button[] = { Counter(0, 'B'), Counter(1, 'B'), Counter(2, 'B'), Counter(3, 'B'), Counter(4, 'B') };  //buttons and its corresponding pins
unsigned long debounce = 20;                                                                                 //debounce duration (ms)


int button_num = (sizeof(button) / sizeof(button[0]));    //calculate the number of buttons initialized
unsigned char *read = (unsigned char *)0x23;
unsigned char *dir = (unsigned char *)0x24;
unsigned char *write = (unsigned char *)0x25;

void setup() {
  Serial.begin(9600);

  *dir = 0b00000000;  // makes the pins as INPUT_PULLUP
  *write = 0b11111111;
}

void loop() {


  for (int a = 0; a < button_num; a++) {      //loops according to number of buttons

    unsigned long current_time = millis();    //update current_time
    int current = (((*read) & button[a].pinB) == 0);    //checks if button is pushed or not returning to current

    if (current_time - button[a].prev_time > debounce) {    //if time passed since last pushed was more than debounce duration

      if (current && !button[a].last_state) {  // checks if current and prev is not the same
        button[a].count += 1;                  // increases count value
        button[a].prev_time = millis();
      }
      button[a].last_state = current;  // makes prev and current the same value
    }
  }

  for (int b = 0; b < button_num; b++) {    //prints the number of button presses according to button number
    Serial.print("Button ");
    Serial.print(b + 1);
    Serial.print(" = ");
    Serial.print(button[b].count);
    Serial.print(" | ");
  }
  Serial.println();
  Serial.println();
}
