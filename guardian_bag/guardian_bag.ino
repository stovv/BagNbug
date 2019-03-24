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
int PIN_LOCKER = 6;
int PIN_BLINK = 4;

int gRxPin = 10;
int gTxPin = 11;

SoftwareSerial BTSerial(gRxPin, gTxPin);
SoftwareSerial SIM800(2, 3);

String lock_state = "";
bool is_locked = false;

bool is_car_warning = false;

// the setup function runs once when you press reset or power the board
void setup()
{
    Serial.begin(9600);
    BTSerial.begin(9600);
    SIM800.begin(9600);
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

void check_location(){
    String _response = sendATCommand("AT+CENG?\r\n", true);
}

void sendAndroidValues()
{
    if (is_locked){
        //BTSerial.print('#');
        BTSerial.print("{\"notification\":{\"type\":2,\"value\":0}}");
        BTSerial.println();
        is_locked = false;
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
        //Serial.println(lock_state);
        if (lock_state == "{\"response\":101}"){
            if (is_locked){
                BTSerial.print("{\"lock_state\":0}");
            }else{
                BTSerial.print("{\"lock_state\":1}");
            }
            BTSerial.println();
        }
        else if (lock_state == "{\"mode\":{\"type\":2,\"value\":1}}")
        {
            locker->unlock();
            BTSerial.print("{\"lock_state\":1}");
            BTSerial.println();
            vibro->run();
            delay(300);
            vibro->stop();
            is_locked = false;
        }
        else if (lock_state == "{\"mode\":{\"type\":2,\"value\":0}}")
        {
            locker->lock();
            BTSerial.print("{\"lock_state\":0}");
            BTSerial.println();
            vibro->run();
            delay(300);
            vibro->stop();
        }
    }
    if (move_detector->check_moving(12.0))
    {
        is_locked = true;
        locker->lock();
        vibro->run();
        delay(300);
        vibro->stop();
    }
    //Serial.println(is_locked);
    //delay by 2s. Meaning we will be sent values every 2s approx
    //also means that it can take up to 2 seconds to change LED state
    blink->set_brightness(50);
    delay(50);
    blink->center_end_fill(M_BLUE);
    delay(50);
    blink->end_center_clean();
    delay(300);
    blink->pulse(M_GREEN);
    delay(100);
    delay(200);
}
