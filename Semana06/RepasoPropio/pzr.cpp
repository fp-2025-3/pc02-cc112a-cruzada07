//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Producto {
    int id;                  // Identificador único
    char nombre[30];         // Nombre del producto
    double precio;           // Precio unitario
    int stock;               // Cantidad disponible
    bool activo;             // true = activo, false = eliminado lógicamente
};


int buscarProductoPorID(const char* nombreArchivo, int idBuscado){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
        cerr<<"Error\n";
        return -1;

    }
    Producto p;
    int posicion=0;
    while(archivo.read((char*)&p, sizeof(p))){
        if(p.id==idBuscado){
            archivo.close();
            return posicion;
        }
        posicion++;
    }
    archivo.close();
    return -1;
}

void registrarProducto(const char* nombreArchivo){
    Producto nuevo;
    cout<<"Ingrese el ID del producto: "; cin>>nuevo.id;
    if(buscarProductoPorID(nombreArchivo, nuevo.id)  == -1 ){
        cerr<<"ID repetido\n";
        return;
    }


    ofstream archivo(nombreArchivo, ios::binary | ios::app);
    if(!archivo){
        cerr<<"Error\n";
        return;

    }
    
    cout<<"Ingrese el nombre del producto: "; cin>>nuevo.nombre;
    cout<<"Ingrese el precio del producto: "; cin>>nuevo.precio;
    cout<<"Ingrese el stock del producto: "; cin>>nuevo.stock;


}

void mostrarProductos(const char* nombreArchivo);

void modificarPrecio(const char* nombreArchivo, int id, double nuevoPrecio);

void eliminarProducto(const char* nombreArchivo, int id);

double calcularValorInventario(const char* nombreArchivo);