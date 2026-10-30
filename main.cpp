#include <iostream>



int main()
{
    double speed=0.0;
    std::cout << "Motor control demo" << std::endl;
    std::cout << "Speed: "<< speed << " rpm"<< std::endl;

    for(int i=1;i<11;i++){
        speed+=100.0;
        std::cout<<"Step "<<i<<": "<<speed<<" rpm"<<std::endl;
    }


    return 0;
}
