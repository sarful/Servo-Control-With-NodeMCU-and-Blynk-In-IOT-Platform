/***************************************************************************************************************
 *  Servo Control using NodeMCU ESP-12 Develop Kit V1.0 
 *  Including Blynk Control
 *  Servo connected to NodeMCU pin D2  
 *  Developed by mechatronicslabrpi.blogspot.com 
 ********************************************************************************************************************************/
#define SW_VERSION "ServoCtrlBlynk_V.1" 

/*NodeMCU */
#include <ESP8266WiFi.h>
char ssid [] = "rowsoni";
char pass [] = "007892057";

/* Blynk */
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
char auth [] = "3832c3be543540ae86235fd87df2bf3c"; // Servo Control Project // Servo Control Project



/* Servo */
#define servo1Pin D2
#include <Servo.h>
Servo servo1;

/* Initial pot reading and servo position set the position to neutral */
//#define potPin A0
int potReading = 1023/2;
int servo1Angle = 90;

/* Reads slider in the Blynk app and writes the value to "potReading" variable */
BLYNK_WRITE(V0) 
{
  potReading = param.asInt();
}

/* Display servo position on Blynk app */
BLYNK_READ(V1) 
{
  Blynk.virtualWrite(V1, servo1Angle);
}

void setup () 
{
  Serial.begin(115200); 
  servo1.attach(servo1Pin);
  Blynk.begin(auth, ssid, pass);
}

void loop() 
{
  Blynk.run();
  //PotReading = analogRead(potPin);               // Read Analog data from potenciometer not used here
  servo1Angle = map(potReading, 0, 1023, 0, 180);  // Map the pot reading to an angle from 0 to 180 
  servo1.write(servo1Angle);                       // Move the servo to a position
  delay (200);
}


