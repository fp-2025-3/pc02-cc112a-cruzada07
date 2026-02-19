#include <iostream>
using namespace std;
//funcion para verificar si hay 2 numeros que cumplan con la suma
void verificarSuma(int* arr, int tam, int k){


    int* inicio = arr;            
    int* fin = arr + (tam - 1);  

    bool encontrado= false;
    // Mientras los punteros no se crucen
    while(inicio<fin){
        int sumaActual = *inicio + *fin;

        if(sumaActual == k){
            encontrado = true;
            break; //terminado
        }if(sumaActual < k){
            inicio= inicio+1;
        }else{
            fin =fin -1; //estos 2 casos grcias a que el arreglo esta ascendente
        }
    }

    if (encontrado==true) {
        cout<<"SI existen 2 numeros con suma "<<k<<"\n";
    } else {
        cout<<"NO existen 2 numeros con suma "<<k<<"\n";
    }
}

int main(){
    char texto[]="1, 2, 4, 7, 11";
    int k1,k2;

    cout<<"Ingrese un numero: "; cin>>k1;
    cout<<"Ingrese otro numero: "; cin>>k2;
    cout<<"\n";
    //cambiaremos la cadena de caracteres por un arreglo de enteros:
    int numeros[100]; 
    int cantidad = 0;
    
    for(int i = 0;texto[i] != '\0';i++){
        // Si encontramos un dígito
        if(texto[i] >= '0' && texto[i] <= '9'){
            int valor = 0;
            // Mientras sigan siendo dígitos (para numeros de mas de una cifra)
            while(texto[i] >= '0' && texto[i] <= '9'){
                valor= (valor*10) + (texto[i] - '0');
                i++;
            }
            numeros[cantidad] = valor;
            cantidad++;
            
            //Retrocedemos 1 porque el for principal tambien le sumara i++
            i--; 
        }
    }

    //Imprimimos el arreglo igualito como dice la hoja
    cout<<"texto:  '";
    for(int i=0; i<4; i++){
        cout<<*(numeros+i)<<", ";
    }
    cout<<numeros[4]<<"'"<<"\n";


    verificarSuma(numeros,cantidad,k1);
    verificarSuma(numeros,cantidad,k2);

    return 0;
}

