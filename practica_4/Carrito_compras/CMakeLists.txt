# CMake configuration for Carrito de Compras project
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(CarritoCompras VERSION 1.0 LANGUAGES CXX)

# Estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir directorios de encabezados
include_directories(include)

# Buscar todos los archivos fuente automáticamente
file(GLOB SOURCES
    "src/*.cpp"
    "main.cpp"
)

# Crear el ejecutable
add_executable(carrito ${SOURCES})

# Mensaje informativo al compilar
message(STATUS "Compilando proyecto Carrito de Compras")
message(STATUS "Archivos fuente: ${SOURCES}")
