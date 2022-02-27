
#ifndef FUNCTION_OUTPUT_HEADER_H
#define FUNCTION_OUTPUT_HEADER_H

#include "absOutput.hpp"

typedef bool (*execFunction)(void);

class behaviorOutput : public absOutput
{
public:
    /*! \brief behaviorOutput class constructor.
    *
    *  Constructor
    * 
    */
    behaviorOutput();

    /*! \brief behaviorOutput class constructor.
    *
    *  Custom Constructor
    * 
    *  @param ptrToBehaviour the behavior to be saved.
    */
    behaviorOutput(const execFunction);

    /*! \brief behaviorOutput class destructor.
    *
    *  Destructor (default)
    * 
    */
    ~behaviorOutput();

    /*! \brief executeOutput()
    *
    *  Execute method, to execute the output behavior required.
    * 
    *  @return buffer the execution function return
    */
    bool executeOutput() const;


    /*! \brief setValue()
    *
    *  Sets the execution behavior.
    * 
    *  @param ptrToBehaviour pointer to function which will act as the behavior.
    *  @return true if saved successfully, false if else.
    */
    bool setValue(const execFunction);

    
    /*! \brief clearValue()
    *
    *  Clears the execution behavior.
    * 
    *  @return true if clear successfully, false if else.
    */
    bool clearValue();

private:
    execFunction m_behavior;

};

#endif  /* FUNCTION_OUTPUT_HEADER_H */