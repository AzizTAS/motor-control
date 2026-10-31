#include <iostream>
#include "motor.h"
#include "pidcontroller.h"

int main()
{
    std::cout << "Motor control demo" << std::endl;

    Motor motor;
    const double target=1500.0;
    const double dt=0.1;
    PidController pid(0.001, 0.002, 0.0);

    for(int i=1; i<=50;i++){
        double power = pid.compute(target, motor.speed(),dt);
        motor.update(power,dt);
        std::cout<<"Step "<<i<<": "<<motor.speed()<<" rpm"<<std::endl;
    }

    return 0;
}
