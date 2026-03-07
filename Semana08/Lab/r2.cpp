//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <fstream>
using namespace std;

struct CuentaBancaria {
    int numeroCuenta;
    char titular[40];
    double saldo;
    bool activa;
};

void crearArchivo(const string & nombreArchivo, int N){
    fstream archivo(nombreArchivo, ios::binary  | ios::out | ios::in  ); //+ lectura
    if(!archivo){
        cerr<<"Error\n";
        return;
    }






}
void buscarCuenta(int numeroCuentaBuscada){


}

void ejecucion(){

}
void desactivarCuenta(){

}
void mostrarCuentasActivas(){

}
int main(){


    return 0;
}