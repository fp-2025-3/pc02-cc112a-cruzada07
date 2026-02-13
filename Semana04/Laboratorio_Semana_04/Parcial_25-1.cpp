/*
#include <iostream>
using namespace std;
void explorarRegion(int** mapa,int filas,int cols,int x,int y){
    if(x < 0 || x >= filas || y < 0 || y >= cols){
        return;
    }
    if(mapa[x][y] == 1){
        return;
    }
    mapa[x][y] = 1;
    explorarRegion(mapa, filas, cols, x - 1, y); // Arriba
    explorarRegion(mapa, filas, cols, x + 1, y); // Abajo
    explorarRegion(mapa, filas, cols, x, y - 1); // Izquierda
    explorarRegion(mapa, filas, cols, x, y + 1); // Derecha
}
int main(){
    int filas,columnas;
    int mapaEstatico[100][100];
    int* punteroDoble[100];

    cout<<"Ingrese el numero de filas y columnas del mapa: ";cin>>filas>>columnas;
    cout<<"Ingrese los valores del mapa (0 = camino, 1 = obstaculo):"<<endl;
    for(int i=0; i<filas; i++){
        punteroDoble[i] = mapaEstatico[i];
        
        for(int j = 0; j < columnas; j++){
            cin>>mapaEstatico[i][j];
        }
    }
    int contadorRegiones = 0;
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            if(punteroDoble[i][j] == 0){
                contadorRegiones++;
                explorarRegion(punteroDoble, filas, columnas, i, j);
            }
        }
    }
    cout<<"Numero de regiones transitables conectadas: "<<contadorRegiones<<endl;
    return 0;
}
*/