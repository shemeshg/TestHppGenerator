#include <string>

class Shalom
{
    std::string name;

public:
    Shalom(std::string  popo, std::string name = "World");
    Shalom();
    void say_shalom();
    void say_bye();
    const std::vector<std::string> peopleNames(std::string additionalName);
};

