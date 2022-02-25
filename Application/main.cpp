
#include <unistd.h>
#include <iostream>
#include <utility>
#include "genericInput.hpp"
#include "behaviorOutput.hpp"
#include "Executer.hpp"

bool test1()
{
    std::cout << "TEST-1" << std::endl;   
    return true;
}

bool test2()
{
    std::cout << "TEST-2" << std::endl;   
    return true;
}

int main()
{
    std::cout << "\n\n\n\nTEEEEEEEEEEEESSSSSSSSSSSSSSSSSSSSSSST" << std::endl;

    behaviorOutput out1;
    out1.setValue(test1);

    behaviorOutput out2(nullptr);

    bool t1 = out1.executeOutput();
    std::cout << "TEST-1 output = " << t1 << std::endl;   

    bool t2 = out2.executeOutput();
    std::cout << "TEST-2 output = " << t2 << std::endl;   

    out1.clearValue();

    t1 = out1.executeOutput();
    std::cout << "TEST-1 output = " << t1 << std::endl;   

    sleep(1);
    return 0;
}
