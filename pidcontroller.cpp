#include "pidcontroller.h"
#include <algorithm>

PidController::PidController(double kp, double ki, double kd)

    : m_kp(kp), m_ki(ki), m_kd(kd)

{

}

double PidController::compute(double target, double measured, double dt)
{
    double error=target-measured;
    m_integral+=(error*dt);
    double derivative=(error-m_previousError)/dt;
    m_previousError=error;
    double output=m_kp*error+m_ki*m_integral+m_kd*derivative;
    output=std::clamp(output, 0.0,1.0);

    return output;

}
