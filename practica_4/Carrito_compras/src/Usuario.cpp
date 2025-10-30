#include "Usuario.h"
#include <iostream>

Usuario::Usuario(const std::string& nombre) : nombre(nombre) {}

void Usuario::realizarCompra(const CarritoCompras& carrito) {
    // Copiamos el carrito al historial
    historial.push_back(carrito);
    std::cout << nombre << " ha realizado una compra por $"
              << carrito.calcularTotal() << std::endl;
}

void Usuario::mostrarHistorial() const {
    std::cout << "\nHistorial de compras de " << nombre << ":\n";
    for (size_t i = 0; i < historial.size(); ++i) {
        std::cout << "Compra #" << (i + 1) << ":\n";
        historial[i].mostrarCarrito();
    }
}

