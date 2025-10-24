#include "Libro.h"
#include <iostream>
using namespace std;

Libro::Libro(const string& titulo, const string& autor, const string& isbn, bool disponible)
    : titulo(titulo), autor(autor), isbn(isbn), disponible(disponible) {}  // ✅ respeta el valor pasado

string Libro::getTitulo() const { return titulo; }
string Libro::getAutor() const { return autor; }
string Libro::getIsbn() const { return isbn; }
bool Libro::estaDisponible() const { return disponible; }

void Libro::setDisponible(bool estado) {
    disponible = estado;
}

void Libro::mostrarInfo() const {
    cout << "Título: " << titulo
         << ", Autor: " << autor
         << ", ISBN: " << isbn
         << ", Disponible: " << (disponible ? "Sí" : "No") << endl;
}
