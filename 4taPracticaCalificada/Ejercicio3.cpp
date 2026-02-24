//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <cstring>
using namespace std;

struct Producto{
    int codigo;
    char* nombre;
    double precio;
    int stock;

};
Producto crearProducto(int codigo,const char* nombre,double precio,int stock){
    Producto p;
    p.codigo=codigo;
    p.precio=precio;
    p.stock=stock;
    
    p.nombre = new char[  strlen( nombre) +1];
    strcpy(p.nombre,nombre);
    
    return p;

}

Producto* crearInventario(int n){
    Producto* arreglo = new Producto[n];
    for(int i=0;i<n;i++){
        int c,s;
        double pr;
        char tempNom[100];

        cout<<"Producto "<<i+1<<":"<<"\n";
        cout<<"Codigo: "; cin>>c;
        cout<<"Nombre: "; cin.ignore(); cin.getline(tempNom,100);
        cout<<"Precio: "; cin>>pr;
        cout<<"Stock: "; cin>>s;

        *( arreglo+i) = crearProducto(c,tempNom,pr,s);


    }
    return arreglo;

}

Producto* buscarProducto(Producto* inventario,int n,int codigoBuscado){
    for(int i=0;i<n;i++){

        if((inventario+i)->codigo == codigoBuscado){

            return (inventario+i);

        }
    }

    return nullptr;

}

void liberarInventario(Producto* inventario,int n){
    for(int i=0;i<n;i++){
        delete[] (inventario+i)->nombre;

    }

    delete[] inventario; 
}

void imprimirInventario(Producto* inventario,int n){
    cout<<"\nINVENTARIO"<<"\n";

    for(int i=0;i<n;i++){
        Producto* p =inventario+i;
        cout<<"Codigo: "<<p->codigo<<" | "<<"Nombre: "<<p->nombre<<" | "<<"Precio: "<<p->precio<<" | "<<"Stock: "<<p->stock<<"\n";

    }
}
int main(){
    int n;
    int codigoABuscar;
    
    cout<<"Ingrese la cantidad de productos: ";cin>>n;

    Producto* inventario = crearInventario(n);
    imprimirInventario(inventario,n);

    cout<<"\nIngrese el codigo del producto a buscar: "; cin>>codigoABuscar;
    cout<<"Buscando producto con codigo "<<codigoABuscar<<"..."<<"\n";

    Producto* hallado = buscarProducto(inventario, n, codigoABuscar);

    if(hallado != nullptr){
        cout<<"Producto encontrado: "<<hallado->nombre<<" | Precio: "<<hallado->precio<<"\n";
        
    }else{
        cout<<"No se encontro el producto"<<"\n";
    }
    liberarInventario(inventario, n);


    return 0;
}
