#include "Vehiculo.h"
#include <iostream>
using namespace std;

Vehiculo::Vehiculo(const string& m, const string& mo, const string& p, bool d)
    : marca(m), modelo(mo), placa(p), disponible(d) {}

string Vehiculo::getPlaca() const {
    return placa;
}

bool Vehiculo::estaDisponible() const {
    return disponible;
}

void Vehiculo::setDisponible(bool estado) {
    disponible = estado;
}

void Vehiculo::mostrarInformacion() const {
    cout << "Marca: " << marca << ", Modelo: " << modelo 
         << ", Placa: " << placa
         << ", Disponible: " << (disponible ? "Si" : "No") << endl;
}
