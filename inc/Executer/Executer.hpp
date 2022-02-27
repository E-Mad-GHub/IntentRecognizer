
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
    /*! \brief Executer class constructor.
    *
    *  Constructor
    * 
    */
    Executer();

    /*! \brief Executer class constructor.
    *
    *  Copy Constructor
    * 
    */
    Executer(Executer& exec);

    /*! \brief Executer class constructor.
    *
    *  Move Constructor
    * 
    */
    Executer(Executer&& exec);

    /*! \brief Executer class destructor.
    *
    *  Destructor
    * 
    */
    ~Executer();

    /*! \brief registerInToOut(...).
    *
    *  Registers an input to an output
    * 
    *  @param variadic(firstPair, nextPairs) pairs of input and output pointer.
    *  @return true if registration succeeded, false if else.
    */  
    template <typename fPair, typename... nPairs>  
    typename std::enable_if<std::is_convertible<fPair, customPair>::type::value, bool>::type
    registerInToOut(fPair firstPair, nPairs... nextPairs);

    /*! \brief registerInToOut().
    *
    *  Registers an input to an output individually
    * 
    *  @param inputPtr input pointer.
    *  @param outputPtr output pointer.
    *
    *  @return true if registration succeeded, false if else.
    */
    bool registerInToOut(const absInput* inputPtr, const absOutput* outputPtr);

    /*! \brief executeOutput().
    *
    *  Executes a behavior that maps to the given input.
    * 
    *  @param inputPtr input pointer.
    *
    *  @return buffer the result of the executed function.
    */
    bool executeOutput(const absInput* inputVariablePtr) const;

    /*! \brief inputExists().
    *
    *  Checks whether or not the input existed already.
    * 
    *  @param inputPtr input pointer.
    *
    *  @return true if exists, false if else.
    */
    bool inputExists(const absInput* inputVariablePtr) const;

private:
    // Map which has the mapping between inputs and outputs
    std::unordered_map<const absInput*, const absOutput*> m_parserMap;

    // Private helper
    inline bool registerInToOut(){return true;}
};

#include "./../../src/Executer/Executer.cpp"

#endif  /* EXECUTER_HEADER_H */