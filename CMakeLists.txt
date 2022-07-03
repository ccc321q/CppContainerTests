
cmake_minimum_required(VERSION 3.5.1)
project(DirectoryTest)

#Bring the headers, such as Student.h into the project
include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

#Uses the SOURCES variable, rather than an explicit reference to
#each source file
add_executable(DirectoryTest ${SOURCES})
