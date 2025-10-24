#ifndef LIBRO_H
#define LIBRO_H

#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    string isbn;
    bool disponible;

public:
    // Constructor
    Libro(const string& t, const string& a, const string& i, bool d = true);

    // Getters
    string getTitulo() const;
    string getAutor() const;
    string getIsbn() const;
    bool estaDisponible() const;

    // Setters
    void setDisponible(bool d);

    // Mostrar información del libro
    void mostrarInfo() const;
};

#endif
