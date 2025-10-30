/**
 * @file ItemCarrito.h
 * @brief Define la clase ItemCarrito que representa un producto dentro del carrito.
 */

#ifndef ITEMCARRITO_H
#define ITEMCARRITO_H

#include "Producto.h"

/**
 * @class ItemCarrito
 * @brief Representa un producto añadido al carrito con su cantidad.
 */
class ItemCarrito {
private:
    Producto producto;
    int cantidad;

public:
    ItemCarrito(const Producto& producto, int cantidad);
    double getSubtotal() const;
    std::string getNombreProducto() const;
    int getCantidad() const;
};

#endif
