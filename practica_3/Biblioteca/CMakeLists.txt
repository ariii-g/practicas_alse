cmake_minimum_required(VERSION 3.28)
project(SistemaBiblioteca)
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
 
include_directories(include)
 
add_executable(SistemaBiblioteca
    src/main.cpp
    src/Libro.cpp
    src/Biblioteca.cpp
    src/Usuario.cpp
)
