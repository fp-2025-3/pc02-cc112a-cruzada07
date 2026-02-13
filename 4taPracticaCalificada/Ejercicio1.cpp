//Autor: Kevin de la Cruz Sanchez
#include <iostream>
using namespace std;
void sumarPolinomios(int* coef1,int* coef2, int* coef3, int g1, int g2, int g3){
    int gradMayor=0;
    if(g1>=g2 && g1>=g3){
        gradMayor=g1;
    }
    if(g2>=g1 && g2>=g3){
        gradMayor=g2;
    }
    if(g3>=g1 && g3>=g2){
        gradMayor=g3;
    }
    int* coefsuma= new int [gradMayor+1];
    
    coefsuma[0]=coef1[0]+0+coef3[0];
    coefsuma[1]=coef1[1]+coef2[0]+coef3[1];
    coefsuma[2]=coef1[2]+coef2[1]+coef3[2];
    for(int i=0;i<gradMayor+1;i++){
        cout<<"+("<<coefsuma[i]<<")x^"<<gradMayor-i;
    }
    delete[] coefsuma;
}

void multiplicarPolinomios(int* coef1,int* coef2, int* coef3, int g1, int g2, int g3){
    int* coefmult = new int[(g1+g2+g3)+1];







    delete[] coefmult;
}

int main(){
    int g1=2,g2=1,g3=2;

    int* coef1 = new int[3];
    int* coef2 = new int[2];
    int* coef3 = new int[3];

    coef1[0]=1;
    coef1[1]=0;
    coef1[2]=3;

    coef2[0]=-4;
    coef2[1]=5;

    coef3[0]=3;
    coef3[1]=0;
    coef3[2]=1;
    //mostrar:
    cout<<"Polinomio 1: ";
    for(int i=0;i<3;i++){
        cout<<"+("<<coef1[i]<<")x^"<<3-i-1;
    }

    cout<<"\nPolinomio 2: ";
    for(int i=0;i<2;i++){
        cout<<"+("<<coef2[i]<<")x^"<<2-i-1;
    }

    cout<<"\nPolinomio 3: ";
    for(int i=0;i<3;i++){
        cout<<"+("<<coef3[i]<<")x^"<<3-i-1;
    }

    cout<<"\nSuma de los tres polinomios: ";
    sumarPolinomios(coef1,coef2, coef3,  g1,  g2,  g3);









    cout<<"\n";
    delete[] coef1;
    delete[] coef2;
    delete[] coef3;
    
    return 0;
}