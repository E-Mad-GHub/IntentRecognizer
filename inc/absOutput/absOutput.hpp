
#ifndef ABS_OUTPUT_HEADER_H
#define ABS_OUTPUT_HEADER_H

/*! \brief Output abstract class.
 *
 *  Output abstract class, used to define the
 *         expected methods of the children classes
 * 
 */
class absOutput
{
public:
    // Virtual destructor, to enable inheritance
    virtual ~absOutput() = default;

    // Execute method, to execute the output behavior required
    virtual bool executeOutput() const = 0;

    // Clears the execution behavior
    virtual bool clearValue() = 0;

};

#endif  /* ABS_OUTPUT_HEADER_H */