
#ifndef FUNCTION_OUTPUT_HEADER_H
#define FUNCTION_OUTPUT_HEADER_H

#include "absOutput.hpp"

typedef bool (*execFunction)(void);

class behaviorOutput : public absOutput
{
public:
    // Constructor
    behaviorOutput();

    // Constructor
    behaviorOutput(const execFunction);

    // Destructor
    ~behaviorOutput();

    // Execute method, to execute the output behavior required
    bool executeOutput() const;

    // Sets the execution behavior
    bool setValue(const execFunction);

    // Clears the execution behavior
    bool clearValue();

private:
    execFunction m_behavior;

};

#endif  /* FUNCTION_OUTPUT_HEADER_H */