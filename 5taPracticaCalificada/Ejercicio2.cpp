//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <fstream>
using namespace std;
struct Empleado{
    int id;
    char nombre[30];
    double salario;
};
int buscarEmpleado(const string & nombreArchivo, int idBuscado){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
        cerr<<"Error al abrir empleados.dat\n";
        return -1;
    }

    Empleado p;
    int posicion = 0;

    while(archivo.read((char*)&p, sizeof(p))){

        if(p.id == idBuscado){
            archivo.close();
            return posicion;
        }
        posicion++;
    }

    archivo.close();
    return -1;
}
int buscarSalario(const string & nombreArchivo, int idBuscado){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
        cerr<<"Error al abrir empleados.dat\n";
        return -1;
    }

    Empleado p;

    while(archivo.read((char*)&p, sizeof(p))){

        if(p.id == idBuscado){
            archivo.close();
            return p.salario;
        }
    }

    archivo.close();
    return -1;
}

void modificarSalario(const string & nombreArchivo, int id, double nuevoSalario){
    int posicion = buscarEmpleado(nombreArchivo, id);

    if(posicion == -1){
        cout<<"Error\n";
        return;
    }

    fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);
    if(!archivo){
        cout<<"Error al abrir empleados.dat\n";
        return;
    }

    archivo.seekg(posicion * sizeof(Empleado), ios::beg);

    Empleado p;
    archivo.read((char*)&p, sizeof(p));

    p.salario = nuevoSalario;

    archivo.seekp(posicion * sizeof(Empleado), ios::beg);
    archivo.write((char*)&p, sizeof(p));

    archivo.close();

    cout<<"Salario actualiza correctamente.\n";
}

int main(){
    char carac;
    
    string nombreArchivo="empleados.dat";
    int direc;
    cout<<"Ingrese ID de empleado: "; cin>>direc;
    cout<<"--- DATOS DEL EMPLEADO ---\n";
    cout<<"ID: "<<direc<<"\n";
    cout<<"Nombre: Empleado_"<<direc<<"\n";
    cout<<"Salario: "<<buscarSalario(nombreArchivo, direc);

    int nuevoSalario;
    cout<<"\n\nIngrese nuevo salario: ";cin>>nuevoSalario;
    cout<<"\n\n";

    modificarSalario(nombreArchivo,direc, nuevoSalario);
    

    return 0;

}