
#include <Stepper.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the LCD pins
LiquidCrystal lcd(0, 1, 4, 5, 6, 7);

// change this to the number of steps on your motor
#define STEPS 150

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
