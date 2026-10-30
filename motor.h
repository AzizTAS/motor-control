#ifndef MOTOR_H
#define MOTOR_H

class Motor
{
public:
    Motor();
    void update (double power,double dt);
    double speed() const;
private:
    double m_speed=0.0;
};

#endif // MOTOR_H
