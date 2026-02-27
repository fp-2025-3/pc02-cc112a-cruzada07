//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <fstream>
using namespace std;
//      ventas.dat
struct Venta {
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};
int totalRegistros(const string & nombreArchivo){
    ifstream archivo(nombreArchivo,ios ::binary);
    Venta p;
    int numero=0;
    while(archivo.read((char*)&p, sizeof(p))){
        numero++;
    }
    archivo.close();
    return numero;
}
float montoTotalVendido(const string & nombreArchivo){
    ifstream archivo(nombreArchivo,ios ::binary);
    Venta p;
    float monto=0;
    while(archivo.read((char*)&p, sizeof(p))){
        float n=(p.cantidad)*(p.precioUnitario);
        monto += n;
        
    }
    archivo.close();
    return monto;
}
void mejorVendedor(const string & nombreArchivo){
    ifstream archivo(nombreArchivo,ios ::binary);
    Venta p;
    int idvend;
    float mejormonto=0;
    while(archivo.read((char*)&p, sizeof(p))){
        if(mejormonto<(p.cantidad) * (p.precioUnitario)){
            mejormonto=(p.cantidad) * (p.precioUnitario);
            idvend=p.idVendedor;
        }
        
    }
    cout<<"\nVENDEDOR CON MAYOR RECAUDACION:\n";
    cout<<"ID Vendedor: "<<idvend;
    cout<<"\nTotal vendido: S/."<<mejormonto;
    cout<<"\n";


    archivo.close();
    return;
}
void mejorProducto(const string & nombreArchivo){
    ifstream archivo(nombreArchivo,ios ::binary);
    Venta p;
    int cant=0;
    int idMejorProc;
    while(archivo.read((char*)&p, sizeof(p))){
        if(cant<(p.cantidad)){
            cant=(p.cantidad) ;
            idMejorProc=p.idProducto;
        }
        
    }
    cout<<"\nPRODUCTO MAS VENDIDO:\n";
    cout<<"ID Producto: "<<idMejorProc;
    cout<<"\nTotal unidades: "<<cant;
    cout<<"\n";


    archivo.close();
    return;
}
void ventaSospechosa(const string & nombreArchivo){






    cout<<"\nVENTAS SOSPECHOSAS(cantidad>100):\n\n";


    return;
}


void crearReporte(const string & nombreArchivo, const string & reporteArchivo){

    ofstream reporte(reporteArchivo, ios::app);
    if(!reporte){
        cerr<<"Error\n";
        return;
    }

    reporte<<"---REPORTE GENERAL DE VENTA---\n\n";
    reporte<<"Total de registros: "<<totalRegistros(nombreArchivo);
    reporte<<"\nMONTO TOTAL VENDIDO:\n";
    reporte<<"S/."<<montoTotalVendido(nombreArchivo);
    reporte<<"\n\n------------------------------";
    mejorVendedor(nombreArchivo);
    reporte<<"\n------------------------------";
    mejorProducto(nombreArchivo);
    reporte<<"\n------------------------------";



    
    reporte.close();
}
int main(){
    string nombreArchivo="ventas.dat";
    string reporteArchivo="reporte.txt";
    crearReporte(nombreArchivo,reporteArchivo);
    

    return 0;
}