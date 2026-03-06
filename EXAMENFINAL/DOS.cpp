//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <cmath>
using namespace std;

struct Punto{
    int x;
    int y;

};
void leerPunto(Punto *p){
    Punto p1= *p;
    cout<<"\nLas coordenadas del punto son: \n";
    cout<<"Punto X: "<<p1.x;
    cout<<"\nPunto Y: "<<p1.y;
    cout<<"\n";
}
double distanciaOrigen( const Punto* p){
    Punto p1=*p;
    double d1;
    d1=sqrt ( (p1.x)^2 + (p1.y)^2 );
    return d1;
}

Punto* masLejano(Punto* p1, Punto* p2){
    Punto pU= *p1;
    Punto pD= *p2;
    Punto* masLejos;
    double d1 =distanciaOrigen(p1);
    double d2 =distanciaOrigen(p2);
    
    if(d1<d2){
        *masLejos=pD;
    }
    if(d1>=d2){
        *masLejos=pU;
    }
    return masLejos;
}
int main(){

    Punto p1;
    p1.x=2;
    p1.y=4;

    Punto p2;
    p2.x=3;
    p2.y=7;

    Punto* F =masLejano(&p1,&p2);

    leerPunto(F);

    return 0;
}
