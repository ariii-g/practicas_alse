/**
 * @file Usuario.h
 * @brief Define la clase Usuario con historial de compras.
 */

#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "CarritoCompras.h"

/**
 * @class Usuario
 * @brief Representa un cliente con historial de compras.
 */
class Usuario {
private:
    std::string nombre;                  ///< Nombre del usuario
    std::vector<CarritoCompras> historial; ///< Historial de compras

public:
    /**
     * @brief Constructor del usuario.
     * @param nombre Nombre del usuario.
     */
    explicit Usuario(const std::string& nombre);

    /**
     * @brief Guarda una compra realizada.
     * @param carrito El carrito de compras finalizado.
     */
    void realizarCompra(const CarritoCompras& carrito);

    /**
     * @brief Muestra todas las compras del usuario.
     */
    void mostrarHistorial() const;
};

#endif
