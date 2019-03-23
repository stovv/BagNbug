#include "locker.h"
#include "vibro.h"
#include "blink.h"
#include "blue.h"

Bt *bt;

// the setup function runs once when you press reset or power the board
void setup()
{
    Serial.begin(9600);
    bt = new Bt(10, 11);
    // init all modules
}

// the loop function runs over and over again forever
void loop()
{
}
