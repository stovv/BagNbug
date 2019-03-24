#include <SoftwareSerial.h>
#include "locker.h"
#include "vibro.h"
#include "blink.h"
#include "move.h"

Blink *blink;
Lock *locker;
Move *move_detector;
Vibro *vibro;

int COUNT_LED = 5;

int PIN_VIBRO = 7;
int PIN_LOCKER = 8;
int PIN_BLINK = 9;

int gRxPin = 10;
int gTxPin = 11;

SoftwareSerial BTSerial(gRxPin, gTxPin);

String lock_state = "";
bool is_locked = false;

// the setup function runs once when you press reset or power the board
void setup()
{
    Serial.begin(9600);
    BTSerial.begin(9600);
    // init all modules

    blink = new Blink(PIN_BLINK, COUNT_LED);
    locker = new Lock(PIN_LOCKER);
    move_detector = new Move();
    if (!move_detector->init())
    {
        Serial.print("ERROR: axcel not init");
    }
    vibro = new Vibro(PIN_VIBRO);
}

void sendAndroidValues()
{
    if (is_locked){
        BTSerial.print("{\"\mode\":{\"type\":2, \"value\":0}}");
    }
    //BTSerial.println();
    delay(10); //added a delay to eliminate missed transmissions
}

// the loop function runs over and over again forever
void loop()
{
    sendAndroidValues();
    //when serial values have been received this will be true
    if (BTSerial.available() > 0)
    {
        lock_state = BTSerial.readString();
        if (lock_state == "{\"mode\":{\"type\":2, \"value\":1}}")
        {
            locker->unlock();
        }
        if (lock_state == "{\"mode\":{\"type\":2, \"value\":0}}")
        {
            locker->lock();
        }
    }
    if (move_detector->check_moving(11.5))
    {
        is_locked = true;
    }
    //delay by 2s. Meaning we will be sent values every 2s approx
    //also means that it can take up to 2 seconds to change LED state
    delay(2000);
}