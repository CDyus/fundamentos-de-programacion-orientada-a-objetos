#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

/* ============================================================
   EJERCICIO 1
   ============================================================ */
void leer_arreglo(int *a, size_t n) {
    for (size_t i = 0; i < n; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> *(a + i);
    }
}

void min_max_prom(const int *a, size_t n, int *minv, int *maxv, double *prom) {
    if (n == 0) return;
    *minv = *a;
    *maxv = *a;
    long long suma = 0;
    for (const int *p = a; p < a + n; p++) {
        if (*p < *minv) *minv = *p;
        if (*p > *maxv) *maxv = *p;
        suma += *p;
    }
    *prom = static_cast<double>(suma) / n;
}

void ejecutar_ejercicio1() {
    cout << "\n=== EJERCICIO 1 ===\n";
    size_t n;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;
    int *a = new int[n];
    leer_arreglo(a, n);
    int minv, maxv;
    double prom;
    min_max_prom(a, n, &minv, &maxv, &prom);
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "\nMínimo = " << minv << endl;
    cout << "Máximo = " << maxv << endl;
    cout << "Promedio = " << prom << endl;
    delete[] a;
}

/* ============================================================
   EJERCICIO 2
   ============================================================ */
void reverse(int *a, size_t i, size_t j) {
    while (i < j) {
        int temp = *(a + i);
        *(a + i) = *(a + j);
        *(a + j) = temp;
        i++;
        j--;
    }
}

void rotar_derecha(int *a, size_t n, size_t k) {
    if (n == 0) return;
    k %= n;
    if (k == 0) return;
    reverse(a, 0, n - 1);
    reverse(a, 0, k - 1);
    reverse(a, k, n - 1);
}

void mostrar_arreglo(const int *a, size_t n) {
    for (size_t i = 0; i < n; i++)
        cout << *(a + i) << " ";
    cout << endl;
}

void ejecutar_ejercicio2() {
    cout << "\n=== EJERCICIO 2 ===\n";
    size_t n, k;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;
    int *a = new int[n];
    for (size_t i = 0; i < n; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> *(a + i);
    }
    cout << "Ingrese el desplazamiento k: ";
    cin >> k;
    cout << "\nArreglo original:\n";
    mostrar_arreglo(a, n);
    rotar_derecha(a, n, k);
    cout << "\nArreglo rotado:\n";
    mostrar_arreglo(a, n);
    delete[] a;
}

/* ============================================================
   EJERCICIO 3
   ============================================================ */
size_t normalizar_espacios(const char *in, char *out, size_t outcap) {
    const char *src = in;
    char *dst = out;
    bool en_espacio = false;
    while (*src == ' ') src++;
    while (*src && (size_t)(dst - out) < outcap - 1) {
        if (*src == ' ') {
            if (!en_espacio) {
                *dst++ = ' ';
                en_espacio = true;
            }
        } else {
            *dst++ = *src;
            en_espacio = false;
        }
        src++;
    }
    if (dst > out && *(dst - 1) == ' ')
        dst--;
    *dst = '\0';
    return (size_t)(dst - out);
}

void ejecutar_ejercicio3() {
    cout << "\n=== EJERCICIO 3 ===\n";
    cin.ignore();
    const size_t CAP = 1000;
    char entrada[CAP], salida[CAP];
    cout << "Ingrese una línea: ";
    cin.getline(entrada, CAP);
    size_t len = normalizar_espacios(entrada, salida, CAP);
    cout << "\nNormalizado: \"" << salida << "\" (" << len << " caracteres)\n";
}

/* ============================================================
   EJERCICIO 4
   ============================================================ */
int **mat_crear(size_t m, size_t n) {
    int **A = new int*[m];
    for (size_t i = 0; i < m; i++) A[i] = new int[n];
    return A;
}

void mat_destruir(int **A, size_t m) {
    for (size_t i = 0; i < m; i++) delete[] A[i];
    delete[] A;
}

void mat_sumas(int **A, size_t m, size_t n, int *sumF, int *sumC) {
    for (size_t i = 0; i < m; i++) sumF[i] = 0;
    for (size_t j = 0; j < n; j++) sumC[j] = 0;
    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < n; j++) {
            sumF[i] += A[i][j];
            sumC[j] += A[i][j];
        }
}

void mostrar_matriz(int **A, size_t m, size_t n) {
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) cout << A[i][j] << "\t";
        cout << endl;
    }
}

void ejecutar_ejercicio4() {
    cout << "\n=== EJERCICIO 4 ===\n";
    size_t m, n;
    cout << "Filas: "; cin >> m;
    cout << "Columnas: "; cin >> n;
    int **A = mat_crear(m, n);
    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    cout << "\nMatriz ingresada:\n";
    mostrar_matriz(A, m, n);
    int *sumF = new int[m], *sumC = new int[n];
    mat_sumas(A, m, n, sumF, sumC);
    cout << "\nSuma por filas: [ ";
    for (size_t i = 0; i < m; i++) cout << sumF[i] << " ";
    cout << "]\nSuma por columnas: [ ";
    for (size_t j = 0; j < n; j++) cout << sumC[j] << " ";
    cout << "]\n";
    delete[] sumF; delete[] sumC; mat_destruir(A, m);
}

/* ============================================================
   EJERCICIO 5
   ============================================================ */
typedef struct { char nombre[40]; int edad; double promedio; } Estudiante;

int cmp_prom_desc(const void *a, const void *b) {
    const Estudiante *ea = (const Estudiante *)a;
    const Estudiante *eb = (const Estudiante *)b;
    return (ea->promedio < eb->promedio) - (ea->promedio > eb->promedio);
}

int buscar_nombre(Estudiante *v, size_t n, const char *clave) {
    for (size_t i = 0; i < n; i++)
        if (strcmp(v[i].nombre, clave) == 0) return (int)i;
    return -1;
}

void ejecutar_ejercicio5() {
    cout << "\n=== EJERCICIO 5 ===\n";
    size_t n;
    cout << "Número de estudiantes: ";
    cin >> n; cin.ignore();
    Estudiante *v = new Estudiante[n];
    for (size_t i = 0; i < n; i++) {
        cout << "\nNombre: "; cin.getline(v[i].nombre, 40);
        cout << "Edad: "; cin >> v[i].edad;
        cout << "Promedio: "; cin >> v[i].promedio;
        cin.ignore();
    }
    qsort(v, n, sizeof(Estudiante), cmp_prom_desc);
    cout << "\n--- Ordenados por promedio ---\n";
    for (size_t i = 0; i < n; i++)
        cout << v[i].nombre << " (" << v[i].promedio << ")\n";
    cout << "\nTop 3:\n";
    for (size_t i = 0; i < n && i < 3; i++)
        cout << v[i].nombre << " (" << v[i].promedio << ")\n";
    char clave[40];
    cout << "\nBuscar nombre: "; cin.getline(clave, 40);
    int idx = buscar_nombre(v, n, clave);
    if (idx != -1)
        cout << "Encontrado en índice " << idx << ": " << v[idx].nombre << endl;
    else cout << "No encontrado.\n";
    delete[] v;
}

/* ============================================================
   EJERCICIO 6
   ============================================================ */
typedef struct Nodo {
    int x; struct Nodo *sig;
} Nodo;

Nodo* push_front(Nodo *head, int val) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->x = val; nuevo->sig = head; return nuevo;
}
Nodo* push_back(Nodo *head, int val) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->x = val; nuevo->sig = nullptr;
    if (!head) return nuevo;
    Nodo *p = head; while (p->sig) p = p->sig;
    p->sig = nuevo; return head;
}
Nodo* pop_front(Nodo *head) {
    if (!head) return nullptr;
    Nodo *tmp = head->sig; free(head); return tmp;
}
void clear(Nodo *head) {
    while (head) { Nodo *tmp = head->sig; free(head); head = tmp; }
}
size_t size(Nodo *head) {
    size_t c = 0; for (Nodo *p = head; p; p = p->sig) c++; return c;
}
void imprimir_lista(Nodo *head) {
    for (Nodo *p = head; p; p = p->sig) cout << p->x << " ";
    cout << endl;
}
void ejecutar_ejercicio6() {
    cout << "\n=== EJERCICIO 6 ===\n";
    cout << "pf X | pb X | pop | fin\n";
    Nodo *head = nullptr; string cmd; int val;
    while (true) {
        cout << "> "; cin >> cmd;
        if (cmd == "pf") { cin >> val; head = push_front(head, val); }
        else if (cmd == "pb") { cin >> val; head = push_back(head, val); }
        else if (cmd == "pop") { head = pop_front(head); }
        else if (cmd == "fin") break;
        else cout << "Comando no válido.\n";
    }
    cout << "\nLista final:\n"; imprimir_lista(head);
    cout << "Tamaño: " << size(head) << endl;
    clear(head);
}

/* ============================================================
   EJERCICIO 7
   ============================================================ */
int doble(int x) { return 2 * x; }
int cuadrado(int x) { return x * x; }

void aplicar(int *a, size_t n, int (*op)(int)) {
    for (size_t i = 0; i < n; i++)
        a[i] = op(a[i]);
}

void ejecutar_ejercicio7() {
    cout << "\n=== EJERCICIO 7 ===\n";
    size_t n;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;
    int *a = new int[n];
    for (size_t i = 0; i < n; i++) {
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }

    int opcion;
    cout << "\nSeleccione operación:\n1. Doble\n2. Cuadrado\n> ";
    cin >> opcion;

    if (opcion == 1)
        aplicar(a, n, doble);
    else if (opcion == 2)
        aplicar(a, n, cuadrado);
    else
        cout << "Opción no válida.\n";

    cout << "\nResultado:\n";
    mostrar_arreglo(a, n);
    delete[] a;
}

/* ============================================================
   EJERCICIO 8A: Archivo CSV real
   ============================================================ */
typedef struct { char prod[32]; int unidades; double precio; } Venta;

void ejecutar_ejercicio8A() {
    cout << "\n=== EJERCICIO 8A: Archivo CSV ===\n";
    string archivoCSV;
    cout << "Ingrese el nombre del archivo (ej: ventas.csv): ";
    cin >> archivoCSV;
    ifstream arch(archivoCSV);
    if (!arch.is_open()) {
        cerr << "❌ Error al abrir el archivo.\n";
        return;
    }
    Venta *ventas = nullptr; size_t n = 0; string linea;
    while (getline(arch, linea)) {
        if (linea.empty()) continue;
        ventas = (Venta*)realloc(ventas, (n + 1) * sizeof(Venta));
        char buf[128]; strncpy(buf, linea.c_str(), sizeof(buf)); buf[sizeof(buf) - 1] = '\0';
        char *tok = strtok(buf, ",");
        if (!tok) continue;
        strncpy(ventas[n].prod, tok, sizeof(ventas[n].prod));
        tok = strtok(NULL, ","); ventas[n].unidades = tok ? atoi(tok) : 0;
        tok = strtok(NULL, ","); ventas[n].precio = tok ? atof(tok) : 0.0;
        n++;
    }
    arch.close();
    if (n == 0) { cout << "No se cargaron datos.\n"; free(ventas); return; }
    double total = 0; int idxMax = 0;
    for (size_t i = 0; i < n; i++) {
        total += ventas[i].unidades * ventas[i].precio;
        if (ventas[i].unidades > ventas[idxMax].unidades) idxMax = i;
    }
    cout << "\nTotal vendido: $" << total;
    cout << "\nProducto más vendido: " << ventas[idxMax].prod << " (" << ventas[idxMax].unidades << " unidades)";
    cout << "\nTicket promedio: $" << total / n << endl;
    free(ventas);
}

/* ============================================================
   EJERCICIO 8B: Modo ONLINE (sin archivo)
   ============================================================ */
void ejecutar_ejercicio8B() {
    cout << "\n=== EJERCICIO 8B: Modo ONLINE ===\n";
    cout << "Ingrese las líneas CSV (producto,unidades,precio). Escriba 'fin' para terminar.\n";
    Venta *ventas = nullptr; size_t n = 0; string linea;
    cin.ignore();
    while (true) {
        cout << "> ";
        getline(cin, linea);
        if (linea == "fin" || linea.empty()) break;
        ventas = (Venta*)realloc(ventas, (n + 1) * sizeof(Venta));
        char buf[128]; strncpy(buf, linea.c_str(), sizeof(buf)); buf[sizeof(buf) - 1] = '\0';
        char *tok = strtok(buf, ",");
        if (!tok) continue;
        strncpy(ventas[n].prod, tok, sizeof(ventas[n].prod));
        tok = strtok(NULL, ","); ventas[n].unidades = tok ? atoi(tok) : 0;
        tok = strtok(NULL, ","); ventas[n].precio = tok ? atof(tok) : 0.0;
        n++;
    }
    if (n == 0) { cout << "No se ingresaron datos.\n"; free(ventas); return; }
    double total = 0; int idxMax = 0;
    for (size_t i = 0; i < n; i++) {
        total += ventas[i].unidades * ventas[i].precio;
        if (ventas[i].unidades > ventas[idxMax].unidades) idxMax = i;
    }
    cout << "\nTotal vendido: $" << total;
    cout << "\nProducto más vendido: " << ventas[idxMax].prod << " (" << ventas[idxMax].unidades << " unidades)";
    cout << "\nTicket promedio: $" << total / n << endl;
    free(ventas);
}

/* ============================================================
   MENÚ PRINCIPAL
   ============================================================ */
int main() {
    int opcion;
    do {
        cout << "\n===== MENÚ PRINCIPAL =====\n";
        cout << "1. Ejercicio 1\n";
        cout << "2. Ejercicio 2\n";
        cout << "3. Ejercicio 3\n";
        cout << "4. Ejercicio 4\n";
        cout << "5. Ejercicio 5\n";
        cout << "6. Ejercicio 6\n";
        cout << "7. Ejercicio 7\n";
        cout << "8. Ejercicio 8A (Archivo CSV)\n";
        cout << "9. Ejercicio 8B (Modo ONLINE)\n";
        cout << "0. Salir\n> ";
        cin >> opcion;

        switch (opcion) {
            case 1: ejecutar_ejercicio1(); break;
            case 2: ejecutar_ejercicio2(); break;
            case 3: ejecutar_ejercicio3(); break;
            case 4: ejecutar_ejercicio4(); break;
            case 5: ejecutar_ejercicio5(); break;
            case 6: ejecutar_ejercicio6(); break;
            case 7: ejecutar_ejercicio7(); break;
            case 8: ejecutar_ejercicio8A(); break;
            case 9: ejecutar_ejercicio8B(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
    return 0;
}
