/**
 * @file CarritoCompras.h
 * @brief Contiene la definición de la clase CarritoCompras.
 */

#ifndef CARRITOCOMPRAS_H
#define CARRITOCOMPRAS_H

#include <vector>
#include "ItemCarrito.h"

/**
 * @class CarritoCompras
 * @brief Permite agregar, eliminar y calcular el total de productos.
 */
class CarritoCompras {
private:
    std::vector<ItemCarrito> items;

public:
    void agregarProducto(const Producto& producto, int cantidad);
    void eliminarProducto(const std::string& nombre);
    double calcularTotal() const;
    void mostrarCarrito() const;
};

#endif
