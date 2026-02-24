#include<iostream>
using namespace std;


void leerDatos(int* coef,int g){
    for(int i=0;i<g+1;i++){
        cout<<"Ingrese el coeficiente de x^"<<g-i<<": ";cin>>coef[i];
    }
}
void mostrarDatos(int* coef, int g){
    
    for(int i=0;i<g+1;i++){
        cout<<"+"<<coef[i]<<"x^"<<g-i;
    }
}
void sumaPolinomios(int* coef1, int g1,int* coef2,int g2){
    int gMayor;
    if (g1 > g2) {
        gMayor = g1;
    } else {
        gMayor = g2;
    }
    
    int* suma = new int[gMayor+1];

    for(int i=0;i<=gMayor;i++){
        suma[i]=0;
    }

    //alinear grados
    for(int i=0;i<=g1;i++){
        suma[gMayor-g1+i]+=coef1[i];
    }

    for(int i=0;i<=g2;i++){
        suma[gMayor-g2+i]+=coef2[i];
    }

    mostrarDatos(suma,gMayor);
    delete[] suma;
}
void productoPolinomios(int* coef1, int g1,int* coef2,int g2){
    int gProd = g1 + g2;
    int* prod = new int[gProd+1];

    for(int i=0;i<=gProd;i++){
        prod[i]=0;
    }

    for(int i=0;i<=g1;i++){
        for(int j=0;j<=g2;j++){
            prod[i+j]+=coef1[i]*coef2[j];
        }
    }

    mostrarDatos(prod,gProd);
    delete[] prod;
}
int evaluarPolinomio(int* coef, int g, int x){
    int resultado = 0;
    for(int i=0;i<=g;i++){
        int potencia = 1;
        for(int j=0;j<g-i;j++){
            potencia*=x;
        }
        resultado += coef[i]*potencia;
    }
    return resultado;
}
int main(){
    int g1,g2;
    cout<<"Ingrese el grado del primer polinomio: ";cin>>g1;
    cout<<"Ingrese el grado del segundo polinomio: ";cin>>g2;
    int*coef1 = new int[g1+1];
    int* coef2= new int[g2+1];
    leerDatos(coef1, g1);
    leerDatos(coef2,g2);
    cout<<"Primer polinomio: ";
    mostrarDatos(coef1, g1);
    cout<<"\nSegundo polinomio: ";
    mostrarDatos(coef2, g2);
    cout<<"\nLa suma de los polinomios es: ";
    sumaPolinomios(coef1,g1,coef2,g2);
    cout<<"\nEl producto de los polinomios es: ";
    productoPolinomios(coef1,g1,coef2,g2);

    int x;
    cout<<"\n\nIngrese el valor de x para evaluar el primer polinomio: ";
    cin>>x;

    int resultado = evaluarPolinomio(coef1,g1,x);
    cout<<"El primer polinomio evaluado en x = "<<x<<" es: "<<resultado;

    delete[] coef1;
    delete[] coef2;




    return 0;
}