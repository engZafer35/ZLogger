/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 4, 2019 - 2:55:04 PM
* #File Name    : ISubLogger.hpp
* #File Path    : /ZCommonLib/Logger/inc/ISubLogger.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __LOGGER_INC_ISUBLOGGER_HPP__
#define __LOGGER_INC_ISUBLOGGER_HPP__
/*********************************INCLUDES*************************************/
#include "../../Utility/inc/GlobalDefinitions.hpp"
#include "Record.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace zlogger
{
class ISubLogger
{
public:
    virtual ~ISubLogger(){};
    virtual RETURN_TYPE write(Record &record) = 0;
};

}

#endif /* __LOGGER_INC_ISUBLOGGER_HPP__ */

/********************************* End Of File ********************************/
