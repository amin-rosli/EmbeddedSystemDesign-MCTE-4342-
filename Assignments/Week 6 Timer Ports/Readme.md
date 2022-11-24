## Week 6 Timer Ports

### emulated_pwm
A pwm signal is emulated using software by outputting the emulated pwm to a digital pin.

Video: https://drive.google.com/file/d/1rZtp6VBJc8mJt76BWx7BbJi63--hr7pO/view?usp=sharing

### pwm_timerport
A pwm signal is produced by using timer ports to control the speed of a DC motor using a L293D integrated curcuit.
The timer port used is timer port 0 configured as UP to OCR0A, PWM mode. 0CR0A is set as 255 and values of
0CR0B is adjusted to change the duty cycle of the resulting pwm signal.

Video: https://drive.google.com/file/d/1rZtp6VBJc8mJt76BWx7BbJi63--hr7pO/view?usp=sharing
