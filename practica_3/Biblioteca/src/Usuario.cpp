#include "Usuario.h"
#include <iostream>

using namespace std;

// Constructor Usuario
Usuario::Usuario(const string& nombre, const string& c, int limite)
    : nombre(nombre), correo(c), limitePrestamo(limite) {}

string Usuario::getNombre() const { return nombre; }
string Usuario::getCorreo() const { return correo; }
int Usuario::getLimitePrestamo() const { return limitePrestamo; }
int Usuario::getCantidadLibrosPrestados() const { return librosPrestados.size(); }

void Usuario::mostrarInfo() const {
    cout << "Nombre: " << nombre << ", Correo: " << correo
         << ", Limite de Prestamo: " << limitePrestamo
         << ", Libros Prestados: " << librosPrestados.size() << endl;
}

bool Usuario::prestarLibro(Libro& libro) {
    if (!libro.estaDisponible()) {
        cout << "El libro " << libro.getTitulo() << " no está disponible para préstamo." << endl;
        return false;
    }

    if (librosPrestados.size() >= limitePrestamo) {
        cout << "El usuario " << nombre << " ha alcanzado el límite de préstamo." << endl;
        return false;
    }

    libro.setDisponible(false);  // Suponiendo que tienes setDisponible()
    librosPrestados.push_back(libro);

    cout << "Libro " << libro.getTitulo() << " prestado a " << nombre << "." << endl;
    return true;
}

void Usuario::devolverLibro(const string& isbn) {
    for (auto it = librosPrestados.begin(); it != librosPrestados.end(); ++it) {
        if (it->getIsbn() == isbn) {
            it->setDisponible(true);  // Suponiendo que tienes setDisponible()
            cout << "Libro " << it->getTitulo() << " devuelto por " << nombre << "." << endl;
            librosPrestados.erase(it);
            return;
        }
    }
    cout << "El usuario " << nombre << " no tiene prestado un libro con ISBN " << isbn << "." << endl;
}

// Constructor Estudiante
Estudiante::Estudiante(const string& nombre, const string& c)
    : Usuario(nombre, c, 3) {}

// Constructor Profesor
Profesor::Profesor(const string& nombre, const string& c)
    : Usuario(nombre, c, 5) {}
Usuario::~Usuario() {} // Definición del destructor virtual (aunque esté vacío)
