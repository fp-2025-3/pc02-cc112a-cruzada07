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
void registrarDatos(Seleccion* lista,int n){
    for(int i=0;i<n;i++){
        lista[i].PG=lista[i].PE=lista[i].PP=0;
        lista[i].GF=lista[i].GC=lista[i].puntajeTotal=lista[i].DG=0;

        for(int p=0;p<100;p++){
            int gF= rand()%6;
            int gC= rand()%6;

            if(gF>gC){
                lista[i].PG++;
                lista[i].puntajeTotal += 3;
            }else if(gF == gC){
                lista[i].PE++;
                lista[i].puntajeTotal += 1;
            }else{
                lista[i].PP++;
            }

            lista[i].GF += gF;
            lista[i].GC += gC;
        }


        lista[i].DG= lista[i].GF-lista[i].GC;
        lista[i].redimiento= (lista[i].puntajeTotal * 100.00) / 300.00;
    }

}
void ordenarYMostrar(Seleccion* lista, int n){  //imprimir ---> ordenarymostrar
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            bool cambiar = false;
            if(lista[j].puntajeTotal<lista[j + 1].puntajeTotal){
                cambiar = true;

            }else if(lista[j].puntajeTotal == lista[j+1].puntajeTotal){
                if(lista[j].DG<lista[j+1].DG){
                    cambiar= true;
                }else if(lista[j].DG == lista[j+1].DG){
                    if(lista[j].GF<lista[j+1].GF){
                        cambiar= true;
                        
                    }

                }
            }
            if(cambiar){ 
                Seleccion aux=lista[j];
                lista[j]=lista[j+1];
                lista[j+1]=aux;

            }
        }

    }

    cout<<"Seleccion\tPG\tPE\tPP\tGF\tGC\tDG\tPts\tRend(%)"<<"\n";
    for(int i=0;i<n;i++){
        cout<<lista[i].nombre<<"\t\t"<<lista[i].PG<<"\t"<<lista[i].PE<<"\t"<<lista[i].PP<<"\t"<<lista[i].GF<<"\t"<<lista[i].GC<<"\t" <<lista[i].DG<<"\t"<<lista[i].puntajeTotal<<"\t"<<lista[i].redimiento<<"\n";

    }

    cout<<"\nCAMPEON: "<<lista[0].nombre<<" | Puntaje: "<<lista[0].puntajeTotal<<" | DG: "<<lista[0].DG<<" | Rendimiento: "<<lista[0].redimiento<<"%";

}
int main(){
    srand(time(0));
    Seleccion* lista= new Seleccion[5];
    lista[0].nombre="Pais_1";
    lista[1].nombre="Pais_2";
    lista[2].nombre="Pais_3";
    lista[3].nombre="Pais_4";
    lista[4].nombre="Pais_5";

    registrarDatos(lista, 5);
    ordenarYMostrar(lista, 5);
    cout<<"\n";
    delete[] lista;
    return 0;
}
