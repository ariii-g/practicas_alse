#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;
    string placa;
    bool disponible;
public:
    Vehiculo(const string& m, const string& mo, const string& p, bool d = true);
    virtual ~Vehiculo() {}
    string getPlaca() const;
    bool estaDisponible() const;
    void setDisponible(bool estado);
    virtual void mostrarInformacion() const;
};

#endif
