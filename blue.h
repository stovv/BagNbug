#include <SoftwareSerial.h>

using namespace std;

class Bt
{
private:
    SoftwareSerial* bt;
    int tx, rx;
public:
    Bt(int tx, int rx);
    void send(int data);
    void send(String data);
    String read(char _end_ = '\n');
};

Bt::Bt(int tx, int rx)
{
    this->tx = tx;
    this->rx = rx;
    bt = new SoftwareSerial(this->tx, this->rx);
    bt->begin(9600);
}

void Bt::send(int data){
    bt->write(String(data).c_str());
}

void Bt::send(String data){
    bt->write(data.c_str());
}

String Bt::read(char _end_ = '\n'){
    int timeout = 0;
    while (true) {
        if ( bt->available() ){
            String data = bt->readStringUntil(_end_);
            return data;
        }
        delay(5);
        timeout++;
        if (timeout >= 10000 ){
            return String("none");
        }
    }
}
