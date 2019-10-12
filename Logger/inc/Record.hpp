/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 4, 2019 - 3:01:12 PM
* #File Name    : Record.hpp
* #File Path    : /ZCommonLib/Logger/Record.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __LOGGER_RECORD_HPP__
#define __LOGGER_RECORD_HPP__
/*********************************INCLUDES*************************************/
#include "GlobalDefinitions.hpp"
#include "LogLevel.hpp"
#include "IRecord.hpp"
#include <iostream>
#include <sstream>
#include <vector>
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/

namespace logger
{


/*for string record*/
inline void operator<<(std::ostringstream &stream, const char *str)
{
    if (nullptr == str)
    {
        str =  "(NULL_STR)";
    }

    std::operator<<(stream, str);
}

/*for string record*/
inline void operator<<(std::ostringstream& stream, const std::string& data)
{
    operator<<(stream, data.c_str());
}

class Record
{
public:
    /** \brief constructor */
    Record(LOG_LEVEL level) : m_level{level}, m_lineNum{0}, m_fileName{NULL_PTR}, m_funcName{NULL_PTR} {};

    /** \brief if user want to store line number, file name and function name, this constructor should be used */
    Record(LOG_LEVEL level, U32 line, const char*fileName, const char*funcName) : \
           m_level{level}, m_lineNum{line}, m_fileName{fileName}, m_funcName{funcName} {};

    /** \brief destructor*/
    virtual ~Record(void){};

    /*
     * \brief get Record class
     * \return Record class reference
     */
    inline Record& ref(void)
    {
        return *this;
    }

    template<typename T>
    Record& operator<<(T &r);

    template<typename T>
    Record& operator<<(const T &r);

    /*
     * \brief store string data
     * \param string data address
     */
    inline Record& operator<<(const char * const p)
    {
        std::cout << "string pointer" << std::endl;

        m_message << p;
        return *this;
    }

    /*
     * \brief () operator using for store array
     * \param address of data
     * \param length
     */
    Record& operator()(const void *ptr, int leng)
    {
        std::cout << "operator ()" << std::endl;

        loadArray(static_cast<const char*>(ptr), leng);
        return *this;
    }

    /**
     * \brief load array which has any type.
     * \note user must send array(pointer)
     * \param starting address of buffer
     * \param length
     */
    template<typename T>
    Record& loadArray(T buff, unsigned int leng)
    {
        std::cout << "Template loadArray" << std::endl;

        for(unsigned int i = 0; i < leng; i++)
        {
            data<T>.push_back(buff + i);
        }

        return *this;
    }

    /**
     * \brief get log level
     * \param log level
     */
    virtual LOG_LEVEL getLogLevel(void) const
    {
        return m_level;
    }

    /**
     * \brief get file name
     * \param string pointer
     */
    virtual const char* getFileName(void) const
    {
        return m_fileName;
    }

    /**
     * \brief get function name
     * \param string pointer
     */
    virtual const char* getFuncName(void) const
    {
        return m_funcName;
    }

    /**
     * \brief get line number
     * \param line number
     */
    virtual U32 getLineNumber(void) const
    {
        return m_lineNum;
    }

    /**
     * \brief get all string message
     * \return string data reference
     */
    virtual const std::ostringstream& getMessage(void) const
    {
        return m_message;
    }

    /**
     * \brief get data vector referance
     * \note  all data stored in pointer type,
     *        so user should invoke this func with related data pointer
     * \return vector reference of stored data
     */
    template<typename T>
    std::vector<T>& getData(void)
    {
        return data<T>;
    }

private:

    template<typename T>
    static std::vector<T> data;

    std::ostringstream m_message; /*!< All string msg will be stored here. */

    U32 m_lineNum;
    LOG_LEVEL m_level;
    const char * const m_fileName;
    const char * const m_funcName;
}; // class Record

/**
 *  \brief Record int number
 *  \tparam int number
 */
template<>
inline Record& Record::operator<< <int>(const int &r)
{
    std::cout << "int number " << std::endl;

    data <int>.push_back(r);
    return *this;
}

/**
 *  \brief Record data which has reference type
 *  \tparam any data type.
 */
template<typename T>
inline Record& Record::operator<<(T &r)
{
    std::cout << "Template referance" << std::endl;

    data<T*>.push_back((T*)&r);
    return *this;
}

/**
 *  \brief Record data which has const reference type
 *  \tparam any const data type
 */
template<typename T>
inline Record& Record::operator<<(const T &r)
{
    std::cout << "Template const referance" << std::endl;

    data<const T*>.push_back((const T*)&r);

    return *this;
}

/**
 * \brief Record string message which has std::string type
 * \tparam std::string class
 */
template<>
inline Record& Record::operator<< <std::string>(std::string &r)
{
    std::cout << "Template string referance " << std::endl;
    m_message << r;
    return *this;
}

//!  All different type will store in this vector.
template<typename T>
std::vector<T> Record::data;

}
#endif /* __LOGGER_RECORD_HPP__ */

/********************************* End Of File ********************************/
