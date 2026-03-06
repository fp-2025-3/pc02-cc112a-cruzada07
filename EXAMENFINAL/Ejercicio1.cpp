//Autor: Kevin de la Cruz Sanchez
#include <iostream>
using namespace std;

int** crearMatriz(int n, int m){
    int** matriz = new int*[n];
    for (int i=0;i<n;i++){
        matriz[i] = new int[m];
    }

    return matriz;
}

void llenarMatriz(int** M, int n, int m){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            M[i][j]=(i+1)*(j+1);

        }
    }
    
}

int* sumaFilas(int** M, int n,int m){
    int* sfil= new int[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sfil[i]+=M[i][j];

        }
    }

    return sfil;
}

void liberarMatriz(int** M, int n){
    for(int i=0;i<n;i++){
        delete[] M[i];

    }

    delete[] M;
}

int main(){


    int n,m;
    cout<<"Ingrese numero de filas: ";cin>>n;
    cout<<"Ingrese numero de columnas: ";cin>>m;
    int** M= crearMatriz(n,m);
    llenarMatriz(M,n,m);
    int* sfilas=sumaFilas(M, n,m);
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<"\nSuma de elementos de la fila "<<i+1<<": "<<sfilas[i];
    }
    cout<<"\n";

    liberarMatriz(M,n);



    return 0;
}