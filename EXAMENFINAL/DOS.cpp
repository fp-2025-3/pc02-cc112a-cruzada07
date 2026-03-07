//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <cmath>
using namespace std;

struct Punto{
    int x;
    int y;

};
void leerPunto(Punto *p){
    cout<<"Ingrese X: "; cin>>p->x;

    cout<<"Ingrese Y: "; cin>>p->y;

}
double distanciaOrigen( const Punto* p){
    return sqrt(p->x * p->x + p->y * p->y); //x*x en vez de x^2
}

Punto* masLejano(Punto* p1, Punto* p2){
    
    double d1 =distanciaOrigen(p1);
    double d2 =distanciaOrigen(p2);
    
    if(d1<d2){
        return p1;
    }
    if(d1>=d2){
        return p2;
    }
}
int main(){

    Punto p1,p2;
    
    cout<<"Punto 1\n";
    leerPunto(&p1);

    cout<<"Punto 2\n";
    leerPunto(&p2);

    Punto* F =masLejano(&p1,&p2);
    
    cout<<"\nEl mas lejano es: \n";
    cout<<"X: "<<F->x<<endl;
    cout<<"Y: "<<F->y<<endl;

    return 0;
}
