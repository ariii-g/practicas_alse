cmake_minimum_required(VERSION 3.10)
project(Vehiculos)

# Usar C++17 (puedes cambiarlo si usas otra versión)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir la carpeta donde están los .h
include_directories(include)

# Agregar los archivos fuente (.cpp)
add_executable(Vehiculos
    src/main.cpp
    src/Auto.cpp
    src/Bicicleta.cpp
    src/SistemaAlquiler.cpp
    src/Vehiculo.cpp
)


