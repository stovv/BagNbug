#include <Mpu6050.h>

class Move
{
  private:
    Mpu6050 sensor;
    Vector3f accel;

  public:
    Move();
    bool init();
    bool check_moving(float k = 15.0);
};

Move::Move(/* args */)
{
    sensor = Mpu6050();
}

bool Move::init()
{
    if (!sensor.init())
        return true;
    return false;
}

bool Move::check_moving(float k = 15.0)
{
    accel = sensor.readAcceleration();
    Serial.println(accel.magnitude());
    if (accel.magnitude() > k)
        return true;
    return false;
}
