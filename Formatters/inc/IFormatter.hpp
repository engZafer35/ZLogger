/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 12, 2019 - 9:36:55 PM
* #File Name    : IFormatter.hpp
* #File Path    : /ZLogger/Formatters/IFormatter.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __IFORMATTER_HPP__
#define __IFORMATTER_HPP__
/*********************************INCLUDES*************************************/
#include <iostream>
#include "Record.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/
namespace zlogger
{

class IFormatter
{
public:
    virtual ~IFormatter(void){};
    virtual std::string header(void) const = 0;
    virtual std::string format(const Record &record) = 0;
    virtual int getFileType(void) const = 0;
};

}//namespace logger
/********************************* CLASS **************************************/

#endif /* __IFORMATTER_HPP__ */

/********************************* End Of File ********************************/
