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
int main(){

    Punto* p1;
    Punto* p2;
    p1->x=3;
    p1->y=7;
    leerPunto(p1);
    return 0;
}