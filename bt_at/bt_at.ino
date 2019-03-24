#include <SoftwareSerial.h>

//int gRxPin = 10;
//int gTxPin = 11;

#include <SoftwareSerial.h>

int gRxPin = 10;
int gTxPin = 11;

SoftwareSerial BTSerial(gRxPin, gTxPin);

char inbyte = 0;
int led = 13;

void setup()
{
    //BTSerial.begin(9600);
    Serial.begin(9600);
    BTSerial.begin(9600);
    pinMode(led, OUTPUT);
    //delay(500);
}

void sendAndroidValues()
{
    BTSerial.print('#');
    BTSerial.print('~'); //used as an end of transmission character - used in app for string length
    BTSerial.println();
    delay(10); //added a delay to eliminate missed transmissions
}

void loop()
{
    sendAndroidValues();
    //when serial values have been received this will be true
    if (BTSerial.available() > 0)
    {
        inbyte = BTSerial.read();
        if (inbyte == '0')
        {
            //LED off
            digitalWrite(led, LOW);
        }
        if (inbyte == '1')
        {
            //LED on
            digitalWrite(led, HIGH);
        }
    }
    //delay by 2s. Meaning we will be sent values every 2s approx
    //also means that it can take up to 2 seconds to change LED state
    delay(2000);
}