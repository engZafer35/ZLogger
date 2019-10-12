/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 4, 2019 - 1:36:43 PM
* #File Name    : Singleton.hpp
* #File Path    : /ZCommonLib/Utility/Singleton.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __UTILITY_SINGLETON_HPP__
#define __UTILITY_SINGLETON_HPP__
/*********************************INCLUDES*************************************/
#include "GlobalDefinitions.hpp"
#include <iostream>
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/


class NonCopyable
{
protected:
    NonCopyable(void){}

private:
    NonCopyable(const NonCopyable&);
    NonCopyable& operator=(const NonCopyable&);
};
/********************************* CLASS **************************************/

template<class T>
class Singleton : NonCopyable
{
public:
    Singleton()
    {
        if(nullptr == m_instance)
        {
            m_instance = static_cast<T*>(this);
        }
    }

    ~Singleton()
    {
        if(nullptr != m_instance)
        {
            m_instance = nullptr;
        }
    }

    static T* getInstance()
    {
        if (m_instance == nullptr)
            std::cout << " hopp null" << std::endl;
        return m_instance;
    }

private:
    static T* m_instance;
};

template<class T>
T* Singleton<T>::m_instance = nullptr;


#endif /* __UTILITY_SINGLETON_HPP__ */

/********************************* End Of File ********************************/
