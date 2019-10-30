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
namespace zlogger
{

#define FFL_INFO  __FILE__, __FUNCTION__, __LINE__

#define LOGBIN0()                   (cout << "hello" )
#define LOGBIN1(val)                (*(zlogger::getLogger())+=zlogger::Record(zlogger::EN_LOG_LEVEL_DEBUG, FFL_INFO).ref().loadArray(val, 1))
#define LOGBIN2(arr, leng)          (*(zlogger::getLogger())+=zlogger::Record(zlogger::EN_LOG_LEVEL_DEBUG, FFL_INFO).ref().loadArray(arr, leng))
#define LOGBIN3(arr, leng, ...)     (*(zlogger::getLogger())) += (zlogger::Record(zlogger::EN_LOG_LEVEL_DEBUG, FFL_INFO).ref() << __VA_ARGS__).loadArray(arr, leng)

#define GET_MACRO(_0, _1, _2, _3,NAME,...) NAME
#define LOGBIN(...) GET_MACRO(_0, ##__VA_ARGS__,  LOGBIN3, LOGBIN2, LOGBIN1, LOGBIN0)(__VA_ARGS__)

#define ZLOG_(loggerID, logLevel)   (*(zlogger::getLogger<loggerID>()))+=zlogger::Record(logLevel, FFL_INFO).ref()

#define ZLOG                        ZLOG_(LOGGER_DEFAULT_ID, zlogger::EN_LOG_LEVEL_DEBUG)

#define ZLOGV_(loggerID)            ZLOG_(loggerID, zlogger::EN_LOG_LEVEL_VERBOSE)
#define ZLOGD_(loggerID)            ZLOG_(loggerID, zlogger::EN_LOG_LEVEL_DEBUG)
#define ZLOGW_(loggerID)            ZLOG_(loggerID, zlogger::EN_LOG_LEVEL_WARNING)
#define ZLOGE_(loggerID)            ZLOG_(loggerID, zlogger::EN_LOG_LEVEL_ERROR)
#define ZLOGF_(loggerID)            ZLOG_(loggerID, zlogger::EN_LOG_LEVEL_FATAL)
#define ZLOGN_(loggerID)            ZLOG_(loggerID, zlogger::EN_LOG_LEVEL_NONE)

#define ZLOGV                       ZLOGV_( LOGGER_DEFAULT_ID)
#define ZLOGD                       ZLOGD_( LOGGER_DEFAULT_ID)
#define ZLOGW                       ZLOGW_( LOGGER_DEFAULT_ID)
#define ZLOGE                       ZLOGE_( LOGGER_DEFAULT_ID)
#define ZLOGF                       ZLOGF_( LOGGER_DEFAULT_ID)
#define ZLOGN                       ZLOGN_( LOGGER_DEFAULT_ID)

#define ZLOGV_ID(loggerID)          ZLOGV_( loggerID)
#define ZLOGD_ID(loggerID)          ZLOGD_( loggerID)
#define ZLOGW_ID(loggerID)          ZLOGW_( loggerID)
#define ZLOGE_ID(loggerID)          ZLOGE_( loggerID)
#define ZLOGF_ID(loggerID)          ZLOGF_( loggerID)
#define ZLOGN_ID(loggerID)          ZLOGN_( loggerID)

#define ZLOG_CONDITION(condition, logLevel, loggerID)   if (!(condition)) {;} else ZLOG_(loggerID, logLevel)

#define ZLOGV_IF(condition)                     ZLOG_CONDITION(condition, zlogger::EN_LOG_LEVEL_VERBOSE, LOGGER_DEFAULT_ID)
#define ZLOGD_IF(condition)                     ZLOG_CONDITION(condition, zlogger::EN_LOG_LEVEL_DEBUG, LOGGER_DEFAULT_ID)
#define ZLOGW_IF(condition)                     ZLOG_CONDITION(condition, zlogger::EN_LOG_LEVEL_WARNING, LOGGER_DEFAULT_ID)
#define ZLOGE_IF(condition)                     ZLOG_CONDITION(condition, zlogger::EN_LOG_LEVEL_ERROR, LOGGER_DEFAULT_ID)
#define ZLOGF_IF(condition)                     ZLOG_CONDITION(condition, zlogger::EN_LOG_LEVEL_FATAL, LOGGER_DEFAULT_ID)
#define ZLOGN_IF(condition)                     ZLOG_CONDITION(condition, zlogger::EN_LOG_LEVEL_NONE, LOGGER_DEFAULT_ID)

#define ZLOGV_IF_ID(condition, loggerID)        ZLOG_CONDITION(condition, zlogger::EN_LOG_LEVEL_VERBOSE, loggerID)
#define ZLOGD_IF_ID(condition, loggerID)        ZLOG_CONDITION(condition, zlogger::EN_LOG_LEVEL_DEBUG, loggerID)
#define ZLOGW_IF_ID(condition, loggerID)        ZLOG_CONDITION(condition, zlogger::EN_LOG_LEVEL_WARNING, loggerID)
#define ZLOGE_IF_ID(condition, loggerID)        ZLOG_CONDITION(condition, zlogger::EN_LOG_LEVEL_ERROR, loggerID)
#define ZLOGF_IF_ID(condition, loggerID)        ZLOG_CONDITION(condition, zlogger::EN_LOG_LEVEL_FATAL, loggerID)
#define ZLOGN_IF_ID(condition, loggerID)        ZLOG_CONDITION(condition, zlogger::EN_LOG_LEVEL_NONE, loggerID)

}//namespace logger
/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/

#endif /* __LOGGER_INC_ZLOGGER_H__ */

/********************************* End Of File ********************************/
