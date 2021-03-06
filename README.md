<a name="top"></a>
# Valve-Opening-Control

![VALVE](https://github.com/FreakJazz/Valve-Opening-Control/blob/master/images/Result6.jpg)

<a name="item1"></a>
## Description

This work shows the open-loop control of the opening and closing of a globe valve by means of an adaptation of gears to a stepper motor, in addition to showing the opening percentage by means of an LCD and calibrating the setpoint by means of a potentiometer, the Flow shows the flow of water from the valve using an oscilloscope for opening and closing tests.

<a name="item2"></a>
## Contents
- [Description](#item1)
- [Contents](#item2)
- [Programming](#item3)
- [Desing](#item4)
- [Results](#item5)
- [Contributing](#item6)

[Up](#top)

<a name="item3"></a>
## Programming

In this section, the programming of the Arduino is observed to calibrate the steps and show both the setpoint and the valve opening on the LCD

### LiquidCrystal

In order to visualize the interface the LCD 16x2 is used.

![LCD](https://github.com/FreakJazz/Valve-Opening-Control/blob/master/images/lcd.jpg)

This library is used to LCD 16x2

```C
#include "lcd.h"
```
### Step Motor

In order to control the openning of the valve the step motor is used.

![LCD](https://github.com/FreakJazz/Valve-Opening-Control/blob/master/images/step-motor.jpg)

This library is used to STEP MOTOR

```C
#include <Stepper.h>
```
<a name="item4"></a>
## Desing

### Step Motor

The valve is designed by means of a gear arrangement to be coupled to the motor

![VALVE](https://github.com/FreakJazz/Valve-Opening-Control/blob/master/images/valve.PNG)


<a name="item5"></a>
## Result

Connections and Test results are seen below

![VALVE](https://github.com/FreakJazz/Valve-Opening-Control/blob/master/images/final_programming.PNG)

![VALVE](https://github.com/FreakJazz/Valve-Opening-Control/blob/master/images/Result1.jpg)

![VALVE](https://github.com/FreakJazz/Valve-Opening-Control/blob/master/images/Result2.jpg)

![VALVE](https://github.com/FreakJazz/Valve-Opening-Control/blob/master/images/Result3.jpg)

![VALVE](https://github.com/FreakJazz/Valve-Opening-Control/blob/master/images/Result4.jpg)

![VALVE](https://github.com/FreakJazz/Valve-Opening-Control/blob/master/images/Result5.jpg)


<a name="item5"></a>
## Contributing

**JAZMIN RODRIGUEZ** 

[GitHub](https://github.com/FreakJazz), [LinkedIn](https://www.linkedin.com/in/jazmin-rodriguez-bermeo/)

[Up](#top)


