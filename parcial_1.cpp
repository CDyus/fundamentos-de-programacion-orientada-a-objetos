/*
Parcial C++
Nombre: cristhian david grisales yusti 
codigo: 2561397
Grupo:
Fecha: 18/10/2025

Sección A — Opción múltiple (10 × 3 pts = 30 pts)
1) ¿Cuál declara y define una variable entera con valor 10?
• ( ) A) int x; x == 10;
• (x) B) int x = 10;
• ( ) C) int x( ); x = '10';
• ( ) D) int x { "10" };
2) ¿Qué imprime? std::cout << 7/2 << " " << 7/2.0;
• ( ) A) 3 3
• (x) B) 3 3.5
• ( ) C) 3.5 3.5
• ( ) D) 3 3.0
3) Con bool a=true, b=false; ¿Qué imprime? std::cout << (a&&b) << " " << (a||b) << " " << (!b);
• ( ) A) true true false
• (x) B) 0 1 1
• ( ) C) 1 1 0
• ( ) D) false true true
4) Dado int x=3; if (x=0) { ... } else { ... } ¿qué ocurre?
• (x) A) Error de compilación por asignación en if.
• ( ) B) Entra al if siempre.
• ( ) C) Entra al else porque el valor es 0 tras la asignación.
• ( ) D) Comportamiento indefinido.
5) do-while respecto a while:
• ( ) A) Nunca ejecuta si la condición es falsa.
• (x) B) Ejecuta al menos una vez.
• ( ) C) Ejecuta exactamente una vez.
• ( ) D) Es más rápido por definición.
6) ¿Cuál lee dos enteros separados por espacio?
• ( ) A) cin << a << b;
• ( ) B) cin >> a, b;
• (x) C) cin >> a >> b;
• ( ) D) cin (a, b);
7) ¿Qué imprime?
int a=5, b=2;
std::cout << a + b*3 << '\n';
• (x) A) 11
• ( ) B) 21
• ( ) C) 10
• ( ) D) 7
8) ¿Cuál firma pasa un entero por referencia?
• ( ) A) void f(int n&);
• ( ) B) void f(int& n);
• (x) C) void f(ref int n);
• ( ) D) int& f(int n);
9) ¿Qué hace continue en un for?
• ( ) A) Termina por completo el bucle.
• (x) B) Salta a la siguiente iteración.
• ( ) C) Reinicia el contador a 0.
• ( ) D) Salta dos iteraciones.
10) ¿Cuál condición es verdadera?
• (x) A) (3 == 3) && !(2 > 5)
• ( ) B) (3 = 3) || (2 < 1)
• ( ) C) !(3 == 3) || (2 > 5)
• ( ) D) (3 != 3) && (2 <= 5)

Sección B — Predice la salida (5 × 6 pts = 30 pts)
Escribe exactamente lo que se imprime (respeta espacios y saltos de línea).
1)
int a=5, b=2;
std::cout << a + b*3 << std::endl;
Respuesta: 11
2)
int n=0;
while (n<3) {
 std::cout << n << " ";
 n++;
}
Respuesta: 0 1 2 
3)
int x=10;
if (x%2==0) std::cout << "par";
else std::cout << "impar";
Respuesta: par
4)
int i=3;
do {
 std::cout << i--;
} while (i>0);
Respuesta: 321
5)
int a=1;
int b = (a++ > 1) ? 100 : 200;
std::cout << a << " " << b
respuesta: 2 200
*/
using namespace std;
#include <iostream>
#include <string>



int max3(int a, int b, int c){
    int max_ab = (a > b) ? a : b;
    return (max_ab > c) ? max_ab : c;
}

int sumarangos(int inicio, int fin){
    int suma = 0;
    for(int i = inicio; i <= fin; i++){
        suma += i;
    }
    return suma;
}

bool contienedigito(int numero, int digito){
    while(numero > 0){
        if (numero == 0 && digito == 0) return true;
        int ultimo_digito = numero % 10;
        if(ultimo_digito == digito){
            return true;
        }
        numero /= 10;
    }
    return false;
}

void tabla_multiplicacion(int n){
    for(int i = 1; i <= 10; i++){
        cout << n << " x " << i << " = " << n * i << "\n";
    }
}


int main(){
    cout<<max3(20, 143, 30)<<"\n";
    cout<<sumarangos(1, 44)<<"\n";
    cout<<(contienedigito(12345, 8) ? "true" : "false")<<"\n";
    tabla_multiplicacion(58);
}