
#include "behaviorOutput.hpp"

/*! \brief behaviorOutput class constructor.
*
*  Constructor
* 
*/
behaviorOutput::behaviorOutput()
{
    m_behavior = nullptr;
}


/*! \brief behaviorOutput class constructor.
*
*  Custom Constructor
* 
*  @param ptrToBehaviour the behavior to be saved.
*/
behaviorOutput::behaviorOutput(const execFunction ptrToBehaviour)
{
    (void*)this->setValue(ptrToBehaviour);
}


/*! \brief behaviorOutput class destructor.
*
*  Destructor (default)
* 
*/
behaviorOutput::~behaviorOutput() = default;


/*! \brief executeOutput()
*
*  Execute method, to execute the output behavior required.
* 
*  @return buffer the execution function return
*/
bool behaviorOutput::executeOutput() const
{
    bool returnVal = false;
   
    if(m_behavior)
    {
        returnVal = m_behavior();
    }

    return returnVal;
}


/*! \brief setValue()
*
*  Sets the execution behavior.
* 
*  @param ptrToBehaviour pointer to function which will act as the behavior.
*  @return true if saved successfully, false if else.
*/
bool behaviorOutput::setValue(const execFunction ptrToBehaviour)
{
    bool returnVal = false;

    if(nullptr != ptrToBehaviour)
    {
        m_behavior = ptrToBehaviour;
        returnVal = true;
    }

    return returnVal;
}


/*! \brief clearValue()
*
*  Clears the execution behavior.
* 
*  @return true if clear successfully, false if else.
*/
bool behaviorOutput::clearValue()
{
    // This return value of boolean is for other complex implementations other than that if needed
    m_behavior = nullptr;
    return true;
}