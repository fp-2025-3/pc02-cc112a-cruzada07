//Autor: Kevin de la Cruz Sanchez
#include <iostream>
using namespace std;

struct Estudiante{
    string nombre;
    double nota;
};

int main(){
    int n;
    cout<<"Ingrese el numero de estudiantes: "; cin>> n;

    Estudiante lista[n];
    for(int i=0;i<n;i++){
        cout<<"Ingrese el nombre del estudiante "<<i+1<<": ";
        cin.ignore();
        getline(cin, lista[i].nombre);
        cout<<"Ingrese la nota del estudiante "<<i+1<<": ";cin>>lista[i].nota;
    }
    int indiceMayor=0;
    for(int i=1;i<n;i++){
        if(lista[i].nota>lista[indiceMayor].nota){
            indiceMayor=i;
        }
    }
    cout<<"El estudiante con la mayor nota es: "<<lista[indiceMayor].nombre;
    cout<<"\nNota"<<lista[indiceMayor].nota<<"\n";


    return 0;
}