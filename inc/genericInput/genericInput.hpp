
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

    // Constructor
    genericInput(VALUE_TYPE&&);

    // Destructor
    ~genericInput();

    // Value match compare
    bool matches(const absInput*) const;

    // Value setter
    bool setValue(const genericInput&);
    
    // Clear the value method
    bool clearValue();

private:

    // Generic value type
    VALUE_TYPE inputValue;

};

#endif  /* STRING_INPUT_HEADER_H */