#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    
    //=========EJERCICIO 3: DESARROLLA UN PROGRAMA QUE CALCULE LA TRANSPUESTA DE UNA MATRIZ=====
    cout << "3. Desarrolla un programa que calcule la transpuesta de una matriz\n";

    int filas, columnas;

    cout << "Ingrese el numero de filas: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;
    
    //creo y reservo memoria para la matriz original
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }
    //pido los elementos de la matriz al usuario
    cout << "\nIngrese los elementos de la matriz:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Crear y reservo memoria para la matriz transpuesta
    int** transpuesta = new int*[columnas];
    for (int i = 0; i < columnas; i++) {
        transpuesta[i] = new int[filas];
    }

    // Calcular la matriz transpuesta
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }

    // Mostramos la matriz original
    cout << "\nMatriz original:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    // Mostramos la matriz transpuesta
    cout << "\nMatriz transpuesta:\n";
    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < filas; j++) {
            cout << transpuesta[i][j] << "\t";
        }
        cout << endl;
    }

    // Liberamos la memoria de ambas mamtrices
    for (int i = 0; i < filas; i++) delete[] matriz[i];
    delete[] matriz;

    for (int i = 0; i < columnas; i++) delete[] transpuesta[i];
    delete[] transpuesta;

}