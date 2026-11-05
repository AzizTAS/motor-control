#include "motor.h"

Motor::Motor() {}

void Motor::update(double power, double dt)
{
    const double maxSpeed = 3000.0;
    const double timeConstant = 0.5;

    double targetSpeed = power * maxSpeed;

    m_speed += (targetSpeed - m_speed) * dt / timeConstant;
}

double Motor::speed() const
{
    return m_speed;
}
