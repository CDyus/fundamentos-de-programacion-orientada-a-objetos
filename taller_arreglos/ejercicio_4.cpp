#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    


    //=====EJERCICIO 4: CREA UN SISTEMA DE INVENTARIO SIMPLE CON ARRAYS=======0
    cout << "4. Crea un sistema de inventario simple con arrays\n";
    
    const int MAX_PRODUCTOS = 100;

    string nombres[MAX_PRODUCTOS];
    int cantidades[MAX_PRODUCTOS];
    float precios[MAX_PRODUCTOS];
    int totalProductos = 0;

    int opcion;
    do {
        cout << "\n=== SISTEMA DE INVENTARIO ===\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar inventario\n";
        cout << "3. Buscar producto\n";
        cout << "4. Actualizar cantidad\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // limpiar buffer de entrada

        switch (opcion) {
            case 1: { // Agregar producto
                if (totalProductos < MAX_PRODUCTOS) {
                    cout << "Ingrese nombre del producto: ";
                    getline(cin, nombres[totalProductos]);

                    cout << "Ingrese cantidad: ";
                    cin >> cantidades[totalProductos];

                    cout << "Ingrese precio: ";
                    cin >> precios[totalProductos];

                    totalProductos++;
                    cout << "Producto agregado con exito!\n";
                } else {
                    cout << "Inventario lleno, no se pueden agregar mas productos.\n";
                }
                break;
            }

            case 2: { // Mostrar inventario
                if (totalProductos == 0) {
                    cout << "El inventario esta vacio.\n";
                } else {
                    cout << "\n=== INVENTARIO ===\n";
                    for (int i = 0; i < totalProductos; i++) {
                        cout << i+1 << ". " << nombres[i] 
                             << " | Cantidad: " << cantidades[i]
                             << " | Precio: $" << precios[i] << endl;
                    }
                }
                break;
            }

            case 3: { // Buscar producto
                if (totalProductos == 0) {
                    cout << "Inventario vacio.\n";
                    break;
                }
                string buscar;
                cout << "Ingrese el nombre del producto a buscar: ";
                getline(cin, buscar);

                bool encontrado = false;
                for (int i = 0; i < totalProductos; i++) {
                    if (nombres[i] == buscar) {
                        cout << "Producto encontrado: "
                             << nombres[i] << " | Cantidad: " 
                             << cantidades[i] << " | Precio: $" 
                             << precios[i] << endl;
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) cout << "Producto no encontrado.\n";
                break;
            }

            case 4: { // Actualizar cantidad
                if (totalProductos == 0) {
                    cout << "Inventario vacio.\n";
                    break;
                }
                string buscar;
                cout << "Ingrese el nombre del producto a actualizar: ";
                getline(cin, buscar);

                bool encontrado = false;
                for (int i = 0; i < totalProductos; i++) {
                    if (nombres[i] == buscar) {
                        cout << "Cantidad actual: " << cantidades[i] << endl;
                        cout << "Ingrese nueva cantidad: ";
                        cin >> cantidades[i];
                        cout << "Cantidad actualizada!\n";
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) cout << "Producto no encontrado.\n";
                break;
            }

            case 5:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }

    } while (opcion != 5);


}