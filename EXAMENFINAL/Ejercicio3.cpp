//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <fstream>
using namespace std;

struct Proyecto{
    int id;
    char titulo[40];
    double presupuesto;
    int duracionMeses;
};

/*
void crearArchivo(const string & nombreArchivo){
    ofstream registro(nombreArchivo, ios::binary | ios::app);
    if(!registro){
        cerr<<"Error\n";
        return ;
    }
    Proyecto p;
    registro<<""
    while(registro.read((char*)&p,sizeof(p))){

    }
}

*/
int main(){
    string nombreArchivo= "proyectos.dat";

    //crearArchivo(nombreArchivo);
    


    return 0;
}
