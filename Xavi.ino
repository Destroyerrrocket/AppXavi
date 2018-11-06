#include <SoftwareSerial.h>
#include <Servo.h>

Servo TDR;
char rxChar;
int ang = 90;

SoftwareSerial blue(2, 3);

char NOMBRE[21] = "HC-06 Dinastia_Tec";
char BPS = "4";
char PASS[5] = "1234";

void setup()
{
  blue.begin(9600);
  
  blue.print("AT");  
  delay(1000);
  
  blue.print("AT+NAME"); 
  blue.print(NOMBRE);
  delay(1000);                 
  
  blue.print("AT+BAUD");  
  blue.print(BPS); 
  delay(1000);
  
  blue.print("AT+PIN");   
  blue.print(PASS); 
  delay(1000);    
  TDR.attach(3,600,2400);
  Serial.begin(9600);
}
 
void loop()
{
  if(Serial.available() > 0)
  {
    rxChar = Serial.read();
  }
  
  if (rxChar == "t")
  {
    TDR.write(85);
    delay(3000);
    TDR.write(90);
    delay (1000);
  }
}
