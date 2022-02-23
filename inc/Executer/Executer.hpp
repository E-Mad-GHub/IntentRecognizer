
#ifndef ROSETTA_HEADER_H
#define ROSETTA_HEADER_H

#include "absInput.hpp"
#include "absOutput.hpp"
#include <unordered_map>

class Executer
{
public:
    Executer();

    ~Executer();

    bool registerInOut(const absInput* inputVariablePtr, const absOutput* outputBehaviorPtr);

    bool executeOutput(const absInput* inputVariablePtr);

    bool inputExists(const absInput* inputVariablePtr);

private:
    std::unordered_map<absInput*, absOutput*> parserMap;
};

#endif  /* ROSETTA_HEADER_H */