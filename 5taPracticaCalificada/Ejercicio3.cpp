//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const double PI = 3.14159265; //definimos valor de pi
int main() {

    const int FILAS = 21;
    const int COLUMNAS = 80;

    char grafico[FILAS][COLUMNAS]; //matriz del grafico

    for(int i=0;i<FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            grafico[i][j] = ' '; // inicializamos con espacios
        }
    }

    //dibujamos eje x
    int ejeX = FILAS/2;
    for(int j=0;j<COLUMNAS; j++){
        grafico[ejeX][j] = '-';
    }

    //dibujamos eje y
    for(int i=0;i<FILAS;i++){
        grafico[i][0] = '|';
    }

    //funcion sen5x
    for(int col=0; col<COLUMNAS;col++){


        double x = (2*PI*col)/(COLUMNAS - 1);

        double y = sin(5*x); 

        int fila = (int)((1 - y) * (FILAS - 1)/2);

        if(fila >= 0 && fila<FILAS){
            grafico[fila][col] = '*';
        }
    }

    ofstream archivo("grafico.txt");
    for(int i=0;i<FILAS;i++){
        for(int j=0;j<COLUMNAS;j++){
            archivo<<grafico[i][j];
        }
        archivo<<"\n";
    }

    archivo.close();
    cout<<"Archivo grafico.txt generado correctamente\n";

    return 0;
}
