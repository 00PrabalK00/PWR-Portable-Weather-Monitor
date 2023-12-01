#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>
#include <Adafruit_BMP085.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>

#define ALTITUDE 6.7
ThreeWire myWire(4, 9, 6); // IO, SCLK, RST
RtcDS1302<ThreeWire> Rtc(myWire);
Adafruit_BMP085 bmp;

#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.begin();
  dht.begin();
  bmp.begin();
  pinMode(A0, INPUT);    //raindrop
  pinMode(8, OUTPUT);    //buzzer
  pinMode(10, OUTPUT);   //red
  pinMode(11, OUTPUT);   //green
  pinMode(12, OUTPUT);   //blue
  sensors.begin();
  Serial.begin(9600);

  Rtc.Begin();
  //RtcDateTime rtcDateTime(2023, 6, 9, 7, 19, 10); //year day month //hours min sec
  //Rtc.SetDateTime(rtcDateTime);
}

void loop()
{
  while (true)
  {
    digitalWrite(10, HIGH);  // Set red LED pin HIGH
    digitalWrite(11, LOW);   // Set green LED pin LOW
    digitalWrite(12, HIGH);  // Set blue LED pin HIGH

    // Check if it's raining
    if (isRaining())
    {
      Rain_Print();
      delay(2000); // Delay for 2 seconds to display "RAINING!"
      lcd.clear();
    }
    else
    {
      NoRain_Print();
      delay(2000); // Delay for 2 seconds to display "No Rain"
      lcd.clear();
      if (isRaining())
      {
      Rain_Print();
      delay(2000); // Delay for 2 seconds to display "RAINING!"
      lcd.clear();
      }
      // Display temperature and humidity
      Temp_print();
      Humidity_print();
      delay(1500);
      lcd.clear();
      if (isRaining())
      {
      Rain_Print();
      delay(2000); // Delay for 2 seconds to display "RAINING!"
      lcd.clear();
      }
      if (isRaining())
      {
      Rain_Print();
      delay(2000); // Delay for 2 seconds to display "RAINING!"
      lcd.clear();
      }
      // Display pressure
      Pressure_print();
      delay(1500);
      lcd.clear();

      // Display date and time
      DateTime_print();
      delay(1500);
      lcd.clear();
    }
  }
}

bool isRaining()
{
  int raindrop = analogRead(A0);
  digitalWrite(8, HIGH);
  Serial.println(raindrop);
  if (raindrop <= 950)
  {
    digitalWrite(8, LOW);
    return true;
  }
  return false;
}

void Rain_Print()
{
  lcd.setCursor(0, 0);
  lcd.print("RAINING!");
  digitalWrite(10, LOW);   // Set red LED pin LOW
  digitalWrite(11, HIGH);  // Set green LED pin HIGH
  digitalWrite(12, HIGH);  // Set blue LED pin HIGH
}

void NoRain_Print()
{
  lcd.setCursor(0, 0);
  lcd.print("No Rain");
  digitalWrite(10, HIGH);  // Set red LED pin HIGH
  digitalWrite(11, LOW);   // Set green LED pin LOW
  digitalWrite(12, HIGH);  // Set blue LED pin HIGH
}

void Temp_print()
{
  sensors.requestTemperatures();
  float temper = sensors.getTempCByIndex(0);
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.setCursor(6, 0);
  lcd.print(temper);
  lcd.setCursor(11, 0);
  lcd.print("C");
}

void Humidity_print()
{
  int c = dht.readHumidity();
  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  lcd.setCursor(10, 1);
  lcd.print(c);
  lcd.setCursor(12, 1);
  lcd.print("%");
  Serial.println(c);
}

void Pressure_print()
{
  float pres = bmp.readPressure();
  lcd.setCursor(0, 1);
  lcd.print("Press:");
  lcd.print(pres / 1000);
  lcd.print("kPa");
  Serial.println(pres / 1000);
}

void DateTime_print()
{
  RtcDateTime now = Rtc.GetDateTime();
  lcd.setCursor(0, 0);
  lcd.print("Date: ");
  lcd.print(now.Day(), DEC);
  lcd.print('/');
  lcd.print(now.Month(), DEC);
  lcd.print('/');
  lcd.print(now.Year(), DEC);
  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  lcd.print(now.Hour(), DEC);
  lcd.print(':');
  lcd.print(now.Minute(), DEC);
  lcd.print(':');
  lcd.print(now.Second(), DEC);
}