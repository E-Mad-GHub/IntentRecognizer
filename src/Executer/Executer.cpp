
/*! \brief Executer class constructor.
*
*  Constructor
* 
*/
Executer::Executer()
{
    this->m_parserMap.clear();
}

/*! \brief Executer class constructor.
*
*  Copy Constructor
* 
*/
Executer::Executer(Executer& exec)
{
    this->m_parserMap.clear();
    this->m_parserMap = exec.m_parserMap;
}

/*! \brief Executer class constructor.
*
*  Move Constructor
* 
*/
Executer::Executer(Executer&& exec)
{
    this->m_parserMap.clear();
    this->m_parserMap = std::move(exec.m_parserMap);
}

/*! \brief Executer class destructor.
*
*  Destructor
* 
*/
Executer::~Executer()
{
    this->m_parserMap.clear();
}

/*! \brief registerInToOut(...).
*
*  Registers an input to an output
* 
*  @param variadic(firstPair, nextPairs) pairs of input and output pointer.
*  @return true if registration succeeded, false if else.
*/
template <typename fPair, typename... nPairs>    
typename std::enable_if<std::is_convertible<fPair, customPair>::type::value, bool>::type
Executer::registerInToOut(std::shared_ptr<fPair> firstPair, std::shared_ptr<nPairs>... nextPairs)
{
    bool returnVal = true;

    if((firstPair.first) && (firstPair.second))
    {
        m_parserMap[firstPair.first] = firstPair.second;
        returnVal &= this->registerInToOut(std::forward<nPairs>(nextPairs)...);            
    }
    else
    {
        returnVal = false;
    }

    return returnVal;
}

/*! \brief registerInToOut().
*
*  Registers an input to an output individually
* 
*  @param inputPtr input pointer.
*  @param outputPtr output pointer.
*
*  @return true if registration succeeded, false if else.
*/
bool Executer::registerInToOut(const std::shared_ptr<absInput> inputPtr, const std::shared_ptr<absOutput> outputPtr)
{
    bool returnVal = false;
    bool found = false;

    if(inputPtr && outputPtr)
    {
        for (auto &it : m_parserMap)
        {
            if(it.first->matches((const absInput*)inputPtr)) 
            {           
                it.second = outputPtr;
                found = true;
            }
        }

        if(!found)
        {
            m_parserMap[inputPtr] = outputPtr;
        }


        returnVal = true;
    }

    return returnVal;
}

/*! \brief executeOutput().
*
*  Executes a behavior that maps to the given input.
* 
*  @param inputPtr input pointer.
*
*  @return buffer the result of the executed function.
*/
bool Executer::executeOutput(const std::shared_ptr<absInput> inputPtr) const
{
    bool returnVal = false;

    if(inputPtr)
    {        
        for (auto &it : m_parserMap)
        {
            if(it.first->matches(inputPtr)) 
            {
                returnVal = it.second->executeOutput();
            }
        }
    }

    return returnVal;    
}

/*! \brief inputExists().
*
*  Checks whether or not the input existed already.
* 
*  @param inputPtr input pointer.
*
*  @return true if exists, false if else.
*/
bool Executer::inputExists(const std::shared_ptr<absInput> inputPtr) const
{
    bool returnVal = false;

    if(inputPtr)
    {
        for (auto &it : m_parserMap)
        {
            if(it.first->matches(inputPtr)) 
            {
                returnVal = true;
            }
        }
    }

    return returnVal;
}