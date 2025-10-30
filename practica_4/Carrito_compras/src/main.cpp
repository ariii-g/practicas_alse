#include <iostream>
#include <string>
#include "Producto.h"
#include "CarritoCompras.h"
#include "Usuario.h"

int main() {
    std::cout << "=== Sistema de Carrito de Compras ===\n\n";

    // Inventario predefinido
    std::vector<Producto> inventario = {
        Producto("Laptop", 1200.0, 5),
        Producto("Mouse", 25.0, 30),
        Producto("Teclado", 45.0, 20),
        Producto("Monitor", 300.0, 10),
        Producto("USB 32GB", 15.0, 50)
    };

    CarritoCompras carrito;
    bool salir = false;

    while (!salir) {
        std::cout << "\n--- MENU PRINCIPAL ---\n";
        std::cout << "1. Ver productos disponibles\n";
        std::cout << "2. Agregar producto al carrito\n";
        std::cout << "3. Eliminar producto del carrito\n";
        std::cout << "4. Ver carrito y total\n";
        std::cout << "5. Finalizar compra\n";
        std::cout << "Seleccione una opción: ";

        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::cout << "\n--- Productos disponibles ---\n";
                for (size_t i = 0; i < inventario.size(); ++i) {
                    std::cout << i + 1 << ". " << inventario[i].getNombre()
                              << " - $" << inventario[i].getPrecio()
                              << " (Stock: " << inventario[i].getStock() << ")\n";
                }
                break;
            }

            case 2: {
                int num, cantidad;
                std::cout << "\nIngrese el número del producto que desea agregar: ";
                std::cin >> num;
                std::cout << "Cantidad: ";
                std::cin >> cantidad;

                if (num > 0 && num <= (int)inventario.size()) {
                    try {
                        inventario[num - 1].reducirStock(cantidad);
                        carrito.agregarProducto(inventario[num - 1], cantidad);
                        std::cout << "Producto agregado al carrito.\n";
                    } catch (const std::exception& e) {
                        std::cout << "Error: " << e.what() << std::endl;
                    }
                } else {
                    std::cout << "Opción no válida.\n";
                }
                break;
            }

            case 3: {
                std::string nombre;
                std::cout << "\nIngrese el nombre del producto a eliminar: ";
                std::cin >> nombre;
                carrito.eliminarProducto(nombre);
                std::cout << "Producto eliminado del carrito (si existía).\n";
                break;
            }

            case 4: {
                std::cout << "\n--- Carrito actual ---\n";
                carrito.mostrarCarrito();
                std::cout << "Total a pagar: $" << carrito.calcularTotal() << "\n";
                break;
            }

            case 5: {
                std::string nombreUsuario;
                std::cout << "\nIngrese su nombre para finalizar la compra: ";
                std::cin >> nombreUsuario;

                Usuario usuario(nombreUsuario);
                usuario.realizarCompra(carrito);

                std::cout << "\n--- Historial de compras ---\n";
                usuario.mostrarHistorial();

                std::cout << "\nGracias por su compra.\n";
                salir = true;
                break;
            }

            default:
                std::cout << "Opción no válida.\n";
                break;
        }
    }

    return 0;
}
