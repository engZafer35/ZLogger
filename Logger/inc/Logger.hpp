/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 4, 2019 - 2:49:25 PM
* #File Name    : Logger.hpp
* #File Path    : /ZCommonLib/Logger/inc/Logger.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __LOGGER_INC_LOGGER_HPP__
#define __LOGGER_INC_LOGGER_HPP__
/*********************************INCLUDES*************************************/
#include <vector>
#include <iostream>
#include "GlobalDefinitions.hpp"
#include "ISubLogger.hpp"
#include "Singleton.hpp"
#include "LogLevel.hpp"
#include "Record.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/
namespace zlogger
{
#define LOGGER_DEFAULT_ID (0) ///<default logger ID
}
/*******************************TYPE DEFINITIONS ******************************/


/************************* GLOBAL VARIBALE REFERENCES *************************/

/********************************* CLASS **************************************/
namespace zlogger
{

/*
 * \class Logger class
 * \brief Logger class handles logger with send sublogger. This class is formed by the singleton method.
 *        So user just can one Logger class which has same ID. Each different Logger class have to have
 *        different ID.
 *        After class created, user should add sublogger to handle recorded log data.
 */
template <int LoggerID>
class Logger : public Singleton < Logger<LoggerID> >, public ISubLogger
{
public:
    Logger(LOG_LEVEL logLevel);                 /**< Logger costructor*/

    LOG_LEVEL getLogLevel(void) const;          /**< get log level */

    void setLogLevel(LOG_LEVEL level);          /**< set log level */

    bool checkLogLevel(LOG_LEVEL level) const;  /**< compare log level */

    RETURN_TYPE write(Record &record) override; /**< write stored log data with sublogger */

    void operator+=(Record &record);            /**< get Record data */

    Logger<LoggerID> & addSubLogger(ISubLogger *sublogger); /**< add sublogger */

private:
    LOG_LEVEL m_logLevel;
    int m_oggerID;
    std::vector<ISubLogger*> m_subLoggers;
};

template <int LoggerID>
Logger<LoggerID>::Logger(LOG_LEVEL logLevel) : m_logLevel{logLevel}, m_oggerID{LoggerID}
{
    std::cout << "logger created level:" << m_logLevel << std::endl;
}

template <int LoggerID>
inline LOG_LEVEL Logger<LoggerID>::getLogLevel(void) const
{
    return m_logLevel;
}

template <int LoggerID>
inline void Logger<LoggerID>::setLogLevel(LOG_LEVEL level)
{
    m_logLevel = level;
}

template <int LoggerID>
inline bool Logger<LoggerID>::checkLogLevel(LOG_LEVEL level) const
{
    return (m_logLevel <= level);
}

template <int LoggerID>
inline RETURN_TYPE Logger<LoggerID>::write(Record &record)
{
    RETURN_TYPE retVal = SUCCESS;

    if (checkLogLevel(record.getLogLevel()))
    {
        *this += record;
    }
    return retVal;
}

template <int LoggerID>
inline void Logger<LoggerID>::operator+=(Record &record)
{
    std::cout << "logger created ID:" << LoggerID;
    for (std::vector<ISubLogger*>::iterator it = m_subLoggers.begin(); it != m_subLoggers.end(); it++)
    {
        (*it)->write(record);
    }
}

template <int LoggerID>
inline Logger<LoggerID> & Logger<LoggerID>::addSubLogger(ISubLogger *sublogger)
{

    if (nullptr != sublogger && this != sublogger)
    {
        m_subLoggers.push_back(sublogger);
    }

    return *this;
}

/************************* GLOBAL FUNCTION DEFINITIONS ************************/
/**
 * \brief get logger class address(pointer)
 */
template <int LoggerID>
extern inline Logger<LoggerID>* getLogger(void)
{
    return Logger<LoggerID>::getInstance();
}

/**
 * \brief get logger address(pointer) which has default logger ID
 */
Logger<LOGGER_DEFAULT_ID>* getLogger(void);

/**
 * \brieff create a logger with sent id
 * \tparam logger id(integer)
 * \param  logger level
 * \param  subLoger.(it can be file logger, console logger, ext comm line logger, ...)
 * \return logger reference
 */
template < int LoggerID>
extern inline Logger<LoggerID>& loggerInit(LOG_LEVEL level, ISubLogger* sublogger = nullptr)
{
    static Logger<LoggerID> logger(level);
    return logger.addSubLogger(sublogger);
}

/*
 * \brief  create a logger which has default logger ID
 * \param  logger level
 * \return logger reference
 */
Logger<LOGGER_DEFAULT_ID>& loggerInit(LOG_LEVEL level = EN_LOG_LEVEL_VERBOSE);

}//namespace logger


#endif /* __LOGGER_INC_LOGGER_HPP__ */

/********************************* End Of File ********************************/
