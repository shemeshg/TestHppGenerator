//-define-file body MyLib.cpp 
//-define-file header MyLib.h
//-only-file body
#include <iostream>
#include "MyLib.h"
#include "Shalom.h"
//-only-file body //-
//- {NEXT[0:]}
//-only-file header ;
void say_hello()
//-only-file body
{
    Shalom s("Yossi");
    s.say_shalom();    
}
