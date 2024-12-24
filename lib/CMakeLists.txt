# Define a custom target to run the shell script
add_custom_target(run_script ALL
    COMMAND python3 ${CMAKE_SOURCE_DIR}/scripts/parseHpp.py ${CMAKE_SOURCE_DIR}/scripts/hppTemplates.txt *.hpp
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Running parseHpp shell script"
)


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

# Ensure the script runs before the main build target
add_dependencies(MyLib run_script)
