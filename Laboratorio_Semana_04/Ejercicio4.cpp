#include <iostream>
#include <cstring>

using namespace std;

int cantidad(int* p) {
    int contador = 0;
    
    while (*p != -1) {
        contador++;
        p++;
    }
    
    return contador;
}
void segmentos(int *p){
    int cant=cantidad(p);

    if(cant=1){
        cout<<*p;
    }
    if(cant>=2){
        
    }



}


int main(){
    int ct=0;
    cout<<"Ingrese la cantidad de numeros (Max 15): ";
    cin>>ct;
    while(ct>15){
        cout<<"Ingrese denuevo: "; cin>>ct;
    }
    int* p = new int[ct];
    for(int i=0;i<ct;i++){
        cout<<"Ingrese el elemento "<<i+1; cin>>p[i];
    }

    delete[] p;
    return 0;
}