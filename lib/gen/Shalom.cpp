#include "Shalom.h"
#include <iostream>
     Shalom::Shalom(std::string popo, int popo2, std::string name ) 
    :name(name)
    {       
        name = name + popo; 
    }

     Shalom::Shalom(std::string name ) 
    :name(name)
    {                
    }

    void Shalom::say_shalom() 
    {
        std::cout << "Shalom olam "  << name << ", from MyLib!\n";
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
