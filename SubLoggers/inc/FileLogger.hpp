/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 14, 2019 - 4:56:53 PM
* #File Name    : FileLogger.hpp
* #File Path    : /ZLogger/SubLoggers/inc/FileLogger.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __FILE_LOGGER_HPP__
#define __FILE_LOGGER_HPP__
/*********************************INCLUDES*************************************/
#include "GlobalDefinitions.hpp"
#include "Record.hpp"
#include "ISubLogger.hpp"
#include "IFormatter.hpp"
#include "IFileOpr.hpp"
#include "Utility.hpp"

#include <dirent.h>
#include <string.h>
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/
#define FILE_NAME_SEPERATOR "_$"
/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/

namespace zlogger
{

class FileLogger : public ISubLogger
{
public:
    FileLogger(){}
    FileLogger(const char * filePath, const char *fileName, unsigned int fileSize, unsigned int maxFile, IFormatter *formatter, IFileOpr* fileOpr) : \
               m_filePath{filePath}, m_fileName{fileName}, m_fileSize{fileSize}, m_maxFile{maxFile}, m_formatter{formatter}, m_fileOpr{fileOpr} {}

    RETURN_TYPE write(Record &record) override
    {
        MutexLock mutexLock(m_mutex);

        RETURN_TYPE retVal = SUCCESS;

        return retVal;
    }

public:
    int openFile(void)
    {
        int latestFileNum = findLatestFile();

        if (latestFileNum < 0) //create first file
        {
            std::string fullPath;

            fullPath = m_filePath;
            fullPath += m_fileName;


//            std::ofstream file(fullPath);
//            if (file) //file opened
//            {
//
//            }
        }

    }

    //create new file.
    int createNewFile(void);

    int closeFile(void);


    RETURN_TYPE findRawFileName(char *rawName)
    {
        RETURN_TYPE retVal = FAILURE;
        std::string fullName(m_fileName);
        int pos = fullName.find(".");

        if (pos >= 0)
        {
            fullName.copy(rawName, pos, 0);
            retVal = SUCCESS;
        }

        return retVal;
    }

    /**
     * \brief find latest file number.
     * \return if could not be file return FAILURE(-1)
     *
     */
    int findLatestFile(void)
    {
        DIR *dir;
        struct dirent *dirent;
        std::string file;
        int fileNumber = -1;
        int tempCounter = 0;
        int pos, posEnd;
        char fileExtNum[8] = "";
        char rawFileName[128] = "";

        if ((m_filePath != NULL_PTR) || (m_fileName != NULL_PTR))
        {
            dir = opendir(m_filePath);
            if (dir)
            {
                if (SUCCESS == findRawFileName(rawFileName))
                {
                    while (NULL != (dirent = readdir(dir)))
                    {
                        if (DT_REG == dirent->d_type)
                        {
                            file = dirent->d_name;

                            int isCurrectFile = file.find(rawFileName);
                            pos = file.find(FILE_NAME_SEPERATOR);

                            if ( (isCurrectFile >= 0) && (pos > 0))
                            {
                                if ((posEnd = file.find(".", pos)))
                                {
                                    file.copy(fileExtNum, (posEnd-(pos + 2)), pos + 2);
                                    tempCounter = std::atoi(fileExtNum);

                                    if (tempCounter > fileNumber)
                                    {
                                        fileNumber = tempCounter;
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }

        std::cout << "latest file number: " << fileNumber << std::endl;

        return fileNumber;
    }


private:
    unsigned int m_fileSize;
    unsigned int m_maxFile;
    const char   *m_filePath;
    const char   *m_fileName;
    IFormatter   *m_formatter;
    IFileOpr     *m_fileOpr;
    Mutex        m_mutex;
};

}//namespace zlogger

#endif /* __FILE_LOGGER_HPP__ */

/********************************* End Of File ********************************/
