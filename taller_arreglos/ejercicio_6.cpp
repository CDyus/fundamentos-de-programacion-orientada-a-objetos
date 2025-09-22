#include <iostream>
#include <algorithm> 
using namespace std;

int main() {


    //==== EJERCCIO 6: DESARROLLA UN PRORGAMA QUE ENCUENTRE LOS ELEMENTOS DUPLICADOS=====
    cout << "6. Desarrolla un programa que encuentre elementos duplicados\n";
    int n;
    cout << "Ingrese la cantidad de elementos del array: ";
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arr[i];
    }

    bool hayDuplicados = false;
    cout << "\nConteo de elementos duplicados:\n";

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) continue; // Ignoramos los elementos duplicados ya encontrados

        int contador = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                contador++;
                arr[j] = -1; /*incrementamos el contador
                y guardamos el elemento duplicado
                para imprimirlo luego*/
            }
        }
        /*si el contador a avanzado imprimimos el elemento
        y la cantidad de veces que se repitio*/
        if (contador > 1) {
            cout << arr[i] << " se repite " << contador << " veces\n";
            hayDuplicados = true;
        }
    }

    if (!hayDuplicados) {
        cout << "No hay elementos duplicados\n";
    }

    // Liberamos la memoria reservada
    delete[] arr;





}