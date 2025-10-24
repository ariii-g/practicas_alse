#ifndef AUTO_H
#define AUTO_H

#include "Vehiculo.h"

class Auto : public Vehiculo {
private:
    int capacidadPasajeros;
public:
    Auto(const string& m, const string& mo, const string& p, int capacidad);
    void mostrarInformacion() const override;
};

#endif
