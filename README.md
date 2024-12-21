# example generating include and cpp files

```bash
python3 parseHpp.py templates.txt shalom.hpp
```

https://github.com/shemeshg/TestHppGenerator/blob/main/lib/Shalom.hpp

```cpp
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
```