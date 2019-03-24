#include <Mpu6050.h>

class Move
{
  private:
    Mpu6050 sensor;
    Mpu6050Data data;
    Vector3f accel;
    float prev_magnitude;

  public:
    Move();
    bool init();
    bool check_moving(float k);
};

Move::Move(/* args */)
{
    sensor = Mpu6050();
    prev_magnitude = 0.0;
}

bool Move::init()
{
    if (!sensor.init())
        return false;
    return true;
}

bool Move::check_moving(float k = 25.0)
{
    accel = sensor.readAcceleration();
    data = sensor.readData();

    float current_magnitude = accel.magnitude();

    float difference_magnitude = current_magnitude - prev_magnitude;
    Serial.println(accel.magnitude());
    prev_magnitude = current_magnitude;
    if (prev_magnitude > k)
        return true;
    return false;
}
