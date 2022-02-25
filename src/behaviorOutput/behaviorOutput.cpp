
#include "behaviorOutput.hpp"

// Constructor
behaviorOutput::behaviorOutput()
{
    m_behavior = nullptr;
}

// Constructor
behaviorOutput::behaviorOutput(const execFunction ptrToBehaviour)
{
    (void*)this->setValue(ptrToBehaviour);
}

// Destructor
behaviorOutput::~behaviorOutput() = default;

// Execute method, to execute the output behavior required
bool behaviorOutput::executeOutput() const
{
    bool returnVal = false;
   
    if(m_behavior)
    {
        returnVal = m_behavior();
    }

    return returnVal;
}

// Sets the execution behavior
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

// Clears the execution behavior
bool behaviorOutput::clearValue()
{
    // This return value of boolean is for other complex implementations other than that if needed
    m_behavior = nullptr;
    return true;
}