
#include <unistd.h>
#include <iostream>
#include <utility>
#include "genericInput.hpp"
#include "behaviorOutput.hpp"
#include "Executer.hpp"

int main()
{
    std::cout << "\n\n\n\nTEEEEEEEEEEEESSSSSSSSSSSSSSSSSSSSSSST" << std::endl;

    genericInput<std::string> sIn("Hello_1");

    std::string tmp = "Hello_1";
    genericInput<std::string> sIn_1(tmp);
    genericInput<std::string> sIn_11(sIn_1);
    genericInput<std::string> sIn_12("IM");

    genericInput<std::string> sIn_2("Hello_2");
    genericInput<std::string> sIn_22(sIn_2);

    // sIn = std::move(sIn_1);

    bool match  = (sIn_1.matches(&sIn_2));

    std::cout << "1 matches 2 (0) -> " << (int)match << std::endl;

    bool match2 = (sIn_2.matches(&sIn_22));

    std::cout << "2 matches 22 (1) -> " << (int)match2 << std::endl;

    sIn_2.setValue("Hello_3");

    bool match3 = (sIn_2.matches(&sIn_22));

    std::cout << "2 matches 22 (0) -> " << (int)match3 << std::endl;

    sIn_1.clearValue();

    bool match4  = (sIn_1.matches(&sIn));

    std::cout << "1 matches 0 (0) -> " << (int)match4 << std::endl;

    sleep(1);
    return 0;
}
