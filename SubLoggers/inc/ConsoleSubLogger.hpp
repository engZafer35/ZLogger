/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 12, 2019 - 8:59:52 PM
* #File Name    : ConsoleSubLogger.hpp
* #File Path    : /ZLogger/SubLoggers/inc/ConsoleSubLogger.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __CONSOLE_SUBLOGGER_HPP__
#define __CONSOLE_SUBLOGGER_HPP__
/*********************************INCLUDES*************************************/
#include "GlobalDefinitions.hpp"
#include "Logger.hpp"
#include "Record.hpp"
#include "ISubLogger.hpp"
#include "IFormatter.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace zlogger
{
class ConsoleSubLoggeer : public ISubLogger
{

public:

    ConsoleSubLoggeer(IFormatter* formatter) : m_formatter{formatter} {}

    virtual RETURN_TYPE write(Record &record) override
    {
        RETURN_TYPE retVal = SUCCESS;

        setColor(record.getLogLevel());
        std::cout << m_formatter->format(record);
        clearColor();

        return retVal;
    }

private: /******** private functions ********/
    void setColor(LOG_LEVEL level)
    {
        switch (level)
        {
            case EN_LOG_LEVEL_FATAL:
            {
                std::cout << "\x1B[97m\x1B[41m"; // white on red background
                break;
            }

            case EN_LOG_LEVEL_ERROR:
            {
                std::cout << "\x1B[91m"; // red
                break;
            }

            case EN_LOG_LEVEL_WARNING:
            {
                std::cout << "\x1B[93m"; // yellow
                break;
            }

            case EN_LOG_LEVEL_DEBUG:
            case EN_LOG_LEVEL_VERBOSE:
            {
                std::cout << "\x1B[96m"; // cyan
                break;
            }

            default:
                break;
        }
    }

    void clearColor(void)
    {
        std::cout << "\x1B[0m\x1B[0K"; //clear
    }


private:
    IFormatter* m_formatter;

};

}//namespace logger
#endif /* __CONSOLE_SUBLOGGER_HPP__ */

/********************************* End Of File ********************************/
