#include <LiquidCrystal.h>
#include <NewPing.h>

#define TRIGGER_PIN  2  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     4  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

LiquidCrystal lcd(13, 12, 8, 7, 6, 5);
int LED10 = 3;
int LED11 = 9;
int LED12 = 10;
int LED13 = 11;
int st;

//DEKLARACIJA TIPKE***************************************************
int buttonPin = 1;
int buttonState = 0; 

void setup() {
  pinMode(LED10, OUTPUT);
  pinMode(LED11, OUTPUT);
  pinMode(LED12, OUTPUT);
  pinMode(LED13, OUTPUT);
  pinMode(buttonPin, INPUT);
  lcd.begin(16, 2);
  lcd.print("> POLETNA SOLA <");
}
int meritev()
{
  int vsota=0;
  for(int i=0; i<1; i++)
  {
    //unsigned int uS = sonar.ping();
    unsigned int uS = sonar.ping_median(5);
    //unsigned int uS = sonar.convert_cm(100);
    vsota+=uS / US_ROUNDTRIP_CM;
    delay(30);
  }
  return vsota/1;
}
void loop() {
  if((millis()/300)%4==0)
    digitalWrite(LED13, HIGH);
  else
    digitalWrite(LED13, LOW);
  if((millis()/300+1)%4==0)
    digitalWrite(LED12, HIGH);
  else
    digitalWrite(LED12, LOW);
  if((millis()/300+2)%4==0)
    digitalWrite(LED11, HIGH);
  else
    digitalWrite(LED11, LOW);
  if((millis()/300+3)%4==0)
    digitalWrite(LED10, HIGH);
  else
    digitalWrite(LED10, LOW);
  lcd.setCursor(9, 1);
  lcd.print(meritev());
  lcd.print("cm ");
  
  lcd.setCursor(0, 1);
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {       
    lcd.print("OFF");  
  } 
  else {
    lcd.print("ON ");  
  }
}
