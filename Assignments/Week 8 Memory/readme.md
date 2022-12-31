# Toggle LED

The toggle LED is program is a program that simply toggles an LED on and off. However, unlike normal programs that rely on the volatile memory of the microcontroller, this program uses non-volatile memory(EEPROM) instead. The advantage of using the EEPROM to store the state of the LED is that it stores the data even when power is lost to the device, meaning that is not volatile to power hence the name.

In the video, I reset the Arduino a couple of times but the LED still retains the state that it was previously in either on or off which cannot occur if we rely on volatile memory.

https://user-images.githubusercontent.com/116183995/210133764-cf66fb10-8236-429d-b90a-215bbeb610a3.mp4

# Servo position

This program consists of two main functions being, writer() and reader().

## writer ():
The user pushes the in built button on the Arduino to initiate writing mode, the LED will light up to indicate that writing mode is initiated. 

When the writing mode is initated, the user could use the potentiometer to change the position of the servo motor and press 1 of 3 buttons for saving that position.

## reader ():
The user pushes the in built button on the Arduino to initiate reading mode, the LED will turn off to indicate that reading mode is initiated. 

The user then pushes 1 of 3 buttons so that the program will read the position of the servo motor stored in each profile.

Because this program uses the EEPROM, the position saved in each profile is still retained even when the Arduino loses power (in this case, the Arduino is reset).


https://user-images.githubusercontent.com/116183995/210133961-5c45e876-564d-484b-bbde-482915ae0961.mp4

# Distance

An ultrasonic sensor is connected to the Arduino and by using an SD card module, the readings obtained from the sensor will then be saved into an SD card to export the data.


![Setup](https://user-images.githubusercontent.com/116183995/210134100-9e8f91be-7813-4f19-9366-548cba067f98.jpg)

The resulting data obtained from the SD card:

![SD Card Data](https://user-images.githubusercontent.com/116183995/210134147-bdeff70e-4222-4b35-be55-d65242c518b9.jpg)
