#ifndef BICICLETA_H
#define BICICLETA_H

#include "Vehiculo.h"

class Bicicleta : public Vehiculo {
private:
    string tipo;
public:
    Bicicleta(const string& m, const string& mo, const string& p, const string& t);
    void mostrarInformacion() const override;
};

#endif
