#include "Producto.h"
#include <iostream>
 
using namespace std;
 
Producto::Producto(string n, float p, int s, int d) {
    nombre = n;
    precio = p;
    stock = s;
    descuento = d;
}
 
void Producto::actualizarPrecio(float nuevoPrecio) {
    precio = nuevoPrecio;
    cout << "El nuevo precio de " << nombre << " es: $" << precio << endl;
}
 
void Producto::resumenProducto() const {
    cout << "-----------------------------" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: $" << precio << endl;
    cout << "Stock: " << stock << " unidades" << endl;
    cout << "Descuento: " << descuento << "%" << endl;
    cout << "Valor total inventario: $" << consultarValorInventario() << endl;
    cout << "-----------------------------" << endl;
}
 
float Producto::vender(int cantidad) {
    if (cantidad > stock) {
        cout << "No hay suficiente stock para vender " << cantidad
             << " unidades de " << nombre << endl;
        return 0.0;
    }
    stock -= cantidad;
    float precioFinal = precio * (1 - (descuento / 100.0));
    float total = precioFinal * cantidad;
    cout << "Venta realizada: " << cantidad
         << " unidades de " << nombre << " por $" << total << endl;
    return total;
}
 
void Producto::reabastecer(int cantidad) {
    stock += cantidad;
    cout << "Se reabastecieron " << cantidad
         << " unidades de " << nombre << ". Nuevo stock: " << stock << endl;
}
 
float Producto::consultarValorInventario() const {
    float precioFinal = precio * (1 - (descuento / 100.0));
    return precioFinal * stock;
}