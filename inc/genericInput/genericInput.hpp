
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

    // Constructor
    genericInput();

    // Copy Constructor
    genericInput(const genericInput<VALUE_TYPE>&);

    // Move Constructor
    genericInput(genericInput<VALUE_TYPE>&&);

    // Constructor
    genericInput(const VALUE_TYPE&);

    // Destructor
    ~genericInput();

    // Value match compare
    bool matches(const absInput*) const;

    // Value setter
    bool setValue(const VALUE_TYPE&);

    // Clear the value method
    bool clearValue();

private:

    // Generic value type
    VALUE_TYPE *m_inputValuePtr;

};

#include "./../../src/genericInput/genericInput.cpp"

#endif  /* STRING_INPUT_HEADER_H */