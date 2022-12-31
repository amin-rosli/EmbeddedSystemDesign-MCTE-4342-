# Power Saving Methods

Multiple methods was used to take to gauge differing methods and its affects on the power consumption of an Arduino Mega. Measurements of the battery voltage was taken to calculate the power consumption used by the Arduino Mega. 

To measure the power consumption, Watt's law is used:

P = I * V
where : P = Power consumption (W) , I = Current (A) , V = Potential difference (V) 

## Battery Voltage
![20221231_190838](https://user-images.githubusercontent.com/116183995/210134554-3cd494b7-47a1-40c1-8687-082593425a9e.jpg)

The battery voltage measured is 4.71 V

## Arduino Mega default power consumption
![Screenshot 2022-12-31 191222](https://user-images.githubusercontent.com/116183995/210134622-ed59b388-d4a9-493c-9a34-4700417ec223.jpg)

The default current draw of the Arduino Mega was taken with a current draw of 36.5mA. 
The power consumption is 4.71V x 36.5mA = 0.172W.

## Let unused pins as input
Turning all unused pins as output decreases the power consumption of the Arduino it does not have to poll for any changes in the pin.

![output](https://user-images.githubusercontent.com/116183995/210134809-c2b145eb-a77a-473e-8ac1-15f909b3825a.jpg)

Current draw = 35.0mA
Power consumption = 0.164W

## Disable the ADC
Disabling the analog to digital converter allows us to save energy as the converter is shut off.

![ADC](https://user-images.githubusercontent.com/116183995/210135042-45e9a90d-aff4-427b-a8ae-c920a945af0c.jpg)

Current draw = 34.7mA
Power consumption = 0.163W

## Enable Sleep Mode
Putting the Arduino to sleep mode, shuts off all unnecessary components, reducing the power consumption. This tremendously reduces power consumption of the Arduino.

![sleep](https://user-images.githubusercontent.com/116183995/210135131-a8932493-9ce8-4cd2-b948-e4fdc3128778.jpg)

Current draw = 4.70mA
Power consumption = 0.022W

The Arduino could be waken up by attaching an interrupt to wake the Arduino when it is required to be functional.
