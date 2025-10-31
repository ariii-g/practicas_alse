#ifndef PRODUCTO_H
#define PRODUCTO_H
 
#include <string>
#include <iostream>
 
/**
* @brief Clase que representa un producto.
*/
class Producto {
private:
    std::string nombre;   ///< Nombre del producto
    float precio;         ///< Precio del producto
    int stock;            ///< Cantidad en inventario
    int descuento;        ///< Descuento en porcentaje
 
public:
    /**
     * @brief Constructor que inicializa los atributos del producto.
     * @param n Nombre del producto
     * @param p Precio del producto
     * @param s Stock inicial
     * @param d Descuento aplicado
     */
    Producto(std::string n, float p, int s, int d);
 
    /**
     * @brief Método que actualiza el precio del producto.
     * @param nuevoPrecio Nuevo valor del precio
     */
    void actualizarPrecio(float nuevoPrecio);
 
    /**
     * @brief Muestra todas las características del producto.
     */
    void resumenProducto() const;
 
    /**
     * @brief Disminuye el stock si hay unidades suficientes y retorna el total de la venta.
     * @param cantidad Cantidad de unidades vendidas
     * @return Valor total de la venta (precio con descuento aplicado)
     */
    float vender(int cantidad);
 
    /**
     * @brief Incrementa el stock al reabastecer productos.
     * @param cantidad Cantidad agregada al inventario
     */
    void reabastecer(int cantidad);
 
    /**
     * @brief Devuelve el valor total del inventario (precio * stock con descuento aplicado).
     * @return Valor total del inventario
     */
    float consultarValorInventario() const;
};
 
#endif