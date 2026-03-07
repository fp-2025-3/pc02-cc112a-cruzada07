// Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Producto {
    int id;
    char nombre[30];
    double precio;
    int stock;
    bool activo;
};

//Buscar producto por ID
int buscarProductoPorID(const char* nombreArchivo, int idBuscado){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
        return -1;
    }

    Producto p;
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

//Registrar producto
void registrarProducto(const char* nombreArchivo){

    Producto nuevo;

    cout<<"ID: ";
    cin>>nuevo.id;

    if(buscarProductoPorID(nombreArchivo, nuevo.id) != -1){
        cout<<"ID repetido\n";
        return;
    }

    cout<<"Nombre: ";
    cin>>nuevo.nombre;

    do{
        cout<<"Precio (>0): ";
        cin>>nuevo.precio;
    }while(nuevo.precio <= 0);

    do{
        cout<<"Stock (>=0): ";
        cin>>nuevo.stock;
    }while(nuevo.stock < 0);

    nuevo.activo = true;

    ofstream archivo(nombreArchivo, ios::binary | ios::app);
    if(!archivo){
        cout<<"Error al abrir archivo\n";
        return;
    }

    archivo.write((char*)&nuevo, sizeof(nuevo));
    archivo.close();

    cout<<"✔ Producto registrado\n";
}

//Mostrar productos activos
void mostrarProductos(const char* nombreArchivo){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
        cout<<"Error al abrir archivo\n";
        return;
    }

    Producto p;
    int posicion = 0;

    while(archivo.read((char*)&p, sizeof(p))){
        if(p.activo){
            cout<<"Posicion: "<<posicion
                <<" | ID: "<<p.id
                <<" | Nombre: "<<p.nombre
                <<" | Precio: "<<p.precio
                <<" | Stock: "<<p.stock<<endl;
        }
        posicion++;
    }

    archivo.close();
}

// ✏ Modificar precio (acceso aleatorio)
void modificarPrecio(const char* nombreArchivo, int id, double nuevoPrecio){
    int posicion = buscarProductoPorID(nombreArchivo, id);

    if(posicion == -1){
        cout<<"Producto no encontrado\n";
        return;
    }

    fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);
    if(!archivo){
        cout<<"Error al abrir archivo\n";
        return;
    }

    archivo.seekg(posicion * sizeof(Producto), ios::beg);

    Producto p;
    archivo.read((char*)&p, sizeof(p));

    p.precio = nuevoPrecio;

    archivo.seekp(posicion * sizeof(Producto), ios::beg);
    archivo.write((char*)&p, sizeof(p));

    archivo.close();

    cout<<"✔ Precio modificado\n";
}

//Eliminación lógica
void eliminarProducto(const char* nombreArchivo, int id){
    int posicion = buscarProductoPorID(nombreArchivo, id);

    if(posicion == -1){
        cout<<"Producto no encontrado\n";
        return;
    }

    fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);
    if(!archivo){
        cout<<"Error al abrir archivo\n";
        return;
    }

    archivo.seekg(posicion * sizeof(Producto), ios::beg);

    Producto p;
    archivo.read((char*)&p, sizeof(p));

    p.activo = false;

    archivo.seekp(posicion * sizeof(Producto), ios::beg);
    archivo.write((char*)&p, sizeof(p));

    archivo.close();

    cout<<"✔ Producto eliminado logicamente\n";
}

//Calcular valor total inventario
double calcularValorInventario(const char* nombreArchivo){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
        cout<<"Error al abrir archivo\n";
        return 0;
    }

    Producto p;
    double total = 0;

    while(archivo.read((char*)&p, sizeof(p))){
        if(p.activo){
            total += p.precio * p.stock;
        }
    }

    archivo.close();
    return total;
}

//Menú principal
int main(){
    const char* nombreArchivo = "inventario.dat";
    int opcion;

    do{
        cout<<"\n===== MENU =====\n";
        cout<<"1. Registrar producto\n";
        cout<<"2. Mostrar productos\n";
        cout<<"3. Buscar producto\n";
        cout<<"4. Modificar precio\n";
        cout<<"5. Eliminar producto\n";
        cout<<"6. Calcular valor total\n";
        cout<<"7. Salir\n";
        cout<<"Opcion: ";
        cin>>opcion;

        int id;
        double precio;

        switch(opcion){

        case 1:
            registrarProducto(nombreArchivo);
            break;

        case 2:
            mostrarProductos(nombreArchivo);
            break;

        case 3:
            cout<<"ID a buscar: ";
            cin>>id;
            {
                int pos = buscarProductoPorID(nombreArchivo, id);
                if(pos == -1)
                    cout<<"No encontrado\n";
                else
                    cout<<"Encontrado en posicion: "<<pos<<endl;
            }
            break;

        case 4:
            cout<<"ID: ";
            cin>>id;
            cout<<"Nuevo precio: ";
            cin>>precio;
            modificarPrecio(nombreArchivo, id, precio);
            break;

        case 5:
            cout<<"ID: ";
            cin>>id;
            eliminarProducto(nombreArchivo, id);
            break;

        case 6:
            cout<<"Valor total inventario: "
                <<calcularValorInventario(nombreArchivo)
                <<endl;
            break;

        case 7:
            cout<<"Saliendo...\n";
            break;

        default:
            cout<<"Opcion invalida\n";
        }

    }while(opcion != 7);

    return 0;
}