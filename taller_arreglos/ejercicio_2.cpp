#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    

    //=======EJERCICIO 2: IMPLEMENTA LA BUSQUEDA BINARIA EN UN ARRAY ORDENADO=======
    cout << "2. Implementa la búsqueda binaria en un array ordenado\n";

    int nn, x;

    cout << "Ingrese la cantidad de elementos del array: ";
    cin >> nn;

    int* arr2 = new int[nn];

    cout << "\nIngrese los elementos:\n";
    for (int i = 0; i < nn; i++) {
        cout << "Elemento " << i+1 << ": ";
        cin >> arr2[i];
    }

    sort(arr2, arr2 + nn);

    cout << "\nArray ordenado: ";
    for (int i = 0; i < nn; i++) cout << arr2[i] << " ";
    cout << "\n";

    // le pido al ususario que ingrese el elemento que buscaremos
    cout << "\nIngrese el numero que desea buscar: ";
    cin >> x;



    int inicio = 0, fin = nn - 1;
    bool encontrado = false;
    int posicion = -1;
    

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;

        if (arr2[medio] == x) {
            encontrado = true;
            posicion = medio;
            break; // paramos el proceso si encontramos el elemento
        }
        else if (arr2[medio] < x) {
            inicio = medio + 1; // buscamos el elemento  en la mitad derecha del array
        }
        else {
            fin = medio - 1; // buscamos el elemento en la mitad izquierda del array
        }
    }

    // mostramos el resultado de la busqueda binaria
    if (encontrado) {
        cout << "\nEl elemento se encontro en la posicion " << posicion << "\n";
    } else {
        cout << "\nEl elemento NO fue encontrado en el array" << "\n";
    }

    delete[] arr2;
}