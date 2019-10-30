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
#include <fstream>
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/
#define FILE_NAME_SEPERATOR "_"
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
    FileLogger(const char * filePath, const char *fileName, U32 fileSize, S32 maxFile, IFormatter *formatter, IFileOpr* fileOpr) : \
               m_filePath{filePath}, m_fileName{fileName}, m_fileSize{fileSize}, m_maxFile{maxFile}, m_formatter{formatter}, m_fileOpr{fileOpr}, \
               isFileOpened{FALSE} {}

    ~FileLogger(void)
    {
        closeFile(m_file);
    }

    RETURN_STATUS write(Record &record) override
    {
        MutexLock mutexLock(m_mutex);
        RETURN_STATUS retVal = SUCCESS;

        if (FALSE == isFileOpened)
        {
            if (SUCCESS == openFile())
            {
                isFileOpened = TRUE;
            }
        }

        if (TRUE == isFileOpened)
        {
            std::string str = m_formatter->format(record);
            m_file.write(str.c_str(), str.size());
        }

        return retVal;
    }

public:

    BOOL isFileFull(std::ofstream &rFile)
    {
        BOOL retVal = FALSE;
        if (rFile.tellp() >= m_fileSize)
        {
            retVal = TRUE;
        }

        return retVal;
    }

    RETURN_STATUS openFile(void)
    {
        RETURN_STATUS retVal = FAILURE;
        S32 lastFileNum = findLatestFile();

        if ((lastFileNum < 0) || (lastFileNum > m_maxFile))
        {
            //create first file.
            m_currFileName  = m_filePath;
            m_currFileName += "0_";
            m_currFileName += m_fileName;

            //open first file or open first file again(max file number)
            m_file.open(m_currFileName, std::ofstream::out);
        }
        else
        {
            //open file in append mode.
            m_file.open(m_currFileName, std::ofstream::out | std::ofstream::app);

            if (TRUE == isFileFull(m_file))
            {
                closeFile(m_file);

                m_currFileName.clear();
                m_currFileName  = m_filePath;

                if ((lastFileNum + 1) > m_maxFile)
                {
                    //create first file.
                    m_currFileName += "0_";
                }
                else
                {
                    //TODO: convert int to  string lastFileNum
                    m_currFileName += std::to_string(lastFileNum + 1);
                    m_currFileName += "_";
                }

                m_currFileName += m_fileName;

                //open file by new file
                m_file.open(m_currFileName, std::ofstream::out);
            }
        }

        if (m_file) //file opened
        {
            retVal = SUCCESS;
        }

        return retVal;
    }

    //create new file.
    void createNewFileName(const std::string &oldFileName, std::string &setNewFileName)
    {

    }

    RETURN_STATUS closeFile(std::ofstream &file)
    {
        if (file) //file opened
        {
            file.close();
        }

        return SUCCESS;
    }

    /**
     * \brief find latest file number.
     * \return if could not be file return FAILURE(-1)
     *
     */
    S32 findLatestFile(void)
    {
        DIR *dir;
        struct dirent *dirent;
        std::string file;
        std::string tempFile;
        int fileNumber = -1;
        int tempCounter = 0;
        int pos;
        char fileExtNum[8] = "";

        if ((m_filePath != NULL_PTR) || (m_fileName != NULL_PTR))
        {
            dir = ::opendir(m_filePath);
            if (dir)
            {
                while (NULL != (dirent = ::readdir(dir))) //scan all files to find correct file
                {
                    if (::DT_REG == dirent->d_type) //just handle regular files
                    {
                        file = dirent->d_name;

                        int isMyFile = file.find(m_fileName);
                        if ( isMyFile > 0) //check fileName
                        {
                            pos = file.find(FILE_NAME_SEPERATOR);
                            if (pos > 0)
                            {
                                file.copy(fileExtNum, pos, 0);
                                tempCounter = std::atoi(fileExtNum);

                                if (tempCounter > fileNumber)
                                {
                                    fileNumber = tempCounter;
                                    tempFile = file;
                                }
                            }
                        }
                    }
                }

                if (fileNumber > -1)
                {
                    m_currFileName  = m_filePath;
                    m_currFileName += tempFile.c_str();
                }

                ::closedir(dir);
            }
        }

        return fileNumber;
    }


private:
    U32 m_fileSize;
    S32 m_maxFile;
    BOOL isFileOpened;
    std::ofstream m_file;
    const char   *m_filePath;
    const char   *m_fileName;
    std::string   m_currFileName;
    IFormatter   *m_formatter;
    IFileOpr     *m_fileOpr;
    Mutex        m_mutex;
};

}//namespace zlogger

#endif /* __FILE_LOGGER_HPP__ */

/********************************* End Of File ********************************/
