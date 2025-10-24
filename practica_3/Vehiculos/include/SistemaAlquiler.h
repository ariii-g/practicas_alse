#ifndef SISTEMAALQUILER_H
#define SISTEMAALQUILER_H

#include <vector>
#include "Vehiculo.h"

class SistemaAlquiler {
private:
    vector<Vehiculo*> vehiculos;
public:
    ~SistemaAlquiler();
    void registrarVehiculo(Vehiculo* v);
    void mostrarTodosVehiculos() const;
    void mostrarVehiculosDisponibles() const;
    bool alquilarVehiculo(const string& placa);
    bool devolverVehiculo(const string& placa);
};

#endif
