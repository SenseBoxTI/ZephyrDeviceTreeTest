cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(sensebox)

MACRO(RECURSE_FILES return_list filter)
    FILE(GLOB_RECURSE new_list ${filter})
    SET(file_list "")
    FOREACH(file_path ${new_list})
        SET(file_list ${file_list} ${file_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES file_list)
    SET(${return_list} ${file_list})
ENDMACRO()

# recursively get all src files
RECURSE_FILES(cpp_file_list src/*.cpp)
RECURSE_FILES(c_file_list src/*.c)

target_sources(app PRIVATE ${cpp_file_list} ${c_file_list})