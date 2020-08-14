

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


int ProgressCounterMode_1 = 1;

int Applecounter = 1;
int FLcounter = 1;
int OPcounter = 1;

unsigned long previousBirdMillis = 1;
unsigned long previous3LvLMillisMODE_1 = 1;
unsigned long previousFLMillis = 1;
unsigned long previousOPMillis = 1;
unsigned long previousAppleMillis = 1;


unsigned long currentMillis = millis();
unsigned long previousMillis = 0;        // will store last time LED was updated
int interval = 1000;           // interval at which to blink (milliseconds)

int value = 0;
int value2 = 0;
int value3 = 0;

int randomNumber;
int AVAILABLE_COLORS[9][3] = {{200, 0, 200}, {200, 200, 0}, {0, 200, 200}, {200, 100, 0}, {100, 200, 0}, {0, 200, 100}, {0, 100, 200}, {250, 50, 50}, {100, 150, 200}} ;
int AVAILABLE_COLORS_OP[14][3] = {{3000, 0, 0},{0, 3000, 0},{0, 0, 3000},{3000, 3000, 0},{3000, 0, 3000},{0, 3000, 3000},{1000, 3000, 3000},{3000, 0, 1000},{3000, 1000, 2000},{1000, 500, 3000},{3000, 1500, 1500},{500, 3000, 1000},{500, 3000, 2000},{700, 2500, 3000}};

long TreeR, TreeG, TreeB;
long CanopyR, CanopyG, CanopyB;

long Bird_1_R, Bird_1_G, Bird_1_B;
long Bird_2_R, Bird_2_G, Bird_2_B;
long Bird_3_R, Bird_3_G, Bird_3_B;
long Bird_4_R, Bird_4_G, Bird_4_B;

long Apple_12_R, Apple_12_G, Apple_12_B;
long Apple_34_R, Apple_34_G, Apple_34_B;
long Apple_56_R, Apple_56_G, Apple_56_B;

long AppleLeaf_12_R, AppleLeaf_12_G, AppleLeaf_12_B;
long AppleLeaf_34_R, AppleLeaf_34_G, AppleLeaf_34_B;
long AppleLeaf_56_R, AppleLeaf_56_G, AppleLeaf_56_B;

long Blossom_14_R, Blossom_14_G, Blossom_14_B;
long Blossom_23_R, Blossom_23_G, Blossom_23_B;
long Blossom_56_R, Blossom_56_G, Blossom_56_B;

//Falling Leaves
long FL_1_R, FL_1_G, FL_1_B;
long FL_2_R, FL_2_G, FL_2_B;
long FL_3_R, FL_3_G, FL_3_B;
long FL_4_R, FL_4_G, FL_4_B;
long FL_5_R, FL_5_G, FL_5_B;
long FL_6_R, FL_6_G, FL_6_B;
long FL_7_R, FL_7_G, FL_7_B;
long FL_8_R, FL_8_G, FL_8_B;
long FL_9_R, FL_9_G, FL_9_B;

int randomFL1;
int randomFL2;
int randomFL3;

//Fiber Optics
long OP_1_R, OP_1_G, OP_1_B;
long OP_2_R, OP_2_G, OP_2_B;
long OP_3_R, OP_3_G, OP_3_B;
long OP_4_R, OP_4_G, OP_4_B;
long OP_5_R, OP_5_G, OP_5_B;
long OP_6_R, OP_6_G, OP_6_B;
long OP_7_R, OP_7_G, OP_7_B;


//_______TARGET______________


long TargetTreeR, TargetTreeG, TargetTreeB;
long TargetCanopyR, TargetCanopyG, TargetCanopyB;

long TargetBird_1_R, TargetBird_1_G, TargetBird_1_B;
long TargetBird_2_R, TargetBird_2_G, TargetBird_2_B;
long TargetBird_3_R, TargetBird_3_G, TargetBird_3_B;
long TargetBird_4_R, TargetBird_4_G, TargetBird_4_B;

long TargetApple_12_R, TargetApple_12_G, TargetApple_12_B;
long TargetApple_34_R, TargetApple_34_G, TargetApple_34_B;
long TargetApple_56_R, TargetApple_56_G, TargetApple_56_B;

long TargetAppleLeaf_12_R, TargetAppleLeaf_12_G, TargetAppleLeaf_12_B;
long TargetAppleLeaf_34_R, TargetAppleLeaf_34_G, TargetAppleLeaf_34_B;
long TargetAppleLeaf_56_R, TargetAppleLeaf_56_G, TargetAppleLeaf_56_B;

long TargetBlossom_14_R, TargetBlossom_14_G, TargetBlossom_14_B;
long TargetBlossom_23_R, TargetBlossom_23_G, TargetBlossom_23_B;
long TargetBlossom_56_R, TargetBlossom_56_G, TargetBlossom_56_B;

//Falling Leaves
long TargetFL_1_R, TargetFL_1_G, TargetFL_1_B;
long TargetFL_2_R, TargetFL_2_G, TargetFL_2_B;
long TargetFL_3_R, TargetFL_3_G, TargetFL_3_B;
long TargetFL_4_R, TargetFL_4_G, TargetFL_4_B;
long TargetFL_5_R, TargetFL_5_G, TargetFL_5_B;
long TargetFL_6_R, TargetFL_6_G, TargetFL_6_B;
long TargetFL_7_R, TargetFL_7_G, TargetFL_7_B;
long TargetFL_8_R, TargetFL_8_G, TargetFL_8_B;
long TargetFL_9_R, TargetFL_9_G, TargetFL_9_B;

//Fiber Optics
long TargetOP_1_R, TargetOP_1_G, TargetOP_1_B;
long TargetOP_2_R, TargetOP_2_G, TargetOP_2_B;
long TargetOP_3_R, TargetOP_3_G, TargetOP_3_B;
long TargetOP_4_R, TargetOP_4_G, TargetOP_4_B;
long TargetOP_5_R, TargetOP_5_G, TargetOP_5_B;
long TargetOP_6_R, TargetOP_6_G, TargetOP_6_B;
long TargetOP_7_R, TargetOP_7_G, TargetOP_7_B;


void setup() {

Serial.begin(9600);

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



}

void loop() {
  unsigned long current3LvLMillisMODE_1 = millis();


  unsigned long AppleMillis = millis();


  checkButton();



  if (buttonCounter == 1)
  {


 if ( current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 <= 4000 ){
 ProgressCounterMode_1 = 1;     
 }
 
 if ( current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 > 4000 && current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 <= 6000 ){
 ProgressCounterMode_1 = 2;   
 }

 if ( current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 > 6000 && current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 <= 12000 ){
 ProgressCounterMode_1 = 3;   
 }

 if ( current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 > 12000 && current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 <= 20000 ){
 ProgressCounterMode_1 = 4;   
 }

 if ( current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 > 20000 && current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 <= 30000 ){
 ProgressCounterMode_1 = 5;   
 }

 if ( current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 > 30000 && current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 <= 45000 ){
 ProgressCounterMode_1 = 6;   
 }

 if ( current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 > 45000 && current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 <= 55000 ){
 ProgressCounterMode_1 = 7;   
 }

 if ( current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 > 55000 && current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 <= 71000 ){
 ProgressCounterMode_1 = 8;   
 }
 
 if ( current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 > 71000 && current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 <= 76000 ){
 ProgressCounterMode_1 = 9;   
 }

 if ( current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 > 76000 && current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 <= 80000 ){
 ProgressCounterMode_1 = 10;   
 }

 if ( current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 > 80000 && current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 <= 100000 ){
 ProgressCounterMode_1 = 11;   
 }

  if ( current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 > 100000 && current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 <= 101000 ){
 ProgressCounterMode_1 = 12;   
 }
  if ( current3LvLMillisMODE_1 - previous3LvLMillisMODE_1 > 101000){
previous3LvLMillisMODE_1 = current3LvLMillisMODE_1;
 }
 


//__________________STEP 1_____________________________
  if (ProgressCounterMode_1 == 1){

//Target values for step 1
TargetTreeR = 60;
TargetTreeG = 60;
TargetTreeB = 60;
}

//__________________STEP 2_____________________________
  if (ProgressCounterMode_1 == 2){

//Target values for step 2
TargetTreeR = 150;
TargetTreeG = 60;
TargetTreeB = 0;
}

//__________________STEP 3_____________________________

  if (ProgressCounterMode_1 == 3){

if ( AppleMillis - previousAppleMillis >= 500 && Applecounter == 1){
      previousAppleMillis = AppleMillis;
      Applecounter = 2;      

TargetBlossom_14_R = 2000, TargetBlossom_14_G = 0, TargetBlossom_14_B = 600;
}
if ( AppleMillis - previousAppleMillis >= 500 && Applecounter == 2){
      previousAppleMillis = AppleMillis;
      Applecounter = 3;     

TargetBlossom_23_R = 2000, TargetBlossom_23_G = 0, TargetBlossom_23_B = 600;
}
if ( AppleMillis - previousAppleMillis >= 500 && Applecounter == 3){
      previousAppleMillis = AppleMillis;
      Applecounter = 4;  

TargetBlossom_56_R = 2000, TargetBlossom_56_G = 0, TargetBlossom_56_B = 600;
}
}


//__________________STEP 4_____________________________

  if (ProgressCounterMode_1 == 4){

TargetCanopyR = 30;
TargetCanopyG = 100;
TargetCanopyB = 0;

}


  if (ProgressCounterMode_1 == 5){

if ( AppleMillis - previousAppleMillis >= 500 && Applecounter == 4){
      previousAppleMillis = AppleMillis;
      Applecounter = 5;      
TargetBlossom_14_R = 0, TargetBlossom_14_G = 0, TargetBlossom_14_B = 0;
}
if ( AppleMillis - previousAppleMillis >= 500 && Applecounter == 5){
      previousAppleMillis = AppleMillis;
      Applecounter = 6;     
TargetBlossom_23_R = 0, TargetBlossom_23_G = 0, TargetBlossom_23_B = 0;
}
if ( AppleMillis - previousAppleMillis >= 500 && Applecounter == 6){
      previousAppleMillis = AppleMillis;
      Applecounter = 7;  
TargetBlossom_56_R = 0, TargetBlossom_56_G = 0, TargetBlossom_56_B = 0;
}


if ( Blossom_14_R == 0 && Blossom_14_G == 0 && Blossom_14_B == 0 ){
TargetApple_12_R = 600, TargetApple_12_G = 250, TargetApple_12_B = 0;
TargetAppleLeaf_12_R = 40, TargetAppleLeaf_12_G = 100, TargetAppleLeaf_12_B = 0;
}
if ( Blossom_23_R == 0 && Blossom_23_G == 0 && Blossom_23_B == 0 ){ 
TargetApple_34_R = 600, TargetApple_34_G = 250, TargetApple_34_B = 0;
TargetAppleLeaf_34_R = 40, TargetAppleLeaf_34_G = 100, TargetAppleLeaf_34_B = 0;
}
if ( Blossom_56_R == 0 && Blossom_56_G == 0 && Blossom_56_B == 0 ){ 
TargetApple_56_R = 600, TargetApple_56_G = 250, TargetApple_56_B = 0;
TargetAppleLeaf_56_R = 40, TargetAppleLeaf_56_G = 100, TargetAppleLeaf_56_B = 0;
}

}



  if (ProgressCounterMode_1 == 6){

if ( AppleMillis - previousAppleMillis >= 500 && Applecounter == 7){
      previousAppleMillis = AppleMillis;
      Applecounter = 8;      
TargetApple_12_R = 600, TargetApple_12_G = 0, TargetApple_12_B = 0;
}
if ( AppleMillis - previousAppleMillis >= 500 && Applecounter == 8){
      previousAppleMillis = AppleMillis;
      Applecounter = 9;     
TargetApple_34_R = 600, TargetApple_34_G = 0, TargetApple_34_B = 0;
}
if ( AppleMillis - previousAppleMillis >= 500 && Applecounter == 9){
      previousAppleMillis = AppleMillis;
      Applecounter = 10;  
TargetApple_56_R = 600, TargetApple_56_G = 0, TargetApple_56_B = 0;
}


}


  if (ProgressCounterMode_1 == 7){
    
TargetCanopyR = 200;
TargetCanopyG = 50;
TargetCanopyB = 0;

TargetAppleLeaf_12_R = 150, TargetAppleLeaf_12_G = 100, TargetAppleLeaf_12_B = 0;
TargetAppleLeaf_34_R = 150, TargetAppleLeaf_34_G = 100, TargetAppleLeaf_34_B = 0;
TargetAppleLeaf_56_R = 150, TargetAppleLeaf_56_G = 100, TargetAppleLeaf_56_B = 0;

}


  if (ProgressCounterMode_1 == 8){

if ( AppleMillis - previousAppleMillis >= 1200 && Applecounter == 10){
      previousAppleMillis = AppleMillis;
      Applecounter = 11;      
TargetApple_12_R = 0, TargetApple_12_G = 0, TargetApple_12_B = 0;
TargetAppleLeaf_12_R = 0, TargetAppleLeaf_12_G = 0, TargetAppleLeaf_12_B = 0;
Apple_12_R = 0, Apple_12_G = 0, Apple_12_B = 0;
AppleLeaf_12_R = 0, AppleLeaf_12_G = 0, AppleLeaf_12_B = 0;
}
if ( AppleMillis - previousAppleMillis >= 1200 && Applecounter == 11){
      previousAppleMillis = AppleMillis;
      Applecounter = 12;     
TargetApple_34_R = 0, TargetApple_34_G = 0, TargetApple_34_B = 0;
TargetAppleLeaf_34_R = 0, TargetAppleLeaf_34_G = 0, TargetAppleLeaf_34_B = 0;
Apple_34_R = 0, Apple_34_G = 0, Apple_34_B = 0;
AppleLeaf_34_R = 0, AppleLeaf_34_G = 0, AppleLeaf_34_B = 0;
}
if ( AppleMillis - previousAppleMillis >= 1200 && Applecounter == 12){
      previousAppleMillis = AppleMillis;
      Applecounter = 1;  
TargetApple_56_R = 0, TargetApple_56_G = 0, TargetApple_56_B = 0;
TargetAppleLeaf_56_R = 0, TargetAppleLeaf_56_G = 0, TargetAppleLeaf_56_B = 0;
Apple_56_R = 0, Apple_56_G = 0, Apple_56_B = 0;
AppleLeaf_56_R = 0, AppleLeaf_56_G = 0, AppleLeaf_56_B = 0;
}
}



  if (ProgressCounterMode_1 == 9){
    
TargetCanopyR = 50;
TargetCanopyG = 50;
TargetCanopyB = 50;

TargetTreeR = 50;
TargetTreeG = 50;
TargetTreeB = 50;

}

  if (ProgressCounterMode_1 == 10){

TargetCanopyR = 0;
TargetCanopyG = 0;
TargetCanopyB = 0;
TargetFL_1_R = 0, TargetFL_1_G = 0, TargetFL_1_B = 0;
TargetFL_2_R = 0, TargetFL_2_G = 0, TargetFL_2_B = 0;
TargetFL_3_R = 0, TargetFL_3_G = 0, TargetFL_3_B = 0;
TargetFL_4_R = 0, TargetFL_4_G = 0, TargetFL_4_B = 0;
TargetFL_5_R = 0, TargetFL_5_G = 0, TargetFL_5_B = 0;
TargetFL_6_R = 0, TargetFL_6_G = 0, TargetFL_6_B = 0;
TargetFL_7_R = 0, TargetFL_7_G = 0, TargetFL_7_B = 0;
TargetFL_8_R = 0, TargetFL_8_G = 0, TargetFL_8_B = 0;
TargetFL_9_R = 0, TargetFL_9_G = 0, TargetFL_9_B = 0;

}


  if (ProgressCounterMode_1 == 11){

OpticFibers();

}


  if (ProgressCounterMode_1 == 12){

      OPcounter = 1;
}

  if (ProgressCounterMode_1 == 8 || ProgressCounterMode_1 == 9){

FallingLeaves();
  }

Birds();
ReachingTarget();
mode();

  }


  
  if (buttonCounter == 2)
  {

CanopyR = 300;
CanopyG = 50;
CanopyB = 0;

TreeR = 180;
TreeG = 80;
TreeB = 0;

AppleLeaf_12_R = 150, AppleLeaf_12_G = 70, AppleLeaf_12_B = 0;
AppleLeaf_34_R = 150, AppleLeaf_34_G = 70, AppleLeaf_34_B = 0;
AppleLeaf_56_R = 150, AppleLeaf_56_G = 70, AppleLeaf_56_B = 0;

Apple_12_R = 600, Apple_12_G = 0, Apple_12_B = 0;
Apple_34_R = 600, Apple_34_G = 0, Apple_34_B = 0;
Apple_56_R = 600, Apple_56_G = 0, Apple_56_B = 0;

FallingLeaves();
Birds();
ReachingTarget();
mode();
 
  }

  if (buttonCounter == 3)
  {

CanopyR = 300;
CanopyG = 300;
CanopyB = 300;

TreeR = 50;
TreeG = 50;
TreeB = 50;

OpticFibers_2();
Birds();
ReachingTarget();
mode();
  }



  if (buttonCounter == 4){


TreeR = 50;
TreeG = 50;
TreeB = 50;

OpticFibers_2();
Birds();
ReachingTarget();
mode();

  }

  if (buttonCounter == 5){

CanopyR = 50;
CanopyG = 300;
CanopyB = 0;

TreeR = 180;
TreeG = 80;
TreeB = 0;

AppleLeaf_12_R = 200, AppleLeaf_12_G = 300, AppleLeaf_12_B = 0;
AppleLeaf_34_R = 200, AppleLeaf_34_G = 300, AppleLeaf_34_B = 0;
AppleLeaf_56_R = 200, AppleLeaf_56_G = 300, AppleLeaf_56_B = 0;

Apple_12_R = 600, Apple_12_G = 0, Apple_12_B = 0;
Apple_34_R = 600, Apple_34_G = 0, Apple_34_B = 0;
Apple_56_R = 600, Apple_56_G = 0, Apple_56_B = 0;


Birds();
ReachingTarget();
mode();

  }




  if (buttonCounter == 6)
  {
buttonCounter = 1;
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
delay(400);

  unsigned long current3LvLMillisMODE_1 = millis();
  unsigned long BirdMillis = millis();
  unsigned long OPMillis = millis();
  unsigned long AppleMillis = millis();


previous3LvLMillisMODE_1 = current3LvLMillisMODE_1;
previousBirdMillis = BirdMillis;
previousAppleMillis = AppleMillis;
previousOPMillis = OPMillis;
Applecounter = 1;
OPcounter = 1;
FLcounter = 1;

    // turn LED on:
    digitalWrite(ledPin, HIGH);
      turnoff();
      mode();
    }
  }
} //END of     c h e c k B u t t o n ( )

   
 
void mode() {


pwm1.setPWM(0, 0, FL_7_G);  
pwm1.setPWM(1, 0, FL_7_B); 
pwm1.setPWM(2, 0, FL_8_B); 
pwm1.setPWM(3, 0, FL_8_G);
pwm1.setPWM(4, 0, FL_9_G); 
pwm1.setPWM(5, 0, FL_9_B); 
pwm1.setPWM(6, 0, FL_4_G); 
pwm1.setPWM(7, 0, FL_4_B);  
pwm1.setPWM(8, 0, FL_1_G); 
pwm1.setPWM(9, 0, 0); 
pwm1.setPWM(10, 0, FL_6_G);
pwm1.setPWM(11, 0, FL_5_B); 
pwm1.setPWM(12, 0, FL_1_B); 
pwm1.setPWM(13, 0, FL_2_B); 
pwm1.setPWM(14, 0, FL_2_G);
pwm1.setPWM(15, 0, FL_3_G); 

pwm2.setPWM(0, 0, FL_3_B);  
pwm2.setPWM(1, 0, AppleLeaf_12_B); // a0ppleleaf12 B
pwm2.setPWM(2, 0, AppleLeaf_12_G); // a0ppleleaf12 G
pwm2.setPWM(3, 0, Blossom_14_B);
pwm2.setPWM(4, 0, Blossom_14_G); 
pwm2.setPWM(5, 0, AppleLeaf_56_G); 
pwm2.setPWM(6, 0, AppleLeaf_56_B); 
pwm2.setPWM(7, 0, Blossom_56_B);  
pwm2.setPWM(8, 0, Blossom_56_G);  // blossom 56 G
pwm2.setPWM(9, 0, AppleLeaf_34_B);    // 
pwm2.setPWM(10, 0, AppleLeaf_34_G);    //
pwm2.setPWM(11, 0, Blossom_23_B);    // blossom 23 B
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
pwm3.setPWM(8, 0, CanopyG); 
pwm3.setPWM(9, 0, CanopyB); 
pwm3.setPWM(10, 0, CanopyR); 
pwm3.setPWM(11, 0, 0); 
pwm3.setPWM(12, 0, 0); 
pwm3.setPWM(13, 0, OP_1_B); 
pwm3.setPWM(14, 0, OP_1_G);
pwm3.setPWM(15, 0, OP_1_R); 

pwm4.setPWM(0, 0, OP_2_R);  
pwm4.setPWM(1, 0, OP_2_G); 
pwm4.setPWM(2, 0, OP_2_B); 
pwm4.setPWM(3, 0, OP_3_R);
pwm4.setPWM(4, 0, OP_3_G); 
pwm4.setPWM(5, 0, OP_3_B); 
pwm4.setPWM(6, 0, OP_4_R); 
pwm4.setPWM(7, 0, OP_4_G);  
pwm4.setPWM(8, 0, Bird_2_B); 
pwm4.setPWM(9, 0, Bird_1_B); 
pwm4.setPWM(10, 0, Bird_4_B); 
pwm4.setPWM(11, 0, Bird_3_B); 
pwm4.setPWM(12, 0, Bird_2_G); 
pwm4.setPWM(13, 0, Bird_1_G); 
pwm4.setPWM(14, 0, OP_4_B);
pwm4.setPWM(15, 0, OP_5_R); 


pwm5.setPWM(0, 0, OP_5_G);  
pwm5.setPWM(1, 0, OP_5_B); 
pwm5.setPWM(2, 0, OP_7_R); 
pwm5.setPWM(3, 0, OP_7_G);
pwm5.setPWM(4, 0, 0); 
pwm5.setPWM(5, 0, 0); 
pwm5.setPWM(6, 0, OP_7_B); 
pwm5.setPWM(7, 0, OP_6_R);  
pwm5.setPWM(8, 0, OP_6_G); 
pwm5.setPWM(9, 0, OP_6_B); 
pwm5.setPWM(10, 0, Bird_4_G); 
pwm5.setPWM(11, 0, Bird_3_G); 
pwm5.setPWM(12, 0, Bird_2_R); 
pwm5.setPWM(13, 0, Bird_1_R); 
pwm5.setPWM(14, 0, Bird_4_R);
pwm5.setPWM(15, 0, Bird_3_R); 

pwm6.setPWM(0, 0, TreeB);  
pwm6.setPWM(1, 0, TreeG); 
pwm6.setPWM(2, 0, TreeR); 
pwm6.setPWM(3, 0, 0);
pwm6.setPWM(4, 0, Blossom_56_R); 
pwm6.setPWM(5, 0, AppleLeaf_56_R); 
pwm6.setPWM(6, 0, Blossom_14_R); 
pwm6.setPWM(7, 0, Blossom_23_R);
pwm6.setPWM(8, 0, AppleLeaf_12_R);  
pwm6.setPWM(9, 0, 0); 
pwm6.setPWM(10, 0, AppleLeaf_34_R); 
pwm6.setPWM(11, 0, Apple_56_R); 
pwm6.setPWM(12, 0, FL_1_R); 
pwm6.setPWM(13, 0, Apple_12_R); 
pwm6.setPWM(14, 0, FL_2_R); 
pwm6.setPWM(15, 0, Apple_34_R); 

pwm7.setPWM(0, 0, Apple_56_G);  
pwm7.setPWM(1, 0, FL_6_R); 
pwm7.setPWM(2, 0, Apple_34_G); 
pwm7.setPWM(3, 0, FL_5_R); 
pwm7.setPWM(4, 0, Apple_12_G); 
pwm7.setPWM(5, 0, FL_4_R); 
pwm7.setPWM(6, 0, Apple_56_B); 
pwm7.setPWM(7, 0, FL_9_R);  
pwm7.setPWM(8, 0, Apple_34_B); 
pwm7.setPWM(9, 0, FL_8_R); 
pwm7.setPWM(10, 0, Apple_12_B); 
pwm7.setPWM(11, 0, FL_7_R); 
pwm7.setPWM(12, 0, 0); 
pwm7.setPWM(13, 0, 0); 
pwm7.setPWM(14, 0, 0);
pwm7.setPWM(15, 0, 0); 
}

 
void turnoff() {

TreeR = 0, TreeG = 0, TreeB = 0;
CanopyR = 0, CanopyG = 0, CanopyB = 0;

Bird_1_R = 0, Bird_1_G = 0, Bird_1_B = 0;
Bird_2_R = 0, Bird_2_G = 0, Bird_2_B = 0;
Bird_3_R = 0, Bird_3_G = 0, Bird_3_B = 0;
Bird_4_R = 0, Bird_4_G = 0, Bird_4_B = 0;

Apple_12_R = 0, Apple_12_G = 0, Apple_12_B = 0;
Apple_34_R = 0, Apple_34_G = 0, Apple_34_B = 0;
Apple_56_R = 0, Apple_56_G = 0, Apple_56_B = 0;

AppleLeaf_12_R = 0, AppleLeaf_12_G = 0, AppleLeaf_12_B = 0;
AppleLeaf_34_R = 0, AppleLeaf_34_G = 0, AppleLeaf_34_B = 0;
AppleLeaf_56_R = 0, AppleLeaf_56_G = 0, AppleLeaf_56_B = 0;

Blossom_14_R = 0, Blossom_14_G = 0, Blossom_14_B = 0;
Blossom_23_R = 0, Blossom_23_G = 0, Blossom_23_B = 0;
Blossom_56_R = 0, Blossom_56_G = 0, Blossom_56_B = 0;

FL_1_R = 0, FL_1_G = 0, FL_1_B = 0;
FL_2_R = 0, FL_2_G = 0, FL_2_B = 0;
FL_3_R = 0, FL_3_G = 0, FL_3_B = 0;
FL_4_R = 0, FL_4_G = 0, FL_4_B = 0;
FL_5_R = 0, FL_5_G = 0, FL_5_B = 0;
FL_6_R = 0, FL_6_G = 0, FL_6_B = 0;
FL_7_R = 0, FL_7_G = 0, FL_7_B = 0;
FL_8_R = 0, FL_8_G = 0, FL_8_B = 0;
FL_9_R = 0, FL_9_G = 0, FL_9_B = 0;

OP_1_R = 0, OP_1_G = 0, OP_1_B = 0;
OP_2_R = 0, OP_2_G = 0, OP_2_B = 0;
OP_3_R = 0, OP_3_G = 0, OP_3_B = 0;
OP_4_R = 0, OP_4_G = 0, OP_4_B = 0;
OP_5_R = 0, OP_5_G = 0, OP_5_B = 0;
OP_6_R = 0, OP_6_G = 0, OP_6_B = 0;
OP_7_R = 0, OP_7_G = 0, OP_7_B = 0;

TargetTreeR = 0, TargetTreeG = 0, TargetTreeB = 0;
TargetCanopyR = 0, TargetCanopyG = 0, TargetCanopyB = 0;

TargetBird_1_R = 0, TargetBird_1_G = 0, TargetBird_1_B = 0;
TargetBird_2_R = 0, TargetBird_2_G = 0, TargetBird_2_B = 0;
TargetBird_3_R = 0, TargetBird_3_G = 0, TargetBird_3_B = 0;
TargetBird_4_R = 0, TargetBird_4_G = 0, TargetBird_4_B = 0;

TargetApple_12_R = 0, TargetApple_12_G = 0, TargetApple_12_B = 0;
TargetApple_34_R = 0, TargetApple_34_G = 0, TargetApple_34_B = 0;
TargetApple_56_R = 0, TargetApple_56_G = 0, TargetApple_56_B = 0;

TargetAppleLeaf_12_R = 0, TargetAppleLeaf_12_G = 0, TargetAppleLeaf_12_B = 0;
TargetAppleLeaf_34_R = 0, TargetAppleLeaf_34_G = 0, TargetAppleLeaf_34_B = 0;
TargetAppleLeaf_56_R = 0, TargetAppleLeaf_56_G = 0, TargetAppleLeaf_56_B = 0;

TargetBlossom_14_R = 0, TargetBlossom_14_G = 0, TargetBlossom_14_B = 0;
TargetBlossom_23_R = 0, TargetBlossom_23_G = 0, TargetBlossom_23_B = 0;
TargetBlossom_56_R = 0, TargetBlossom_56_G = 0, TargetBlossom_56_B = 0;

//Falling Leaves
TargetFL_1_R = 0, TargetFL_1_G = 0, TargetFL_1_B = 0;
TargetFL_2_R = 0, TargetFL_2_G = 0, TargetFL_2_B = 0;
TargetFL_3_R = 0, TargetFL_3_G = 0, TargetFL_3_B = 0;
TargetFL_4_R = 0, TargetFL_4_G = 0, TargetFL_4_B = 0;
TargetFL_5_R = 0, TargetFL_5_G = 0, TargetFL_5_B = 0;
TargetFL_6_R = 0, TargetFL_6_G = 0, TargetFL_6_B = 0;
TargetFL_7_R = 0, TargetFL_7_G = 0, TargetFL_7_B = 0;
TargetFL_8_R = 0, TargetFL_8_G = 0, TargetFL_8_B = 0;
TargetFL_9_R = 0, TargetFL_9_G = 0, TargetFL_9_B = 0;

//Fiber Optics
TargetOP_1_R = 0, TargetOP_1_G = 0, TargetOP_1_B = 0;
TargetOP_2_R = 0, TargetOP_2_G = 0, TargetOP_2_B = 0;
TargetOP_3_R = 0, TargetOP_3_G = 0, TargetOP_3_B = 0;
TargetOP_4_R = 0, TargetOP_4_G = 0, TargetOP_4_B = 0;
TargetOP_5_R = 0, TargetOP_5_G = 0, TargetOP_5_B = 0;
TargetOP_6_R = 0, TargetOP_6_G = 0, TargetOP_6_B = 0;
TargetOP_7_R = 0, TargetOP_7_G = 0, TargetOP_7_B = 0;

}


void ReachingTarget(){




//__________________kokius values išsiunčiam_____________________________
//____________TREE_______________    
if ( TreeR < TargetTreeR ){
  TreeR += 1;
}
   else if ( TreeR > TargetTreeR ){
  TreeR -= 1;    
   }  

if ( TreeB < TargetTreeB ){
  TreeB+= 1;
}
   else if ( TreeB > TargetTreeB ){
  TreeB-= 1;    
   }  

if ( TreeG < TargetTreeG ){
  TreeG+= 1;
}
   else if ( TreeG > TargetTreeG ){
  TreeG-= 1;    
   }  


//____________CANOPY_______________
if ( CanopyR < TargetCanopyR ){
  CanopyR += 3;
}
   else if ( CanopyR > TargetCanopyR ){
  CanopyR -= 3;    
   }  

if ( CanopyB < TargetCanopyB ){
  CanopyB+= 3;
}
   else if ( CanopyB > TargetCanopyB ){
  CanopyB-= 3;    
   }  

if ( CanopyG < TargetCanopyG ){
  CanopyG+= 3;
}
   else if ( CanopyG > TargetCanopyG ){
  CanopyG-= 3;    
   }  
 
  
  //____________BIRDS_______________
if ( Bird_1_R < TargetBird_1_R ){
  Bird_1_R += 2;
}
   else if ( Bird_1_R > TargetBird_1_R ){
  Bird_1_R -= 2;    
   }  

if ( Bird_1_B < TargetBird_1_B ){
  Bird_1_B+= 2;
}
   else if ( Bird_1_B > TargetBird_1_B ){
  Bird_1_B-= 2;    
   }  

if ( Bird_1_G < TargetBird_1_G ){
  Bird_1_G+= 2;
}
   else if ( Bird_1_G > TargetBird_1_G ){
  Bird_1_G-= 2;    
   }  
// ________________
 if ( Bird_2_R < TargetBird_2_R ){
  Bird_2_R += 2;
}
   else if ( Bird_2_R > TargetBird_2_R ){
  Bird_2_R -= 2;    
   }  

if ( Bird_2_B < TargetBird_2_B ){
  Bird_2_B+= 2;
}
   else if ( Bird_2_B > TargetBird_2_B ){
  Bird_2_B-= 2;    
   }  

if ( Bird_2_G < TargetBird_2_G ){
  Bird_2_G+= 2;
}
   else if ( Bird_2_G > TargetBird_2_G ){
  Bird_2_G-= 2;    
   }   
// ________________
 if ( Bird_3_R < TargetBird_3_R ){
  Bird_3_R += 2;
}
   else if ( Bird_3_R > TargetBird_3_R ){
  Bird_3_R -= 2;    
   }  

if ( Bird_3_B < TargetBird_3_B ){
  Bird_3_B+= 2;
}
   else if ( Bird_3_B > TargetBird_3_B ){
  Bird_3_B-= 2;    
   }  

if ( Bird_3_G < TargetBird_3_G ){
  Bird_3_G+= 2;
}
   else if ( Bird_3_G > TargetBird_3_G ){
  Bird_3_G-= 2;    
   }   

// ________________
 if ( Bird_4_R < TargetBird_4_R ){
  Bird_4_R += 2;
}
   else if ( Bird_4_R > TargetBird_4_R ){
  Bird_4_R -= 2;    
   }  

if ( Bird_4_B < TargetBird_4_B ){
  Bird_4_B+= 2;
}
   else if ( Bird_4_B > TargetBird_4_B ){
  Bird_4_B-= 2;    
   }  

if ( Bird_4_G < TargetBird_4_G ){
  Bird_4_G+= 2;
}
   else if ( Bird_4_G > TargetBird_4_G ){
  Bird_4_G-= 2;    
   }   

//____________FALLING LEAVES_______________
if ( FL_1_R < TargetFL_1_R ){
  FL_1_R += 10;
}
   else if ( FL_1_R > TargetFL_1_R ){
  FL_1_R -= 10;    
   }  

if ( FL_1_G < TargetFL_1_G ){
  FL_1_G+= 10;
}
   else if ( FL_1_G > TargetFL_1_G ){
  FL_1_G-= 10;    
   }  

if ( FL_1_B < TargetFL_1_B ){
  FL_1_B+= 10;
}
   else if ( FL_1_B > TargetFL_1_B ){
  FL_1_B-= 10;    
   }  
// _______2_________
if ( FL_2_R < TargetFL_2_R ){
  FL_2_R += 10;
}
   else if ( FL_2_R > TargetFL_2_R ){
  FL_2_R -= 10;    
   }  

if ( FL_2_G < TargetFL_2_G ){
  FL_2_G+= 10;
}
   else if ( FL_2_G > TargetFL_2_G ){
  FL_2_G-= 10;    
   }  

if ( FL_2_B < TargetFL_2_B ){
  FL_2_B+= 10;
}
   else if ( FL_2_B > TargetFL_2_B ){
  FL_2_B-= 10;    
   }  
// _______3_________
if ( FL_3_R < TargetFL_3_R ){
  FL_3_R += 10;
}
   else if ( FL_3_R > TargetFL_3_R ){
  FL_3_R -= 10;    
   }  

if ( FL_3_G < TargetFL_3_G ){
  FL_3_G+= 10;
}
   else if ( FL_3_G > TargetFL_3_G ){
  FL_3_G-= 10;    
   }  

if ( FL_3_B < TargetFL_3_B ){
  FL_3_B+= 10;
}
   else if ( FL_3_B > TargetFL_3_B ){
  FL_3_B-= 10;    
   }  
// _______4_________
if ( FL_4_R < TargetFL_4_R ){
  FL_4_R += 10;
}
   else if ( FL_4_R > TargetFL_4_R ){
  FL_4_R -= 10;    
   }  

if ( FL_4_G < TargetFL_4_G ){
  FL_4_G+= 10;
}
   else if ( FL_4_G > TargetFL_4_G ){
  FL_4_G-= 10;    
   }  

if ( FL_4_B < TargetFL_4_B ){
  FL_4_B+= 10;
}
   else if ( FL_4_B > TargetFL_4_B ){
  FL_4_B-= 10;    
   }  
// _______5_________
if ( FL_5_R < TargetFL_5_R ){
  FL_5_R += 10;
}
   else if ( FL_5_R > TargetFL_5_R ){
  FL_5_R -= 10;    
   }  

if ( FL_5_G < TargetFL_5_G ){
  FL_5_G+= 10;
}
   else if ( FL_5_G > TargetFL_5_G ){
  FL_5_G-= 10;    
   }  

if ( FL_5_B < TargetFL_5_B ){
  FL_5_B+= 10;
}
   else if ( FL_5_B > TargetFL_5_B ){
  FL_5_B-= 10;    
   }  
// _______6_________
if ( FL_6_R < TargetFL_6_R ){
  FL_6_R += 10;
}
   else if ( FL_6_R > TargetFL_6_R ){
  FL_6_R -= 10;    
   }  

if ( FL_6_G < TargetFL_6_G ){
  FL_6_G+= 10;
}
   else if ( FL_6_G > TargetFL_6_G ){
  FL_6_G-= 10;    
   }  

if ( FL_6_B < TargetFL_6_B ){
  FL_6_B+= 10;
}
   else if ( FL_6_B > TargetFL_6_B ){
  FL_6_B-= 10;    
   }  
// _______7_________
if ( FL_7_R < TargetFL_7_R ){
  FL_7_R += 10;
}
   else if ( FL_7_R > TargetFL_7_R ){
  FL_7_R -= 10;    
   }  

if ( FL_7_G < TargetFL_7_G ){
  FL_7_G+= 10;
}
   else if ( FL_7_G > TargetFL_7_G ){
  FL_7_G-= 10;    
   }  

if ( FL_7_B < TargetFL_7_B ){
  FL_7_B+= 10;
}
   else if ( FL_7_B > TargetFL_7_B ){
  FL_7_B-= 10;    
   }  
// _______8_________
if ( FL_8_R < TargetFL_8_R ){
  FL_8_R += 10;
}
   else if ( FL_8_R > TargetFL_8_R ){
  FL_8_R -= 10;    
   }  

if ( FL_8_G < TargetFL_8_G ){
  FL_8_G+= 10;
}
   else if ( FL_8_G > TargetFL_8_G ){
  FL_8_G-= 10;    
   }  

if ( FL_8_B < TargetFL_8_B ){
  FL_8_B+= 10;
}
   else if ( FL_8_B > TargetFL_8_B ){
  FL_8_B-= 10;    
   }  
// _______9_________
if ( FL_9_R < TargetFL_9_R ){
  FL_9_R += 10;
}
   else if ( FL_9_R > TargetFL_9_R ){
  FL_9_R -= 10;    
   }  

if ( FL_9_G < TargetFL_9_G ){
  FL_9_G+= 10;
}
   else if ( FL_9_G > TargetFL_9_G ){
  FL_9_G-= 10;    
   }  

if ( FL_9_B < TargetFL_9_B ){
  FL_9_B+= 10;
}
   else if ( FL_9_B > TargetFL_9_B ){
  FL_9_B-= 10;    
   }  


//____________APPLES_______________
if ( Apple_12_R < TargetApple_12_R ){
  Apple_12_R += 1;
}
   else if ( Apple_12_R > TargetApple_12_R ){
  Apple_12_R -= 1;    
   }  

if ( Apple_12_G < TargetApple_12_G ){
  Apple_12_G+= 1;
}
   else if ( Apple_12_G > TargetApple_12_G ){
  Apple_12_G-= 1;    
   }  

if ( Apple_12_B < TargetApple_12_B ){
  Apple_12_B+= 1;
}
   else if ( Apple_12_B > TargetApple_12_B ){
  Apple_12_B-= 1;    
   }  
 // _______2_________

if ( Apple_34_R < TargetApple_34_R ){
  Apple_34_R += 1;
}
   else if ( Apple_34_R > TargetApple_34_R ){
  Apple_34_R -= 1;    
   }  

if ( Apple_34_G < TargetApple_34_G ){
  Apple_34_G+= 1;
}
   else if ( Apple_34_G > TargetApple_34_G ){
  Apple_34_G-= 1;    
   }  

if ( Apple_34_B < TargetApple_34_B ){
  Apple_34_B+= 1;
}
   else if ( Apple_34_B > TargetApple_34_B ){
  Apple_34_B-= 1;    
   }  

 // _______3_________

if ( Apple_56_R < TargetApple_56_R ){
  Apple_56_R += 1;
}
   else if ( Apple_56_R > TargetApple_56_R ){
  Apple_56_R -= 1;    
   }  

if ( Apple_56_G < TargetApple_56_G ){
  Apple_56_G+= 1;
}
   else if ( Apple_56_G > TargetApple_56_G ){
  Apple_56_G-= 1;    
   }  

if ( Apple_56_B < TargetApple_56_B ){
  Apple_56_B+= 1;
}
   else if ( Apple_56_B > TargetApple_56_B ){
  Apple_56_B-= 1;    
   }  
   
//____________APPLE_LEAVES_______________

if ( AppleLeaf_12_R < TargetAppleLeaf_12_R ){
  AppleLeaf_12_R += 3;
}
   else if ( AppleLeaf_12_R > TargetAppleLeaf_12_R ){
  AppleLeaf_12_R -= 3;    
   }  

if ( AppleLeaf_12_G < TargetAppleLeaf_12_G ){
  AppleLeaf_12_G+= 3;
}
   else if ( AppleLeaf_12_G > TargetAppleLeaf_12_G ){
  AppleLeaf_12_G-= 3;    
   }  

if ( AppleLeaf_12_B < TargetAppleLeaf_12_B ){
  AppleLeaf_12_B+= 3;
}
   else if ( AppleLeaf_12_B > TargetAppleLeaf_12_B ){
  AppleLeaf_12_B-= 3;    
   }  
 
 // _______2_________

if ( AppleLeaf_34_R < TargetAppleLeaf_34_R ){
  AppleLeaf_34_R += 3;
}
   else if ( AppleLeaf_34_R > TargetAppleLeaf_34_R ){
  AppleLeaf_34_R -= 3;    
}  

if ( AppleLeaf_34_G < TargetAppleLeaf_34_G ){
  AppleLeaf_34_G+= 3;
}
   else if ( AppleLeaf_34_G > TargetAppleLeaf_34_G ){
  AppleLeaf_34_G-= 3;    
}  

if ( AppleLeaf_34_B < TargetAppleLeaf_34_B ){
  AppleLeaf_34_B+= 3;
}
   else if ( AppleLeaf_34_B > TargetAppleLeaf_34_B ){
  AppleLeaf_34_B-= 3;    
}  

 // _______3_________

if ( AppleLeaf_56_R < TargetAppleLeaf_56_R ){
  AppleLeaf_56_R += 3;
}
   else if ( AppleLeaf_56_R > TargetAppleLeaf_56_R ){
  AppleLeaf_56_R -= 3;    
}  

if ( AppleLeaf_56_G < TargetAppleLeaf_56_G ){
  AppleLeaf_56_G+= 3;
}
   else if ( AppleLeaf_56_G > TargetAppleLeaf_56_G ){
  AppleLeaf_56_G-= 3;    
}  

if ( AppleLeaf_56_B < TargetAppleLeaf_56_B ){
  AppleLeaf_56_B+= 3;
}
   else if ( AppleLeaf_56_B > TargetAppleLeaf_56_B ){
  AppleLeaf_56_B-= 3;    
}  


//____________Blossoms_______________

if ( Blossom_14_R < TargetBlossom_14_R ){
  Blossom_14_R += 15;
}
   else if ( Blossom_14_R > TargetBlossom_14_R ){
  Blossom_14_R -= 20;    
   }  

if ( Blossom_14_G < TargetBlossom_14_G ){
  Blossom_14_G+= 10;
}
   else if ( Blossom_14_G > TargetBlossom_14_G ){
  Blossom_14_G-= 10;    
   }  

if ( Blossom_14_B < TargetBlossom_14_B ){
  Blossom_14_B+= 10;
}
   else if ( Blossom_14_B > TargetBlossom_14_B ){
  Blossom_14_B-= 10;    
   }  
 
 // _______2_________

if ( Blossom_23_R < TargetBlossom_23_R ){
  Blossom_23_R += 15;
}
   else if ( Blossom_23_R > TargetBlossom_23_R ){
  Blossom_23_R -= 20;    
   }  

if ( Blossom_23_G < TargetBlossom_23_G ){
  Blossom_23_G+= 10;
}
   else if ( Blossom_23_G > TargetBlossom_23_G ){
  Blossom_23_G-= 10;    
   }  

if ( Blossom_23_B < TargetBlossom_23_B ){
  Blossom_23_B+= 10;
}
   else if ( Blossom_23_B > TargetBlossom_23_B ){
  Blossom_23_B-= 10;    
   }  
 
 // _______3_________

if ( Blossom_56_R < TargetBlossom_56_R ){
  Blossom_56_R += 15;
}
   else if ( Blossom_56_R > TargetBlossom_56_R ){
  Blossom_56_R -= 20;    
   }  
if ( Blossom_56_G < TargetBlossom_56_G ){
  Blossom_56_G += 10;
}
   else if ( Blossom_56_G > TargetBlossom_56_G ){
  Blossom_56_G-= 10;    
   }  
if ( Blossom_56_B < TargetBlossom_56_B ){
  Blossom_56_B+= 10;
}
   else if ( Blossom_56_B > TargetBlossom_56_B ){
  Blossom_56_B-= 10;    
   }
   }  

void FallingLeaves(){
  //__________________STEP - FALLING LEAVES_____________________________

unsigned long FLMillis = millis();
      
if ( FLMillis - previousFLMillis >= 700 && FLcounter == 1){
      previousFLMillis = FLMillis;
      FLcounter = 2;

randomFL1 = random(1,4);

if ( randomFL1 == 1 ){
TargetFL_1_R = 800, TargetFL_1_G = 800, TargetFL_1_B = 0;
TargetFL_2_R = 0, TargetFL_2_G = 0, TargetFL_2_B = 0;
TargetFL_3_R = 0, TargetFL_3_G = 0, TargetFL_3_B = 0;
TargetFL_4_R = 0, TargetFL_4_G = 0, TargetFL_4_B = 0;
TargetFL_5_R = 0, TargetFL_5_G = 0, TargetFL_5_B = 0;
TargetFL_6_R = 0, TargetFL_6_G = 0, TargetFL_6_B = 0;
TargetFL_7_R = 0, TargetFL_7_G = 0, TargetFL_7_B = 0;
TargetFL_8_R = 0, TargetFL_8_G = 0, TargetFL_8_B = 0;
TargetFL_9_R = 0, TargetFL_9_G = 0, TargetFL_9_B = 0;
  
  randomFL2 = random(4,6);
}
if ( randomFL1 == 2 ){
TargetFL_1_R = 0, TargetFL_1_G = 0, TargetFL_1_B = 0;
TargetFL_2_R = 800, TargetFL_2_G = 800, TargetFL_2_B = 0;
TargetFL_3_R = 0, TargetFL_3_G = 0, TargetFL_3_B = 0;
TargetFL_4_R = 0, TargetFL_4_G = 0, TargetFL_4_B = 0;
TargetFL_5_R = 0, TargetFL_5_G = 0, TargetFL_5_B = 0;
TargetFL_6_R = 0, TargetFL_6_G = 0, TargetFL_6_B = 0;
TargetFL_7_R = 0, TargetFL_7_G = 0, TargetFL_7_B = 0;
TargetFL_8_R = 0, TargetFL_8_G = 0, TargetFL_8_B = 0;
TargetFL_9_R = 0, TargetFL_9_G = 0, TargetFL_9_B = 0;
  
  randomFL2 = random(4,7);
}
if ( randomFL1 == 3 ){
TargetFL_1_R = 0, TargetFL_1_G = 0, TargetFL_1_B = 0;
TargetFL_2_R = 0, TargetFL_2_G = 0, TargetFL_2_B = 0;
TargetFL_3_R = 800, TargetFL_3_G = 800, TargetFL_3_B = 0;
TargetFL_4_R = 0, TargetFL_4_G = 0, TargetFL_4_B = 0;
TargetFL_5_R = 0, TargetFL_5_G = 0, TargetFL_5_B = 0;
TargetFL_6_R = 0, TargetFL_6_G = 0, TargetFL_6_B = 0;
TargetFL_7_R = 0, TargetFL_7_G = 0, TargetFL_7_B = 0;
TargetFL_8_R = 0, TargetFL_8_G = 0, TargetFL_8_B = 0;
TargetFL_9_R = 0, TargetFL_9_G = 0, TargetFL_9_B = 0;
  
  randomFL2 = random(5,7);
}
}

//___STAGE 2____
if ( FLMillis - previousFLMillis >= 1300 && FLcounter == 2){
      previousFLMillis = FLMillis;
      FLcounter = 3;

      
if ( randomFL2 == 4 ){
TargetFL_1_R = 0, TargetFL_1_G = 0, TargetFL_1_B = 0;
TargetFL_2_R = 0, TargetFL_2_G = 0, TargetFL_2_B = 0;
TargetFL_3_R = 0, TargetFL_3_G = 0, TargetFL_3_B = 0;
TargetFL_4_R = 800, TargetFL_4_G = 800, TargetFL_4_B = 0;
TargetFL_5_R = 0, TargetFL_5_G = 0, TargetFL_5_B = 0;
TargetFL_6_R = 0, TargetFL_6_G = 0, TargetFL_6_B = 0;
TargetFL_7_R = 0, TargetFL_7_G = 0, TargetFL_7_B = 0;
TargetFL_8_R = 0, TargetFL_8_G = 0, TargetFL_8_B = 0;
TargetFL_9_R = 0, TargetFL_9_G = 0, TargetFL_9_B = 0;
  randomFL3 = random(7,9);
}
if ( randomFL2 == 5 ){
TargetFL_1_R = 0, TargetFL_1_G = 0, TargetFL_1_B = 0;
TargetFL_2_R = 0, TargetFL_2_G = 0, TargetFL_2_B = 0;
TargetFL_3_R = 0, TargetFL_3_G = 0, TargetFL_3_B = 0;
TargetFL_4_R = 0, TargetFL_4_G = 0, TargetFL_4_B = 0;
TargetFL_5_R = 800, TargetFL_5_G = 800, TargetFL_5_B = 0;
TargetFL_6_R = 0, TargetFL_6_G = 0, TargetFL_6_B = 0;
TargetFL_7_R = 0, TargetFL_7_G = 0, TargetFL_7_B = 0;
TargetFL_8_R = 0, TargetFL_8_G = 0, TargetFL_8_B = 0;
TargetFL_9_R = 0, TargetFL_9_G = 0, TargetFL_9_B = 0;
  randomFL3 = random(7,10);
}
if ( randomFL2 == 6 ){
TargetFL_1_R = 0, TargetFL_1_G = 0, TargetFL_1_B = 0;
TargetFL_2_R = 0, TargetFL_2_G = 0, TargetFL_2_B = 0;
TargetFL_3_R = 0, TargetFL_3_G = 0, TargetFL_3_B = 0;
TargetFL_4_R = 0, TargetFL_4_G = 0, TargetFL_4_B = 0;
TargetFL_5_R = 0, TargetFL_5_G = 0, TargetFL_5_B = 0;
TargetFL_6_R = 800, TargetFL_6_G = 800, TargetFL_6_B = 0;
TargetFL_7_R = 0, TargetFL_7_G = 0, TargetFL_7_B = 0;
TargetFL_8_R = 0, TargetFL_8_G = 0, TargetFL_8_B = 0;
TargetFL_9_R = 0, TargetFL_9_G = 0, TargetFL_9_B = 0;
  randomFL3 = random(8,10);
}
}
//___STAGE 3____
if ( FLMillis - previousFLMillis >= 1300 && FLcounter == 3){
      previousFLMillis = FLMillis;
      FLcounter = 4;

if ( randomFL3 == 7 ){
TargetFL_1_R = 0, TargetFL_1_G = 0, TargetFL_1_B = 0;
TargetFL_2_R = 0, TargetFL_2_G = 0, TargetFL_2_B = 0;
TargetFL_3_R = 0, TargetFL_3_G = 0, TargetFL_3_B = 0;
TargetFL_4_R = 0, TargetFL_4_G = 0, TargetFL_4_B = 0;
TargetFL_5_R = 0, TargetFL_5_G = 0, TargetFL_5_B = 0;
TargetFL_6_R = 0, TargetFL_6_G = 0, TargetFL_6_B = 0;
TargetFL_7_R = 800, TargetFL_7_G = 800, TargetFL_7_B = 0;
TargetFL_8_R = 0, TargetFL_8_G = 0, TargetFL_8_B = 0;
TargetFL_9_R = 0, TargetFL_9_G = 0, TargetFL_9_B = 0;


}
if ( randomFL3 == 8 ){
TargetFL_1_R = 0, TargetFL_1_G = 0, TargetFL_1_B = 0;
TargetFL_2_R = 0, TargetFL_2_G = 0, TargetFL_2_B = 0;
TargetFL_3_R = 0, TargetFL_3_G = 0, TargetFL_3_B = 0;
TargetFL_4_R = 0, TargetFL_4_G = 0, TargetFL_4_B = 0;
TargetFL_5_R = 0, TargetFL_5_G = 0, TargetFL_5_B = 0;
TargetFL_6_R = 0, TargetFL_6_G = 0, TargetFL_6_B = 0;
TargetFL_7_R = 0, TargetFL_7_G = 0, TargetFL_7_B = 0;
TargetFL_8_R = 800, TargetFL_8_G = 800, TargetFL_8_B = 0;
TargetFL_9_R = 0, TargetFL_9_G = 0, TargetFL_9_B = 0;
}
if ( randomFL3 == 9 ){
  
TargetFL_1_R = 0, TargetFL_1_G = 0, TargetFL_1_B = 0;
TargetFL_2_R = 0, TargetFL_2_G = 0, TargetFL_2_B = 0;
TargetFL_3_R = 0, TargetFL_3_G = 0, TargetFL_3_B = 0;
TargetFL_4_R = 0, TargetFL_4_G = 0, TargetFL_4_B = 0;
TargetFL_5_R = 0, TargetFL_5_G = 0, TargetFL_5_B = 0;
TargetFL_6_R = 0, TargetFL_6_G = 0, TargetFL_6_B = 0;
TargetFL_7_R = 0, TargetFL_7_G = 0, TargetFL_7_B = 0;
TargetFL_8_R = 0, TargetFL_8_G = 0, TargetFL_8_B = 0;
TargetFL_9_R = 800, TargetFL_9_G = 800, TargetFL_9_B = 0;
}
}
//___STAGE 4____
if ( FLMillis - previousFLMillis >= 1300 && FLcounter == 4){
      previousFLMillis = FLMillis;
      FLcounter = 1;

TargetFL_1_R = 0, TargetFL_1_G = 0, TargetFL_1_B = 0;
TargetFL_2_R = 0, TargetFL_2_G = 0, TargetFL_2_B = 0;
TargetFL_3_R = 0, TargetFL_3_G = 0, TargetFL_3_B = 0;
TargetFL_4_R = 0, TargetFL_4_G = 0, TargetFL_4_B = 0;
TargetFL_5_R = 0, TargetFL_5_G = 0, TargetFL_5_B = 0;
TargetFL_6_R = 0, TargetFL_6_G = 0, TargetFL_6_B = 0;
TargetFL_7_R = 0, TargetFL_7_G = 0, TargetFL_7_B = 0;
TargetFL_8_R = 0, TargetFL_8_G = 0, TargetFL_8_B = 0;
TargetFL_9_R = 0, TargetFL_9_G = 0, TargetFL_9_B = 0;
}

}

void OpticFibers(){
  
  unsigned long OPMillis = millis();

 if ( OPMillis - previousOPMillis >= 400 && OPcounter == 1){
      previousOPMillis = OPMillis;
      OPcounter = 2;
  OP_1_R = AVAILABLE_COLORS_OP[1][0];
  OP_1_G = AVAILABLE_COLORS_OP[1][1];
  OP_1_B = AVAILABLE_COLORS_OP[1][2]; 
 }
 if ( OPMillis - previousOPMillis >= 400 && OPcounter == 2){
      previousOPMillis = OPMillis;
      OPcounter = 3;
  OP_2_R = AVAILABLE_COLORS_OP[6][0];
  OP_2_G = AVAILABLE_COLORS_OP[6][1];
  OP_2_B = AVAILABLE_COLORS_OP[6][2]; 
 }
 if ( OPMillis - previousOPMillis >= 400 && OPcounter == 3){
      previousOPMillis = OPMillis;
      OPcounter = 4;
  OP_3_R = AVAILABLE_COLORS_OP[8][0];
  OP_3_G = AVAILABLE_COLORS_OP[8][1];
  OP_3_B = AVAILABLE_COLORS_OP[8][2]; 
 }
 if ( OPMillis - previousOPMillis >= 400 && OPcounter == 4){
      previousOPMillis = OPMillis;
      OPcounter = 5;
  OP_4_R = AVAILABLE_COLORS_OP[3][0];
  OP_4_G = AVAILABLE_COLORS_OP[3][1];
  OP_4_B = AVAILABLE_COLORS_OP[3][2]; 
 }
 if ( OPMillis - previousOPMillis >= 400 && OPcounter == 5){
      previousOPMillis = OPMillis;
      OPcounter = 6;
  OP_5_R = AVAILABLE_COLORS_OP[10][0];
  OP_5_G = AVAILABLE_COLORS_OP[10][1];
  OP_5_B = AVAILABLE_COLORS_OP[10][2]; 
 }
 if ( OPMillis - previousOPMillis >= 400 && OPcounter == 6){
      previousOPMillis = OPMillis;
      OPcounter = 7;
  OP_6_R = AVAILABLE_COLORS_OP[14][0];
  OP_6_G = AVAILABLE_COLORS_OP[14][1];
  OP_6_B = AVAILABLE_COLORS_OP[14][2]; 
 }
 if ( OPMillis - previousOPMillis >= 400 && OPcounter == 7){
      previousOPMillis = OPMillis;
      OPcounter = 8;
  OP_7_R = AVAILABLE_COLORS_OP[12][0];
  OP_7_G = AVAILABLE_COLORS_OP[12][1];
  OP_7_B = AVAILABLE_COLORS_OP[12][2]; 
 }


 if ( OPMillis - previousOPMillis >= 600 && OPcounter >= 8 && OPcounter <= 23 ){
     OPcounter++;
      previousOPMillis = OPMillis; 
   randomNumber = random(14);
  OP_1_R = AVAILABLE_COLORS_OP[randomNumber][0];
  OP_1_G = AVAILABLE_COLORS_OP[randomNumber][1];
  OP_1_B = AVAILABLE_COLORS_OP[randomNumber][2]; 
   randomNumber = random(14);
  OP_2_R = AVAILABLE_COLORS_OP[randomNumber][0];
  OP_2_G = AVAILABLE_COLORS_OP[randomNumber][1];
  OP_2_B = AVAILABLE_COLORS_OP[randomNumber][2]; 
   randomNumber = random(14);
  OP_3_R = AVAILABLE_COLORS_OP[randomNumber][0];
  OP_3_G = AVAILABLE_COLORS_OP[randomNumber][1];
  OP_3_B = AVAILABLE_COLORS_OP[randomNumber][2]; 
   randomNumber = random(14);
  OP_4_R = AVAILABLE_COLORS_OP[randomNumber][0];
  OP_4_G = AVAILABLE_COLORS_OP[randomNumber][1];
  OP_4_B = AVAILABLE_COLORS_OP[randomNumber][2]; 
   randomNumber = random(14);
  OP_5_R = AVAILABLE_COLORS_OP[randomNumber][0];
  OP_5_G = AVAILABLE_COLORS_OP[randomNumber][1];
  OP_5_B = AVAILABLE_COLORS_OP[randomNumber][2]; 
   randomNumber = random(14);
  OP_6_R = AVAILABLE_COLORS_OP[randomNumber][0];
  OP_6_G = AVAILABLE_COLORS_OP[randomNumber][1];
  OP_6_B = AVAILABLE_COLORS_OP[randomNumber][2]; 
   randomNumber = random(14);
  OP_7_R = AVAILABLE_COLORS_OP[randomNumber][0];
  OP_7_G = AVAILABLE_COLORS_OP[randomNumber][1];
  OP_7_B = AVAILABLE_COLORS_OP[randomNumber][2]; 
  

   }

   
 if ( OPMillis - previousOPMillis >= 300 && OPcounter == 24){
      previousOPMillis = OPMillis;
      OPcounter = 25;
  OP_1_R = 0;
  OP_1_G = 0;
  OP_1_B = 0; 
 }
 if ( OPMillis - previousOPMillis >= 300 && OPcounter == 25){
      previousOPMillis = OPMillis;
      OPcounter = 26;
  OP_2_R = 0;
  OP_2_G = 0;
  OP_2_B = 0;
 }
 if ( OPMillis - previousOPMillis >= 300 && OPcounter == 26){
      previousOPMillis = OPMillis;
      OPcounter = 27;
  OP_3_R = 0;
  OP_3_G = 0;
  OP_3_B = 0; 
 }
 if ( OPMillis - previousOPMillis >= 300 && OPcounter == 27){
      previousOPMillis = OPMillis;
      OPcounter = 28;
  OP_4_R = 0;
  OP_4_G = 0;
  OP_4_B = 0; 
 }
 if ( OPMillis - previousOPMillis >= 300 && OPcounter == 28){
      previousOPMillis = OPMillis;
      OPcounter = 29;
  OP_5_R = 0;
  OP_5_G = 0;
  OP_5_B = 0;
 }
 if ( OPMillis - previousOPMillis >= 300 && OPcounter == 29){
      previousOPMillis = OPMillis;
      OPcounter = 30;
  OP_6_R = 0;
  OP_6_G = 0;
  OP_6_B = 0; 
 }
 if ( OPMillis - previousOPMillis >= 300 && OPcounter == 30){
      previousOPMillis = OPMillis;
  OP_7_R = 0;
  OP_7_G = 0;
  OP_7_B = 0; 
 } 
}

void OpticFibers_2(){
    unsigned long OPMillis = millis();
 if ( OPMillis - previousOPMillis >= 600 ){

      previousOPMillis = OPMillis; 
   randomNumber = random(14);
  OP_1_R = AVAILABLE_COLORS_OP[randomNumber][0];
  OP_1_G = AVAILABLE_COLORS_OP[randomNumber][1];
  OP_1_B = AVAILABLE_COLORS_OP[randomNumber][2]; 
   randomNumber = random(14);
  OP_2_R = AVAILABLE_COLORS_OP[randomNumber][0];
  OP_2_G = AVAILABLE_COLORS_OP[randomNumber][1];
  OP_2_B = AVAILABLE_COLORS_OP[randomNumber][2]; 
   randomNumber = random(14);
  OP_3_R = AVAILABLE_COLORS_OP[randomNumber][0];
  OP_3_G = AVAILABLE_COLORS_OP[randomNumber][1];
  OP_3_B = AVAILABLE_COLORS_OP[randomNumber][2]; 
   randomNumber = random(14);
  OP_4_R = AVAILABLE_COLORS_OP[randomNumber][0];
  OP_4_G = AVAILABLE_COLORS_OP[randomNumber][1];
  OP_4_B = AVAILABLE_COLORS_OP[randomNumber][2]; 
   randomNumber = random(14);
  OP_5_R = AVAILABLE_COLORS_OP[randomNumber][0];
  OP_5_G = AVAILABLE_COLORS_OP[randomNumber][1];
  OP_5_B = AVAILABLE_COLORS_OP[randomNumber][2]; 
   randomNumber = random(14);
  OP_6_R = AVAILABLE_COLORS_OP[randomNumber][0];
  OP_6_G = AVAILABLE_COLORS_OP[randomNumber][1];
  OP_6_B = AVAILABLE_COLORS_OP[randomNumber][2]; 
   randomNumber = random(14);
  OP_7_R = AVAILABLE_COLORS_OP[randomNumber][0];
  OP_7_G = AVAILABLE_COLORS_OP[randomNumber][1];
  OP_7_B = AVAILABLE_COLORS_OP[randomNumber][2]; 
  
 }
   }

void Birds(){

  //__________________BIRD_RANDOM_COLOR_____________________________
    unsigned long BirdMillis = millis();
    
 if ( BirdMillis - previousBirdMillis >= 3000){
      previousBirdMillis = BirdMillis;
    
   randomNumber = random(9);
  TargetBird_1_R = AVAILABLE_COLORS[randomNumber][0];
  TargetBird_1_G = AVAILABLE_COLORS[randomNumber][1];
  TargetBird_1_B = AVAILABLE_COLORS[randomNumber][2]; 
   randomNumber = random(9);
  TargetBird_2_R = AVAILABLE_COLORS[randomNumber][0];
  TargetBird_2_G = AVAILABLE_COLORS[randomNumber][1];
  TargetBird_2_B = AVAILABLE_COLORS[randomNumber][2]; 
   randomNumber = random(9);
  TargetBird_3_R = AVAILABLE_COLORS[randomNumber][0];
  TargetBird_3_G = AVAILABLE_COLORS[randomNumber][1];
  TargetBird_3_B = AVAILABLE_COLORS[randomNumber][2]; 
   randomNumber = random(9);
  TargetBird_4_R = AVAILABLE_COLORS[randomNumber][0];
  TargetBird_4_G = AVAILABLE_COLORS[randomNumber][1];
  TargetBird_4_B = AVAILABLE_COLORS[randomNumber][2]; 

   }
}
