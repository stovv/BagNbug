#include <Adafruit_NeoPixel.h>
#define PIN 6       // номер порта к которому подключен модуль
#define count_led 5 // количество светодиодов
#define delayval 500
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(count_led, PIN, NEO_GRB + NEO_KHZ800); //first number change does distance between colors
void setup()
{
    pixels.begin();
    pixels.show(); // Устанавливаем все светодиоды в состояние "Выключено"
}
void loop()
{
    for (int i = 0; i < count_led; i++)
    {
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(random(0, 255), random(0, 255), random(0, 255))); // Moderately bright green color.
        pixels.show();                                                                         // This sends the updated pixel color to the hardware.
        delay(delayval);                                                                       // Delay for a period of time (in milliseconds).
    }
}