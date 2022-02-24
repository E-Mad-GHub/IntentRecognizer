
#include <typeinfo>
#include <utility>
#include <new>
#include "genericInput.hpp"

#include <iostream>

// Constructor
template <typename VALUE_TYPE>
genericInput<VALUE_TYPE>::genericInput()
{
    // Initial value
    this->m_inputValuePtr = nullptr;
}

// Copy Constructor
template <typename VALUE_TYPE>
genericInput<VALUE_TYPE>::genericInput(const genericInput<VALUE_TYPE>& RHS)
{
    // Taking screenshot of the argument
    VALUE_TYPE tmpValue = *(RHS.m_inputValuePtr);

    // Initial value
    this->m_inputValuePtr = nullptr;

    // Creating private data for this class
    this->setValue(tmpValue);
}

// Move Constructor
template <typename VALUE_TYPE>
genericInput<VALUE_TYPE>::genericInput(genericInput<VALUE_TYPE>&& RHS)
{
    // Taking the RHS pointer
    this->m_inputValuePtr = RHS.m_inputValuePtr;

    // nulling the RHS pointer
    RHS.m_inputValuePtr = nullptr;
}

// Constructor
template <typename VALUE_TYPE>
genericInput<VALUE_TYPE>::genericInput(const VALUE_TYPE& passedValue)
{
    // Initial value
    this->m_inputValuePtr = nullptr;

    this->setValue(passedValue);
}

// Destructor
template <typename VALUE_TYPE>
genericInput<VALUE_TYPE>::~genericInput()
{
    this->clearValue();
}

// Value match compare
template <typename VALUE_TYPE>
bool genericInput<VALUE_TYPE>::matches(const absInput* inputPtr) const
{
    bool returnVal = false;

    try 
    {
        if((typeid(genericInput<VALUE_TYPE>)) == (typeid(*inputPtr)))
        {
            if((this->m_inputValuePtr) && ((static_cast<const genericInput<VALUE_TYPE>*>(inputPtr))->m_inputValuePtr))
            {
                returnVal = (*(this->m_inputValuePtr) == *((static_cast<const genericInput<VALUE_TYPE>*>(inputPtr))->m_inputValuePtr));
            }
        }
    } 
    catch(const std::bad_typeid& e) 
    {

        returnVal = false;
    }

    return returnVal;
}

// Value setter
template <typename VALUE_TYPE>
bool genericInput<VALUE_TYPE>::setValue(const VALUE_TYPE& inputValue)
{
    if (!this->m_inputValuePtr)
    {
        try
        {
            this->m_inputValuePtr = new VALUE_TYPE;
        }
        catch (const std::bad_alloc& e)
        {
            return false;
        }
    }

    *(this->m_inputValuePtr) = inputValue;

    return true;
}

// Clear the value method
template <typename VALUE_TYPE>
bool genericInput<VALUE_TYPE>::clearValue()
{
    if (this->m_inputValuePtr)
    {
        delete this->m_inputValuePtr;
        this->m_inputValuePtr = nullptr;
    }
}
