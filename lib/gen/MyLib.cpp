#include "MyLib.h"
#include "Shalom.h"
#include <iostream>


    void say_hello() 
{
    Shalom s("Yossi");
    s.say_shalom();    
}

    void say_aloha () 
{
    std::cout << "Aloha from MyLib!\n";
}