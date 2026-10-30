#include <iostream>
#include "motor.h"



int main()
{

    std::cout << "Motor control demo" << std::endl;

    Motor motor;

    for(int i=1; i<=10;i++){
        motor.update(1.0,0.1);
        std::cout<<"Step "<<i<<": "<<motor.speed()<<" rpm"<<std::endl;
    }

    return 0;
}
