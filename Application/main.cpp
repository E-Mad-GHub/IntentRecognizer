
#include <unistd.h>
#include <iostream>
#include <utility>
#include <csignal>

#include "Executer.hpp"
#include "configHandler.hpp"

void signalHandler( int signum ) {
    exit(signum);
}

int main(int argc, char *argv[])
{
    signal(SIGINT, signalHandler);

    if((argc < 2) && (!argv[1]))
    {
        std::cout << "\n\n\n\nInvalid Input" << std::endl;
        std::cout << "\nUsage Instruction:\n\tEx. IRecog <PATH/TO/FILE/config.ini>\n" << std::endl;
        return 0;
    }

    std::cout << "\n\n\n\nWELCOME TO INTENT REGOCNITION\n\n\n" << std::endl;

    // Instantiate an executer
    Executer ex;

    // Parse the ini config file (Thats is customized for the application configuration)
    configHandler cH(argv[1], ex);

    while(true)
    {
        std::string userInput;
        std::cout << "\nWhat is in your mind: ";
        getline (std::cin, userInput);

        genericInput<std::string> tmpInput(userInput);

        if(!ex.executeOutput(&tmpInput))
        {
            std::cout << "\nINVALID\n";
        }
    }

    sleep(1);
    return 0;
}
