#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Estructura Contacto
struct Contacto {
    string nombre;
    string telefono;
    string email;
    string direccion;
};

// Función para mostrar un contacto
void mostrarContacto(const Contacto& c, int indice) {
    cout << "\nContacto #" << indice + 1 << "\n";
    cout << "Nombre: " << c.nombre << "\n";
    cout << "Telefono: " << c.telefono << "\n";
    cout << "Email: " << c.email << "\n";
    cout << "Direccion: " << c.direccion << "\n";
}

// Función para agregar un contacto
void agregarContacto(vector<Contacto>& lista) {
    Contacto nuevo;
    cout << "\n--- Agregar nuevo contacto ---\n";
    cout << "Nombre: "; getline(cin >> ws, nuevo.nombre);
    cout << "Telefono: "; getline(cin, nuevo.telefono);
    cout << "Email: "; getline(cin, nuevo.email);
    cout << "Direccion: "; getline(cin, nuevo.direccion);

    lista.push_back(nuevo);
    cout << "Contacto agregado correctamente.\n";
}

// Mostrar todos los contactos
void mostrarContactos(const vector<Contacto>& lista) {
    if (lista.empty()) {
        cout << "No hay contactos guardados.\n";
        return;
    }
    cout << "\n=== Lista de contactos ===\n";
    for (size_t i = 0; i < lista.size(); ++i) {
        mostrarContacto(lista[i], i);
    }
}

// Buscar contacto por nombre
void buscarContacto(const vector<Contacto>& lista) {
    if (lista.empty()) {
        cout << "No hay contactos para buscar.\n";
        return;
    }

    string nombreBuscado;
    cout << "Ingrese el nombre a buscar: ";
    getline(cin >> ws, nombreBuscado);

    bool encontrado = false;
    for (size_t i = 0; i < lista.size(); ++i) {
        if (lista[i].nombre == nombreBuscado) {
            mostrarContacto(lista[i], i);
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "No se encontro ningun contacto con ese nombre.\n";
}

// Editar un contacto existente
void editarContacto(vector<Contacto>& lista) {
    if (lista.empty()) {
        cout << "No hay contactos para editar.\n";
        return;
    }

    string nombre;
    cout << "Ingrese el nombre del contacto a editar: ";
    getline(cin >> ws, nombre);

    for (auto& c : lista) {
        if (c.nombre == nombre) {
            cout << "\n--- Editar contacto ---\n";
            cout << "Nuevo telefono (" << c.telefono << "): ";
            getline(cin, c.telefono);
            cout << "Nuevo email (" << c.email << "): ";
            getline(cin, c.email);
            cout << "Nueva direccion (" << c.direccion << "): ";
            getline(cin, c.direccion);
            cout << "Contacto actualizado.\n";
            return;
        }
    }
    cout << "Contacto no encontrado.\n";
}

// Eliminar contacto
void eliminarContacto(vector<Contacto>& lista) {
    if (lista.empty()) {
        cout << "No hay contactos para eliminar.\n";
        return;
    }

    string nombre;
    cout << "Ingrese el nombre del contacto a eliminar: ";
    getline(cin >> ws, nombre);

    auto it = remove_if(lista.begin(), lista.end(),
                        [&](const Contacto& c) { return c.nombre == nombre; });

    if (it != lista.end()) {
        lista.erase(it, lista.end());
        cout << "Contacto eliminado correctamente.\n";
    } else {
        cout << "No se encontro ningun contacto con ese nombre.\n";
    }
}

int main() {
    vector<Contacto> contactos;
    int opcion;
    bool salir = false;

    while (!salir) {
        cout << "\n====== MENU DE CONTACTOS ======\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Mostrar todos\n";
        cout << "3. Buscar por nombre\n";
        cout << "4. Editar contacto\n";
        cout << "5. Eliminar contacto\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: agregarContacto(contactos); break;
            case 2: mostrarContactos(contactos); break;
            case 3: buscarContacto(contactos); break;
            case 4: editarContacto(contactos); break;
            case 5: eliminarContacto(contactos); break;
            case 6: salir = true; break;
            default: cout << "Opcion invalida.\n"; break;
        }
    }

    cout << "\nPrograma finalizado.\n";
    return 0;
}
