#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Polinomio {
    vector<double> coef; // coeficientes del polinomio

    
    Polinomio(initializer_list<double> c) : coef(c) {}

    // Método para evaluar el polinomio
    double evaluar(double x) const {
        double resultado = 0;
        for (int i = 0; i < coef.size(); ++i)
            resultado += coef[i] * pow(x, i);
        return resultado;
    }

    // Mostramos el polinomio
    void mostrar() const {
        for (int i = coef.size() - 1; i >= 0; --i) {
            cout << coef[i] << "x^" << i;
            if (i > 0) cout << " + ";
        }
        cout << endl;
    }
};

int main() {
    Polinomio p = {2, 3, 4,5, 6, 7, 8, 9, 10};
    cout << "Polinomio: ";
    p.mostrar();
    cout << "P(3) = " << p.evaluar(3) << endl; //evalua el polinomio en x=3
}
