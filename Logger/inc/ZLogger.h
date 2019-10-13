/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 12, 2019 - 8:23:20 PM
* #File Name    : ZLogger.h
* #File Path    : /ZLogger/Logger/inc/ZLogger.h
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __LOGGER_INC_ZLOGGER_H__
#define __LOGGER_INC_ZLOGGER_H__
/*********************************INCLUDES*************************************/
#include "Logger.hpp"
#include "Record.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/
namespace logger
{
#define FFL_INFO  __FILE__, __FUNCTION__, __LINE__

#define LOGBIN0()                   (cout << "hello" )
#define LOGBIN1(val)                (*(logger::getLogger())+=logger::Record(logger::EN_LOG_LEVEL_DEBUG, FFL_INFO).ref().loadArray(val, 1))
#define LOGBIN2(arr, leng)          (*(logger::getLogger())+=logger::Record(logger::EN_LOG_LEVEL_DEBUG, FFL_INFO).ref().loadArray(arr, leng))
#define LOGBIN3(arr, leng, ...)     (*(logger::getLogger())) += (logger::Record(logger::EN_LOG_LEVEL_DEBUG, FFL_INFO).ref() << __VA_ARGS__).loadArray(arr, leng)

#define GET_MACRO(_0, _1, _2, _3,NAME,...) NAME
#define LOGBIN(...) GET_MACRO(_0, ##__VA_ARGS__,  LOGBIN3, LOGBIN2, LOGBIN1, LOGBIN0)(__VA_ARGS__)

#define LOG() *(logger::getLogger())+=logger::Record(logger::EN_LOG_LEVEL_DEBUG).ref()

}//namespace logger
/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/

#endif /* __LOGGER_INC_ZLOGGER_H__ */

/********************************* End Of File ********************************/
