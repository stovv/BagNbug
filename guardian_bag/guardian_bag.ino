#include "locker.h"
#include "vibro.h"
#include "blink.h"
#include "blue.h"
#include "move.h"

Bt *bt;

Blink *blink;
Lock *locker;
Move *move_detector;
Vibro *vibro;


int COUNT_LED = 5;

int PIN_VIBRO = 7;
int PIN_LOCKER = 8;
int PIN_BLINK = 9;
int PIN_BLUETOOTH_1 = 10;
int PIN_BLUETOOTH_2 = 11;

// the setup function runs once when you press reset or power the board
void setup()
{
    Serial.begin(9600);
    bt = new Bt(PIN_BLUETOOTH_1, PIN_BLUETOOTH_2);
    // init all modules

    blink = new Blink(PIN_BLINK, COUNT_LED);
    locker = new Lock(PIN_LOCKER);
    move_detector = new Move();
    vibro = new Vibro(PIN_VIBRO);
}

// the loop function runs over and over again forever
void loop()
{
  //vibro->my_melody();
}
