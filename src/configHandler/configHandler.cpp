
#include <iostream>
#include "behaviorList.hpp"

// Constructor
configHandler::configHandler(std::string filePath, Executer& container)
{
    fillDataBase();

    // Read ini behavior number
    boost::property_tree::ptree pt;
    boost::property_tree::ini_parser::read_ini(filePath, pt);

    int NoOfBehav = std::stoi(pt.get<std::string>("NoOfExec.Number"));

    // Loop over every behavior and extract the input and the output behavior
    for (int count = 0 ; count < NoOfBehav ; ++count)
    {        
        std::string tmpString = pt.get<std::string>("Exec" + std::to_string(count) + ".Input");
        m_inputs.push_back(new genericInput<std::string>(tmpString));

        tmpString = pt.get<std::string>("Exec" + std::to_string(count) + ".Behavior");
        behaviorOutput tmpOutput(m_rosetta[tmpString]);
        m_outputs.push_back(new behaviorOutput(m_rosetta[tmpString]));

        container.registerInToOut(m_inputs.back(), m_outputs.back());
    }
}

// Destructor (Delete allocated memory)
configHandler::~configHandler()
{
    for(auto &it : m_inputs)
    {
        delete it;
    }
     
    for(auto &it : m_outputs)
    {
        delete it;
    }
}

void configHandler::fillDataBase()
{
    // Fill database map
    m_rosetta["behavior_1"] = behavior_1;
    m_rosetta["behavior_2"] = behavior_2;
    m_rosetta["behavior_3"] = behavior_3;
    m_rosetta["behavior_4"] = behavior_4;
    m_rosetta["behavior_5"] = behavior_5;
    m_rosetta["behavior_6"] = behavior_6;
    m_rosetta["behavior_7"] = behavior_7;
    m_rosetta["behavior_8"] = behavior_8;
    m_rosetta["behavior_9"] = behavior_9;
    m_rosetta["behavior_0"] = behavior_0;
}

