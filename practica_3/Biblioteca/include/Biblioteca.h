#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <string>
#include <vector>
#include "Libro.h"
using namespace std;

class Biblioteca {
private:
    vector<Libro> libros;

public:
    // Agregar un libro
    void agregarLibro(const Libro& libro);

    // Eliminar un libro por ISBN
    void eliminarLibro(const string& isbn);

    // Mostrar todos los libros
    void mostrarLibros() const;

    // Mostrar solo los disponibles
    void mostrarLibrosDisponibles() const;

    // Prestar y devolver libros
    void prestarLibro(const string& isbn);
    void devolverLibro(const string& isbn);
};

#endif
