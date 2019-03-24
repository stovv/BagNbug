#include <gprs.h>
#include <ArduinoJson.h>
#include <gprs800.h>
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
    char http_cmd[] = "POST /positioning/v1/locate?app_id=ADD_ID&amp;app_code=APP_CODE HTTP/1.1\r\n\r\n";       //server request
    char website[] = "pos.api.here.com";          //website domain name or ip address
    char apn[] = "internet.yota";             //APN of your cellular network provider
    char uname[] = "";								  //APN username
    char pword[] = "";                                //APN password
    int port = 80;                                    //connection port, usually 80 for HTTP
    void get_infos();

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

void Geopos::get_infos(){
  
}

void Geopos::send_sms(String sms_number, String sms_text){
  delay(100);
  gsm.print("AT+CMGS=\"");
  gsm.print((String)sms_number);
  gsm.println("\"");
  delay(100);
  gsm.println((String)sms_text);
  delay(100);
  gsm.write(0x1A);  // command for send sms, code for CTRL-Z
  //gsm.print((char)26);           // ^Z
  //gsm.print((char)13);           // CR
  delay(2000);
  Serial.println("Sending SMS\n");
  delay(100);
  gsm.println ("AT+CMGD=4"); // удалить все смс
  delay(100);
  //getGSManswer();
}