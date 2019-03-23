#include <SoftwareSerial.h>
#include "secret.h"

using namespace std;

class Bt
{
  private:
    int timeout = 1000;
    SoftwareSerial *bt;
    int tx, rx;
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
}

void Bt::send(String data)
{
    int time_out = 0;
    bt->write(data.c_str());
    /*while (true)
    {
        if (bt->available())
        {
            String BluetoothData = bt->readString();
            String response_success = "{\"response\":1}";
            String response_fail = "{\"response\":0}";
            //sprintf(response_fail, response_mask, FAIL);

            if (BluetoothData == response_success)
            {
                Serial.println(BluetoothData);
                Serial.println("SUCESS");
            }
            else
            {
                Serial.println(BluetoothData);
                Serial.println("FAIL");
            }
            delay(100);
            time_out++;
            if (time_out == timeout)
            {
                Serial.println("FAIL((((");
                break;
            }
        }
    }*/
}
