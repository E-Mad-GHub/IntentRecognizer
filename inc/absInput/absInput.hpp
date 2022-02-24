
#ifndef ABS_INPUT_HEADER_H
#define ABS_INPUT_HEADER_H

/*! \brief Output abstract class.
 *
 *  Output abstract class, used to define the
 *         methods of the input children classes
 * 
 */
class absInput
{
public:
    // Virtual Destructor for inheritance enabling
    virtual ~absInput() = default;

    // This API will be used by any user of the children of the input (Ex. rosetta)
    virtual bool matches(const absInput*) const = 0;

    // Clear the value method
    virtual bool clearValue() = 0;
};

#endif  /* ABS_INPUT_HEADER_H */