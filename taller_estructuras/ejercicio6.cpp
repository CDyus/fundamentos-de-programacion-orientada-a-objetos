#include <iostream>
#include <numeric> 
using namespace std;

// Estructura para representar una fracción
struct Fraccion {
    int num, den;

    // Constructor
    Fraccion(int n = 0, int d = 1) {
        num = n;
        den = (d == 0) ? 1 : d;
        simplificar();
    }

    // Simplificar fracción
    void simplificar() {
        int g = gcd(num, den);
        num /= g;
        den /= g;
        if (den < 0) { 
            num *= -1;
            den *= -1;
        }
    }

    // Mostrar fracción
    void mostrar() const {
        cout << num << "/" << den;
    }

    // Operaciones básicas
    Fraccion operator+(const Fraccion& f) const {
        return Fraccion(num * f.den + f.num * den, den * f.den);
    }
    Fraccion operator-(const Fraccion& f) const {
        return Fraccion(num * f.den - f.num * den, den * f.den);
    }
    Fraccion operator*(const Fraccion& f) const {
        return Fraccion(num * f.num, den * f.den);
    }
    Fraccion operator/(const Fraccion& f) const {
        return Fraccion(num * f.den, den * f.num);
    }
};

int main() {
    Fraccion f1, f2, resultado;
    int opcion;
    bool salir = false;

    while (!salir) {
        cout << "\n====== MENU DE FRACCIONES ======\n";
        cout << "1. Ingresar primera fraccion\n";
        cout << "2. Ingresar segunda fraccion\n";
        cout << "3. Sumar\n";
        cout << "4. Restar\n";
        cout << "5. Multiplicar\n";
        cout << "6. Dividir\n";
        cout << "7. Mostrar fracciones\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese numerador y denominador de la primera fraccion: ";
                cin >> f1.num >> f1.den;
                f1.simplificar();
                break;
            case 2:
                cout << "Ingrese numerador y denominador de la segunda fraccion: ";
                cin >> f2.num >> f2.den;
                f2.simplificar();
                break;
            case 3:
                resultado = f1 + f2;
                cout << "Resultado: "; resultado.mostrar(); cout << "\n";
                break;
            case 4:
                resultado = f1 - f2;
                cout << "Resultado: "; resultado.mostrar(); cout << "\n";
                break;
            case 5:
                resultado = f1 * f2;
                cout << "Resultado: "; resultado.mostrar(); cout << "\n";
                break;
            case 6:
                resultado = f1 / f2;
                cout << "Resultado: "; resultado.mostrar(); cout << "\n";
                break;
            case 7:
                cout << "Fraccion 1: "; f1.mostrar(); cout << "\n";
                cout << "Fraccion 2: "; f2.mostrar(); cout << "\n";
                break;
            case 8:
                salir = true;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }

    cout << "Programa finalizado.\n";
    return 0;
}
