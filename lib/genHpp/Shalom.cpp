#line 4 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/Shalom.hpp"
#include "Shalom.h"
#include <iostream>
#include <vector>
   Shalom::Shalom(std::string popo, int popo2,std::string name ) 
#line 19 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/Shalom.hpp"
    :name(name)
    {       
        name = name + popo; 
    }

     Shalom::Shalom(std::string name ) 
#line 27 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/Shalom.hpp"
    :name(name)
    {                
    }

    void Shalom::say_shalom() 
#line 34 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/Shalom.hpp"
    {
        std::cout << "Shalom " << name << ", from MyLib!\n";
    }

    void Shalom::say_bye() 
#line 41 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/Shalom.hpp"
    {
        std::cout << "Goodbye " << name << ", from MyLib!\n";
    }

    const std::vector<std::string> Shalom::peopleNames(std::string additionalName) 
#line 48 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/Shalom.hpp"
    {
        std::vector<std::string> s = {"aaa", "bbb", additionalName};
        return s;
    }
