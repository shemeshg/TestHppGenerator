#include "folderb.h"
#include <iostream>
     FolderB::FolderB(std::string n ) 
    :Shalom{n}
    {               
    }

    void FolderB::say_folderb() 
    {
        std::cout << "Folder B says "  << name << ", from MyLib!\n";
    }

