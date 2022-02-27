
#include <typeinfo>
#include <utility>
#include <new>
#include "genericInput.hpp"

/*! \brief genericInput class constructor.
*
*  Constructor
* 
*/
template <typename VALUE_TYPE>
genericInput<VALUE_TYPE>::genericInput()
{
    // Initial value
    this->m_inputValuePtr = nullptr;
}


/*! \brief genericInput class constructor.
*
*  Copy Constructor
* 
*  @param RHS the object which will be copied.
*/
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


/*! \brief genericInput class constructor.
*
*  Move Constructor
* 
*  @param RHS the object which will be moved.
*/
template <typename VALUE_TYPE>
genericInput<VALUE_TYPE>::genericInput(genericInput<VALUE_TYPE>&& RHS)
{
    // Taking the RHS pointer
    this->m_inputValuePtr = RHS.m_inputValuePtr;

    // nulling the RHS pointer
    RHS.m_inputValuePtr = nullptr;
}


/*! \brief genericInput class constructor.
*
*  Custom Constructor
* 
*  @param passedValue the value of the input.
*/
template <typename VALUE_TYPE>
genericInput<VALUE_TYPE>::genericInput(const VALUE_TYPE& passedValue)
{
    // Initial value
    this->m_inputValuePtr = nullptr;

    this->setValue(passedValue);
}


/*! \brief genericInput class destructor.
*
*  Destructor
* 
*/
template <typename VALUE_TYPE>
genericInput<VALUE_TYPE>::~genericInput()
{
    this->clearValue();
}


/*! \brief matches() API
*
*  To compare two input in the matter of values.
* 
*  @param inputPtr the input to compare with.
*  @return true if matches, false if else
*/
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


/*! \brief setValue() API
*
*  Sets the value of the input
* 
*  @param inputPtr the input to compare with.
*  @return true if success, false if else
*/
template <typename VALUE_TYPE>
bool genericInput<VALUE_TYPE>::setValue(const VALUE_TYPE& inputValue)
{
    if (!(this->m_inputValuePtr))
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


/*! \brief clearValue() API
*
*  Clears the value inside the class
* 
*  @return true if success, false if else
*/template <typename VALUE_TYPE>
bool genericInput<VALUE_TYPE>::clearValue()
{
    if (this->m_inputValuePtr)
    {
        delete this->m_inputValuePtr;
        this->m_inputValuePtr = nullptr;
    }
}
