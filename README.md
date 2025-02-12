# example generating include and cpp files

```bash
python3 parseHpp.py templates.txt shalom.hpp MyLib.hpp
```

## explanation

The trailing `//-` will enable the following line unremarked on destination.
```
//-only-file body //-
//- #include "Shalom.h"
```

Trailing `;`  appends 
```
`//-only-file header ;`
```

Send to the following to null
```
//-only-file null
```

## Examples:

https://github.com/shemeshg/TestHppGenerator/blob/main/lib/Shalom.hpp

https://github.com/shemeshg/TestHppGenerator/blob/main/lib/MyLib.hpp

https://github.com/shemeshg/TestHppGenerator/blob/main/lib/QtQmlExample.hpp

https://github.com/shemeshg/TestHppGenerator/blob/main/lib/templates.txt