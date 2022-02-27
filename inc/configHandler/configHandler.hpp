
#ifndef CONFIG_HANDLER_HEADER_H
#define CONFIG_HANDLER_HEADER_H

#include <vector>
#include <string>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include "genericInput.hpp"
#include "behaviorOutput.hpp"
#include "Executer.hpp"

typedef bool (*ptrToBehavior)() ;

// This class is made specifically for the application, not implemented to become generic
class configHandler
{
public:
    // Constructor
    configHandler(std::string, Executer&);

    // Destructor
    ~configHandler();

private:
    // Map which maps the strings read and their corresponding APIs
    std::unordered_map<std::string, ptrToBehavior> m_rosetta;

    // All the inputs
    std::vector<genericInput<std::string>*> m_inputs;
    
    // All the outputs
    std::vector<behaviorOutput*> m_outputs;

    // Private helper
    void fillDataBase();
};

#include "./../../src/configHandler/configHandler.cpp"

#endif  /* CONFIG_HANDLER_HEADER_H */