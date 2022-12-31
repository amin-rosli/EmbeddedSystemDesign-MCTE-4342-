## Toggle LED

The toggle LED is program is a program that simply toggles an LED on and off. However, unlike normal programs that rely on the volatile memory of the microcontroller, this program uses non-volatile memory(EEPROM) instead. The advantage of using the EEPROM to store the state of the LED is that it stores the data even when power is lost to the device, meaning that is not volatile to power hence the name.

In the video, I reset the Arduino a couple of times but the LED still retains the state that it was previously in either on or off which cannot occur if we rely on volatile memory.

https://user-images.githubusercontent.com/116183995/210133764-cf66fb10-8236-429d-b90a-215bbeb610a3.mp4
