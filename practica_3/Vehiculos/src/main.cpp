#include <iostream>
#include "SistemaAlquiler.h"
#include "Auto.h"
#include "Bicicleta.h"
using namespace std;

#include <iostream>
#include "SistemaAlquiler.h"
#include "Auto.h"
#include "Bicicleta.h"

using namespace std;

int main() {
    SistemaAlquiler sistema;
    int opcion;

    
    sistema.registrarVehiculo(new Auto("Toyota", "Corolla", "ABC123", 5));
    sistema.registrarVehiculo(new Auto("Honda", "Civic", "XYZ789", 4));
    sistema.registrarVehiculo(new Bicicleta("Trek", "Marlin 7", "BICI001", "Montaña"));
    sistema.registrarVehiculo(new Bicicleta("Giant", "Escape 3", "BICI002", "Urbana"));

    do {
        cout << "\n--- Sistema de Alquiler de Vehículos ---\n";
        cout << "1. Registrar Auto\n";
        cout << "2. Registrar Bicicleta\n";
        cout << "3. Mostrar todos los vehículos\n";
        cout << "4. Mostrar vehículos disponibles\n";
        cout << "5. Alquilar vehículo\n";
        cout << "6. Devolver vehículo\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: {
                string marca, modelo, placa;
                int capacidad;
                cout << "Marca: "; getline(cin, marca);
                cout << "Modelo: "; getline(cin, modelo);
                cout << "Placa: "; getline(cin, placa);
                cout << "Capacidad pasajeros: "; cin >> capacidad; cin.ignore();
                sistema.registrarVehiculo(new Auto(marca, modelo, placa, capacidad));
                break;
            }
            case 2: {
                string marca, modelo, placa, tipo;
                cout << "Marca: "; getline(cin, marca);
                cout << "Modelo: "; getline(cin, modelo);
                cout << "Placa: "; getline(cin, placa);
                cout << "Tipo de bicicleta: "; getline(cin, tipo);
                sistema.registrarVehiculo(new Bicicleta(marca, modelo, placa, tipo));
                break;
            }
            case 3:
                sistema.mostrarTodosVehiculos();
                break;
            case 4:
                sistema.mostrarVehiculosDisponibles();
                break;
            case 5: {
                string placa;
                cout << "Ingrese la placa del vehículo a alquilar: ";
                getline(cin, placa);
                sistema.alquilarVehiculo(placa);
                break;
            }
            case 6: {
                string placa;
                cout << "Ingrese la placa del vehículo a devolver: ";
                getline(cin, placa);
                sistema.devolverVehiculo(placa);
                break;
            }
            case 7:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }

    } while(opcion != 7);

    return 0;
}
