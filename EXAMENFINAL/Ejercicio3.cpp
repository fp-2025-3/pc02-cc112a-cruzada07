//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Proyecto{
    int id;
    char titulo[40];
    double presupuesto;
    int duracionMeses;
};

int contarRegistros(fstream &f){
    Proyecto p;
    int contador=0;
    f.seekg(0);

    while(f.read((char*)&p,sizeof(Proyecto))){
        contador++;

    }

    f.clear();
    return contador;
}
bool existeID(fstream &f,int id){
    Proyecto p;
    f.seekg(0);

    while(f.read((char*)&p,sizeof(Proyecto))){
        if(p.id==id){
            return true;
        }

    }

    f.clear();
    return false;
}

int posicionInsercion(fstream &f,double presupuesto){
    Proyecto p;
    int n = contarRegistros(f);

    for(int i=0;i<n;i++){
        f.seekg(i*sizeof(Proyecto));
        f.read((char*)&p,sizeof(Proyecto));

        if(p.presupuesto<presupuesto){
            return i;

        }
    }

    return n;
}

void insertarProyecto(fstream &f,Proyecto nuevo){

    if(existeID(f,nuevo.id)){
        cout<<"Ya existe un proyecto con esta ID\n";
        return;
    }

    int n = contarRegistros(f);
    int pos = posicionInsercion(f,nuevo.presupuesto);

    Proyecto temp;

    for(int i=n-1;i>=pos;i--){

        f.seekg(i*sizeof(Proyecto));
        f.read((char*)&temp,sizeof(Proyecto));

        f.seekp((i+1)*sizeof(Proyecto));
        f.write((char*)&temp,sizeof(Proyecto));


    }

    f.seekp(pos*sizeof(Proyecto));
    f.write((char*)&nuevo,sizeof(Proyecto));

    f.clear();
}

void mostrarArchivo(fstream &f){

    Proyecto p;

    cout<<"\nREGISTROS:\n";

    f.seekg(0);

    while(f.read((char*)&p,sizeof(Proyecto))){
        cout<<"ID: "<<p.id<<"\n";
        cout<<"Titulo: "<<p.titulo<<"\n";
        cout<<"Presupuesto: "<<p.presupuesto<<"\n";
        cout<<"Duracion: "<<p.duracionMeses<<"\n\n";
    }

    f.clear();
}

int main(){

    fstream f("proyectos.dat",ios::in|ios::out|ios::binary);

    if(!f){
        f.open("proyectos.dat",ios::out|ios::binary);
        f.close();
        f.open("proyectos.dat",ios::in|ios::out|ios::binary);
    }

    int N;
    cout<<"Cuantos proyectos desea ingresar: ";cin>>N;

    for(int i=0;i<N;i++){

        Proyecto p;

        cout<<"\nProyecto "<<i+1<<"\n";
        cout<<"ID: "; cin>>p.id;

        cout<<"Titulo: ";
        cin.ignore();
        cin.getline(p.titulo,40);

        cout<<"Presupuesto: "; cin>>p.presupuesto;

        cout<<"Duracion meses: "; cin>>p.duracionMeses;

        insertarProyecto(f,p);
    }

    Proyecto nuevo;
    cout<<"\n--- Insertar nuevo proyecto ---\n";

    cout<<"ID: "; cin>>nuevo.id;

    cout<<"Titulo: ";
    cin.ignore();
    cin.getline(nuevo.titulo,40);

    cout<<"Presupuesto: ";cin>>nuevo.presupuesto;

    cout<<"Duracion meses: "; cin>>nuevo.duracionMeses;

    insertarProyecto(f,nuevo);

    mostrarArchivo(f);

    f.close();

    return 0;
}
