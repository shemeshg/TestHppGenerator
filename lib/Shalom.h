#include <string>

class Shalom
{
    std::string name;

public:
    Shalom(std::string  popo, int popo2,std::string name = "World");
    Shalom(std::string name );
    void say_shalom();
    void say_bye();
    const std::vector<std::string> peopleNames(std::string additionalName);
};

