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
void registrarProducto(const char* nombreArchivo){
    Producto nuevo;
    cout<<"Ingrese el ID del producto: "; cin>>nuevo.id;
    cout<<"Ingrese el nombre del producto: "; cin>>nuevo.nombre;
    cout<<"Ingrese el precio del producto: "; cin>>nuevo.precio;
    cout<<"Ingrese el stock del producto: "; cin>>nuevo.stock;
    ofstream archivo(nombreArchivo, ios::binary | ios::app);
    if(!archivo){
        cerr<<"Error\n";
        return ;
    }
    archivo.write( (char*)&nuevo, sizeof(nuevo));
    archivo.close();
}

void mostrarProductos(const char* nombreArchivo){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
        cerr<<"Error\n";
        return;
    }
    Producto a;
    while(archivo.read  ( (char*)&a, sizeof(a) ) ){
        cout<<"ID: "<<a.id<<" Nombre: "<<a.nombre<<" Precio: "<<a.precio<<" Stock: "<<a.stock<<"\n";
    }
    archivo.close();
}

int buscarProductoPorID(const char* nombreArchivo, int idBuscado){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
        cerr<<"Error\n";
        return;
    }
    Producto a;
    int cont=0;
    while( archivo.read  ( (char*)&a, sizeof(a) )  ){
        if(a.id==idBuscado){
            cout<<"Nombre: "<<a.nombre<<" Precio: "<<a.precio<<" Stock: "<<a.stock<<"\n";
        }
        cont++;
    }
    
    archivo.close();
    cout<<"Contador: ";
    return cont;

}

void modificarPrecio(const char* nombreArchivo, int id, double nuevoPrecio){
    fstream archivo(nombreArchivo, ios::binary | ios::out | ios::in);
    if(!archivo){
        cerr<<"Error\n";
        return ;
    }
    int cont= buscarProductoPorID(nombreArchivo, id);
    archivo.seekg(cont*sizeof(Producto), ios::beg);
    Producto p;
    if(!archivo.read( (char*)&p, sizeof(p) )){
        cerr<<"ID incorrecta\n";
        archivo.close();
        return ;
    }
    archivo.seekp(cont*sizeof(Producto), ios::beg);
    archivo.write( (char*)&p, sizeof(p) );
    archivo.close();
    
}

void eliminarProducto(const char* nombreArchivo, int id);

double calcularValorInventario(const char* nombreArchivo){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
        cerr<<"Error\n";
        return ;
    }
    float suma=0;
    Producto a;
    while(archivo.read( (char*)&a, sizeof(a) )  ){
        suma += (a.precio)*(a.stock);
        
    }
    return suma;
}



int main(){
    string nombreArchivo = "inventario.dat";

}