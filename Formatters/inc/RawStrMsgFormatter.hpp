/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 12, 2019 - 9:24:21 PM
* #File Name    : RawMessageFormatter.hpp
* #File Path    : /ZLogger/Formatters/RawMessageFormatter.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __RAW_FORMATTER_HPP__
#define __RAW_FORMATTER_HPP__
/*********************************INCLUDES*************************************/
#include <iostream>

#include "IFormatter.hpp"
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

class RawFormatter : public IFormatter
{
public:
    virtual ~RawFormatter(void);

    virtual std::string header(void) const
    {
        return "";
    }

    virtual std::string format(const Record &record)
    {
        std::string retStr;

        retStr = record.getMessage();

        return retStr;
    }

    virtual int getFileType(void) const
    {
        return 1;// TODO:
    }
};

}//namespace logger
#endif /* __RAW_MESSAGE_FORMATTER_HPP__ */

/********************************* End Of File ********************************/
