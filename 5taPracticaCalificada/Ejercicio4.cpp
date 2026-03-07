//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <fstream>
using namespace std;

// ventas.dat
struct Venta {
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};

int totalRegistros(const string & nombreArchivo){
    ifstream archivo(nombreArchivo, ios::binary);
    Venta p;
    int numero=0;

    while(archivo.read((char*)&p, sizeof(p))){
        numero++;
    }
    archivo.close();
    return numero;
}

double montoTotalVendido(const string & nombreArchivo){ //cambiamos float por double
    ifstream archivo(nombreArchivo, ios::binary);
    Venta p;
    double monto=0;

    while(archivo.read((char*)&p, sizeof(p))){
        monto += p.cantidad * p.precioUnitario; //era innecesario el "float n"
    }
    archivo.close();
    return monto;
}

void mejorVendedor(const string & nombreArchivo, int &idMejor, double &mejorMonto){ //cambiamos firma
    ifstream archivo(nombreArchivo, ios::binary);
    Venta p;

    mejorMonto = 0;
    idMejor = 0;
    while(archivo.read((char*)&p, sizeof(p))){
        // calculamos total de este vendedor
        double totalVendedor = 0;

        ifstream archivo2(nombreArchivo, ios::binary);
        Venta q;

        while(archivo2.read((char*)&q, sizeof(q))){
            if(q.idVendedor == p.idVendedor){
                totalVendedor += q.cantidad * q.precioUnitario;
            }
        }

        archivo2.close();
        if(totalVendedor>mejorMonto){ //se actualizara el mejor vendedor si supera el monto actual
            mejorMonto = totalVendedor;
            idMejor = p.idVendedor;
        }
    }
    archivo.close();
}

void mejorProducto(const string & nombreArchivo, int &idMejorProd, int &mayorCantidad){
    ifstream archivo(nombreArchivo, ios::binary);
    Venta p;

    mayorCantidad = 0;
    idMejorProd = 0;

    while(archivo.read((char*)&p, sizeof(p))){
        int totalUnidades = 0;

        ifstream archivo2(nombreArchivo, ios::binary);
        Venta q;

        while(archivo2.read((char*)&q, sizeof(q))){
            if(q.idProducto == p.idProducto){
                totalUnidades += q.cantidad;
            }
        }
        archivo2.close();

        if(totalUnidades > mayorCantidad){
            mayorCantidad = totalUnidades;
            idMejorProd = p.idProducto;
        }
    }
    archivo.close();
}

void ventasSospechosas(const string & nombreArchivo, ofstream &reporte){
    ifstream archivo(nombreArchivo, ios::binary);
    Venta p;

    reporte << "\nVENTAS SOSPECHOSAS (cantidad > 100):\n\n";

    while(archivo.read((char*)&p, sizeof(p))){
        if(p.cantidad > 100){
            reporte<<"ID Venta: "<<p.idVenta<<" | Vendedor: "<<p.idVendedor<<" | Producto: "<<p.idProducto<<" | Cantidad: "<<p.cantidad<<"\n";

        }
    }

    archivo.close();
}

void crearReporte(const string & nombreArchivo, const string & reporteArchivo){
    ofstream reporte(reporteArchivo);

    if(!reporte){
        cerr<<"Error\n";
        return;
    }

    reporte<<"---REPORTE GENERAL DE VENTAS---\n\n";

    int total = totalRegistros(nombreArchivo);
    reporte<<"Total de registros: "<<total<<"\n\n";

    double monto = montoTotalVendido(nombreArchivo);
    reporte<<"MONTO TOTAL VENDIDO:\n";
    reporte<<"S/. "<<monto<<"\n\n";

    reporte<<"--------------------------------\n";

    int idVend;
    double mejorMonto;
    mejorVendedor(nombreArchivo, idVend, mejorMonto);

    reporte<<"VENDEDOR CON MAYOR RECAUDACION:\n";
    reporte<<"ID Vendedor: "<<idVend<<"\n";
    reporte<<"Total vendido: S/. "<<mejorMonto<<"\n\n";

    reporte<<"--------------------------------\n";

    int idProd;
    int mayorCant;
    mejorProducto(nombreArchivo, idProd, mayorCant);
    reporte<<"PRODUCTO MAS VENDIDO:\n";
    reporte<<"ID Producto: "<<idProd<<"\n";
    reporte<<"Total unidades: "<<mayorCant<<"\n";


    reporte<<"--------------------------------\n";

    ventasSospechosas(nombreArchivo, reporte);

    
    reporte.close();
}

int main(){
    string nombreArchivo="ventas.dat";
    string reporteArchivo="reporte.txt";

    crearReporte(nombreArchivo,reporteArchivo);

    cout<<"Reporte generado correctamente\n";
    return 0;
}
