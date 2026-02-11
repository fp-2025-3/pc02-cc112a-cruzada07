//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Seleccion{
    string nombre;
    int partidosJugados;
    int PG;
    int PE;
    int PP;
    int puntosTotales;
    float rendimiento;
};

//funcion para imprimir
void imprimirTabla(Seleccion lista[], int size, int mejorIndice){
    cout<<"Seleccion\t\tPG\tPP\tPE\tPuntaje\tRendimiento\n";

    for(int i = 0; i < size; i++){
        cout<<"Pais_seleccion "<<i+1<<"\t"<<lista[i].PG<<"\t"<<lista[i].PP<<"\t"<<lista[i].PE<<"\t"<<lista[i].puntosTotales<<"\t"<<lista[i].rendimiento<<"%\n";
    }

    cout<<"\nLa seleccion con mejor rendimiento es: "<<"Pais_Seleccion "<<mejorIndice+1<<" con rendimiento de "<<lista[mejorIndice].rendimiento<<"%\n";
}

int main(){
    srand(time(0));

    const int N = 5;
    Seleccion lista[N];
    int mejorIndice = 0;

    for(int i=0;i<N;i++){
        lista[i].partidosJugados = 100;

        lista[i].PG = rand() % 101;
        lista[i].PE = rand() % (101 - lista[i].PG);
        lista[i].PP = 100 - lista[i].PG - lista[i].PE;
        lista[i].puntosTotales = (lista[i].PG*3)+ lista[i].PE;
        lista[i].rendimiento = (lista[i].puntosTotales/300)*100;

        if(lista[i].rendimiento > lista[mejorIndice].rendimiento){

            mejorIndice = i;

        }

    }

    imprimirTabla(lista, N, mejorIndice);

    return 0;
}
