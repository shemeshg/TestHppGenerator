#line 8 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/Shalom.hpp"
#include <string>

#line 11 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/Shalom.hpp"
class Shalom
{
    std::string name;

public:
#line 17 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/Shalom.hpp"
    explicit Shalom(std::string  popo, int popo2,std::string name = "World");
#line 25 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/Shalom.hpp"
    Shalom(std::string name );
#line 32 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/Shalom.hpp"
    void say_shalom();
#line 39 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/Shalom.hpp"
    void say_bye();
#line 46 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/Shalom.hpp"
    const std::vector<std::string> peopleNames(std::string additionalName);
#line 53 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/Shalom.hpp"
};

