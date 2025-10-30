/**
 * @file Producto.h
 * @brief Define la clase Producto que representa un artículo en la tienda.
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

/**
 * @class Producto
 * @brief Representa un producto disponible en la tienda.
 */
class Producto {
private:
    std::string nombre; ///< Nombre del producto.
    double precio;      ///< Precio unitario.
    int stock;          ///< Unidades disponibles en inventario.

public:
    Producto(const std::string& nombre, double precio, int stock);

    std::string getNombre() const;
    double getPrecio() const;
    int getStock() const;

    void reducirStock(int cantidad);
};

#endif
