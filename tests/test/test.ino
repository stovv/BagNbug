//#include "blue.h"
#include "../../vibro.h"
#include "../../locker.h"
#include "../../blink.h"
#include "../../colors.h"
#include "../../blue.h"
#include "../../move.h"

//#define VIBRO_TEST
//#define LOCKER_TEST
//#define BLINK_TEST
//#define BLUE_TEST
#define ACCEL_TEST

Bt *bt;
Vibro *vibro;
Lock *lock;
Blink *tape;
Move *move;

void setup()
{
    Serial.begin(9600);
    bt = new Bt(10, 11);
    vibro = new Vibro(12);
    lock = new Lock(9);
    tape = new Blink(8, 5);
    move = new Move();
    if (!move->init())
        Serial.println("ERROR: Accel not init");
}

void loop()
{
#ifdef BLINK_TEST
    tape->set_brightness(100);
    delay(2000);
    tape->center_end_fill(M_BLUE);
    delay(2000);
    tape->end_center_clean();
    delay(2000);
    tape->pulse(M_GREEN);
    delay(3000);
    /*
    for (int i = 100; i >= 0; i-=20)
    {
        Serial.println(String(i));
        tape->set_brightness(i);
        tape->update();
        tape->set_color(M_WHITE);
        delay(300);
        tape->set_color(M_GREEN);
        delay(300);
        tape->set_color(M_BLUE);
        delay(300);
        tape->set_color(M_RED);
        delay(300);
    }*/
#endif

#ifdef BLUE_TEST
    //in progress
    /*if (Serial.available())
    {
        String num = Serial.readString();
        if (num == String(1))
        {
            digitalWrite(9, HIGH);
            Serial.println("start");
            //vibro->run();
        }
        else if (num == '0')
        {
            vibro->stop();
        }
        Serial.print(num);
    }
    //bt->send("hello");
    //Serial.println(bt->read() + "\n");
    */
#endif

#ifdef VIBRO_TEST
    vibro->run();
    delay(1000);
    vibro->stop();
    delay(1000);
#endif

#ifdef LOCKER_TEST
    lock->lock();
    delay(1000);
    lock->unlock();
    delay(1000);
#endif

#ifdef ACCEL_TEST
    if (move->check_moving(25.0))
    {
        tape->pulse(M_RED, 80);
    }
    else
        tape->set_color(M_GREEN);
#endif
}
