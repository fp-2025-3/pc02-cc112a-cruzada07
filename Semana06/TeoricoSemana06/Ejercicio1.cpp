//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <fstream>
using namespace std;
const int DIAS = 7;

int main(){

    ofstream archivo("nuventas.txt", ios::app);
    if(!archivo){
        cout<<"Error al abrir el archivo";
        return 1;
    }

    double total=0.0;
    double mayorVenta=0.0;
    double menorVenta=0.0;
    double venta;

    for(int i=1;i<=DIAS;i++){

        cout<<"Ingrese la venta del dia "<<i<<": ";cin>>venta;

        archivo<<venta<<endl;
        total += venta;

        if(i == 1){
            mayorVenta = venta;
            menorVenta = venta;
        }else{
            if(venta>mayorVenta){
                mayorVenta = venta;
            }
                

            if(venta<menorVenta){
                menorVenta = venta;
            }
                
        }
    }

    double promedio = total/DIAS;

    archivo<<"-------------------------"<<"\n";
    archivo<<"RESUMEN"<<"\n";
    archivo<<"Total: "<<total<<"\n";
    archivo<<"Promedio: "<<promedio<<"\n";
    archivo<<"Mayor venta: "<<mayorVenta<<"\n";
    archivo<<"Menor venta: "<<menorVenta<<"\n";

    archivo.close();

    cout<<"\nDatos guardados correctamente en nuventas.txt\n";

    return 0;
}
