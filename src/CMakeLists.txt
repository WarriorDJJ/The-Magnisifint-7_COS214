cmake_minimum_required(VERSION 3.0)

#Set Project Variables#############################################################################################
#Project Name
set(MAIN_PROJECT_NAME COS214_Project)

#Project sub Directory eg. "Program/" or ""(no sub dir)
set(PROJECT_SUB_DIR "")

#Main Run File Name eg. "main.cpp"
set(PROJECT_MAIN_RUN_FILE_NAME "Main.cpp")

#Versioning Start Name eg. "V"(V1, V2, V3), "V "(V 1, V 2, V 3), "Task "(Task 1, Task 2), "V_"(V_1, V_2), "v"(v1, v2)
set(PROJECT_VERSION_NAMING "V") 
########################################################################################################################

project(${MAIN_PROJECT_NAME})
#set(CMAKE_CXX_STANDARD 98)

#Loop Variables#########################################################################################################
file(GLOB_RECURSE source_folders ${PROJECT_SUB_DIR}${PROJECT_VERSION_NAMING}*/${PROJECT_MAIN_RUN_FILE_NAME})
set(LOOP_COUNTER_NUM 1)
########################################################################################################################
foreach(version_num IN LISTS source_folders)
    message(STATUS "Main: ${version_num}")

    #Naming
    message(STATUS "Version: ${LOOP_COUNTER_NUM}")

    set(PROJECT_VERSION_DIR "${PROJECT_VERSION_NAMING}${LOOP_COUNTER_NUM}")

    message(STATUS "Version dir: ${PROJECT_VERSION_DIR}/")

    #File Vars
    file(GLOB_RECURSE sources ${PROJECT_SUB_DIR}${PROJECT_VERSION_DIR}/*.cpp)
    file(GLOB_RECURSE headers ${PROJECT_SUB_DIR}${PROJECT_VERSION_DIR}/*.h)
    set(SUB_PROJECT_NAME "${MAIN_PROJECT_NAME}_${PROJECT_VERSION_DIR}")

    #Executable Creation
    add_executable(${SUB_PROJECT_NAME} ${sources} ${headers})
    message(STATUS "Created Executable: ${SUB_PROJECT_NAME}")

    #Counter Math
    math(EXPR LOOP_COUNTER_NUM ${LOOP_COUNTER_NUM}+1)
endforeach()