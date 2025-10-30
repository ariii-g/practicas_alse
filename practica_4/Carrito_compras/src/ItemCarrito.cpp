#include "ItemCarrito.h"

ItemCarrito::ItemCarrito(const Producto& producto, int cantidad)
    : producto(producto), cantidad(cantidad) {}

double ItemCarrito::getSubtotal() const {
    return producto.getPrecio() * cantidad;
}

std::string ItemCarrito::getNombreProducto() const {
    return producto.getNombre();
}

int ItemCarrito::getCantidad() const {
    return cantidad;
}
