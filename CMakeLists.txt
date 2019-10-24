cmake_minimum_required(VERSION 3.5.0)

project(MV3D)
message("module path: ${CMAKE_MODULE_PATH}")
find_package(Boost COMPONENTS system filesystem thread REQUIRED)

# Print all environment variables for understanding remote build environment
execute_process(COMMAND "${CMAKE_COMMAND}" "-E" "environment")

set(EXEC_COMMAND uname -s)

execute_process(COMMAND ${EXEC_COMMAND} RESULT_VARIABLE rv)

include_directories(include)
message("gen MVLS")

add_library(MVLS SHARED
        src/max.cpp
	src/fileHandler.cpp
        add.cpp)
set_target_properties(MVLS PROPERTIES SOVERSION 1)
set_target_properties(MVLS PROPERTIES PUBLIC_HEADER include/human.h)
install(TARGETS MVLS
        LIBRARY DESTINATION /usr/lib
        PUBLIC_HEADER DESTINATION /usr/include)

target_link_libraries(MVLS ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})
# add_executable(human human.cc add.cpp src/max.cpp) 
add_executable(human human.cc) 
target_link_libraries(human MVLS)




