#include <iostream>
using namespace std;
struct Contacto{
    string nombre;
    Fecha nacimiento;
};
struct Fecha{
    int dia;
    int mes;
    int anio;
};
void leerDatos(Contacto* ptr, int N){
    for(int i=0; i<N; i++){
        cout<<"Ingrese el nombre de "<<i+1<<": ";cin>>(*(ptr+i )).nombre;
        cout<<"Ingrese la dia de nacimiento de "<<i+1<<": "; cin>>(*(ptr+i )).nacimiento.dia;
        cout<<"Ingrese la mes de nacimiento de "<<i+1<<": "; cin>>(*(ptr+i )).nacimiento.mes;
        cout<<"Ingrese la anio de nacimiento de "<<i+1<<": "; cin>>(*(ptr+i )).nacimiento.anio;
    }
}

void imprimirDatos(Contacto* ptr, int N){
    
}
int main(){
    int N;
    cout<<"Ingrese el numero de contactos: ";cin>>N;
    Contacto* ptr = new Contacto[N];
    int anio;
    cout<<"Ingrese un anio: ";cin>>anio;


    delete[] ptr;
    return 0;
}