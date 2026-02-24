#include <iostream>
using namespace std;
//Definicion de una variable definida por el usuario
struct Estudiante{
    int codigo;
    float promedio;
    char sexo;


};
struct alumno{
    int codigo;
    Fecha nacimiento;

};
struct Fecha{
    int dia;
    int mes;
    int anio;
};




int main(){

    Estudiante e1;
    //Inicializacion directa
    Estudiante e2={20241234, 12.4 , 'M'};
    //Inicializacion miembro a miembro
    e1.codigo=20254172;
    e1.promedio=13.6;
    e1.sexo='F';
    Estudiante e3=e1;
    Estudiante e4;
    cout<<"Ingrese el codigo del estudiante: ";cin>>e4.codigo;
    cout<<"Ingrese el promedio del estudiante: ";cin>>e4.promedio;
    cout<<"Ingrese el sexo del estudiante: ";cin>> e4.sexo;
    cout<<e4.codigo<<"\n";
    cout<<e4.promedio<<"\n";
    cout<<e4.sexo<<"\n";
    Estudiante A[3]; //Define arreglo de 3 estructuras
    for(int i=0; i<3;i++){
        cout<<"Ingrese el codigo del estudiante: ";cin>>A[i].codigo;
        cout<<"Ingrese el promedio del estudiante: ";cin>>A[i].promedio;
        cout<<"Ingrese el sexo del estudiante: ";cin>>A[i].sexo;
    }
    for(int i=0;i<3;i++){
        cout<<"Codigo de "<<i+1<<A[i].codigo<<"\n";
        cout<<"Promedio de "<<i+1<<A[i].promedio<<"\n";
        cout<<"Sexo de "<<i+1<<A[i].sexo<<"\n";
    }
    
    //Estructuras anidadas
    alumno a1;
    a1.codigo=1241;
    a1.nacimiento.dia=11;
    a1.nacimiento.mes=7;
    a1.nacimiento.anio=2007;
    
    //Punteros a estructuras
    Estudiante e5 = {123,23.4,'M'};
    Estudiante* ptr;
    ptr = &e5;
    //Primera forma
    cout<<ptr->codigo<<"\n";
    //Segunda forma
    cout<<(*ptr).codigo<<"\n";
    return 0;
}