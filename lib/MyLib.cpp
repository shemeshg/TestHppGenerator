#include <iostream>
#include "MyLib.h"
#include "Shalom.h"

    void say_hello() 
{
    Shalom s("Yossi");
    s.say_shalom();    
}

    void say_aloha () 
{
    std::cout << "Aloha from MyLib!\n";
}