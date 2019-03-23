#include <Adafruit_NeoPixel.h>
#include "colors.h"

class Blink
{
  private:
    Adafruit_NeoPixel *led_tape;
    int pin;
    int count_led;

  public:
    Blink(int pin, int count_led, uint8_t brightness = 100);
    ~Blink();
    void set_color(uint8_t r, uint8_t g, uint8_t b);
    void set_brightness(uint8_t brightness);
    void update();
    void pulse(uint8_t r, uint8_t g, uint8_t b, int timeout = 100);
    void center_end_fill(uint8_t r, uint8_t g, uint8_t b, int timeout = 100);
    void end_center_clean(int timeout = 100);
};

Blink::Blink(int pin, int count_led, uint8_t brightness = 100)
{
    this->count_led = count_led;
    this->pin = pin;
    led_tape = new Adafruit_NeoPixel(count_led, pin, NEO_GRB + NEO_KHZ800);
    led_tape->begin();
    set_brightness(brightness);
}

Blink::~Blink()
{
    delete led_tape;
}

void Blink::set_color(uint8_t r, uint8_t g, uint8_t b)
{
    led_tape->clear();
    for (int i = 0; i < this->count_led; i++)
    {
        led_tape->setPixelColor(i, r, g, b);
    }
    led_tape->show();
}

void Blink::set_brightness(uint8_t brightness)
{
    for (int i = 0; i < this->count_led; i++)
    {
        led_tape->setBrightness(brightness);
    }
}

void Blink::update()
{
    led_tape->show();
}

void Blink::pulse(uint8_t r, uint8_t g, uint8_t b, int timeout = 100)
{
    led_tape->clear();
    led_tape->show();
    delay(timeout / 0.5);
    int center = this->count_led / 2;
    int right = center + 1;
    int left = center - 1;

    //blink center
    led_tape->setPixelColor(center, r, g, b);
    led_tape->show();
    delay(timeout);

    //from center to ends
    for (int i = 0; i < center; i++)
    {
        led_tape->setPixelColor(left, r, g, b);
        led_tape->setPixelColor(right, r, g, b);
        led_tape->show();

        delay(timeout);
        left--;
        right++;
    }
    delay(timeout * 0.5);

    left = 0;
    right = count_led - 1;
    //from ends to center
    for (int i = 0; i < center; i++)
    {
        led_tape->setPixelColor(left, M_TRANSPARENT);
        led_tape->setPixelColor(right, M_TRANSPARENT);
        led_tape->show();
        delay(timeout);
        left++;
        right--;
    }
    led_tape->setPixelColor(center, M_TRANSPARENT);
    led_tape->show();
}

void Blink::center_end_fill(uint8_t r, uint8_t g, uint8_t b, int timeout = 100)
{
    led_tape->clear();
    led_tape->show();
    delay(timeout / 0.5);
    int center = this->count_led / 2;
    int right = center + 1;
    int left = center - 1;

    //blink center
    led_tape->setPixelColor(center, r, g, b);
    led_tape->show();
    delay(timeout);

    //from center to ends
    for (int i = 0; i < center; i++)
    {
        led_tape->setPixelColor(left, r, g, b);
        led_tape->setPixelColor(right, r, g, b);
        led_tape->show();

        delay(timeout);
        left--;
        right++;
    }
}

void Blink::end_center_clean(int timeout = 100)
{
    int left = 0;
    int right = count_led - 1;
    int center = this->count_led / 2;
    //from ends to center
    for (int i = 0; i < center; i++)
    {
        led_tape->setPixelColor(left, M_TRANSPARENT);
        led_tape->setPixelColor(right, M_TRANSPARENT);
        led_tape->show();
        delay(timeout);
        left++;
        right--;
    }
    led_tape->setPixelColor(center, M_TRANSPARENT);
    led_tape->show();
}