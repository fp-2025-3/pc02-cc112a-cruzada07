#include<iostream>
using namespace std;

struct Termino{
    double coeficiente;
    int exponente;
};

struct Polinomio{
   Termino* terminos;
   int cantidad;
};

void crearPolinomio(Polinomio &p, int n){
    p.cantidad=n;

    p.terminos=new Termino[n];
}

void leerPolinomio(Polinomio &p) {
    for (int i = 0; i < p.cantidad; i++) {
        cout << "Termino " << i + 1 << endl;
        cout << "Coeficiente: ";
        cin >> p.terminos[i].coeficiente;
        cout << "Exponente: ";
        cin >> p.terminos[i].exponente;
    }
}



















int main(){




    return 0;
}