#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

class PidController
{
public:
    PidController(double kp, double ki, double kd);
    double compute(double target, double measured, double dt);

private:
    double m_kp;
    double m_ki;
    double m_kd;
    double m_integral = 0.0;
    double m_previousError = 0.0;
};

#endif // PIDCONTROLLER_H
