# Define a custom target to run the shell script

SET(GEN_HPP TRUE)
if(GEN_HPP)
    file(GLOB HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp" "${CMAKE_CURRENT_SOURCE_DIR}/FolderB/*.hpp")
    add_custom_target(run_script ALL
        COMMAND python3 ${CMAKE_SOURCE_DIR}/scripts/parseHpp.py ${CMAKE_SOURCE_DIR}/scripts/hppTemplates.txt ${HEADER_FILES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Running parseHpp shell script")

    # Run a shell script before everything else
    execute_process(
        COMMAND python3 ${CMAKE_SOURCE_DIR}/scripts/parseHpp.py ${CMAKE_SOURCE_DIR}/scripts/hppTemplates.txt ${HEADER_FILES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        RESULT_VARIABLE result
    )

    # Check the result of the script execution
    if(NOT result EQUAL 0)
        message(FATAL_ERROR "Script execution failed with result: ${result}")
    endif()

    # Continue with the rest of your CMake configuration
endif()

set(MyLib_SRCS
    gen/MyLib.h
    gen/MyLib.cpp
    gen/Shalom.h
    gen/Shalom.cpp
    gen/folderb.h 
    gen/folderb.cpp
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

if(GEN_HPP)
    add_dependencies(MyLib run_script)
endif()
