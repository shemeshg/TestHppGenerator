//-define-file body gen/MyLib.cpp 
//-define-file header gen/MyLib.h
//-only-file null
#include "Shalom.hpp"
//-only-file body //-
//- #include "MyLib.h"
//- #include "Shalom.h"
#include <iostream>


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