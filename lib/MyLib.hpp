//-define-file body MyLib.cpp 
//-define-file header MyLib.h
//-only-file body
#include <iostream>
#include "MyLib.h"
#include "Shalom.h"

//-var {PRE} ""
//- {function}
void say_hello()
//-only-file body
{
    Shalom s("Yossi");
    s.say_shalom();    
}

//- {function}
void say_aloha ()
//-only-file body
{
    std::cout << "Aloha from MyLib!\n";
}