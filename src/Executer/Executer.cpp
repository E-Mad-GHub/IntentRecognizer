
// Constructor
Executer::Executer()
{
    this->m_parserMap.clear();
}

// Copy Constructor
Executer::Executer(Executer& exec)
{
    this->m_parserMap.clear();
    this->m_parserMap = exec.m_parserMap;
}

// Move Constructor
Executer::Executer(Executer&& exec)
{
    this->m_parserMap.clear();
    this->m_parserMap = std::move(exec.m_parserMap);
}

// Destructor
Executer::~Executer()
{
    this->m_parserMap.clear();
}

// Method to register inputs with outputs as pairs
template <typename fPair, typename... nPairs>    
typename std::enable_if<std::is_convertible<fPair, customPair>::type::value, bool>::type
Executer::registerInToOut(fPair firstPair, nPairs... nextPairs)
{
    bool returnVal = true;

    if((firstPair.first) && (firstPair.second))
    {
        m_parserMap[firstPair.first] = firstPair.second;
        returnVal &= this->registerInToOut(std::forward<nPairs>(nextPairs)...);            
    }

    return returnVal;
}

// Method to register inputs with outputs individually
bool Executer::registerInToOut(const absInput* inputPtr, const absOutput* outputPtr)
{
    bool returnVal = false;

    if(inputPtr && outputPtr)
    {
        m_parserMap[inputPtr] = outputPtr;
        returnVal = true;
    }

    return returnVal;
}

// Method to execute the output
bool Executer::executeOutput(const absInput* inputPtr) const
{
    bool returnVal = false;

    if(inputPtr)
    {
        std::unordered_map<const absInput*, const absOutput*>::const_iterator it = m_parserMap.find((absInput*)(inputPtr));

        if(m_parserMap.end() != it)
        {
            returnVal = it->second->executeOutput();
        }
    }

    return returnVal;    
}

// Method to check wether or not the input exists already in the executer
bool Executer::inputExists(const absInput* inputPtr) const
{
    bool returnVal = false;

    if(inputPtr)
    {
        std::unordered_map<const absInput*, const absOutput*>::const_iterator it = m_parserMap.find((inputPtr));

        if(m_parserMap.end() != it)
        {
            returnVal = true;
        }
    }

    return returnVal;
}
