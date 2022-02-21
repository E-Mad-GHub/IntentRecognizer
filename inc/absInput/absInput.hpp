
#ifndef ABS_INPUT_HEADER_H
#define ABS_INPUT_HEADER_H

/*! \brief Output abstract class.
 *
 *  Output abstract class, used to define the
 *         methods of the children classes
 * 
 *  @tparam VAL_TYPE, the value inside the class.
 */
template<typename VAL_TYPE>
class absInput
{
public:
    virtual bool getValue(VAL_TYPE&) const = 0;

    virtual bool setValue(const VAL_TYPE&)  = 0;

    virtual bool setValue(const VAL_TYPE&&) = 0;
    
    virtual bool clearValue() = 0;

private:
    VAL_TYPE valueType;
};

#endif  /* ABS_INPUT_HEADER_H */