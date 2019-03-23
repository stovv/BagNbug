#include <Servo.h>

class Lock
{
  private:
    int *devices;
    Servo myservo;
    int lock_pos = 65;
    int unlock_pos = 170;

  public:
    Lock(int pin);
    ~Lock();

    void lock();
    void unlock();
    void check_device();
};

Lock::Lock(int pin) // len of motors, motors pin array
{
    myservo.attach(pin);
}

Lock::~Lock()
{
    myservo.detach();
}

void Lock::lock()
{
    myservo.write(lock_pos);
}

void Lock::unlock()
{
    myservo.write(unlock_pos);
}

/*
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

*/