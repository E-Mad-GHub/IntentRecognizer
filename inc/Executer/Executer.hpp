
#ifndef EXECUTER_HEADER_H
#define EXECUTER_HEADER_H

#include "absInput.hpp"
#include "absOutput.hpp"
#include <utility>
#include <unordered_map>

typedef std::pair<const absInput*,const absOutput*> customPair;

class Executer
{
public:
    // Constructor
    Executer();

    // Copy Constructor
    Executer(Executer& exec);

    // Move Constructor
    Executer(Executer&& exec);

    // Destructor
    ~Executer();

    // Method to register inputs with outputs as pairs
    template <typename fPair, typename... nPairs>  
    typename std::enable_if<std::is_convertible<fPair, customPair>::type::value, bool>::type
    registerInToOut(fPair firstPair, nPairs... nextPairs);

    // Method to register inputs with outputs individually
    bool registerInToOut(const absInput* inputPtr, const absOutput* outputPtr);

    // Method to execute the output
    bool executeOutput(const absInput* inputVariablePtr) const;

    // Method to check wether or not the input exists already in the executer
    bool inputExists(const absInput* inputVariablePtr) const;

private:
    // Map which has the mapping between inputs and outputs
    std::unordered_map<const absInput*, const absOutput*> m_parserMap;

    // Private helper
    inline bool registerInToOut(){return true;}
};

#include "./../../src/Executer/Executer.cpp"

#endif  /* EXECUTER_HEADER_H */