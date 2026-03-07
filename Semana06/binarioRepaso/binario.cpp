#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Alumno {
    char nombre[30];
    int nota;
};

void escribirBinario(const string& nombreArchivo, const string& nombreIngresado, int nota) {
    
    ofstream archivoEscritura(nombreArchivo, ios::app | ios::binary); 
    if(!archivoEscritura){
        cerr << "Error al abrir el archivo para escritura\n";
        return;
    }

    Alumno alu;
    strncpy(alu.nombre, nombreIngresado.c_str(), sizeof(alu.nombre) - 1);
    alu.nombre[sizeof(alu.nombre) - 1] = '\0';
    alu.nota = nota;

    archivoEscritura.write((char*)&alu, sizeof(Alumno));
    
    archivoEscritura.close();
}

void leerBinario(const string& nombreArchivo){
    ifstream archivoLectura(nombreArchivo, ios::binary);
    if(!archivoLectura){
        cerr << "Error al abrir el archivo para lectura\n";
        return;
    }
    
    Alumno alu;
    
    while(archivoLectura.read((char*)&alu, sizeof(Alumno))){
        cout << "Nombre: " << alu.nombre << " | Nota: " << alu.nota << "\n";
    }
    
    archivoLectura.close();
}

void leerAprobadosBinario(const string& nombreArchivo){
    ifstream archivoAprobados(nombreArchivo, ios::binary);
    if(!archivoAprobados){
        cerr << "Error al abrir el archivo para lectura\n";
        return;
    }
    
    Alumno alu;
    cout << "\n--- Aprobados ---\n";
    
    while(archivoAprobados.read((char*)&alu, sizeof(Alumno))){
        if(alu.nota >= 10){
            cout << "Nombre: " << alu.nombre << " | Nota: " << alu.nota << "\n";
        }
    }
    
    archivoAprobados.close();
}

int main(){
    string nombreArchivo = "notas.dat"; 
    
    remove(nombreArchivo.c_str()); 

    escribirBinario(nombreArchivo, "Kevin", 18);
    escribirBinario(nombreArchivo, "Miguel", 9);
    escribirBinario(nombreArchivo, "Andrea", 7);
    escribirBinario(nombreArchivo, "Lesly", 10);
    escribirBinario(nombreArchivo, "Yessenia", 11);
    
    cout << "Todos los alumnos:\n";
    leerBinario(nombreArchivo);
    
    leerAprobadosBinario(nombreArchivo);
    
    return 0;
}