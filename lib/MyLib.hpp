//-define-file body gen/MyLib.cpp 
//-define-file header gen/MyLib.h
//-only-file header //-
//- #pragma once
//-only-file body //-
//- #include "MyLib.h"
//- #include "Shalom.h"
//- #include "folderb.h"
#include <iostream>
//-only-file null
#include "FolderB/folderb.hpp"
//-only-file header 

//-var {PRE} ""
//- {function} 0 1
void say_hello()
//-only-file body
{
    FolderB f("Yossi");
    
    f.say_shalom();    
    f.say_folderb();
}

//- {function} 0 1
void say_aloha ()
//-only-file body
{
    std::cout << "Aloha from MyLib!\n";
}