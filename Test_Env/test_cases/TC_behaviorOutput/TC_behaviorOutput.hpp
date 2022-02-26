#ifndef TC_BEH_OUTPUT_HPP
#define TC_BEH_OUTPUT_HPP

#include "behaviorOutput.hpp"
#include <iostream>

bool foo_1()
{ 
    return true; 
}

bool foo_2()
{ 
    return false; 
}

bool foo_3()
{ 
    return true; 
}


// SCENARIO
SCENARIO( "Testing generally the behaviorOutput class methods", "[behaviorOutput]" )
{
    // Validate the constructors and the executeOutput() then go further for the other APIs
    GIVEN("Constructors and executeOutput() have no problems")
    {
        behaviorOutput out_1;
        behaviorOutput out_2(foo_2);
        behaviorOutput out_3(foo_3);       

        REQUIRE(! out_1.executeOutput() );
        REQUIRE(! out_2.executeOutput() );
        REQUIRE(  out_3.executeOutput() );

        // Validate the setValue()
        THEN("Test setValue()")
        {
            out_1.setValue(foo_1);
            REQUIRE( out_1.executeOutput() );

            out_1.setValue(foo_2);
            REQUIRE(! out_1.executeOutput() );
        }

        // Validate the clearValue()
        THEN("Test clearValue()")
        {
            out_2.clearValue();
            REQUIRE(! out_2.executeOutput() );

            out_3.clearValue();
            REQUIRE(! out_3.executeOutput() );
        }
    }
}

#endif /* TC_BEH_OUTPUT_HPP */