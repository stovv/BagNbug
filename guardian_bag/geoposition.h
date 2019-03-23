#include <gprs.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#include "secret.h"



//POST /positioning/v1/locate?app_id=ADD_ID&amp;app_code=APP_CODE HTTP/1.1
//Host: pos.api.here.com
//Content-Type: application/json
//Cache-Control: no-cache

//{"gsm": 
//[{
//  "mcc": 262,
//  "mnc": 1,
//  "lac": 5126,
//  "cid": 16504,
//  "nmr": [{
//             "bsic": "6",
//             "bcch": "82"
//            },
//           {
//            "bsic": "7",
//            "bcch": "85"
//           },
//           {
//            "bsic": "12",
//            "bcch": "93"
//           },{
//            "bsic": "13",
//            "bcch": "88"
//          },{
//           "bsic": "19",
//           "bcch": "88"
//          }
//   ]}]}


class Geopos
{
  private:
    GPRS gprs;
    //char http_cmd[] = "GET exploreembedded.com/wiki/images/1/15/Hello.txt HTTP/1.0\r\n\r\n";
    char buffer[512];
    

  public:
    Geopos();
    ~Geopos();

    void get_geo();
};

Geopos::Geopos()
{
    // init geo module
}

Geopos::~Geopos()
{
}

void Geopos::get_geo()
{
}
