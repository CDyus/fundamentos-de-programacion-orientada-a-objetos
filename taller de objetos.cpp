#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include <map>

using namespace std;

// ============================================
// FUNCIONES AUXILIARES PARA ENTRADA
// ============================================

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double leerDouble(const string& mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail()) {
            cout << "❌ Error: Por favor ingrese un número válido." << endl;
            limpiarBuffer();
        } else {
            limpiarBuffer();
            return valor;
        }
    }
}

int leerInt(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail()) {
            cout << "❌ Error: Por favor ingrese un número entero válido." << endl;
            limpiarBuffer();
        } else {
            limpiarBuffer();
            return valor;
        }
    }
}

string leerString(const string& mensaje) {
    string valor;
    cout << mensaje;
    getline(cin, valor);
    return valor;
}

bool leerBool(const string& mensaje) {
    char respuesta;
    while (true) {
        cout << mensaje << " (s/n): ";
        cin >> respuesta;
        limpiarBuffer();
        if (respuesta == 's' || respuesta == 'S') return true;
        if (respuesta == 'n' || respuesta == 'N') return false;
        cout << "❌ Error: Por favor ingrese 's' para sí o 'n' para no." << endl;
    }
}

// ============================================
// NIVEL 1: GETTERS Y SETTERS
// ============================================

// Ejercicio 1.1: Clase Vehículo
class Vehiculo {
private:
    string marca;
    string modelo;
    int año;
    double velocidadMaxima;

public:
    Vehiculo(string m, string mod, int a, double vmax) {
        setMarca(m);
        setModelo(mod);
        setAño(a);
        setVelocidadMaxima(vmax);
    }

    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getAño() const { return año; }
    double getVelocidadMaxima() const { return velocidadMaxima; }

    void setMarca(string m) { marca = m; }
    void setModelo(string m) { modelo = m; }
    
    void setAño(int a) {
        if (a <= 1886) {
            throw invalid_argument("El año debe ser mayor a 1886");
        }
        año = a;
    }
    
    void setVelocidadMaxima(double v) {
        if (v <= 0) {
            throw invalid_argument("La velocidad máxima debe ser positiva");
        }
        velocidadMaxima = v;
    }

    virtual void mostrarInfo() const {
        cout << "\n📋 INFORMACIÓN DEL VEHÍCULO:" << endl;
        cout << "  Marca: " << marca << endl;
        cout << "  Modelo: " << modelo << endl;
        cout << "  Año: " << año << endl;
        cout << "  Velocidad Máxima: " << velocidadMaxima << " km/h" << endl;
    }

    void acelerar(double incremento) {
        if (incremento <= 0) {
            throw invalid_argument("El incremento debe ser positivo");
        }
        velocidadMaxima += incremento;
        cout << "🚀 ¡Acelerando! Nueva velocidad máxima: " << velocidadMaxima << " km/h" << endl;
    }
};

// Ejercicio 1.2: Clase Producto
class Producto {
private:
    string codigo;
    string nombre;
    double precio;
    int cantidad;

public:
    Producto(string cod, string nom, double prec, int cant) {
        setCodigo(cod);
        setNombre(nom);
        setPrecio(prec);
        setCantidad(cant);
    }

    string getCodigo() const { return codigo; }
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }

    void setCodigo(string cod) { codigo = cod; }
    void setNombre(string nom) { nombre = nom; }
    
    void setPrecio(double prec) {
        if (prec < 0) {
            throw invalid_argument("El precio no puede ser negativo");
        }
        precio = prec;
    }
    
    void setCantidad(int cant) {
        if (cant < 0) {
            throw invalid_argument("La cantidad no puede ser negativa");
        }
        cantidad = cant;
    }

    double calcularValorTotal() const {
        return precio * cantidad;
    }

    void aplicarDescuento(double porcentaje) {
        if (porcentaje < 0 || porcentaje > 100) {
            throw invalid_argument("El porcentaje debe estar entre 0 y 100");
        }
        double descuento = precio * (porcentaje / 100);
        precio -= descuento;
        cout << "🎯 Descuento aplicado: " << porcentaje << "%" << endl;
        cout << "💵 Nuevo precio: $" << fixed << setprecision(2) << precio << endl;
    }

    void mostrarInfo() const {
        cout << "\n📦 INFORMACIÓN DEL PRODUCTO:" << endl;
        cout << "  Código: " << codigo << endl;
        cout << "  Nombre: " << nombre << endl;
        cout << "  Precio: $" << fixed << setprecision(2) << precio << endl;
        cout << "  Cantidad: " << cantidad << endl;
        cout << "  Valor total: $" << calcularValorTotal() << endl;
    }
};

// ============================================
// NIVEL 2: HERENCIA SIMPLE
// ============================================

// Ejercicio 2.1: Clases derivadas de Vehículo
class Auto : public Vehiculo {
private:
    int numeroPuertas;
    string tipoCombustible;

public:
    Auto(string marca, string modelo, int año, double velocidadMaxima,
         int puertas, string combustible)
        : Vehiculo(marca, modelo, año, velocidadMaxima) {
        setNumeroPuertas(puertas);
        setTipoCombustible(combustible);
    }

    int getNumeroPuertas() const { return numeroPuertas; }
    string getTipoCombustible() const { return tipoCombustible; }

    void setNumeroPuertas(int puertas) {
        if (puertas <= 0) {
            throw invalid_argument("El número de puertas debe ser positivo");
        }
        numeroPuertas = puertas;
    }
    
    void setTipoCombustible(string combustible) {
        tipoCombustible = combustible;
    }

    void mostrarInfo() const override {
        Vehiculo::mostrarInfo();
        cout << "  Número de puertas: " << numeroPuertas << endl;
        cout << "  Tipo de combustible: " << tipoCombustible << endl;
        cout << "  Tipo: Auto" << endl;
    }
};

class Motocicleta : public Vehiculo {
private:
    bool tieneAlaron;
    int cilindrada;

public:
    Motocicleta(string marca, string modelo, int año, double velocidadMaxima,
                bool alaron, int cilind)
        : Vehiculo(marca, modelo, año, velocidadMaxima) {
        setTieneAlaron(alaron);
        setCilindrada(cilind);
    }

    bool getTieneAlaron() const { return tieneAlaron; }
    int getCilindrada() const { return cilindrada; }

    void setTieneAlaron(bool alaron) { tieneAlaron = alaron; }
    
    void setCilindrada(int cilind) {
        if (cilind <= 0) {
            throw invalid_argument("La cilindrada debe ser positiva");
        }
        cilindrada = cilind;
    }

    void mostrarInfo() const override {
        Vehiculo::mostrarInfo();
        cout << "  Tiene alarón: " << (tieneAlaron ? "Sí" : "No") << endl;
        cout << "  Cilindrada: " << cilindrada << " cc" << endl;
        cout << "  Tipo: Motocicleta" << endl;
    }
};

// Ejercicio 2.2: Sistema de Empleados
class Empleado {
protected:
    string nombreCompleto;
    string numeroEmpleado;
    double salarioBase;

public:
    Empleado(string nombre, string numEmp, double salario)
        : nombreCompleto(nombre), numeroEmpleado(numEmp), salarioBase(salario) {}

    string getNombreCompleto() const { return nombreCompleto; }
    string getNumeroEmpleado() const { return numeroEmpleado; }
    double getSalarioBase() const { return salarioBase; }

    void setNombreCompleto(string nombre) { nombreCompleto = nombre; }
    void setNumeroEmpleado(string num) { numeroEmpleado = num; }
    void setSalarioBase(double salario) { salarioBase = salario; }

    virtual double calcularSalarioTotal() const = 0;

    virtual void mostrarInfo() const {
        cout << "\n👨‍💼 INFORMACIÓN DEL EMPLEADO:" << endl;
        cout << "  Nombre: " << nombreCompleto << endl;
        cout << "  Número de empleado: " << numeroEmpleado << endl;
        cout << "  Salario base: $" << fixed << setprecision(2) << salarioBase << endl;
    }
};

class EmpleadoTiempoCompleto : public Empleado {
private:
    string beneficios;
    double bono;

public:
    EmpleadoTiempoCompleto(string nombre, string numEmp, double salario,
                          string benef, double bon)
        : Empleado(nombre, numEmp, salario), beneficios(benef), bono(bon) {}

    string getBeneficios() const { return beneficios; }
    double getBono() const { return bono; }

    void setBeneficios(string benef) { beneficios = benef; }
    void setBono(double bon) { bono = bon; }

    double calcularSalarioTotal() const override {
        return salarioBase + bono;
    }

    void mostrarInfo() const override {
        Empleado::mostrarInfo();
        cout << "  Beneficios: " << beneficios << endl;
        cout << "  Bono: $" << bono << endl;
        cout << "  Salario total: $" << calcularSalarioTotal() << endl;
        cout << "  Tipo: Tiempo Completo" << endl;
    }
};

class EmpleadoPorHoras : public Empleado {
private:
    int horasTrabajadas;
    double tarifaPorHora;

public:
    EmpleadoPorHoras(string nombre, string numEmp, double salario,
                     int horas, double tarifa)
        : Empleado(nombre, numEmp, salario), 
          horasTrabajadas(horas), tarifaPorHora(tarifa) {}

    int getHorasTrabajadas() const { return horasTrabajadas; }
    double getTarifaPorHora() const { return tarifaPorHora; }

    void setHorasTrabajadas(int horas) { horasTrabajadas = horas; }
    void setTarifaPorHora(double tarifa) { tarifaPorHora = tarifa; }

    double calcularSalarioTotal() const override {
        return horasTrabajadas * tarifaPorHora;
    }

    void mostrarInfo() const override {
        Empleado::mostrarInfo();
        cout << "  Horas trabajadas: " << horasTrabajadas << endl;
        cout << "  Tarifa por hora: $" << tarifaPorHora << endl;
        cout << "  Salario total: $" << calcularSalarioTotal() << endl;
        cout << "  Tipo: Por Horas" << endl;
    }
};

// ============================================
// NIVEL 3: HERENCIA MULTINIVEL
// ============================================

// Ejercicio 3.1: Jerarquía de Animales
class Animal {
protected:
    string nombre;
    int edad;
    double peso;

public:
    Animal(string nom, int ed, double pes) 
        : nombre(nom), edad(ed), peso(pes) {}

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    double getPeso() const { return peso; }

    void setNombre(string nom) { nombre = nom; }
    void setEdad(int ed) { edad = ed; }
    void setPeso(double pes) { peso = pes; }

    virtual void hacerSonido() const = 0;
    
    virtual void mostrarInfo() const {
        cout << "\n🐾 INFORMACIÓN DEL ANIMAL:" << endl;
        cout << "  Nombre: " << nombre << endl;
        cout << "  Edad: " << edad << " años" << endl;
        cout << "  Peso: " << peso << " kg" << endl;
    }
};

class Mamifero : public Animal {
protected:
    bool tieneColaMamifero;

public:
    Mamifero(string nom, int ed, double pes, bool cola)
        : Animal(nom, ed, pes), tieneColaMamifero(cola) {}

    bool getTieneColaMamifero() const { return tieneColaMamifero; }
    void setTieneColaMamifero(bool cola) { tieneColaMamifero = cola; }

    void mostrarInfo() const override {
        Animal::mostrarInfo();
        cout << "  Tipo: Mamífero" << endl;
        cout << "  Tiene cola: " << (tieneColaMamifero ? "Sí" : "No") << endl;
    }

    void hacerSonido() const override {
        cout << "🔊 Sonido genérico de mamífero" << endl;
    }
};

class Ave : public Animal {
protected:
    double envergaduraAlas;

public:
    Ave(string nom, int ed, double pes, double envergadura)
        : Animal(nom, ed, pes), envergaduraAlas(envergadura) {}

    double getEnvergaduraAlas() const { return envergaduraAlas; }
    void setEnvergaduraAlas(double envergadura) { envergaduraAlas = envergadura; }

    void mostrarInfo() const override {
        Animal::mostrarInfo();
        cout << "  Tipo: Ave" << endl;
        cout << "  Envergadura de alas: " << envergaduraAlas << " m" << endl;
    }

    void hacerSonido() const override {
        cout << "🔊 Sonido genérico de ave" << endl;
    }
};

class Perro : public Mamifero {
public:
    Perro(string nom, int ed, double pes, bool cola)
        : Mamifero(nom, ed, pes, cola) {}

    void hacerSonido() const override {
        cout << "🐕 ¡Guau guau!" << endl;
    }

    void mostrarInfo() const override {
        Mamifero::mostrarInfo();
        cout << "  Especie: Perro" << endl;
    }
};

class Gato : public Mamifero {
public:
    Gato(string nom, int ed, double pes, bool cola)
        : Mamifero(nom, ed, pes, cola) {}

    void hacerSonido() const override {
        cout << "🐈 ¡Miau miau!" << endl;
    }

    void mostrarInfo() const override {
        Mamifero::mostrarInfo();
        cout << "  Especie: Gato" << endl;
    }
};

class Loro : public Ave {
public:
    Loro(string nom, int ed, double pes, double envergadura)
        : Ave(nom, ed, pes, envergadura) {}

    void hacerSonido() const override {
        cout << "🦜 ¡Hola! ¡Soy un loro!" << endl;
    }

    void mostrarInfo() const override {
        Ave::mostrarInfo();
        cout << "  Especie: Loro" << endl;
    }
};

class Aguila : public Ave {
public:
    Aguila(string nom, int ed, double pes, double envergadura)
        : Ave(nom, ed, pes, envergadura) {}

    void hacerSonido() const override {
        cout << "🦅 ¡Kiiii kiiii!" << endl;
    }

    void mostrarInfo() const override {
        Ave::mostrarInfo();
        cout << "  Especie: Águila" << endl;
    }
};

// Ejercicio 3.2: Sistema Bancario
class Cuenta {
protected:
    string numeroCuenta;
    string propietario;
    double saldo;

public:
    Cuenta(string num, string prop, double sal)
        : numeroCuenta(num), propietario(prop), saldo(sal) {}

    string getNumeroCuenta() const { return numeroCuenta; }
    string getPropietario() const { return propietario; }
    double getSaldo() const { return saldo; }

    void setNumeroCuenta(string num) { numeroCuenta = num; }
    void setPropietario(string prop) { propietario = prop; }
    void setSaldo(double sal) { saldo = sal; }

    virtual void depositar(double monto) {
        if (monto <= 0) {
            throw invalid_argument("El monto a depositar debe ser positivo");
        }
        saldo += monto;
        cout << "💰 Depósito exitoso. Nuevo saldo: $" << saldo << endl;
    }

    virtual void retirar(double monto) {
        if (monto <= 0) {
            throw invalid_argument("El monto a retirar debe ser positivo");
        }
        if (monto > saldo) {
            throw invalid_argument("Fondos insuficientes");
        }
        saldo -= monto;
        cout << "💳 Retiro exitoso. Nuevo saldo: $" << saldo << endl;
    }

    virtual void mostrarInfo() const {
        cout << "\n🏦 INFORMACIÓN DE LA CUENTA:" << endl;
        cout << "  Número de cuenta: " << numeroCuenta << endl;
        cout << "  Propietario: " << propietario << endl;
        cout << "  Saldo: $" << fixed << setprecision(2) << saldo << endl;
    }
};

class CuentaAhorro : public Cuenta {
private:
    double tasaInteres;

public:
    CuentaAhorro(string num, string prop, double sal, double tasa)
        : Cuenta(num, prop, sal), tasaInteres(tasa) {}

    double getTasaInteres() const { return tasaInteres; }
    void setTasaInteres(double tasa) { tasaInteres = tasa; }

    void generarInteres() {
        double interes = saldo * tasaInteres;
        saldo += interes;
        cout << "📈 Interés generado: $" << interes << endl;
        cout << "💵 Nuevo saldo: $" << saldo << endl;
    }

    void depositar(double monto) override {
        Cuenta::depositar(monto);
        cout << "💹 Este depósito genera interés en tu cuenta de ahorros" << endl;
    }

    void retirar(double monto) override {
        Cuenta::retirar(monto);
        cout << "💡 Recuerda mantener un saldo mínimo para mejores tasas" << endl;
    }

    void mostrarInfo() const override {
        Cuenta::mostrarInfo();
        cout << "  Tipo: Cuenta de Ahorros" << endl;
        cout << "  Tasa de interés: " << (tasaInteres * 100) << "%" << endl;
    }
};

class CuentaCorriente : public Cuenta {
private:
    double limiteDescubierto;

public:
    CuentaCorriente(string num, string prop, double sal, double limite)
        : Cuenta(num, prop, sal), limiteDescubierto(limite) {}

    double getLimiteDescubierto() const { return limiteDescubierto; }
    void setLimiteDescubierto(double limite) { limiteDescubierto = limite; }

    void solicitarDescubierto(double monto) {
        if (monto <= 0) {
            throw invalid_argument("El monto debe ser positivo");
        }
        limiteDescubierto += monto;
        cout << "📊 Límite de descubierto aumentado a: $" << limiteDescubierto << endl;
    }

    void retirar(double monto) override {
        if (monto <= 0) {
            throw invalid_argument("El monto a retirar debe ser positivo");
        }
        
        if (monto <= saldo) {
            saldo -= monto;
            cout << "💳 Retiro exitoso. Nuevo saldo: $" << saldo << endl;
        } else if (monto <= saldo + limiteDescubierto) {
            double descubiertoUsado = monto - saldo;
            saldo = -descubiertoUsado;
            cout << "💳 Retiro exitoso usando descubierto." << endl;
            cout << "⚠️  Descubierto utilizado: $" << descubiertoUsado << endl;
            cout << "💵 Saldo actual: -$" << descubiertoUsado << endl;
        } else {
            throw invalid_argument("Fondos insuficientes y excede límite de descubierto");
        }
    }

    void mostrarInfo() const override {
        Cuenta::mostrarInfo();
        cout << "  Tipo: Cuenta Corriente" << endl;
        cout << "  Límite de descubierto: $" << limiteDescubierto << endl;
    }
};

// ============================================
// NIVEL 4: SISTEMA UNIVERSITARIO
// ============================================

class Curso {
private:
    string codigo;
    string nombre;
    int creditos;
    string profesor;
    map<string, double> calificaciones;

public:
    Curso(string cod, string nom, int cred, string prof)
        : codigo(cod), nombre(nom), creditos(cred), profesor(prof) {}

    string getCodigo() const { return codigo; }
    string getNombre() const { return nombre; }
    int getCreditos() const { return creditos; }
    string getProfesor() const { return profesor; }

    void setCodigo(string cod) { codigo = cod; }
    void setNombre(string nom) { nombre = nom; }
    void setCreditos(int cred) { 
        if (cred <= 0) throw invalid_argument("Los créditos deben ser positivos");
        creditos = cred; 
    }
    void setProfesor(string prof) { profesor = prof; }

    void agregarCalificacion(string cedula, double calificacion) {
        if (calificacion < 0 || calificacion > 5.0) {
            throw invalid_argument("La calificación debe estar entre 0.0 y 5.0");
        }
        calificaciones[cedula] = calificacion;
    }

    double obtenerCalificacion(string cedula) const {
        auto it = calificaciones.find(cedula);
        if (it != calificaciones.end()) {
            return it->second;
        }
        return -1;
    }

    void mostrarInfo() const {
        cout << "\n📚 INFORMACIÓN DEL CURSO:" << endl;
        cout << "  Código: " << codigo << endl;
        cout << "  Nombre: " << nombre << endl;
        cout << "  Créditos: " << creditos << endl;
        cout << "  Profesor: " << profesor << endl;
        cout << "  Estudiantes matriculados: " << calificaciones.size() << endl;
    }

    void mostrarCalificaciones() const {
        if (calificaciones.empty()) {
            cout << "  No hay calificaciones registradas." << endl;
            return;
        }
        cout << "  Calificaciones:" << endl;
        for (const auto& [cedula, calificacion] : calificaciones) {
            cout << "    " << cedula << ": " << calificacion << endl;
        }
    }
};

class Persona {
protected:
    string nombre;
    int edad;
    string cedula;

public:
    Persona(string nom, int ed, string ced) 
        : nombre(nom), edad(ed), cedula(ced) {}

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    string getCedula() const { return cedula; }

    void setNombre(string nom) { nombre = nom; }
    void setEdad(int ed) { 
        if (ed < 0) throw invalid_argument("La edad no puede ser negativa");
        edad = ed; 
    }
    void setCedula(string ced) { cedula = ced; }

    virtual void mostrarInfo() const {
        cout << "\n👤 INFORMACIÓN PERSONAL:" << endl;
        cout << "  Nombre: " << nombre << endl;
        cout << "  Edad: " << edad << " años" << endl;
        cout << "  Cédula: " << cedula << endl;
    }

    virtual ~Persona() = default;
};

class Estudiante : public Persona {
private:
    string carrera;
    double promedio;
    int semestre;
    vector<Curso*> cursosMatriculados;
    map<string, double> calificacionesPorCurso;

public:
    Estudiante(string nom, int ed, string ced, string carr, double prom, int sem)
        : Persona(nom, ed, ced), carrera(carr), promedio(prom), semestre(sem) {}

    string getCarrera() const { return carrera; }
    double getPromedio() const { return promedio; }
    int getSemestre() const { return semestre; }

    void setCarrera(string carr) { carrera = carr; }
    void setPromedio(double prom) { 
        if (prom < 0 || prom > 5.0) throw invalid_argument("El promedio debe estar entre 0.0 y 5.0");
        promedio = prom; 
    }
    void setSemestre(int sem) { 
        if (sem <= 0) throw invalid_argument("El semestre debe ser positivo");
        semestre = sem; 
    }

    void matricularCurso(Curso* curso) {
        if (!curso) throw invalid_argument("Curso inválido");
        cursosMatriculados.push_back(curso);
        cout << "✅ Curso " << curso->getNombre() << " matriculado exitosamente." << endl;
    }

    void agregarCalificacion(string codigoCurso, double calificacion) {
        if (calificacion < 0 || calificacion > 5.0) {
            throw invalid_argument("La calificación debe estar entre 0.0 y 5.0");
        }
        calificacionesPorCurso[codigoCurso] = calificacion;
        calcularPromedioActual();
    }

    double calcularPromedioActual() {
        if (calificacionesPorCurso.empty()) {
            promedio = 0.0;
            return 0.0;
        }

        double suma = 0.0;
        for (const auto& [curso, calificacion] : calificacionesPorCurso) {
            suma += calificacion;
        }
        promedio = suma / calificacionesPorCurso.size();
        return promedio;
    }

    void verCalificaciones() const {
        cout << "\n📊 CALIFICACIONES DE " << nombre << ":" << endl;
        if (calificacionesPorCurso.empty()) {
            cout << "  No hay calificaciones registradas." << endl;
            return;
        }
        for (const auto& [curso, calificacion] : calificacionesPorCurso) {
            cout << "  " << curso << ": " << calificacion << endl;
        }
        cout << "  Promedio actual: " << promedio << endl;
    }

    void mostrarInfo() const override {
        Persona::mostrarInfo();
        cout << "  Tipo: Estudiante" << endl;
        cout << "  Carrera: " << carrera << endl;
        cout << "  Semestre: " << semestre << endl;
        cout << "  Promedio: " << fixed << setprecision(2) << promedio << endl;
        cout << "  Cursos matriculados: " << cursosMatriculados.size() << endl;
        
        if (!cursosMatriculados.empty()) {
            cout << "  Lista de cursos:" << endl;
            for (const auto& curso : cursosMatriculados) {
                cout << "    - " << curso->getNombre() << " (" << curso->getCodigo() << ")" << endl;
            }
        }
    }
};

class Profesor : public Persona {
private:
    string especialidad;
    int añosExperiencia;
    int numeroEstudiantes;

public:
    Profesor(string nom, int ed, string ced, string esp, int exp, int numEst)
        : Persona(nom, ed, ced), especialidad(esp), añosExperiencia(exp), numeroEstudiantes(numEst) {}

    string getEspecialidad() const { return especialidad; }
    int getAñosExperiencia() const { return añosExperiencia; }
    int getNumeroEstudiantes() const { return numeroEstudiantes; }

    void setEspecialidad(string esp) { especialidad = esp; }
    void setAñosExperiencia(int exp) { 
        if (exp < 0) throw invalid_argument("Los años de experiencia no pueden ser negativos");
        añosExperiencia = exp; 
    }
    void setNumeroEstudiantes(int numEst) { 
        if (numEst < 0) throw invalid_argument("El número de estudiantes no puede ser negativo");
        numeroEstudiantes = numEst; 
    }

    bool estaDisponible(int horaDelDia) const {
        return (horaDelDia >= 8 && horaDelDia <= 17);
    }

    void mostrarInfo() const override {
        Persona::mostrarInfo();
        cout << "  Tipo: Profesor" << endl;
        cout << "  Especialidad: " << especialidad << endl;
        cout << "  Años de experiencia: " << añosExperiencia << endl;
        cout << "  Número de estudiantes: " << numeroEstudiantes << endl;
        
        int horaActual = 14;
        cout << "  Disponibilidad (" << horaActual << ":00): " 
             << (estaDisponible(horaActual) ? "✅ Disponible" : "❌ No disponible") << endl;
    }
};

class Personal : public Persona {
private:
    string puesto;
    string departamento;
    double salario;

public:
    Personal(string nom, int ed, string ced, string pue, string dep, double sal)
        : Persona(nom, ed, ced), puesto(pue), departamento(dep), salario(sal) {}

    string getPuesto() const { return puesto; }
    string getDepartamento() const { return departamento; }
    double getSalario() const { return salario; }

    void setPuesto(string pue) { puesto = pue; }
    void setDepartamento(string dep) { departamento = dep; }
    void setSalario(double sal) { 
        if (sal < 0) throw invalid_argument("El salario no puede ser negativo");
        salario = sal; 
    }

    double calcularSalarioMensual() const {
        return salario;
    }

    double calcularSalarioMensual(double bonificacion) const {
        if (bonificacion < 0) throw invalid_argument("La bonificación no puede ser negativa");
        return salario + bonificacion;
    }

    void mostrarInfo() const override {
        Persona::mostrarInfo();
        cout << "  Tipo: Personal Administrativo" << endl;
        cout << "  Puesto: " << puesto << endl;
        cout << "  Departamento: " << departamento << endl;
        cout << "  Salario base: $" << fixed << setprecision(2) << salario << endl;
        cout << "  Salario mensual: $" << calcularSalarioMensual() << endl;
    }
};

// ============================================
// FUNCIONES DE DEMOSTRACIÓN
// ============================================

void demostrarVehiculo() {
    cout << "\n🚗 DEMOSTRACIÓN VEHÍCULO" << endl;
    cout << "========================" << endl;
    
    string marca = leerString("Ingrese la marca del vehículo: ");
    string modelo = leerString("Ingrese el modelo del vehículo: ");
    int año = leerInt("Ingrese el año del vehículo: ");
    double velocidad = leerDouble("Ingrese la velocidad máxima (km/h): ");
    
    Vehiculo vehiculo(marca, modelo, año, velocidad);
    vehiculo.mostrarInfo();
    
    double incremento = leerDouble("Ingrese el incremento de velocidad: ");
    vehiculo.acelerar(incremento);
    vehiculo.mostrarInfo();
}

void demostrarProducto() {
    cout << "\n🛒 DEMOSTRACIÓN PRODUCTO" << endl;
    cout << "========================" << endl;
    
    string codigo = leerString("Ingrese el código del producto: ");
    string nombre = leerString("Ingrese el nombre del producto: ");
    double precio = leerDouble("Ingrese el precio del producto: $");
    int cantidad = leerInt("Ingrese la cantidad en stock: ");
    
    Producto producto(codigo, nombre, precio, cantidad);
    producto.mostrarInfo();
    
    double descuento = leerDouble("Ingrese el porcentaje de descuento: ");
    producto.aplicarDescuento(descuento);
    producto.mostrarInfo();
}

void demostrarAutoYMoto() {
    cout << "\n🚘 DEMOSTRACIÓN AUTO Y MOTOCICLETA" << endl;
    cout << "=================================" << endl;
    
    cout << "\n📝 DATOS DEL AUTO:" << endl;
    string marcaAuto = leerString("Marca del auto: ");
    string modeloAuto = leerString("Modelo del auto: ");
    int añoAuto = leerInt("Año del auto: ");
    double velocidadAuto = leerDouble("Velocidad máxima del auto: ");
    int puertas = leerInt("Número de puertas: ");
    string combustible = leerString("Tipo de combustible: ");
    
    Auto auto1(marcaAuto, modeloAuto, añoAuto, velocidadAuto, puertas, combustible);
    auto1.mostrarInfo();
    
    cout << "\n📝 DATOS DE LA MOTOCICLETA:" << endl;
    string marcaMoto = leerString("Marca de la motocicleta: ");
    string modeloMoto = leerString("Modelo de la motocicleta: ");
    int añoMoto = leerInt("Año de la motocicleta: ");
    double velocidadMoto = leerDouble("Velocidad máxima de la motocicleta: ");
    bool alaron = leerBool("¿Tiene alarón?");
    int cilindrada = leerInt("Cilindrada (cc): ");
    
    Motocicleta moto(marcaMoto, modeloMoto, añoMoto, velocidadMoto, alaron, cilindrada);
    moto.mostrarInfo();
}

void demostrarEmpleados() {
    cout << "\n👨‍💼 DEMOSTRACIÓN EMPLEADOS" << endl;
    cout << "========================" << endl;
    
    cout << "\n📝 EMPLEADO TIEMPO COMPLETO:" << endl;
    string nombre1 = leerString("Nombre completo: ");
    string numero1 = leerString("Número de empleado: ");
    double salario1 = leerDouble("Salario base: $");
    string beneficios = leerString("Beneficios: ");
    double bono = leerDouble("Bono: $");
    
    EmpleadoTiempoCompleto emp1(nombre1, numero1, salario1, beneficios, bono);
    emp1.mostrarInfo();
    
    cout << "\n📝 EMPLEADO POR HORAS:" << endl;
    string nombre2 = leerString("Nombre completo: ");
    string numero2 = leerString("Número de empleado: ");
    int horas = leerInt("Horas trabajadas: ");
    double tarifa = leerDouble("Tarifa por hora: $");
    
    EmpleadoPorHoras emp2(nombre2, numero2, 0, horas, tarifa);
    emp2.mostrarInfo();
}

void demostrarAnimales() {
    cout << "\n🐾 DEMOSTRACIÓN ANIMALES" << endl;
    cout << "=======================" << endl;
    
    cout << "\n📝 DATOS DEL PERRO:" << endl;
    string nombrePerro = leerString("Nombre del perro: ");
    int edadPerro = leerInt("Edad del perro: ");
    double pesoPerro = leerDouble("Peso del perro (kg): ");
    bool colaPerro = leerBool("¿Tiene cola?");
    
    Perro perro(nombrePerro, edadPerro, pesoPerro, colaPerro);
    perro.mostrarInfo();
    perro.hacerSonido();
    
    cout << "\n📝 DATOS DEL GATO:" << endl;
    string nombreGato = leerString("Nombre del gato: ");
    int edadGato = leerInt("Edad del gato: ");
    double pesoGato = leerDouble("Peso del gato (kg): ");
    bool colaGato = leerBool("¿Tiene cola?");
    
    Gato gato(nombreGato, edadGato, pesoGato, colaGato);
    gato.mostrarInfo();
    gato.hacerSonido();
    
    cout << "\n📝 DATOS DEL LORO:" << endl;
    string nombreLoro = leerString("Nombre del loro: ");
    int edadLoro = leerInt("Edad del loro: ");
    double pesoLoro = leerDouble("Peso del loro (kg): ");
    double envergaduraLoro = leerDouble("Envergadura de alas (m): ");
    
    Loro loro(nombreLoro, edadLoro, pesoLoro, envergaduraLoro);
    loro.mostrarInfo();
    loro.hacerSonido();
}

void demostrarSistemaBancario() {
    cout << "\n🏦 DEMOSTRACIÓN SISTEMA BANCARIO" << endl;
    cout << "===============================" << endl;
    
    cout << "\n📝 CUENTA DE AHORROS:" << endl;
    string numAhorros = leerString("Número de cuenta: ");
    string propAhorros = leerString("Propietario: ");
    double saldoAhorros = leerDouble("Saldo inicial: $");
    double tasa = leerDouble("Tasa de interés (ej: 0.02 para 2%): ");
    
    CuentaAhorro ahorros(numAhorros, propAhorros, saldoAhorros, tasa);
    ahorros.mostrarInfo();
    
    double deposito = leerDouble("Monto a depositar: $");
    ahorros.depositar(deposito);
    ahorros.generarInteres();
    ahorros.mostrarInfo();
    
    cout << "\n📝 CUENTA CORRIENTE:" << endl;
    string numCorriente = leerString("Número de cuenta: ");
    string propCorriente = leerString("Propietario: ");
    double saldoCorriente = leerDouble("Saldo inicial: $");
    double limite = leerDouble("Límite de descubierto: $");
    
    CuentaCorriente corriente(numCorriente, propCorriente, saldoCorriente, limite);
    corriente.mostrarInfo();
    
    double retiro = leerDouble("Monto a retirar: $");
    corriente.retirar(retiro);
    corriente.mostrarInfo();
}

void demostrarSistemaUniversitario() {
    cout << "\n🎓 DEMOSTRACIÓN SISTEMA UNIVERSITARIO" << endl;
    cout << "====================================" << endl;

    cout << "\n📚 CREACIÓN DE CURSOS:" << endl;
    Curso curso1("MAT101", "Cálculo I", 4, "Dr. Pérez");
    Curso curso2("PROG101", "Programación Básica", 3, "Dra. García");
    Curso curso3("FIS101", "Física General", 4, "Dr. Rodríguez");

    curso1.mostrarInfo();
    curso2.mostrarInfo();
    curso3.mostrarInfo();

    cout << "\n👨‍🎓 CREACIÓN DE ESTUDIANTES:" << endl;
    Estudiante estudiante1("Juan López", 20, "12345678", "Ingeniería de Sistemas", 4.2, 3);
    Estudiante estudiante2("María García", 19, "87654321", "Ingeniería Civil", 4.5, 2);

    estudiante1.mostrarInfo();
    estudiante2.mostrarInfo();

    cout << "\n📝 MATRICULANDO ESTUDIANTES EN CURSOS:" << endl;
    estudiante1.matricularCurso(&curso1);
    estudiante1.matricularCurso(&curso2);
    estudiante2.matricularCurso(&curso1);
    estudiante2.matricularCurso(&curso3);

    cout << "\n📊 AGREGANDO CALIFICACIONES:" << endl;
    estudiante1.agregarCalificacion("MAT101", 4.5);
    estudiante1.agregarCalificacion("PROG101", 4.8);
    estudiante2.agregarCalificacion("MAT101", 4.2);
    estudiante2.agregarCalificacion("FIS101", 4.7);

    estudiante1.verCalificaciones();
    estudiante2.verCalificaciones();

    estudiante1.mostrarInfo();
    estudiante2.mostrarInfo();

    cout << "\n👨‍🏫 CREACIÓN DE PROFESOR:" << endl;
    Profesor profesor("Carlos Rodríguez", 45, "11223344", "Matemáticas", 15, 120);
    profesor.mostrarInfo();

    cout << "\n⏰ VERIFICANDO DISPONIBILIDAD DEL PROFESOR:" << endl;
    int horaConsulta = leerInt("Ingrese la hora para consultar disponibilidad (0-23): ");
    bool disponible = profesor.estaDisponible(horaConsulta);
    cout << "El profesor " << profesor.getNombre() 
         << (disponible ? " ✅ ESTÁ disponible" : " ❌ NO ESTÁ disponible") 
         << " a las " << horaConsulta << ":00 horas." << endl;

    cout << "\n👨‍💼 CREACIÓN DE PERSONAL ADMINISTRATIVO:" << endl;
    Personal personal("Ana Martínez", 35, "55667788", "Coordinador Académico", "Decanato", 2500.00);
    personal.mostrarInfo();

    double bonificacion = leerDouble("Ingrese bonificación para el personal: $");
    double salarioTotal = personal.calcularSalarioMensual(bonificacion);
    cout << "💰 Salario total con bonificación: $" << salarioTotal << endl;

    cout << "\n🔄 DEMOSTRACIÓN DE POLIMORFISMO:" << endl;
    vector<Persona*> comunidadUniversitaria;
    comunidadUniversitaria.push_back(&estudiante1);
    comunidadUniversitaria.push_back(&estudiante2);
    comunidadUniversitaria.push_back(&profesor);
    comunidadUniversitaria.push_back(&personal);

    cout << "📋 LISTA DE TODA LA COMUNIDAD UNIVERSITARIA:" << endl;
    for (Persona* persona : comunidadUniversitaria) {
        persona->mostrarInfo();
        cout << "------------------------" << endl;
    }

    cout << "\n🎯 GESTIÓN DE CALIFICACIONES EN CURSOS:" << endl;
    
    curso1.agregarCalificacion(estudiante1.getCedula(), 4.5);
    curso1.agregarCalificacion(estudiante2.getCedula(), 4.2);
    curso2.agregarCalificacion(estudiante1.getCedula(), 4.8);
    curso3.agregarCalificacion(estudiante2.getCedula(), 4.7);

    curso1.mostrarInfo();
    curso1.mostrarCalificaciones();
    
    curso2.mostrarInfo();
    curso2.mostrarCalificaciones();
    
    curso3.mostrarInfo();
    curso3.mostrarCalificaciones();
}

// ============================================
// FUNCIÓN PRINCIPAL
// ============================================

int main() {
    cout << "🎓 TALLER DE OBJETOS - SOLUCIÓN COMPLETA UNIFICADA" << endl;
    cout << "==================================================" << endl;
    
    while (true) {
        cout << "\n📋 MENÚ PRINCIPAL:" << endl;
        cout << "1. 🚗 Demostrar Vehículo (Nivel 1)" << endl;
        cout << "2. 🛒 Demostrar Producto (Nivel 1)" << endl;
        cout << "3. 🚘 Demostrar Auto y Motocicleta (Nivel 2)" << endl;
        cout << "4. 👨‍💼 Demostrar Empleados (Nivel 2)" << endl;
        cout << "5. 🐾 Demostrar Animales (Nivel 3)" << endl;
        cout << "6. 🏦 Demostrar Sistema Bancario (Nivel 3)" << endl;
        cout << "7. 🎓 Demostrar Sistema Universitario (Nivel 4)" << endl;
        cout << "8. 🎯 Demostración Completa (Todos los niveles)" << endl;
        cout << "0. ❌ Salir" << endl;
        
        int opcion = leerInt("\nSeleccione una opción: ");
        
        try {
            switch (opcion) {
                case 1:
                    demostrarVehiculo();
                    break;
                case 2:
                    demostrarProducto();
                    break;
                case 3:
                    demostrarAutoYMoto();
                    break;
                case 4:
                    demostrarEmpleados();
                    break;
                case 5:
                    demostrarAnimales();
                    break;
                case 6:
                    demostrarSistemaBancario();
                    break;
                case 7:
                    demostrarSistemaUniversitario();
                    break;
                case 8:
                    cout << "🎯 EJECUTANDO DEMOSTRACIÓN COMPLETA..." << endl;
                    demostrarVehiculo();
                    demostrarProducto();
                    demostrarAutoYMoto();
                    demostrarEmpleados();
                    demostrarAnimales();
                    demostrarSistemaBancario();
                    demostrarSistemaUniversitario();
                    cout << "✨ DEMOSTRACIÓN COMPLETA FINALIZADA ✨" << endl;
                    break;
                case 0:
                    cout << "👋 ¡Hasta luego!" << endl;
                    return 0;
                default:
                    cout << "❌ Opción inválida. Por favor intente nuevamente." << endl;
            }
        } catch (const exception& e) {
            cout << "💥 Error: " << e.what() << endl;
        }
        
        if (opcion != 0) {
            cout << "\n⏎ Presione Enter para continuar...";
            cin.get();
        }
    }
    
    return 0;
}