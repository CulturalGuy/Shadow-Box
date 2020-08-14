#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

 
// called this way, it uses the default address 0x40

Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);
Adafruit_PWMServoDriver pwm3 = Adafruit_PWMServoDriver(0x42);
Adafruit_PWMServoDriver pwm4 = Adafruit_PWMServoDriver(0x43);
Adafruit_PWMServoDriver pwm5 = Adafruit_PWMServoDriver(0x44); 
Adafruit_PWMServoDriver pwm6 = Adafruit_PWMServoDriver(0x45);
Adafruit_PWMServoDriver pwm7 = Adafruit_PWMServoDriver(0x46); 

const int buttonPin = 2;     // the number of the pushbutton pin,
const int ledPin =  13;      // the number of the LED pin

byte lastButtonState = HIGH;
int buttonState = 0; 
byte buttonCounter   = 0;
int PWM = 1;

int brightness = 50;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

int value = 50;
int value2 = 50;
int value3 = 50;




void setup() {

delay(1000);

  pwm1.begin();
  pwm1.setPWMFreq(600);  // This is the maximum PWM frequency

  pwm2.begin();
  pwm2.setPWMFreq(600);  // maximum PWM frequency - (1600 ar 1000)

  pwm3.begin();
  pwm3.setPWMFreq(600);  // maximum PWM frequency - (1600 ar 1000)

  pwm4.begin();
  pwm4.setPWMFreq(600);  // maximum PWM frequency - (1600 ar 1000)

  pwm5.begin();
  pwm5.setPWMFreq(600);  // maximum PWM frequency - (1600 ar 1000)

  pwm6.begin();
  pwm6.setPWMFreq(600);  // maximum PWM frequency - (1600 ar 1000)

  pwm7.begin();
  pwm7.setPWMFreq(600);  // maximum PWM frequency - (1600 ar 1000)

  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

Serial.begin(9600);

}

void loop() {

  checkButton();


pwm1.setPWM(0, 0, 0);  
pwm1.setPWM(1, 0, 0); 
pwm1.setPWM(2, 0, 0); 
pwm1.setPWM(3, 0, 0);
pwm1.setPWM(4, 0, 0); 
pwm1.setPWM(5, 0, 0); 
pwm1.setPWM(6, 0, 0); 
pwm1.setPWM(7, 0, 0);  
pwm1.setPWM(8, 0, 0); 
pwm1.setPWM(9, 0, 0); 
pwm1.setPWM(10, 0, 0); 
pwm1.setPWM(11, 0, 0); 
pwm1.setPWM(12, 0, 0); 
pwm1.setPWM(13, 0, 0); 
pwm1.setPWM(14, 0, 0);
pwm1.setPWM(15, 0, 0); 

pwm2.setPWM(0, 0, 0);  
pwm2.setPWM(1, 0, 0); 
pwm2.setPWM(2, 0, 0); 
pwm2.setPWM(3, 0, 0);
pwm2.setPWM(4, 0, 0); 
pwm2.setPWM(5, 0, 0); 
pwm2.setPWM(6, 0, 0); 
pwm2.setPWM(7, 0, 0);  
pwm2.setPWM(8, 0, 0); 
pwm2.setPWM(9, 0, 0); 
pwm2.setPWM(10, 0, 0); 
pwm2.setPWM(11, 0, 0); 
pwm2.setPWM(12, 0, 0); 
pwm2.setPWM(13, 0, 0); 
pwm2.setPWM(14, 0, 0);
pwm2.setPWM(15, 0, 0); 

pwm3.setPWM(0, 0, 0);  
pwm3.setPWM(1, 0, 0); 
pwm3.setPWM(2, 0, 0); 
pwm3.setPWM(3, 0, 0);
pwm3.setPWM(4, 0, 0); 
pwm3.setPWM(5, 0, 0); 
pwm3.setPWM(6, 0, 0); 
pwm3.setPWM(7, 0, 0);  
pwm3.setPWM(8, 0, 0); 
pwm3.setPWM(9, 0, 0); 
pwm3.setPWM(10, 0, 0); 
pwm3.setPWM(11, 0, 0); 
pwm3.setPWM(12, 0, 0); 
pwm3.setPWM(13, 0, 0); 
pwm3.setPWM(14, 0, 0);
pwm3.setPWM(15, 0, 0); 

pwm4.setPWM(0, 0, 0);  
pwm4.setPWM(1, 0, 0); 
pwm4.setPWM(2, 0, 0); 
pwm4.setPWM(3, 0, 0);
pwm4.setPWM(4, 0, 0); 
pwm4.setPWM(5, 0, 0); 
pwm4.setPWM(6, 0, 0); 
pwm4.setPWM(7, 0, 0);  
pwm4.setPWM(8, 0, 0); 
pwm4.setPWM(9, 0, 0); 
pwm4.setPWM(10, 0, 0); 
pwm4.setPWM(11, 0, 0); 
pwm4.setPWM(12, 0, 0); 
pwm4.setPWM(13, 0, 0); 
pwm4.setPWM(14, 0, 0);
pwm4.setPWM(15, 0, 0); 


pwm5.setPWM(0, 0, 0);  
pwm5.setPWM(1, 0, 0); 
pwm5.setPWM(2, 0, 0); 
pwm5.setPWM(3, 0, 0);
pwm5.setPWM(4, 0, 0); 
pwm5.setPWM(5, 0, 0); 
pwm5.setPWM(6, 0, 0); 
pwm5.setPWM(7, 0, 0);  
pwm5.setPWM(8, 0, 0); 
pwm5.setPWM(9, 0, 0); 
pwm5.setPWM(10, 0, 0); 
pwm5.setPWM(11, 0, 0); 
pwm5.setPWM(12, 0, 0); 
pwm5.setPWM(13, 0, 0); 
pwm5.setPWM(14, 0, 0);
pwm5.setPWM(15, 0, 0); 

pwm6.setPWM(0, 0, 0);  
pwm6.setPWM(1, 0, 0); 
pwm6.setPWM(2, 0, 0); 
pwm6.setPWM(3, 0, 0);
pwm6.setPWM(4, 0, 0); 
pwm6.setPWM(5, 0, 0); 
pwm6.setPWM(6, 0, 0); 
pwm6.setPWM(7, 0, 0);  
pwm6.setPWM(8, 0, 0); 
pwm6.setPWM(9, 0, 0); 
pwm6.setPWM(10, 0, 0); 
pwm6.setPWM(11, 0, 0); 
pwm6.setPWM(12, 0, 0); 
pwm6.setPWM(13, 0, 0); 
pwm6.setPWM(14, 0, 0);
pwm6.setPWM(15, 0, 0); 

pwm7.setPWM(0, 0, 0);  
pwm7.setPWM(1, 0, 0); 
pwm7.setPWM(2, 0, 0); 
pwm7.setPWM(3, 0, 0);
pwm7.setPWM(4, 0, 0); 
pwm7.setPWM(5, 0, 0); 
pwm7.setPWM(6, 0, 0); 
pwm7.setPWM(7, 0, 0);  
pwm7.setPWM(8, 0, 0); 
pwm7.setPWM(9, 0, 0); 
pwm7.setPWM(10, 0, 0); 
pwm7.setPWM(11, 0, 0); 
pwm7.setPWM(12, 0, 0); 
pwm7.setPWM(13, 0, 0); 
pwm7.setPWM(14, 0, 0);
pwm7.setPWM(15, 0, 0); 



  
value = 200;

  if (buttonCounter >= 0 && buttonCounter < 17 && PWM == 1)
  {

pwm1.setPWM(buttonCounter, 0, value);
delay(100);
    if (buttonCounter == 16)
      {
    buttonCounter = 0;
    PWM = 2;
      }    
Serial.println(buttonCounter);
  }

  if (buttonCounter >= 0 && buttonCounter < 17 && PWM == 2)
  {

pwm2.setPWM(buttonCounter, 0, value);
delay(100);
    if (buttonCounter == 16)
      {
    buttonCounter = 0;
    PWM = 3;
      }
Serial.println(buttonCounter);    
  }

  if (buttonCounter >= 0 && buttonCounter < 17 && PWM == 3)
  {

pwm3.setPWM(buttonCounter, 0, value);
delay(100);
    if (buttonCounter == 16)
      {
    buttonCounter = 0;
    PWM = 4;
      }
Serial.println(buttonCounter);    
  }


  if (buttonCounter >= 0 && buttonCounter < 17 && PWM == 4)
  {

pwm4.setPWM(buttonCounter, 0, value);
delay(100);
    if (buttonCounter == 16)
      {
    buttonCounter = 0;
    PWM = 5;
      }  
Serial.println(buttonCounter);  
  }


  if (buttonCounter >= 0 && buttonCounter < 17 && PWM == 5)
  {

pwm5.setPWM(buttonCounter, 0, value);
delay(100);
    if (buttonCounter == 16)
      {
    buttonCounter = 0;
    PWM = 6;
      }  
Serial.println(buttonCounter);  
  }

    if (buttonCounter >= 0 && buttonCounter < 17 && PWM == 6)
  {

pwm6.setPWM(buttonCounter, 0, value);
delay(100);
    if (buttonCounter == 16)
      {
    buttonCounter = 0;
    PWM = 7;
      } 
Serial.println(buttonCounter);   
  }

    if (buttonCounter >= 0 && buttonCounter < 17 && PWM == 7)
  {

pwm7.setPWM(buttonCounter, 0, value);
delay(100);
    if (buttonCounter == 16)
      {
    buttonCounter = 0;
pwm7.setPWM(0, 0, value);
pwm7.setPWM(1, 0, value);
pwm7.setPWM(2, 0, value);
pwm7.setPWM(3, 0, value);
pwm7.setPWM(4, 0, value);
pwm7.setPWM(5, 0, value);
pwm7.setPWM(6, 0, value);
PWM == 1;
      }
Serial.println(buttonCounter);    
  }
} //END of     l o o p ( )




void checkButton()
{
  buttonState = digitalRead(buttonPin);

  if (lastButtonState != buttonState)
  {
    lastButtonState = buttonState;
    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    //has the button been released (HIGH is not pushed)
    if (buttonState == HIGH)
    {
      buttonCounter++;  
      
    // turn LED on:
    digitalWrite(ledPin, HIGH);
      
    }
  }
} //END of     c h e c k B u t t o n ( )
