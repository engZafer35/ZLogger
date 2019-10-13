/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Oct 12, 2019 - 5:00:44 PM
* #File Name    : empty.cpp 
* #File Path    : /ZLogger/Logger/src/empty.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "Logger.hpp"
/****************************** MACRO DEFINITIONS *****************************/

/********************************* NAME SPACE *********************************/

/******************************* LOCAL CLASSES ********************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/
namespace zlogger
{

/**
 * \brief get logger address(pointer) which has default logger ID
 */
Logger<LOGGER_DEFAULT_ID>* getLogger(void)
{
    return Logger<LOGGER_DEFAULT_ID>::getInstance();
}

/*
 * \brief  create a logger which has default logger ID
 * \param  logger level
 * \return logger reference
 */
Logger<LOGGER_DEFAULT_ID>& loggerInit(LOG_LEVEL level)
{
    return loggerInit<LOGGER_DEFAULT_ID>(level, nullptr /*TODO: load console logger*/);
}

}
/***************************** CLASS VARIABLES ********************************/

/***************************** CLASS PRIVATE METHOD ***************************/

/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/

/******************************** End Of File *********************************/
