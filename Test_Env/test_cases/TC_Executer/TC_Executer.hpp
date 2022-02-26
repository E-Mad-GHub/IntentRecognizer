
#ifndef TC_EXECUTER_HEADER_H
#define TC_EXECUTER_HEADER_H

#include "behaviorOutput.hpp"
#include "genericInput.hpp"
#include "Executer.hpp"

bool test_1()
{
    return false;
}

bool test_2()
{
    return true;
}

bool test_3()
{
    return false;
}

// SCENARIO
SCENARIO( "Testing generally the Executer APIs", "[Executer]" )
{
    // Validate the constructors and the matches() then go further for the other APIs
    GIVEN("Constructors have no problems")
    {
        genericInput<std::string> Input_1("In_1");
        genericInput<std::string> Input_2("In_2");
        genericInput<std::string> Input_3("In_3");
        genericInput<std::string> Input_4;

        behaviorOutput Output_1(test_1);
        behaviorOutput Output_2(test_2);
        behaviorOutput Output_3(test_3);
        behaviorOutput Output_4;

        Executer ex_1;

        // Validate the registerInToOut(...)
        THEN("Test variadic registerInToOut(...)")
        {
            REQUIRE(
                ex_1.registerInToOut(
                    std::make_pair<const absInput*,const absOutput*>(&Input_1, &Output_1),
                    std::make_pair<const absInput*,const absOutput*>(&Input_2, &Output_2),
                    std::make_pair<const absInput*,const absOutput*>(&Input_3, &Output_3)                    
                    )
            );

            REQUIRE( !
                ex_1.registerInToOut(
                    std::make_pair<const absInput*,const absOutput*>(&Input_1, &Output_1),
                    std::make_pair<const absInput*,const absOutput*>(&Input_2, &Output_2),
                    std::make_pair<const absInput*,const absOutput*>(nullptr, &Output_3)
                    )
            );            

            REQUIRE( !
                ex_1.registerInToOut(
                    std::make_pair<const absInput*,const absOutput*>(&Input_1, &Output_1),
                    std::make_pair<const absInput*,const absOutput*>(&Input_2, nullptr),
                    std::make_pair<const absInput*,const absOutput*>(&Input_3, &Output_3)
                    )
            );    
        }

        // Validate the registerInToOut()
        THEN("Test registerInToOut(const absInput*, const absOutput*)")
        {
            REQUIRE(
                ex_1.registerInToOut(&Input_1, &Output_1)
            );     

            REQUIRE( !
                ex_1.registerInToOut(nullptr, &Output_2)
            );          

            REQUIRE( !
                ex_1.registerInToOut(&Input_3, nullptr)
            );                
        }

        // Validate the executeOutput(const absInput*)
        THEN("Test executeOutput(const absInput*)")
        {
            ex_1.registerInToOut(
                std::make_pair<const absInput*,const absOutput*>(&Input_1, &Output_1),
                std::make_pair<const absInput*,const absOutput*>(&Input_2, &Output_2),
                std::make_pair<const absInput*,const absOutput*>(&Input_3, &Output_3)                    
            );

            REQUIRE( !
                ex_1.executeOutput(&Input_1)
            );     

            REQUIRE(
                ex_1.executeOutput(&Input_2)
            );          

            REQUIRE( !
                ex_1.executeOutput(&Input_3)
            );        

            REQUIRE( !
                ex_1.executeOutput(&Input_4)
            );                
        }

        // Validate the inputExists(const absInput*)
        THEN("Test inputExists(const absInput*)")
        {
            ex_1.registerInToOut(
                std::make_pair<const absInput*,const absOutput*>(&Input_1, &Output_1)             
            );

            REQUIRE(
                ex_1.inputExists(&Input_1)
            );     

            REQUIRE( !
                ex_1.inputExists(&Input_2)
            );          
        }
    }
}

#endif  /* TC_EXECUTER_HEADER_H */