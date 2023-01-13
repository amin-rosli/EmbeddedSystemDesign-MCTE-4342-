# Random_mode
Program using a linear actuator - developed for project.

The program generates a random distance for the linear actuator to move left and right. It was proposed to be used in our project but was later scraped due to the slow motion of the linear actuator making little difference when compared to a normal linear loop.

https://user-images.githubusercontent.com/116183995/210140503-f7e07e39-21ec-4f40-b9a9-cfe591964219.mp4

# DC Motor Speed and direction

Program that controls the speed of a DC motor and its direction.

Speed : A potentiometer receives input from the 10-bit analog pin and converts it into an 8-bit PWM signal to be sent to the L298N motor driver to control the speed of the motor.

Direction : 2 Buttons controls the direction of the DC motor being clockwise or anti-clockwise. The button receives the input and sends the appropriate signal to the L298N motor driver to change the direction of current flow in the DC motor.

https://user-images.githubusercontent.com/116183995/210178668-8538a69a-1476-46ca-bb0c-b5d570573e68.mp4

A slow motion video to make the direction change easier to see:<br>  
(**WARNING**: FLASHING LIGHTS) 

https://user-images.githubusercontent.com/116183995/210178691-fd98f008-2209-4a19-b583-e620302a3700.mp4

# Stepper motor distance control

A stepper motor is an electric motor that can rotate in precise increments or "steps" rather than continuously. Stepper motors are commonly used in devices that require precise position control, such as printers, scanners, and computer disk drives. They are also used in CNC machines and other industrial automation applications.The stepper motor used here is the 28BYJ-48 Stepper Motor with ULN2003 Driver. The 28BYJ-48 is a unipolar stepper motor that runs on 5V. 

As stepper motor moves in steps which are in terms of angle, we need to find out the steps needed for a stepper motor to spin a single revolution which is usually given in its datasheet but to calculate the steps required for a stepper motor per revolution manually could be done so by:

![Gearing](https://user-images.githubusercontent.com/116183995/212372212-4fda36c5-06d2-465b-87be-b2e3390c5774.png)

Steps required per revoultion : 
[ Required steps for the input gear per revolution ] x [ Gear reduction ratio of the motor ]
= ( 360 ° / 32 ) x 64
= 11.25 x 64
= 2048 steps per revolution

This program steps the motor a specific amount of steps by reading the values given by the potentiometer which is done by interpolation of the potentiometer in terms of the steps for a single revolution of the stepper motor. 

( [Source] , [ Range of 10-bit ADC values ] , [ Range of steps per revolution ] )
= ( Potentiometer, 0, 1024, 0 , 2048 )

The higher the voltage of the potentiometer, the higher the analog value will be which in turn increases the steps of the motor. The user then presses the button to move the motor to that specific steps.

https://user-images.githubusercontent.com/116183995/212367028-b6ff0ead-7a94-46a4-913e-d558c9d9f2c5.mp4
