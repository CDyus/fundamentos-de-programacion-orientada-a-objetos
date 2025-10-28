#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct Producto {
    string nombre;
    double precio;
    int stock;

    // Constructor con valores por defecto
    Producto(string n, double p = 0.0, int s = 0)
        : nombre(n), precio(p), stock(s) {}

    //  Métodos const para no modificar los datos
    bool disponible() const { return stock > 0; }
    bool esValido() const { return !nombre.empty() && precio >= 0; }

    // Sobrecarga de operadores
    bool operator==(const Producto& otro) const {
        // comparación insensible a mayúsculas/minúsculas
        string a = nombre, b = otro.nombre;
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        return a == b;
    }

    bool operator<(const Producto& otro) const {
        if (precio == otro.precio)
            return nombre < otro.nombre;
        return precio < otro.precio;
    }

    // metodo auxiliar para mostrar los productos
    void mostrar() const {
        cout << "Producto: " << nombre
             << " | Precio: $" << precio
             << " | Stock: " << stock
             << (disponible() ? " | Disponible" : " | Agotado")
             << endl;
    }
};

int main() {
    cout << "=== 1. Struct con constructores y valores por defecto ===\n";

    // creamos 3 productos con distintas caracteristicas
    Producto p1("Manzanas");
    Producto p2("Peras", 2.5);
    Producto p3("Bananas", 2.5, 50);

    p1.mostrar();
    p2.mostrar();
    p3.mostrar();

    cout << "\n=== 2. Validación y filtrado ===\n";

    vector<Producto> inventario = {
        p1, p2, p3,
        {"", 3.0, 10},       // si el nombre esta  vacío el producto es inválido
        {"Duraznos", -1.0, 5} // si el precio es negativo el producto es inválido
    };

    // Filtramos los productos no validos
    inventario.erase(
        remove_if(inventario.begin(), inventario.end(),
                  [](const Producto& p){ return !p.esValido(); }),
        inventario.end()
    );

    for (const auto& p : inventario) p.mostrar();

    cout << "\n=== 3. Ordenar y buscar ===\n";

    sort(inventario.begin(), inventario.end());
    for (const auto& p : inventario) p.mostrar();

    // Buscando productos sin importar las mayusculas
    Producto buscado("sandias");
    auto it = find(inventario.begin(), inventario.end(), buscado);
    if (it != inventario.end())
        cout << "\nEncontrado: " << it->nombre << endl;
    else
        cout << "\nNo encontrado.\n";

    return 0;
}

















