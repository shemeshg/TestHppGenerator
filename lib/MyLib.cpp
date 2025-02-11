#line 4 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/MyLib.hpp"
#include <iostream>
#include "MyLib.h"
#include "Shalom.h"

    void say_hello() 
#line 12 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/MyLib.hpp"
{
    Shalom s("Yossi");
    s.say_shalom();    
}

    void say_aloha () 
#line 20 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/MyLib.hpp"
{
    std::cout << "Aloha from MyLib!\n";
}