// See file:///./../Shalom.hpp 
#pragma once
#include <string>
#include <vector>

class Shalom
{
   

public:
     std::string name;

    Shalom(std::string  popo, int popo2, std::string name = "World");
    Shalom(std::string name = "koko 2");
    void say_shalom();
    void say_bye();
    virtual const std::vector<std::string> peopleNames(std::string additionalName);
};

