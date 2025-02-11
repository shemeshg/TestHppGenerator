SET(GEN_HPP TRUE)
if(GEN_HPP)
    file(GLOB HPP_GEN_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"  )
    
    set(HPP_GEN_FILES
        ${CMAKE_SOURCE_DIR}/scripts/hppTemplates.txt
        ${HPP_GEN_FILES}
    )
    add_custom_target(run_script ALL
        COMMAND python3 ${CMAKE_SOURCE_DIR}/scripts/parseHpp.py ${HPP_GEN_FILES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/genHpp
        COMMENT "Running parseHpp shell script")

    # Run a shell script before everything else
    execute_process(
        COMMAND python3 ${CMAKE_SOURCE_DIR}/scripts/parseHpp.py ${HPP_GEN_FILES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/genHpp
        RESULT_VARIABLE result
    )

    # Check the result of the script execution
    if(NOT result EQUAL 0)
        message(FATAL_ERROR "Script execution failed with result: ${result}")
    endif()

    # Continue with the rest of your CMake configuration
endif()

set(MyLib_SRCS
    genHpp/MyLib.h
    genHpp/MyLib.cpp
    genHpp/Shalom.h
    genHpp/Shalom.cpp
)

# Declare the library
add_library(MyLib STATIC
    ${MyLib_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(MyLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/genHpp
)