#include "Producto.h"
#include <stdexcept>

Producto::Producto(const std::string& nombre, double precio, int stock)
    : nombre(nombre), precio(precio), stock(stock) {}

std::string Producto::getNombre() const { return nombre; }
double Producto::getPrecio() const { return precio; }
int Producto::getStock() const { return stock; }

void Producto::reducirStock(int cantidad) {
    if (cantidad > stock) throw std::runtime_error("Stock insuficiente");
    stock -= cantidad;
}
