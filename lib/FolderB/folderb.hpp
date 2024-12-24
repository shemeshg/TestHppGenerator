#include "../Shalom.hpp"
//-define-file body gen/folderb.cpp
//-define-file header gen/folderb.h
//-only-file header //-
//- #pragma once
//- #include "Shalom.h"
//-only-file body //-
//- #include "folderb.h"
//- #include <iostream>
//-only-file header 

//-var {PRE} FolderB::
class FolderB: public Shalom
{
//    std::string name;

public:


   //- {function} 0 0
    FolderB(std::string n = "koko")
    //-only-file body
    :Shalom{n}
    {               
    }

    //- {function} 0 1
    void say_folderb()
    //-only-file body
    {
        std::cout << "Folder B says "  << name << ", from MyLib!\n";
    }

    //-only-file header
};