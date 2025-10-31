#include <iostream>
#include <vector>
#include <fstream>
#include "Producto.h"

using namespace std;

int main() {
    
    vector<Producto> productos = {
        Producto("Laptop", 3500.0, 10, 5),
        Producto("Celular", 2000.0, 20, 10),
        Producto("Audifonos", 150.0, 30, 0)
    };

    cout << "=== INVENTARIO INICIAL ===" << endl;
    for (auto &p : productos) {
        p.resumenProducto();
    }


    cout << "\n=== REALIZANDO VENTAS ===" << endl;
    productos[0].vender(2);  
    productos[1].vender(5);  
    productos[2].vender(10); 


    cout << "\n=== REABASTECIMIENTO ===" << endl;
    productos[0].reabastecer(3);
    productos[2].reabastecer(5);

    cout << "\n=== INVENTARIO FINAL ===" << endl;
    for (auto &p : productos) {
        p.resumenProducto();
    }

    
    ofstream reporte("reporte_inventario.txt");
    if (reporte.is_open()) {
        reporte << "=== REPORTE DE INVENTARIO ===\n";
        for (auto &p : productos) {
            reporte << "Valor total de " << p.consultarValorInventario()
                    << " pesos" << endl;
        }
        reporte.close();
        cout << "\nReporte generado: reporte_inventario.txt" << endl;
    } else {
        cerr << "Error al crear el archivo de reporte." << endl;
    }

    return 0;
}


 