## Week 7 Interrupts

### interrupt_led
An interrupt is attached to button that toggles button_state to turn on and off an LED.

Video: https://drive.google.com/file/d/1rhM1B6bzM80MR7pqOkHNacGic15Yr--B/view?usp=sharing

### limitswitch_emulation
Interrupts are often used when the devices is required to run other commands but needs to 
react quickly to a specific signal. 

A common example of hardware interrupts is an emergency stop button. While the machine is 
still runing, the processor executes commands required for the machine to do its task. Asking
the machine to read the output of the emergency button every second in its programming is
very ineffecient and could spawn conflicts from the other parts of the programming. So, a
hardware interrupt is attached to the emergency stop button so when it is pressed, the 
processor immediately executes the Interrupt Service Routine (ISR) attached to the button
and shut down the machine.Interrupts are very helpful in this case as the processor could keep
watch of the output of the emergency button in the background and be interrupted by it when 
it is pressed.

This experiment tries to replicate the use of a hardware interrupt in a machine such as 
3D printers or CNC machines. When the motors of the machines are homing ( returning
to 0,0), the machine will simply move the motor to the beginning. However, the position of
the motor in the software sometimes do not reflect its actual position exactly. These minor
inaccuracies may cause the motor to be retracted too much or too little that could lead to
the machine not functioning optimally or do damage to the machine. As such, a limit switch
is placed at the end of the machine to detect when the motor reaches at the end. Interrupts
are used as the processor is required to run commands to move the motor but also look out
for the singal from the limit switches. Once the limit switch is activated, the motor stops
immediately.

The left button in the experiment represents the limit switch while the right is the button
to initate homing of the DC motor.

Video: https://drive.google.com/file/d/165AcPp236kVRxIHCeTR_bBt6s2vlrPVN/view?usp=sharing

