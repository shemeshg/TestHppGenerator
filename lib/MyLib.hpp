//-define-file body gen/MyLib.cpp 
//-define-file header gen/MyLib.h
//- {link_back} "../MyLib.hpp"
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
#include <vector>
#include <string>

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

//- {function} 0 1
std::vector<std::string> get_names()
//-only-file body
{
    return {"Yossi", "Moshe", "Dana"};
}