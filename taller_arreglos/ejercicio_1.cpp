#include <iostream>
#include <algorithm>  
using namespace std;

int main() {
    int n;

    cout << "Ingrese la cantidad de elementos del array: ";
    cin >> n;

    // Reservarmos memoria para el array
    int* arr = new int[n];

    // Le piedo al usuario que ingrese los elementos del array
    cout << "\nIngrese los elementos:\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i+1 << ": ";
        cin >> arr[i];
    }

    // Ordeno el array de menor a mayor
    sort(arr, arr + n);

    // Calcular mediana
    double mediana;
    if (n % 2 == 1) {
        // Si el tamaño del array es impar, tomamos el elemento del centro
        mediana = arr[n / 2];
    } else {
        // Si es par, tomamos el promedio de los dos elementos del centro
        mediana = (arr[(n / 2) - 1] + arr[n / 2]) / 2.0;
    }

    // Mostramos el array ordenado
    cout << "\nArray ordenado de menor a mayor: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    //mostramos el resultado de la mediana
    cout << "\nLa mediana del array es: " << mediana << "\n";

    // Libero la memoria del "new"
    delete[] arr;
    
    
}