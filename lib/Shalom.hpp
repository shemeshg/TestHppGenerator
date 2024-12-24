//-define-file body gen/Shalom.cpp
//-define-file header gen/Shalom.h
//-only-file header //-
//- #pragma once
//-only-file body //-
//- #include "Shalom.h"
#include <iostream>
//-only-file header
#include <string>
#include <vector>

//-var {PRE} Shalom::
class Shalom
{
   

public:
     std::string name;

    //- {function} 0 0
    Shalom(std::string  popo, int popo2, std::string name = "World")
    //-only-file body
    :name(name)
    {       
        name = name + popo; 
    }

   //- {function} 0 0
    Shalom(std::string name = "koko")
    //-only-file body
    :name(name)
    {                
    }

    //- {function} 0 1
    void say_shalom()
    //-only-file body
    {
        std::cout << "Shalom olam "  << name << ", from MyLib!\n";
    }

    //- {function} 0 1
    void say_bye()
    //-only-file body
    {
        std::cout << "Goodbye " << name << ", from MyLib!\n";
    }

    //- {function} 1 3
    virtual const std::vector<std::string> peopleNames(std::string additionalName)
    //-only-file body
    {
        std::vector<std::string> s = {"aaa", "bbb", additionalName};
        return s;
    }
    //-only-file header
};

