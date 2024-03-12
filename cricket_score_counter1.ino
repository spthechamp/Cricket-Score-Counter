#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32,16,2);

int wdPin=13, nbPin=12, wPin=11, r1Pin=10, r2Pin=9, r3Pin=8, r4Pin=7, r5Pin=6, r6Pin=5, pbPin=4, ledPin=3;

int tempRun=0, runValue=0, tempBall=1, tempWicket=0, nbExtra=0, wdExtra=0;
int finalScore=0, finalBall=0, finalWicket=0;
int over1=0;

String runString=" 0 ", nbString="", wdString="", wString="", comString="";

void setup()
{
pinMode(wdPin, INPUT);
pinMode(nbPin, INPUT);
pinMode(wPin, INPUT);
pinMode(r1Pin, INPUT);
pinMode(r2Pin, INPUT);
pinMode(r3Pin, INPUT);
pinMode(r4Pin, INPUT);
pinMode(r5Pin, INPUT);
pinMode(r6Pin, INPUT);
pinMode(pbPin, INPUT);
pinMode(ledPin, OUTPUT);
  
lcd.begin(16,2);
lcd.init();
lcd.backlight();
  
lcd.clear();
lcd.setCursor(0,0);
lcd.print("   Cricket");
lcd.setCursor(0,1);
lcd.print("Score Counter");
delay(2000);
printScore(0,0,0,0);
}

void loop()
{
int wdStatus=digitalRead(wdPin);
int nbStatus=digitalRead(nbPin);
int wStatus=digitalRead(wPin);
int r1Status=digitalRead(r1Pin);
int r2Status=digitalRead(r2Pin);
int r3Status=digitalRead(r3Pin);
int r4Status=digitalRead(r4Pin);
int r5Status=digitalRead(r5Pin);
int r6Status=digitalRead(r6Pin);
int pbStatus=digitalRead(pbPin);
  
if (r1Status==HIGH)
{
  runValue=1;
  runString=" 1 ";
  ledBlink();
}
if (r2Status==HIGH)
{
  runValue=2;
  runString=" 2 ";
  ledBlink();
}
if (r3Status==HIGH)
{
  runValue=3;
  runString=" 3 ";
  ledBlink();
}
if (r4Status==HIGH)
{
  runValue=4;
  runString=" 4 ";
  ledBlink();
}
if (r5Status==HIGH)
{
  runValue=5;
  runString=" 5 ";
  ledBlink();
}
if (r6Status==HIGH)
{
  runValue=6;
  runString=" 6 ";
  ledBlink();
}

  
if (nbStatus==HIGH)
{
nbExtra=1;
tempBall=0;
nbString=" nb1 ";
ledBlink();
}

if (wdStatus==HIGH)
{
wdExtra=1;
tempBall=0;
wdString=" wd1 ";
ledBlink();
}
  
if (wStatus==HIGH)
{
tempWicket=1;
wString=" W ";
ledBlink();
}

if (pbStatus==HIGH)
{
finalScore=finalScore+runValue+nbExtra+wdExtra;
finalBall=finalBall+tempBall;
finalWicket=finalWicket+tempWicket;
  
  over1=finalBall/6;
  double temp=finalBall%6;
  double over2=temp/10;
  double finalOver=over1+over2;
  
  double DBLfinalScore=finalScore, DBLfinalBall=finalBall;
  double crr=(DBLfinalScore/DBLfinalBall)*6;
 
  comString=runString+nbString+wdString+wString;
  ledBlink();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CRNT BALL SCORE:");
  lcd.setCursor(0,1);
  lcd.print(comString);  
  delay(3000);
  
printScore(finalScore,finalWicket,finalOver,crr);
 
tempBall=1;
tempRun=0;
tempWicket=0;
nbExtra=0;
wdExtra=0;
runValue=0;
  
runString=" 0 ";
nbString="";
wdString="";
wString="";
}
}

void printScore(int runs, int wicket, double over, double CRR)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("RUN: ");
lcd.print(runs);
lcd.print(" / ");
lcd.print(wicket);
lcd.print(" WKT");
lcd.setCursor(0,1);
lcd.print("OVR:");
lcd.print(over,1);
lcd.print(" CRR:");
lcd.print(CRR);
delay(500);
}

void ledBlink()
{
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
}