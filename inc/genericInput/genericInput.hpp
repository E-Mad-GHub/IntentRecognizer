
#ifndef STRING_INPUT_HEADER_H
#define STRING_INPUT_HEADER_H

#include "absInput.hpp"


/*! \brief Output abstract class.
 *
 *  Output abstract class, used to define the
 *         methods of the input children classes
 * 
 *  @tparam VALUE_TYPE the info type inside the input shell.
 */
template <typename VALUE_TYPE>
class genericInput : public absInput
{
public:

    /*! \brief genericInput class constructor.
    *
    *  Constructor
    * 
    */
    genericInput();


    /*! \brief genericInput class constructor.
    *
    *  Copy Constructor
    * 
    *  @param RHS the object which will be copied.
    */
    genericInput(const genericInput<VALUE_TYPE>&);

    /*! \brief genericInput class constructor.
    *
    *  Move Constructor
    * 
    *  @param RHS the object which will be moved.
    */
    genericInput(genericInput<VALUE_TYPE>&&);

    /*! \brief genericInput class constructor.
    *
    *  Custom Constructor
    * 
    *  @param passedValue the value of the input.
    */
    genericInput(const VALUE_TYPE&);

    /*! \brief genericInput class destructor.
    *
    *  Destructor
    * 
    */
    ~genericInput();

    /*! \brief matches() API
    *
    *  To compare two input in the matter of values.
    * 
    *  @param inputPtr the input to compare with.
    *  @return true if matches, false if else
    */
    bool matches(const absInput*) const;

    /*! \brief setValue() API
    *
    *  Sets the value of the input
    * 
    *  @param inputPtr the input to compare with.
    *  @return true if success, false if else
    */
    bool setValue(const VALUE_TYPE&);

    /*! \brief clearValue() API
    *
    *  Clears the value inside the class
    * 
    *  @return true if success, false if else
    */
    bool clearValue();

private:

    // Generic value type
    VALUE_TYPE *m_inputValuePtr;

};

#include "./../../src/genericInput/genericInput.cpp"

#endif  /* STRING_INPUT_HEADER_H */