set(MyLib_SRCS
    gen/MyLib.h
    gen/MyLib.cpp
    gen/Shalom.h
    gen/Shalom.cpp
)

# Declare the library
add_library(MyLib STATIC
    ${MyLib_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(MyLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/gen
)