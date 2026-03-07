//Autor: Kevin de la Cruz Sanchez
#include <iostream>
using namespace std;

void sumarPolinomios(int* coef1,int* coef2, int* coef3, int g1, int g2, int g3){
    int gradMayor=g1;
    if(g2>gradMayor){
        gradMayor=g2;
    }
    if(g3>gradMayor){
        gradMayor=g3;
    }

    int* coefsuma = new int[gradMayor+1];
    
    for(int i=gradMayor;i>= 0;i--){
        int sumaTermino=0;
        if(i<= g1){
            sumaTermino += coef1[g1-i];
        }
        if(i<= g2){
            sumaTermino += coef2[g2-i];
        }
        if(i<= g3){
            sumaTermino += coef3[g3-i];
        }
        
        coefsuma[gradMayor-i] =sumaTermino;

    }

    cout<<"Suma de los tres polinomios: ";
    for(int i=0;i<=gradMayor;i++){
        if(i>0   &&  coefsuma[i] >=0){
            cout<<" + ";

        }
        cout<<coefsuma[i]<<"x^"<<gradMayor-i;

    }
    cout<<"\n";
    delete[] coefsuma;
}

void multiplicarPolinomios(int*  coef1,int* coef2,int* coef3, int g1,int g2,int g3){
    int gradoFinal = g1+g2+g3;
    int* coefmult = new int[gradoFinal+1];
    
    for (int i=0;i<=gradoFinal;i++){
        coefmult[i] = 0;
    }

    for(int i=0;i<=g1;i++){
        for(int j=0;j<=g2;j++){
            for(int k=0;k<=g3;k++){
                coefmult[i+j+k] += coef1[i] * coef2[j] * coef3[k];
            }

        }
    }   

    cout<<"Producto de los tres polinomios: ";
    for(int i=0;i<=gradoFinal;i++){
        if(i>0  &&   coefmult[i]>=0){
            cout<<" + ";

        }
        cout<<coefmult[i]<<"x^"<<gradoFinal-i;

    }
    cout<<"\n";
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

    cout<<"Polinomio 1: ";
    for(int i=0;i<=g1;i++){
        if(coef1[i] != 0){
            if(i>0   && coef1[i]>0){
                cout<<" + ";
            }

            cout<<coef1[i]<<"x^"<<g1-i;
        }

    }

    cout << "\nPolinomio 2: ";
    for(int i=0;i<=g2;i++){
        if(coef2[i] != 0){
            if(i>0   && coef2[i]>0){
                cout<<" + ";
            }

            cout<<coef2[i]<<"x^"<<g2-i;
        }
    }
    cout << "\nPolinomio 3: ";
    for(int i=0;i<=g3;i++){
        if(coef3[i] != 0){
            if(i>0   && coef3[i]>0){
                cout << " + ";
            }

            cout<<coef3[i]<<"x^"<<g3-i;
        }
    }

    cout<<"\n\n";
    sumarPolinomios(coef1, coef2, coef3, g1, g2, g3);
    multiplicarPolinomios(coef1, coef2, coef3, g1, g2, g3);

    delete[] coef1;
    delete[] coef2;
    delete[] coef3;
    
    return 0;
}
