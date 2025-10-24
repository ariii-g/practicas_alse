#include "Biblioteca.h"
#include "Usuario.h"
#include <iostream>
#include <limits>
using namespace std;

Usuario* crearUsuario() {
    string nombre, correo;
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    cout << "Ingrese su correo: ";
    getline(cin, correo);

    if (correo.find("@profe.edu") != string::npos) {
        cout << "Bienvenido Profesor " << nombre << endl;
        return new Profesor(nombre, correo);
    } else if (correo.find("@est.edu") != string::npos) {
        cout << "Bienvenido Estudiante " << nombre << endl;
        return new Estudiante(nombre, correo);
    } else {
        cout << "Correo no valido. Debe ser de tipo profesor (@profe.edu) o estudiante (@est.edu)." << endl;
        return nullptr;
    }
}

int main() {
    Biblioteca Biblio;

    // Agregar algunos libros iniciales
    Biblio.agregarLibro(Libro("C++ Primer", "Lippman", "14114"));
    Biblio.agregarLibro(Libro("Effective Modern C++", "Scott Meyers", "03995"));
    Biblio.agregarLibro(Libro("The C++ Programming Language", "Bjarne Stroustrup", "978032"));

    Usuario* usuario = nullptr;
    int opcion;

    while (true) {
        cout << "\nMenu de la Biblioteca institucional:\n";
        cout << "1. Crear Usuario\n";
        cout << "2. Mostrar Libros\n";
        cout << "3. Mostrar Libros Disponibles\n";
        cout << "4. Prestar Libro\n";
        cout << "5. Devolver Libro\n";
        cout << "6. Salir\n";

        Profesor* prof = dynamic_cast<Profesor*>(usuario);
        if (prof) {
            cout << "7. Agregar Libro\n";
            cout << "8. Eliminar Libro\n";
        }

        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

        switch (opcion) {
            case 1:
                usuario = crearUsuario();
                break;

            case 2:
                Biblio.mostrarLibros();
                break;

            case 3:
                Biblio.mostrarLibrosDisponibles();
                break;

            case 4:
                if (usuario) {
                    string isbn;
                    cout << "Ingrese el ISBN del libro a prestar: ";
                    getline(cin, isbn);
                    Biblio.prestarLibro(isbn);  
                } else {
                    cout << "Primero debe crear un usuario." << endl;
                }
                break;

            case 5:
                if (usuario) {
                    string isbn;
                    cout << "Ingrese el ISBN del libro a devolver: ";
                    getline(cin, isbn);
                    Biblio.devolverLibro(isbn); 
                } else {
                    cout << "Primero debe crear un usuario." << endl;
                }
                break;

            case 6:
                cout << "Saliendo del sistema. Gracias por usar la Biblioteca." << endl;
                delete usuario;
                return 0;

            case 7:
                if (prof) {
                    string titulo, autor, isbn;
                    cout << "Ingrese el titulo del libro: ";
                    getline(cin, titulo);
                    cout << "Ingrese el autor del libro: ";
                    getline(cin, autor);
                    cout << "Ingrese el ISBN del libro: ";
                    getline(cin, isbn);
                    Biblio.agregarLibro(Libro(titulo, autor, isbn));
                } else {
                    cout << "Opcion no valida." << endl;
                }
                break;

            case 8:
                if (prof) {
                    string isbn;
                    cout << "Ingrese el ISBN del libro a eliminar: ";
                    getline(cin, isbn);
                    Biblio.eliminarLibro(isbn);
                } else {
                    cout << "Opcion no valida." << endl;
                }
                break;

            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    }

    return 0;
}
