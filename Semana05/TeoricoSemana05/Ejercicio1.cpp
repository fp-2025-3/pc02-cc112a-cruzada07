#include <iostream>
using namespace std;

struct Estudiante{
    int codigo;
    float promedio;
};

void LeerDatos(Estudiante* ptr,int  n){
    for(int i =0;i<n;i++){
        cout<<"Ingrese el codigo de "<<i+1<<": ";
        cin>>( *(ptr+i)    ).codigo;
        cout<<"\n";
        cout<<"Ingrese el promedio de "<<i+1<<": ";
        cin>>( *(ptr+i)    ).promedio;
        cout<<"\n";
    }
}

void ImprimirAprobados(Estudiante* ptr,int  n){
    for(int i =0;i<n;i++){
        if(ptr[i].promedio>= 10){
            cout<<"Codigo de "<<i+1<<": "<<( *(ptr+i)    ).codigo;
            cout<<"\n";
            cout<<"Promedio de "<<i+1<<": "<<( *(ptr+i)    ).promedio;
            cout<<"\n";
            
        }
    }
}

int main(){
    int n;
    cout<<"Ingrese la cantidad de alumno: "; cin>>n;
    Estudiante* ptr= new Estudiante[n];
    LeerDatos(ptr, n);
    ImprimirAprobados(ptr,  n);
    delete[] ptr;
    return 0;
}