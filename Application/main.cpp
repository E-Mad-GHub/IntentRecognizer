
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

bool test3()
{
    std::cout << "TEST-3" << std::endl;   
    return true;
}


int main()
{
    std::cout << "\n\n\n\nTEEEEEEEEEEEESSSSSSSSSSSSSSSSSSSSSSST" << std::endl;

    bool res = false;
    bool err = false;
    bool exists = false;
   
    genericInput<std::string> in1("no1"); 
    behaviorOutput out1(test1);

    genericInput<std::string> in2("no2"); 
    behaviorOutput out2;

    genericInput<std::string> in3("no3"); 
    behaviorOutput out3(test3);

    genericInput<std::string> in4("no4"); 

    Executer ex;

    std::pair<const absInput*, const absOutput*> pr1;
    std::pair<const absInput*, const absOutput*> pr2;
    std::pair<const absInput*, const absOutput*> pr3;

    pr1.first = &in1; 
    pr1.second = &out1;

    pr2.first = &in2; 
    pr2.second = &out2;

    pr3.first = &in3; 
    pr3.second = &out3;

    err = ex.registerInToOut(pr1, pr2, pr3);

    std::cout << "err = " << (int)err << std::endl;

    res = ex.executeOutput(&in1);
    res = ex.executeOutput(&in2);
    res = ex.executeOutput(&in3);
    std::cout << "res = " << (int)res << std::endl;

    exists = ex.inputExists(&in1);
    std::cout << "exists = " << (int)exists << std::endl;

    exists = ex.inputExists(&in4);
    std::cout << "exists = " << (int)exists << std::endl;



    sleep(1);
    return 0;
}
