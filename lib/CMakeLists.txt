SET(GEN_HPP TRUE)
if(GEN_HPP)
    file(GLOB HPP_GEN_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"  )    
    set(HPP_GEN_DEST ${CMAKE_CURRENT_BINARY_DIR}/genHpp)
    make_directory(${HPP_GEN_DEST})
    
    set(HPP_GEN_FILES
        ${CMAKE_SOURCE_DIR}/scripts/hppTemplates.txt
        ${HPP_GEN_FILES}
    )
    

    add_custom_target(run_script ALL
        COMMAND python3 ${CMAKE_SOURCE_DIR}/scripts/parseHpp.py ${HPP_GEN_FILES}
        WORKING_DIRECTORY ${HPP_GEN_DEST}
        COMMENT "Running parseHpp shell script")

    # Run a shell script before everything else
    execute_process(
        COMMAND python3 ${CMAKE_SOURCE_DIR}/scripts/parseHpp.py ${HPP_GEN_FILES}
        WORKING_DIRECTORY ${HPP_GEN_DEST}
        RESULT_VARIABLE result
    )

    # Check the result of the script execution
    if(NOT result EQUAL 0)
        message(FATAL_ERROR "Script execution failed with result: ${result}")
    endif()

    # Continue with the rest of your CMake configuration
endif()

set(MyLib_SRCS
    ${HPP_GEN_DEST}/MyLib.h
    ${HPP_GEN_DEST}/MyLib.cpp
    ${HPP_GEN_DEST}/Shalom.h
    ${HPP_GEN_DEST}/Shalom.cpp
)

# Declare the library
add_library(MyLib STATIC
    ${MyLib_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(MyLib PUBLIC
    ${HPP_GEN_DEST}
)