#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <LiquidCrystal_I2C.h>

SoftwareSerial sim900(2,3);      
SoftwareSerial gpsSerial(6,7);   

TinyGPSPlus gps;
LiquidCrystal_I2C lcd(0x27,16,2);

#define BUTTON_PIN 8
#define BUZZER_PIN 12

const char PHONE1[] = "+91xxxxxxxxxx";
const char PHONE2[] = "+91xxxxxxxxxx";
bool alertMode=false;

void sendSMS(const char *number,String msg){
  sim900.print("AT+CMGF=1\r");
  delay(500);
  sim900.print("AT+CMGS=\"");
  sim900.print(number);
  sim900.println("\"");
  delay(1000);
  sim900.print(msg);
  sim900.write(26);
  delay(5000);
}

String getLocation()
{
    gpsSerial.listen();

    lcd.clear();
    lcd.print("Waiting GPS");

    unsigned long start = millis();

    while (millis() - start < 60000)   
    {
        while (gpsSerial.available())
        {
            gps.encode(gpsSerial.read());
        }

        if (gps.location.isUpdated() && gps.location.isValid())
        {
            String url = "https://maps.google.com/?q=";
            url += String(gps.location.lat(), 6);
            url += ",";
            url += String(gps.location.lng(), 6);

            Serial.println(url);

            return url;
        }
    }

    return "GPS NOT AVAILABLE";
}
void checkIncomingSMS()
{
    if (!sim900.available()) return;

    String incoming = "";

    delay(500);

    while (sim900.available())
    {
        incoming += (char)sim900.read();
    }

    Serial.println("Received:");
    Serial.println(incoming);

    incoming.toUpperCase();

    if (incoming.indexOf("STOP") >= 0)
    {
        Serial.println("STOP COMMAND RECEIVED");

        digitalWrite(BUZZER_PIN, LOW);

        alertMode = false;

        lcd.clear();
        lcd.print("Alert Stopped");

        delay(2000);

        lcd.clear();
        lcd.print("System Ready");
    }
}

void setup(){
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  pinMode(BUZZER_PIN,OUTPUT);
  digitalWrite(BUZZER_PIN,LOW);

  Serial.begin(9600);
  sim900.begin(9600);
  delay(1000);
  sim900.println("AT");
  delay(1000);

  sim900.println("AT+CMGF=1");
  delay(1000);

  sim900.println("AT+CNMI=2,2,0,0,0");
  delay(1000);
  Serial.println("SIM900 Ready");
  gpsSerial.begin(9600);
  gpsSerial.listen();
  sim900.println("AT+CMGF=1");
  delay(500);
  sim900.println("AT+CNMI=2,2,0,0,0");
  delay(500);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("System Ready");
}

void loop()
{
    gpsSerial.listen();

    while (gpsSerial.available())
    {
        gps.encode(gpsSerial.read());
    }

    if (!alertMode && digitalRead(BUTTON_PIN) == LOW)
    {
        alertMode = true;

        digitalWrite(BUZZER_PIN, HIGH);

        lcd.clear();
        lcd.print("Waiting GPS");

        String loc = getLocation();

        lcd.clear();
        lcd.print("Sending SMS");

        String msg = "EMERGENCY!\n";
        msg += loc;

        sim900.listen();

        sendSMS(PHONE1, msg);
        sendSMS(PHONE2, msg);

        lcd.clear();
        lcd.print("Alert Sent");
    }

    if (alertMode)
    {
        sim900.listen();

        checkIncomingSMS();
    }
}
