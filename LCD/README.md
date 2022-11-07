# Programming a 16 x 2 LCD Screen

## What is a 16 x 2 LCD
The term LCD stands for _Liquid Crystal Display_ . It is a screen used for displaying numbers, characters and simple graphics. They have an incorporated refreshing controller thereby relieving the CPU of the task of refreshing the LCD.

![Image showing an LCD](https://www.sunrom.com/img/p/2681/2681_800.jpg)
_source: https://www.sunrom.com_


## Working of the 16 x 2 LCD
The LCD Consists of two registers as shown below.

![Image Showing the Registers of an LCD](data/LCD%20Registers.png)

- 8 Data Pins: D0 - D7
- Three control pins: RS, R/W, E
- Voltage Control Pins: VCC, VSS, VEE

## Voltage Control Pins (VCC, VSS, VEE)
- VCC and VSS are used to power the LCD with VCC connecte to +5V and VSS connected to ground
- VEE is used to control the brightness of the LCD. A larger voltage corresponds to a brighter LCD while a smaller voltage corresponds to a dimm LCD

## Three Control Pins (RS, R/W, E)
- _Register Select pin (RS):_ Select between the Data Register and the Instruction Command code Register. When RS = 0 the Instruction command code register is selected. When RS = 1 then the Data Register is selected.
- _Read Write Pin (R/W):_ If a logic 0 is given to R/W pin, it means you are ready to write to the Data Registers. if a logic 1 is given to R/W pin, it means you are going to Read from the Data Register
- _Enable Pin (E):_ Enable pin is used to latch information present to its data pins. This means you first supply the data pins with data and then give the Enable pin a logic HIGH for a period greater than 450ns and then an logic LOW.

## 8 Data Pins (D0 - D7)
- For you to display any number or letter to the LCD, you need to send the ASCII codes for the equivalent letter or number to the data pins.

# Connection with the 8051 microcontroller
![Image showing the connection of the LCD with the 8051 microcontroller](data/LCD%208051%20Connection.png)


- _This Project is heavily inspired by a course taken from [www.udemy.com](https://www.udemy.com/course/8051-microcontroller-embedded-c-and-assembly-language/)_