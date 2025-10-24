#include "SistemaAlquiler.h"
#include <iostream>
using namespace std;

SistemaAlquiler::~SistemaAlquiler() {
    for(auto v : vehiculos) delete v;
}

void SistemaAlquiler::registrarVehiculo(Vehiculo* v) {
    vehiculos.push_back(v);
    cout << "Vehiculo registrado exitosamente." << endl;
}

void SistemaAlquiler::mostrarTodosVehiculos() const {
    cout << "Listado de todos los vehículos:" << endl;
    for(const auto& v : vehiculos) v->mostrarInformacion();
}

void SistemaAlquiler::mostrarVehiculosDisponibles() const {
    cout << "Vehículos disponibles:" << endl;
    for(const auto& v : vehiculos) {
        if(v->estaDisponible()) v->mostrarInformacion();
    }
}

bool SistemaAlquiler::alquilarVehiculo(const string& placa) {
    for(auto& v : vehiculos) {
        if(v->getPlaca() == placa) {
            if(v->estaDisponible()) {
                v->setDisponible(false);
                cout << "Vehículo alquilado exitosamente." << endl;
                return true;
            } else {
                cout << "El vehículo no está disponible." << endl;
                return false;
            }
        }
    }
    cout << "Vehículo no encontrado." << endl;
    return false;
}

bool SistemaAlquiler::devolverVehiculo(const string& placa) {
    for(auto& v : vehiculos) {
        if(v->getPlaca() == placa) {
            if(!v->estaDisponible()) {
                v->setDisponible(true);
                cout << "Vehículo devuelto exitosamente." << endl;
                return true;
            } else {
                cout << "El vehículo ya estaba disponible." << endl;
                return false;
            }
        }
    }
    cout << "Vehículo no encontrado." << endl;
    return false;
}
