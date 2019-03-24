#include <SoftwareSerial.h>

//Create software serial object to communicate with SIM800L

class Sim{
    private:
        SoftwareSerial* mySerial; //SIM800L Tx & Rx is connected to Arduino #3 & #2
    Sim();
    ~Sim();

}

Sim::Sim(){
    mySerial = new SoftwareSerial(3, 2);
    
}
//для велосепидистов поворотники