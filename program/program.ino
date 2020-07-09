/*
 * MotorKnob
 *
 * A stepper motor follows the turns of a potentiometer
 * (or other sensor) on analog input 0.
 *
 
 The circuit:
 * LCD RS pin to digital pin 0
 * LCD Enable pin to digital pin 1
 * LCD D4 pin to digital pin 4
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 7
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 
 
 
 * http://www.arduino.cc/en/Reference/Stepper
 * This example code is in the public domain.
 */

#include <Stepper.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(0, 1, 4, 5, 6, 7);

// change this to the number of steps on your motor
#define STEPS 100

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
int pasos= 20;

const int b_calibrar = 2;    
const int b_incr = 12;    
const int b_decr =  3;      
const int b_enter = 13;  

const int retardo_b = 200;  

int flag_calibrar=0;
int set_point = 0;
int apertura=0;


void setup()
{
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(60);
    // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  
  pinMode(b_calibrar, INPUT_PULLUP);
  pinMode(b_incr, INPUT_PULLUP);
  pinMode(b_decr, INPUT_PULLUP);
  pinMode(b_enter, INPUT_PULLUP);
  
  // Print a message to the LCD.
  lcd.print("Electro Valve ");
  
  
  set_point=0;
  apertura=0;
  lcd.setCursor(0, 1);
  lcd.print("SP:");
  lcd.print(set_point);
  lcd.setCursor(8, 1);
  lcd.print("AV:");
  lcd.print(apertura);
}

void loop()
{
///////////////////////
  if(digitalRead(b_calibrar)==0)
  {
    delay(retardo_b);
    if (flag_calibrar==1)
    {
      flag_calibrar=0;
      lcd.setCursor(0, 0);
      lcd.print("Electro Valve");
    }
    else
    {
      flag_calibrar=1;
      lcd.setCursor(0, 0);
      lcd.print("Calibratioon Mode");
    }
  }
/////////////////////////////////////
/////////////////////////////////////
  if (flag_calibrar==1)
  {
          if (digitalRead(b_incr)==0)
          {
            delay(retardo_b);
            stepper.step(-pasos);
          }
          if (digitalRead(b_decr)==0)
          {
            delay(retardo_b);
            stepper.step(pasos);
          }
          if (digitalRead(b_enter)==0)
          {
            delay(retardo_b);
            set_point=0;
            apertura=0;
            lcd.setCursor(3, 1);
            lcd.print(set_point);
            lcd.print("  ");
            lcd.setCursor(11, 1);
            lcd.print(apertura);
            lcd.print("  ");
          }
  }
  else
  {
         if (digitalRead(b_incr)==0)
          {
            delay(retardo_b);
            if (set_point<100)
            {
              set_point=set_point+5;
              lcd.setCursor(3, 1);
              lcd.print(set_point);
              lcd.print("  ");
           
            }
             
          }
          if (digitalRead(b_decr)==0)
          {
            delay(retardo_b);
            if (set_point>0)
            {
              set_point=set_point-5;
              lcd.setCursor(3, 1);
              lcd.print(set_point);
              lcd.print("  ");
            }
          }
          
          if (digitalRead(b_enter)==0)
          {
           delay(retardo_b);
                if(apertura<set_point)
                {
                   while(apertura!=set_point)
                    {
                      apertura=apertura+1;
                      stepper.step(-pasos);
                      lcd.setCursor(11, 1);
                      lcd.print(apertura);
                      lcd.print("  ");
                    }
                 }
                 else
                 {
                   while(apertura!=set_point)
                    {
                      apertura=apertura-1;
                      stepper.step(pasos);
                      lcd.setCursor(11, 1);
                      lcd.print(apertura);
                      lcd.print("  ");
                    }             
                  }
                  
                
          }

          
  }
   
   
        
//  if (digitalRead(b_enter)==0)
//  {
//    lcd.setCursor(0, 2);
//    lcd.print(4);
//  }

}
