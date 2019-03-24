#include <Servo.h>

class Lock
{
  private:
    int *devices;
    Servo myservo;
    int lock_pos = 85;
    int unlock_pos = 120;

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
    myservo.write(unlock_pos);
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
