//-define-file body Shalom.cpp
//-define-file header Shalom.h
//-only-file body
#include "Shalom.h"
#include <iostream>
#include <vector>
//-only-file header
#include <string>

//-var {PRE} Shalom
class Shalom
{
    std::string name;

public:
    //-only-file body //-
    //- {PRE}::{NEXT[0:]} :name(name)
    //-only-file header ;
    Shalom(std::string name)
    //-only-file body
    {
    }

    //-only-file body //-
    //- {NEXT[0]} {PRE}::{NEXT[1:]} 
    //-only-file header ;
    void say_shalom()
    //-only-file body
    {
        std::cout << "Shalom " << name << ", from MyLib!\n";
    }

    //-only-file body //-
    //- {NEXT[0]} {PRE}::{NEXT[1:]} 
    //-only-file header ;
    void say_bye()
    //-only-file body
    {
        std::cout << "Goodbye " << name << ", from MyLib!\n";
    }

    //-only-file body //-    
    //- {NEXT[0]} {NEXT[1]} {PRE}::{NEXT[2:]} 
    //-only-file header ;
    const std::vector<std::string> peopleNames(std::string additionalName)
    //-only-file body
    {
        std::vector<std::string> s = {"aaa", "bbb", additionalName};
        return s;
    }
    //-only-file header
};