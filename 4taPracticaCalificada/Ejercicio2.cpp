//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
struct Seleccion{
    string nombre;

    int PG; //3
    int PE; //1
    int PP; //0

    int GF;
    int GC;
    //gf=[]
    int puntajeTotal;

    int DG;

    double redimiento;
};
void registrarDatos(Seleccion* lista, int n){
    for(int i=0;i<n;i++){
        lista[i].PG=rand()%101;
        lista[i].PE=rand()%(101-lista[i].PG);
        lista[i].PP=100-lista[i].PG-lista[i].PE;

        lista[i].puntajeTotal=3*(lista[i].PG)+lista[i].PE;
        lista[i].redimiento=(lista[i].puntajeTotal*100.00)/300.00;
    }
    for(int i=0;i<n;i++){
        lista[i].GF=rand()%501;
        lista[i].GC=rand()%501;
        lista[i].DG=lista[i].GF-lista[i].GC;
    }
}
void imprimir(Seleccion* lista, int n){
    for(int i=0;i<n;i++){
        cout<<"\nPais_"<<i+1<<"\t\t"<<lista[i].PG<<"\t"<<lista[i].PE<<"\t"<<lista[i].PP<<"\t"<<lista[i].GF<<"\t"<<lista[i].GC<<"\t"<<lista[i].DG<<"\t"<<lista[i].puntajeTotal<<"\t"<<lista[i].redimiento;
    }


}
int main(){
    srand(time(0));
    Seleccion* lista= new Seleccion[5];
    registrarDatos(lista, 5);
    cout<<"Seleccion\tPG\tPE\tPP\tGF\tGC\tDG\tPts\tRend(%)";
    imprimir(lista, 5);
    cout<<"\n";
    delete[] lista;
    return 0;
}