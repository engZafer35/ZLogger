/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 7, 2019 - 12:43:43 PM
* #File Name    : IRecord.hpp
* #File Path    : /ZCommonLib/Logger/inc/IRecord.hpp
*
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef LOGGER_INC_IRECORD_HPP_
#define LOGGER_INC_IRECORD_HPP_
/*********************************INCLUDES*************************************/
#include "LogLevel.hpp"
/******************************MACRO DEFINITIONS*******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/
namespace logger
{
class IRecord
{
public:
    virtual ~IRecord(void){}
    virtual LOG_LEVEL getLogLevel(void) const = 0;
    virtual IRecord& ref(void) = 0;
};
}
#endif /* LOGGER_INC_IRECORD_HPP_ */

/********************************* End Of File ********************************/
