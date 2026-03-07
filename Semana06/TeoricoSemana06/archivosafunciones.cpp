#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void escribir(const string & nombreArchivo, const string & nombre, int nota){
    ofstream archivoEscritura(nombreArchivo, ios::app); // ios::app para añadir al final
    if(!archivoEscritura){
        cerr << "Error al abrir el archivo para escritura\n";
        return;
    }
    archivoEscritura << nombre << " " << nota << "\n";
    archivoEscritura.close();
}

void leer(const string & nombreArchivo){
    ifstream archivoLectura(nombreArchivo);
    if(!archivoLectura){
        cerr << "Error al abrir el archivo para lectura\n";
        return;
    }
    string nombre;
    int nota;
    while(archivoLectura >> nombre >> nota){
        cout << "Nombre: " << nombre << " Nota: " << nota << "\n";
    }
    archivoLectura.close();
}

void leerAprobados(const string & nombreArchivo){
    ifstream archivoAprobados(nombreArchivo);
    if(!archivoAprobados){
        cerr << "Error al abrir el archivo para lectura\n";
        return;
    }
    string nombre;
    int nota;
    cout << "Aprobados: \n";
    while(archivoAprobados >> nombre >> nota){
        if(nota >= 10){
            cout << "Nombre: " << nombre << " Nota: " << nota << "\n";
        }
    }
    archivoAprobados.close();
}

int main(){
    string nombreArchivo = "notas.txt";
    escribir(nombreArchivo, "Kevin", 18);
    escribir(nombreArchivo, "Miguel", 9);
    escribir(nombreArchivo, "Andrea", 7);
    escribir(nombreArchivo, "Lesly", 10);
    escribir(nombreArchivo, "Yessenia", 11);
    leer(nombreArchivo);
    leerAprobados(nombreArchivo);
    return 0;
}
