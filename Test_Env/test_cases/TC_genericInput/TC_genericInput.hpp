#ifndef TC_GENERIC_INPUT_HPP
#define TC_GENERIC_INPUT_HPP

#include "genericInput.hpp"

TEST_CASE( "Testing generally the genericInput APIs", "[genericInput]" )
{
    // Validate the constructors and the matches() then go further for the other APIs
    GIVEN("Constructors and matches() have no problems")
    {
        std::string tmpString("In_1");
        genericInput<std::string> Input_1("In_1");
        genericInput<std::string> Input_11(tmpString);

        genericInput<std::string> Input_2;
        genericInput<std::string> Input_22;
        
        REQUIRE( Input_1.matches(&Input_11) );
        REQUIRE(! Input_2.matches(&Input_22) );
        REQUIRE(! Input_1.matches(&Input_2) );

        // Validate the setValue()
        THEN("Test setValue()")
        {
            Input_11.setValue("In_x");
            REQUIRE(! Input_1.matches(&Input_11) );

            Input_11.setValue("In_1");
            REQUIRE( Input_1.matches(&Input_11) );   
        }

        // Validate the clearValue()
        WHEN("Test clearValue()")
        {
            Input_11.setValue("In_1");
            REQUIRE( Input_1.matches(&Input_11) ); 

            Input_11.clearValue();
            REQUIRE(! Input_1.matches(&Input_11) );
        }
    }
}

#endif /* TC_GENERIC_INPUT_HPP */