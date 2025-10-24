#include "Auto.h"
#include <iostream>
using namespace std;

Auto::Auto(const string& m, const string& mo, const string& p, int capacidad)
    : Vehiculo(m, mo, p), capacidadPasajeros(capacidad) {}

void Auto::mostrarInformacion() const {
    cout << "Auto - Marca: " << marca << ", Modelo: " << modelo 
         << ", Placa: " << placa 
         << ", Capacidad: " << capacidadPasajeros
         << ", Disponible: " << (disponible ? "Si" : "No") << endl;
}
