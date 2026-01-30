#include <iostream>
using namespace std;

int guardarDirecciones(char* texto, char** indice){

}


int comparar(const char* a, const char* b) { //es la funcion strcmp
    while (*a && (*a == *b)) {
        a++;
        b++;
    }
    return *(unsigned char*)a - *(unsigned char*)b; //unsigned para quitar signos (+) y/o (-)
}


void ordenarIndice(char** indice, int n){

}


void imprimir(char* texto, char** indice, int n){

}






void burb(char* p,int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){

        }
    }



}


int main(){

    char texto[]= "los punteros no se copian se referencian y se ordenan";

    return 0;
}