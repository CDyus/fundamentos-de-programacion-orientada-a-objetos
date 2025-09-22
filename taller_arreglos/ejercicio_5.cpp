#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    


    //====== EJERCICIO 5: IMPLEMENTA EL ALGORITMO DE ORDENAMIENTO POR SELECCION ====
    cout << "5. Implementa el algoritmo de ordenamiento por selección\n";

    int n5;
    cout << "Ingrese la cantidad de elementos del array: ";
    cin >> n5;

    int arr5[100]; // array de tamaño máximo 100 (puedes cambiarlo)
    for (int i = 0; i < n5; i++) {
        cout << "Elemento " << i+1 << ": ";
        cin >> arr5[i];
    }

    // ===== ORDENAMIENTO POR SELECCIÓN =====
    for (int i = 0; i < n5 - 1; i++) {
        int indiceMin = i; // asumimos que el menor está en la posición i

        // buscamos el menor en el resto del array
        for (int j = i + 1; j < n5; j++) {
            if (arr5[j] < arr5[indiceMin]) {
                indiceMin = j;
            }
        }

        // intercambiamos si encontramos un elemento menor
        if (indiceMin != i) {
            int temp = arr5[i];
            arr5[i] = arr5[indiceMin];
            arr5[indiceMin] = temp;
        }
    }

    // Mostrar el array ordenado
    cout << "Array ordenado: ";
    for (int i = 0; i < n5; i++) {
        cout << arr5[i] << " ";
    }
    cout << "\n";
    
}