#include <iostream>
using namespace std;

int my_strlen(const char* str){ //firma
    const char* p = str;
    while(*p != '\0'){
        p++; 
    }

    return p - str;
}

int main(){
    const char* texto = "Hola";
    int longitud = my_strlen(texto);

    cout<<"La palabra '"<<texto<<"' tiene "<<longitud<<" letras"<<endl;

    const char* frase = "FUndamentos de Programacion";
    int longitudFrase = my_strlen(frase);

    cout<<"La frase '"<<frase<<"' tiene "<<longitudFrase<<" caracteres"<<endl;

    return 0;
}