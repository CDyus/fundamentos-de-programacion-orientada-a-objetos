#include <iostream>
using namespace std;

const int SIZE = 3;

void mostrarTablero(char tablero[SIZE][SIZE]) {
    cout << "\n";
    int num = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tablero[i][j] == ' ')
                cout << " " << num << " ";
            else
                cout << " " << tablero[i][j] << " ";
            if (j < SIZE - 1) cout << "|";
            num++;
        }
        cout << "\n";
        if (i < SIZE - 1) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool verificarGanador(char tablero[SIZE][SIZE], char jugador) {
    for (int i = 0; i < SIZE; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador)
            return true;
        if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)
            return true;
    }
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador)
        return true;
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)
        return true;

    return false;
}

bool tableroLleno(char tablero[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (tablero[i][j] == ' ')
                return false;
    return true;
}

int main() {
    char tablero[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            tablero[i][j] = ' ';

    char jugador = 'X';
    int movimiento;
    bool juegoTerminado = false;

    cout << "=== JUEGO DE TRES EN RAYA ===\n";
    mostrarTablero(tablero);

    while (!juegoTerminado) {
        cout << "Turno del jugador " << jugador << "\n";
        cout << "Seleccione una casilla (1-9): ";
        cin >> movimiento;

        if (movimiento < 1 || movimiento > 9) {
            cout << "Casilla invalida. Intente de nuevo.\n";
            continue;
        }

        int fila = (movimiento - 1) / SIZE;
        int columna = (movimiento - 1) % SIZE;

        if (tablero[fila][columna] != ' ') {
            cout << "Casilla ocupada. Intente de nuevo.\n";
            continue;
        }

        tablero[fila][columna] = jugador;
        mostrarTablero(tablero);

        if (verificarGanador(tablero, jugador)) {
            cout << "¡Jugador " << jugador << " gana!\n";
            juegoTerminado = true;
        } 
        else if (tableroLleno(tablero)) {
            cout << "¡Empate!\n";
            juegoTerminado = true;
        } 
        else {
            jugador = (jugador == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}



//PDTT: este fue el mas dificil de lejos, !pero aprendi mucho haciendolo¡




