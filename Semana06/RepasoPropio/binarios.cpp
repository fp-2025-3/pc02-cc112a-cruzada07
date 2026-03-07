//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Estudiante{
    char nombre[50];
    int nota;
};
void escribirBinario(const string & nombreArchivo, const string & nombre, int nota){
    ofstream archivo(nombreArchivo, ios::binary | ios::app);
    if(!archivo){
        cerr<<"Error\n";
        return;
    }
    Estudiante a;
    strncpy(a.nombre  ,  nombre.c_str()  ,  sizeof(a.nombre));
    a.nombre[ sizeof(a.nombre)-1 ]='\0';
    a.nota=nota;

    archivo.write( (char*)&a, sizeof(a)  );
    archivo.close();
}
void leerBinario(const string & nombreArchivo){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
        cerr<<"Error\n";
        return;
    }
    Estudiante a;
    while(archivo.read( (char*)&a, sizeof(a) )){
        cout<<"Nombre: "<<a.nombre<<" Nota: "<<a.nota<<"\n";

    }
    archivo.close();
}   
void leerAprobados(const string & nombreArchivo){

    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
        cerr<<"Error\n";
        return;
    }
    Estudiante a;
    cout<<"Aprobados: \n";
    while(archivo.read( (char*)&a, sizeof(a) )){
        if(a.nota>=10){
            cout<<"Nombre: "<<a.nombre<<" Nota: "<<a.nota<<"\n";
        }

    }
    archivo.close();
}

void modificarNota(const string & nombreArchivo, int posicion, int nuevaNota){
    fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);
    if(!archivo){
        cerr<<"Error\n";
        return ;
    }

    archivo.seekg(posicion * sizeof(Estudiante), ios::beg);

    Estudiante a;
    if(!archivo.read((char*)&a, sizeof(a))){
        cerr<<"La posicion no existe\n";
        archivo.close();
        return;
    }

    a.nota = nuevaNota;

    archivo.seekp(posicion * sizeof(Estudiante), ios::beg);
    archivo.write((char*)&a, sizeof(a));

    archivo.close();
}


int main(){

    string nombreArchivo = "notas.dat";

    escribirBinario(nombreArchivo, "Kevin", 13);
    escribirBinario(nombreArchivo, "Victor", 6);
    escribirBinario(nombreArchivo, "Miguel", 8);
    escribirBinario(nombreArchivo, "Carla", 7);

    leerBinario(nombreArchivo);

    leerAprobados(nombreArchivo);

    modificarNota(nombreArchivo, 3, 20);

    leerAprobados(nombreArchivo);

    return 0;
}