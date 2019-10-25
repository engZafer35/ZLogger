/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 14, 2019 - 5:04:53 PM
* #File Name    : IFileOpr.hpp
* #File Path    : /ZLogger/Utility/inc/IFileOpr.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __UTILITY_INC_IFILEOPR_HPP__
#define __UTILITY_INC_IFILEOPR_HPP__
/*********************************INCLUDES*************************************/

/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
/**
 * \brief system file operation interface class
 *
 */
class IFileOpr
{
public:
    virtual ~IFileOpr(void){}

    virtual int open(const char *fileName) = 0;
    virtual int close(int fileID) = 0;
    virtual int write(const void *buff, unsigned int leng, unsigned int timeout) = 0;
    virtual int read(void *buff, unsigned int leng, unsigned int timeout) = 0;
    virtual int rename(const char *name, const char *newName) = 0;
    virtual int seek(int ofset, int position) = 0;
};
#endif /* __UTILITY_INC_IFILEOPR_HPP__ */

/********************************* End Of File ********************************/
