#include "Biblioteca.h"
#include <iostream>
using namespace std;

void Biblioteca::agregarLibro(const Libro& libro) {
    libros.push_back(libro);
    cout << "Libro agregado: " << libro.getTitulo() << endl;
}

void Biblioteca::eliminarLibro(const string& isbn) {
    for (auto it = libros.begin(); it != libros.end(); ++it) {
        if (it->getIsbn() == isbn) {
            cout << "Libro eliminado: " << it->getTitulo() << endl;
            libros.erase(it);
            return;
        }
    }
    cout << "Libro con ISBN " << isbn << " no encontrado." << endl;
}

void Biblioteca::mostrarLibros() const {
    cout << "Libros en la biblioteca:" << endl;
    for (const auto& libro : libros) {
        libro.mostrarInfo();
    }
}

void Biblioteca::mostrarLibrosDisponibles() const {
    cout << "Libros disponibles en la biblioteca:" << endl;
    for (const auto& libro : libros) {
        if (libro.estaDisponible()) {
            libro.mostrarInfo();
        }
    }
}

void Biblioteca::prestarLibro(const string& isbn) {
    for (auto& libro : libros) {
        if (libro.getIsbn() == isbn) {
            if (libro.estaDisponible()) {
                libro.setDisponible(false);
                cout << "Libro prestado: " << libro.getTitulo() << endl;
            } else {
                cout << "El libro '" << libro.getTitulo() << "' ya está prestado." << endl;
            }
            return;
        }
    }
    cout << "Libro con ISBN " << isbn << " no encontrado." << endl;
}

void Biblioteca::devolverLibro(const string& isbn) {
    for (auto& libro : libros) {
        if (libro.getIsbn() == isbn) {
            if (!libro.estaDisponible()) {
                libro.setDisponible(true);
                cout << "Libro devuelto: " << libro.getTitulo() << endl;
            } else {
                cout << "El libro '" << libro.getTitulo() << "' ya estaba disponible." << endl;
            }
            return;
        }
    }
    cout << "Libro con ISBN " << isbn << " no encontrado." << endl;
}
