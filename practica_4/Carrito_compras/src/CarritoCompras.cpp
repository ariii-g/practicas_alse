#include "CarritoCompras.h"
#include <iostream>
#include <algorithm>
void CarritoCompras::agregarProducto(const Producto& producto, int cantidad) {
    items.emplace_back(producto, cantidad);
}

void CarritoCompras::eliminarProducto(const std::string& nombre) {
    items.erase(
        std::remove_if(items.begin(), items.end(),
            [&](const ItemCarrito& item) {
                return item.getNombreProducto() == nombre;
            }),
        items.end());
}

double CarritoCompras::calcularTotal() const {
    double total = 0;
    for (const auto& item : items)
        total += item.getSubtotal();
    return total;
}

void CarritoCompras::mostrarCarrito() const {
    for (const auto& item : items)
        std::cout << item.getNombreProducto() << " x"
                  << item.getCantidad()
                  << " = $" << item.getSubtotal() << std::endl;
    std::cout << "Total: $" << calcularTotal() << std::endl;
}
