//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <cmath>
using namespace std;
struct Punto{
    double x;
    double y;
    double z;
};
double espacio(Punto n1, Punto n2){
    double distancia;
    distancia= sqrt(pow(n2.x - n1.x, 2) + pow(n2.y - n1.y, 2) + pow(n2.z - n1.z, 2));
    return distancia;
}




int main(){
    Punto n1,n2;
    cout<<"Ingrese las cordenadas del primer punto";
    cout<<"\nX: "; cin>>n1.x;
    cout<<"Y: "; cin>>n1.y;
    cout<<"Z: "; cin>>n1.z;
    cout<<"Ingrese las cordenadas del segundo punto";
    cout<<"\nX: "; cin>>n2.x;
    cout<<"Y: "; cin>>n2.y;
    cout<<"Z: "; cin>>n2.z;
    double distancia;
    distancia=espacio( n1,  n2);
    cout<<"La distancia entre los dos puntos es: "<<distancia<<"\n";
    return 0;
}
