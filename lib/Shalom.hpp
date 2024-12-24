//-define-file body gen/Shalom.cpp
//-define-file header gen/Shalom.h
//-only-file body //-
//- #include "Shalom.h"
#include <iostream>
#include <vector>
//-only-file header
#include <string>

//-var {PRE} Shalom::
class Shalom
{
    std::string name;

public:
    //-only-file body //-
    //- {PRE}
    //- Shalom(std::string  popo, int popo2, std::string name )   
    //-only-file header ;
    Shalom(std::string  popo, int popo2,std::string name = "World")
    //-only-file body
    :name(name)
    {       
        name = name + popo; 
    }

   //- {function} 0
    Shalom(std::string name )
    //-only-file body
    :name(name)
    {                
    }

    //- {function} 1
    void say_shalom()
    //-only-file body
    {
        std::cout << "Shalom " << name << ", from MyLib!\n";
    }

    //- {function} 1
    void say_bye()
    //-only-file body
    {
        std::cout << "Goodbye " << name << ", from MyLib!\n";
    }

    //- {function} 2
    const std::vector<std::string> peopleNames(std::string additionalName)
    //-only-file body
    {
        std::vector<std::string> s = {"aaa", "bbb", additionalName};
        return s;
    }
    //-only-file header
};

