//-define-file body MyLib.cpp 
//-define-file header MyLib.h
//-only-file body
#include <iostream>
#include "MyLib.h"
//- {include-body}
#include "Shalom.hpp" //- #include "Shalom.h"

//-var {PRE} ""
//- {fn}
void say_hello()
//-only-file body
{
    Shalom s("Yossi");
    s.say_shalom();    
}

//- {fn}
void say_aloha ()
//-only-file body
{
    std::cout << "Aloha from MyLib!\n";
}