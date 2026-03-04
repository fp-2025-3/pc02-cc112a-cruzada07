//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <fstream>
#include <cstring> // strcmp
using namespace std;

struct CuentaBancaria{
    int numeroCuenta;
    char titular[40];
    double saldo;
    bool activa;
};

void crearArchivo(const string& nombreArchivo) {
    int N;
    cout << "Ingrese la cantidad de cuentas: ";
    cin >> N;

    CuentaBancaria* cuentas = new CuentaBancaria[N];

    for (int i = 0; i < N; i++) {
        cout << "\n--- Datos Cuenta " << i + 1 << " ---\n";
        
        bool repetido;
        do {
            repetido = false;
            cout << "Numero de cuenta: ";
            cin >> cuentas[i].numeroCuenta;
            
            // Validación de duplicados en el arreglo
            for (int j = 0; j < i; j++) {
                if (cuentas[i].numeroCuenta == cuentas[j].numeroCuenta) {
                    cout << "Error: El numero ya existe. Reintente.\n";
                    repetido = true;
                    break;
                }
            }
        } while (repetido);

        cout << "Titular: ";
        cin.ignore();
        cin.getline(cuentas[i].titular, 40);
        cout << "Saldo inicial: ";
        cin >> cuentas[i].saldo;
        cuentas[i].activa = true;
    }

    // --- ORDENAMIENTO MANUAL (Método de la Burbuja) ---
    // El ejercicio pide que el archivo quede "físicamente ordenado"
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (cuentas[j].numeroCuenta > cuentas[j+1].numeroCuenta) {
                // Intercambio de estructuras
                CuentaBancaria aux = cuentas[j];
                cuentas[j] = cuentas[j+1];
                cuentas[j+1] = aux;
            }
        }
    }

    // Guardado en binario
    ofstream archivo(nombreArchivo, ios::binary | ios::out | ios::trunc);
    if (archivo.is_open()) {
        for (int i = 0; i < N; i++) {
            archivo.write((char*)&cuentas[i], sizeof(CuentaBancaria));
        }
        archivo.close();
        cout << "\nArchivo creado y ordenado correctamente.\n";
    }

    delete[] cuentas; // Liberamos la memoria dinámica
}

// 2. Buscar cuenta usando acceso directo (Cálculo de posición)
// Como el archivo está ordenado, podemos usar búsqueda binaria manual en el archivo
long buscarPosicion(const string& nombreArchivo, int numBuscado) {
    ifstream archivo(nombreArchivo, ios::binary | ios::ate);
    if (!archivo) return -1;

    long tamArchivo = archivo.tellg();
    int totalRegistros = tamArchivo / sizeof(CuentaBancaria);

    int izq = 0, der = totalRegistros - 1;
    CuentaBancaria temp;

    while (izq <= der) {
        int medio = izq + (der - izq) / 2;
        archivo.seekg(medio * sizeof(CuentaBancaria), ios::beg);
        archivo.read((char*)&temp, sizeof(CuentaBancaria));

        if (temp.numeroCuenta == numBuscado) {
            archivo.close();
            return medio; // Retorna el índice del registro
        }
        if (temp.numeroCuenta < numBuscado) izq = medio + 1;
        else der = medio - 1;
    }
    archivo.close();
    return -1;
}

// 3. Modificar saldo (Directo en archivo)
void operarSaldo(const string& nombreArchivo) {
    int num;
    cout << "Ingrese numero de cuenta: ";
    cin >> num;

    long pos = buscarPosicion(nombreArchivo, num);
    if (pos == -1) {
        cout << "Cuenta no encontrada.\n";
        return;
    }

    fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);
    CuentaBancaria c;
    archivo.seekg(pos * sizeof(CuentaBancaria));
    archivo.read((char*)&c, sizeof(CuentaBancaria));

    if (!c.activa) {
        cout << "Operacion denegada: Cuenta inactiva.\n";
        archivo.close();
        return;
    }

    int op;
    double monto;
    cout << "Cuenta de " << c.titular << ". Saldo: " << c.saldo << "\n";
    cout << "1. Depositar / 2. Retirar: ";
    cin >> op;
    cout << "Monto: "; cin >> monto;

    if (op == 1) c.saldo += monto;
    else if (op == 2) {
        if (c.saldo - monto < 0) {
            cout << "Error: No se permite saldo negativo.\n";
            archivo.close();
            return;
        }
        c.saldo -= monto;
    }

    // Regresamos el puntero de escritura a la posición y guardamos
    archivo.seekp(pos * sizeof(CuentaBancaria));
    archivo.write((char*)&c, sizeof(CuentaBancaria));
    archivo.close();
    cout << "Saldo actualizado.\n";
}

// 4. Desactivar (Lógica de baja lógica)
void desactivar(const string& nombreArchivo) {
    int num;
    cout << "Cuenta a desactivar: ";
    cin >> num;
    long pos = buscarPosicion(nombreArchivo, num);
    
    if (pos != -1) {
        fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);
        CuentaBancaria c;
        archivo.seekg(pos * sizeof(CuentaBancaria));
        archivo.read((char*)&c, sizeof(CuentaBancaria));
        
        c.activa = false;
        
        archivo.seekp(pos * sizeof(CuentaBancaria));
        archivo.write((char*)&c, sizeof(CuentaBancaria));
        archivo.close();
        cout << "Cuenta desactivada.\n";
    }
}

// 5. Mostrar activas
void mostrarActivas(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::binary);
    CuentaBancaria c;
    cout << "\n--- Cuentas Activas ---\n";
    while (archivo.read((char*)&c, sizeof(CuentaBancaria))) {
        if (c.activa) {
            cout << "ID: " << c.numeroCuenta << " | Titular: " << c.titular << " | Saldo: " << c.saldo << endl;
        }
    }
    archivo.close();
}

int main() {
    string nombreArchivo = "cuentas.dat";
    // Aquí pondrías tu menú...
    // crearArchivo(path);
    // operarSaldo(path);
    // mostrarActivas(path);
    return 0;
}