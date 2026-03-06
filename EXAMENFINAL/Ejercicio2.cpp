//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <cmath>
using namespace std;

struct Punto{
    int x;
    int y;

};
void leerPunto(Punto* p){
    cout<<"Las coordenadas del punto son:\n";
    cout<<"En X: "<<p->x;
    cout<<"\nEn Y: "<<p->y;
}

double distanciaOrigen(const Punto* p){
    double distancia;
    distancia=sqrt ( (p->x)^2 + (p->y)^2 );

    return distancia;
}

Punto* masLejano(Punto* p1, Punto* p2){
    if(distanciaOrigen(p1)>distanciaOrigen(p2)  ){
        return p1;
    }

    if(distanciaOrigen(p1)<distanciaOrigen(p2)){
        return p2;
    }
    if(distanciaOrigen(p2)== distanciaOrigen(p1)){
        return p2;
    }
    return ;
}


int main(){

    Punto* p1;
    Punto* p2;
    cout<<"Ingrese el X del punto 1: "; cin>>p1->x;
    cout<<"\nIngrese el Y del punto 1: "; cin>>p1->y;

    cout<<"Ingrese el X del punto 2: "; cin>>p2->x;
    cout<<"\nIngrese el Y del punto 2: "; cin>>p2->y;

    cout<<"\nEl punto mas lejano es: \n";
    if(masLejano(p1, p2) ==p1 ){
        cout<<"El punto 1 es el mas lejano:\n";
        leerPunto(p1);

    }
    if(masLejano(p1, p2) ==p2 ){
        cout<<"El punto 2 es el mas lejano:\n";
        leerPunto(p2);


    }



    return 0;
}