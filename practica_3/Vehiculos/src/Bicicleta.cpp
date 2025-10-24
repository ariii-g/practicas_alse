#include "Bicicleta.h"
#include <iostream>
using namespace std;

Bicicleta::Bicicleta(const string& m, const string& mo, const string& p, const string& t)
    : Vehiculo(m, mo, p), tipo(t) {}

void Bicicleta::mostrarInformacion() const {
    cout << "Bicicleta - Marca: " << marca << ", Modelo: " << modelo 
         << ", Placa: " << placa 
         << ", Tipo: " << tipo
         << ", Disponible: " << (disponible ? "Si" : "No") << endl;
}
