#include "Shalom.h"
#include <iostream>
#include <vector>
    Shalom::
    Shalom(std::string  popo, std::string name )   
    :name(name)
    {        
    }

Shalom::Shalom()
    :name(name)
    {                
    }

    void Shalom::say_shalom() 
    {
        std::cout << "Shalom " << name << ", from MyLib!\n";
    }

    void Shalom::say_bye() 
    {
        std::cout << "Goodbye " << name << ", from MyLib!\n";
    }

    const std::vector<std::string> Shalom::peopleNames(std::string additionalName) 
    {
        std::vector<std::string> s = {"aaa", "bbb", additionalName};
        return s;
    }
