#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Producto {
    string nombre;
    double precio;
    int cantidad;
    string categoria;
    string fechaIngreso;

    Producto(string n, double p, int c, string cat, string fecha)
        : nombre(n), precio(p), cantidad(c), categoria(cat), fechaIngreso(fecha) {}

    double valorTotal() const {
        return precio * cantidad;
    }

    void mostrar() const {
        cout << left << setw(12) << nombre
             << setw(10) << precio
             << setw(8) << cantidad
             << setw(15) << categoria
             << setw(12) << fechaIngreso
             << setw(10) << valorTotal()
             << endl;
    }
};

struct Inventario {
    vector<Producto> productos;

    void agregar(const Producto& p) {
        productos.push_back(p);
        cout << "Producto agregado correctamente.\n";
    }

    void mostrar() const {
        if (productos.empty()) {
            cout << "No hay productos en el inventario.\n";
            return;
        }
        cout << left << setw(12) << "Nombre"
             << setw(10) << "Precio"
             << setw(8)  << "Cant"
             << setw(15) << "Categoria"
             << setw(12) << "Ingreso"
             << setw(10) << "Total"
             << endl;
        cout << string(65, '-') << endl;
        for (const auto& p : productos)
            p.mostrar();
    }

    void eliminar(string nombre) {
        auto it = remove_if(productos.begin(), productos.end(),
                            [&](const Producto& p) {
                                return p.nombre == nombre;
                            });
        if (it != productos.end()) {
            productos.erase(it, productos.end());
            cout << "Producto eliminado.\n";
        } else {
            cout << "Producto no encontrado.\n";
        }
    }

    void actualizarStock(string nombre, int cantidadNueva) {
        for (auto& p : productos) {
            if (p.nombre == nombre) {
                p.cantidad = cantidadNueva;
                cout << "Stock actualizado.\n";
                return;
            }
        }
        cout << "Producto no encontrado.\n";
    }

    void buscarPorCategoria(string cat) const {
        cout << "\nProductos en la categoria: " << cat << "\n";
        bool encontrado = false;
        for (const auto& p : productos) {
            if (p.categoria == cat) {
                p.mostrar();
                encontrado = true;
            }
        }
        if (!encontrado)
            cout << "No hay productos en esta categoría.\n";
    }

    double valorTotalInventario() const {
        double total = 0;
        for (const auto& p : productos)
            total += p.valorTotal();
        return total;
    }

    void ordenarPorPrecio() {
        sort(productos.begin(), productos.end(),
             [](const Producto& a, const Producto& b) {
                 return a.precio < b.precio;
             });
        cout << "Productos ordenados por precio ascendente.\n";
    }

    void ordenarPorNombre() {
        sort(productos.begin(), productos.end(),
             [](const Producto& a, const Producto& b) {
                 return a.nombre < b.nombre;
             });
        cout << "Productos ordenados por nombre.\n";
    }
};

int main() {
    //ahora creamos un menu interactivo para hacer el inventario mas divertido
    Inventario tienda;
    int opcion;

    do {
        cout << "\n========= 🏪 MENU INVENTARIO =========\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar todos los productos\n";
        cout << "3. Buscar por categoria\n";
        cout << "4. Actualizar stock\n";
        cout << "5. Eliminar producto\n";
        cout << "6. Ordenar por precio\n";
        cout << "7. Ordenar por nombre\n";
        cout << "8. Ver valor total del inventario\n";
        cout << "9. Salir\n";
        cout << "======================================\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;
        cin.ignore(); // limpiar buffer

        if (opcion == 1) {
            string nombre, categoria, fecha;
            double precio;
            int cantidad;

            cout << "Nombre: "; getline(cin, nombre);
            cout << "Precio: "; cin >> precio;
            cout << "Cantidad: "; cin >> cantidad;
            cin.ignore();
            cout << "Categoria: "; getline(cin, categoria);
            cout << "Fecha de ingreso (YYYY-MM-DD): "; getline(cin, fecha);

            tienda.agregar({nombre, precio, cantidad, categoria, fecha});

        } else if (opcion == 2) {
            tienda.mostrar();

        } else if (opcion == 3) {
            string cat;
            cout << "Categoria a buscar: ";
            getline(cin, cat);
            tienda.buscarPorCategoria(cat);

        } else if (opcion == 4) {
            string nombre;
            int nuevaCantidad;
            cout << "Nombre del producto: ";
            getline(cin, nombre);
            cout << "Nueva cantidad: ";
            cin >> nuevaCantidad;
            tienda.actualizarStock(nombre, nuevaCantidad);

        } else if (opcion == 5) {
            string nombre;
            cout << "Nombre del producto a eliminar: ";
            getline(cin, nombre);
            tienda.eliminar(nombre);

        } else if (opcion == 6) {
            tienda.ordenarPorPrecio();

        } else if (opcion == 7) {
            tienda.ordenarPorNombre();

        } else if (opcion == 8) {
            cout << "💰 Valor total del inventario: $" << tienda.valorTotalInventario() << endl;

        } else if (opcion == 9) {
            cout << "👋 Saliendo del programa...\n";

        } else {
            cout << "⚠️ Opcion no valida.\n";
        }

    } while (opcion != 9);

    return 0;
}
