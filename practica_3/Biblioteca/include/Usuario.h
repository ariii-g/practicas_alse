#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "Libro.h"

using namespace std;

class Usuario {
protected:
    string nombre;
    string correo;
    int limitePrestamo;
    vector<Libro> librosPrestados;

public:
    Usuario(const string& nombre, const string& c, int limite);
    virtual ~Usuario(); // Declaración del destructor virtual
    string getNombre() const;
    string getCorreo() const;
    int getLimitePrestamo() const;
    int getCantidadLibrosPrestados() const;

    virtual void mostrarInfo() const;

    bool prestarLibro(Libro& libro);
    void devolverLibro(const string& isbn);
};

class Estudiante : public Usuario {
public:
    Estudiante(const string& nombre, const string& c);
};

class Profesor : public Usuario {
public:
    Profesor(const string& nombre, const string& c);
};



#endif