#include "motorcontroller.h"

MotorController::MotorController(QObject *parent)
    : QObject{parent}, m_pid(0.001, 0.002, 0.0)
{
    connect(&m_timer, &QTimer::timeout, this, &MotorController::step);
    m_timer.start(100);
}

void MotorController::step()
{
    const double dt = 0.1;
    double power = 0.0;
    if (m_running) {
        power = m_pid.compute(m_target, m_motor.speed(), dt);
    }
    m_motor.update(power, dt);
    emit speedChanged();
}

double MotorController::speed() const
{
    return m_motor.speed();
}

bool MotorController::running() const
{
    return m_running;
}

double MotorController::target() const
{
    return m_target;
}

void MotorController::start()
{
    m_running = true;
    emit runningChanged();
}

void MotorController::stop()
{
    m_running = false;
    emit runningChanged();
}

void MotorController::setTarget(double newTarget)
{
    if (m_target == newTarget)
        return;
    m_target = newTarget;
    emit targetChanged();
}
