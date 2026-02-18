//Me doy cuenta que en UniVirtual no subí el de tipo cpp, perdon.
//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <cstring>
using namespace std;

struct Item{
    char* descripcion;      
    int cantidad;
    double precioUnitario;
};

struct Pedido{
    int numeroPedido;
    char* nombreCliente;
    Item* items;
    int cantidadItems;
};

Item crearItem(const char* descripcion, int cantidad,double precio){

    Item nuevoItem;
    nuevoItem.descripcion = new char[strlen(descripcion)+1];
    strcpy(nuevoItem.descripcion,descripcion);
    
    nuevoItem.cantidad= cantidad;
    nuevoItem.precioUnitario= precio;
    
    return nuevoItem;
}

Pedido* crearPedido(int numero,const char* cliente, int cantidadItems){
    Pedido* p = new Pedido;

    p->numeroPedido = numero;
    p->cantidadItems = cantidadItems;

    p->nombreCliente = new char[strlen(cliente)+1];
    strcpy(p->nombreCliente,cliente);
    p->items = new Item[cantidadItems];

    cout<<"Ingrese los detalles de los "<<cantidadItems<<" items:"<<"\n";
    
    for(int i=0;i<cantidadItems;i++){

        char bufer[100];
        int cant;
        double precio;

        cout<<"\nItem #"<<i+1<<":"<<"\n";
        cout<<"Descripcion: "; cin>>bufer;
        cout<<"Cantidad: ";cin>>cant;
        cout<<"Precio: "; cin>>precio;

        *(p->items + i) = crearItem(bufer, cant, precio);

    }
    cout<<"----------------------------\n\n";

    return p;
}
double calcularTotal(const Pedido* p){

    double total=0.00;
    for(int i=0;i<p->cantidadItems;i++){
        Item* actual = (p->items + i); 
        total += (  actual->cantidad * actual->precioUnitario );

    }

    return total;
}
Item* itemMasCaro(Pedido* p){
    if(p->cantidadItems == 0){
        return nullptr;
    }
    Item* masCaro = p->items;

    for(int i=1;i<p->cantidadItems;i++){

        Item* actual = (p->items +i);
        if(actual->precioUnitario > masCaro->precioUnitario  ){
            masCaro = actual;

        }
    }

    return masCaro;
}
void liberarPedido(Pedido* p){
    if(p == nullptr){
        return;
    }

    for(int i=0;i<p->cantidadItems;i++ ){
        delete[] (p->items + i)->descripcion;
    }
    delete[] p->items;

    delete[] p->nombreCliente;
    delete p;

}
void imprimirRecibo(Pedido* p){

    cout<<"Pedido N: "<<p->numeroPedido<<"\n";
    cout<<"Cliente: "<<p->nombreCliente<<"\n";
    cout<<"\nItems:"<<"\n";
    
    for(int i=0;i<p->cantidadItems;i++){
        Item* it = (p->items  +i );
        cout<<"- "<<it->descripcion<<" | Cant: "<<it->cantidad<<" | Precio: "<<it->precioUnitario<<"\n";

    }
    
    cout<<"\nTotal: "<<calcularTotal(p)<<"\n";

}

int main(){
    int numPed=101;
    char cliente[] ="Carlos Perez";
    int cantItems=3;

    cout<<"--- CREANDO PEDIDO ---\n";
    
    Pedido* miPedido = crearPedido(numPed,cliente,cantItems );
    imprimirRecibo(miPedido);

    Item* caro = itemMasCaro(miPedido);
    if(caro != nullptr){
        cout<<"Item mas caro: "<<caro->descripcion <<" | Precio: "<<caro->precioUnitario<<"\n";

    }


    liberarPedido(miPedido);

    return 0;
}
