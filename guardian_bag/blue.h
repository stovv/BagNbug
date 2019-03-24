#include <SoftwareSerial.h>
#include "secret.h"

using namespace std;

/*
#include <SoftwareSerial.h>

int gRxPin = 10;
int gTxPin = 11;

SoftwareSerial BTSerial(gRxPin, gTxPin);

void setup() {
  BTSerial.begin(9600);
  Serial.begin(9600);
  delay(500);
}

void loop() {
  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}
*/
class Bt
{
  private:
    int timeout = 1000;
    SoftwareSerial *bt;
    int tx, rx;
    void wait_for_connect();
    String response_mask = "{\"response\":%d}";

  public:
    Bt(int tx, int rx);
    void send(String data);
};

Bt::Bt(int tx, int rx)
{
    this->tx = tx;
    this->rx = rx;
    bt = new SoftwareSerial(this->tx, this->rx);
    bt->begin(9600);
    delay(500);
    wait_for_connect();
}

void Bt::wait_for_connect()
{
    while (true)
    {
        if (bt->available())
        {
            String init_stat = bt->readString();
            if (init_stat == "{\"response\":101}")
            {
                break;
            }
            Serial.println("Waiting for connect");
        }
        delay(10);
    }
}

void Bt::send(String data)
{
    bt->print(data);
    while (true)
    {
        if (bt->available())
        {
            String response = bt->readString();
            if (response == "{\"response\":1}")
            {
                Serial.println("SUCESS");
                break;
            }
            else
            {
                Serial.println("FAIL");
                break;
            }
        }
    }
}
