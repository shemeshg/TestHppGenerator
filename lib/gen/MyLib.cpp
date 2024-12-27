#include "MyLib.h"
#include "Shalom.h"
#include "folderb.h"
#include <iostream>
    void say_hello() 
{
    FolderB f("Yossi");
    
    f.say_shalom();    
    f.say_folderb();
}

    void say_aloha () 
{
    std::cout << "Aloha from MyLib!\n";
}

    std::vector<std::string> get_names() 
{
    return {"Yossi", "Moshe", "Dana"};
}