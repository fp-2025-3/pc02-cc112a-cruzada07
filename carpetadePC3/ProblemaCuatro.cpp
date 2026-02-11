#include <iostream>
using namespace std;

int guardaDirecciones(char* texto, char** indice){
    int n = 0;
    char* actual = texto;
    bool buscaPalabras = true;

    while(*actual != '\0'){
        if(*actual == ' '){
            buscaPalabras = true;
        }else if(buscaPalabras){
            *(indice + n) = actual; 
            n++;
            buscaPalabras = false;
        }
        actual++; 
    }
    return n; 
}


int comparar(const char* a, const char* b) { //es la funcion strcmp
    while (*a && (*a == *b)) {
        a++;
        b++;
    }
    return *a - *b; //quite el unsigned char porque al final no es necesario
}


void ordenarIndice(char** indice, int n){
    for(int i=0;i< n-1;i++){
        for(int j =0;j<n -i-1;j++){
            char* pal1 = *(indice+j);
            char* pal2 = *(indice+j+1);

            if(comparar(pal1, pal2)>0){
            	
            	
                char* temp = *(indice+j);
                *(indice+j) = *(indice+j+1);
                *(indice+j+1) = temp;
            }
        }
        
        
    }
}


void imprimir(char* texto, char** indice, int n){
    for(int i=0;i<n;i++){
        char* palabra = *(indice + i);
        char* p = palabra;
        while(*p !=' ' && *p !='\0'){
            cout<<*p;
            p++;
        }
        int len =p-palabra;
        if(len<8){
        	cout<<"\t\t";
		}else{
        	cout<<"\t";
		}
		
        long posicion= palabra-texto; 
        cout<<"(posicion "<<posicion<<")"<<endl;
    }
}







int main(){

    char texto[]= "los punteros no se copian se referencian y se ordenan";
    char* indice[100]; 
    int n = guardaDirecciones(texto, indice);

    ordenarIndice(indice, n);

    imprimir(texto, indice, n);

    return 0;
}
