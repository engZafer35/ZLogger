/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 7, 2019 - 7:39:36 AM
* #File Name    : LogLevel.hpp
* #File Path    : /ZCommonLib/Logger/inc/LogLevel.hpp
*
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __LOG_LEVEL_HPP_
#define __LOG_LEVEL_HPP_
/*********************************INCLUDES*************************************/

/******************************MACRO DEFINITIONS*******************************/

/*******************************TYPE DEFINITIONS ******************************/
namespace logger
{
typedef enum _LOG_LEVEL
{
    EN_LOG_LEVEL_NONE = 0,
    EN_LOG_LEVEL_FATAL,
    EN_LOG_LEVEL_ERROR,
    EN_LOG_LEVEL_WARNING,
    EN_LOG_LEVEL_INFO,
    EN_LOG_LEVEL_DEBUG,
    EN_LOG_LEVEL_VERBOSE
}LOG_LEVEL;
}//namespace logger
/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/


#endif /* __LOG_LEVEL_HPP_ */

/********************************* End Of File ********************************/
