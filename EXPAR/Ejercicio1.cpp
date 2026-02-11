//Borrado por error, igual este problema ya fue calificado
#include <iostream>
using namespace std;

int costoMaximo(int* arr,int n){
    int maximo=0;
    int producto=1;
    if(n==0){ //caso base
        return 0;
    }
    for(int i=0;i<n;i++){

        producto=producto*   *(arr + i);
        int costoResto=costoMaximo(arr+i+1, n-i-1); //movemos al siguiente y pasamos lo que ya usamos

        int total=producto+costoResto;
        if(total>maximo){

            maximo=total;
        }

    }
    return maximo;
}

int main() {
    int A[]={1,2,3,4,5};
    int n1=5;
    
    cout<<endl;
    cout<<"Costo maximo de [1 2 3 4 5]: "<<costoMaximo(A,n1)<<endl; 


    int B[] = {2,1,3};
    int n2 = 3;
    cout<<endl;
    cout<<"Costo maximo de [2 1 3]: "<<costoMaximo(B,n2)<<endl;

    return 0;
}
