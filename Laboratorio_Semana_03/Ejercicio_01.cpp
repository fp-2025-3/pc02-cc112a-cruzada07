#include <iostream>
using namespace std;

int longitud_palabra(const char* p){
    int len = 0;
    while(p[len] != '\0' && p[len] != ' '){
        len++;
    }
    return len;
}


int separar_palabras(char* texto, char* palabras[]){
    int i=0;
    char* p=texto;
    while(*p != '\0'){
        if( (p==texto && *p != ' ') || (*(p-1) == ' ' ) && (*p != ' ') ){
            palabras[i] = p;
            i++;
        }
        p++;
    }
    return i;
}


void clasificar(char* palabras[], int n, char* cortas[], int& nc, char* largas[], int& nl){
    nc = nl = 0;
    for(int i = 0; i < n; i++){
        if(longitud_palabra(palabras[i]) <= 3) cortas[nc++] = palabras[i];
        else largas[nl++] = palabras[i];

    }


}

int comparar_palabras(const char* a, const char* b){
    int i=0;

    while(a[i] != ' ' && a[i] != '\0' && b[i] != ' ' && b[i] != '\0'){
        if(a[i] != b[i]){
            return a[i] - b[i];
        }
        i++;
    }
    if(   (a[i] == ' ' || a[i] == '\0') && (b[i] == ' ' || b[i] == '\0')   ){
        return 0;
    }
    if( (b[i] == ' ' || b[i] == '\0')  ){
        return 1;
    }
    return -1;
}

void intercambiar(char* &a, char* &b){   
    char* temp = a;
    a = b;
    b = temp;
}

void ordenar(char* v[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i;j++){
            if(comparar_palabras(v[j], v[j + 1]) > 0){
                
                intercambiar(v[j], v[j + 1]);
            }

        }
    }

}


void imprimir_grupo(const char* titulo, char* v[], int n){
    cout<<"Palabras "<<titulo<<":"<<endl;
    for(int i=0; i<n; i++){
        char* p = v[i];
        while(*p != '\0' && *p != ' '){
            cout<<*p;
            p++;
        }
        cout<<endl;
    }
    cout<<endl;
}
int main() {
    char texto[300] =  "Programar en C++ requiere logica C++ exige diciplina";
    char* palabras[60];
    char* cortas[60];
    char* largas[60];
    int n,nc , nl;

    n = separar_palabras(texto, palabras);
    clasificar(palabras, n,cortas, nc, largas ,nl);

    ordenar(cortas,nc);
    ordenar(largas,nl);

    imprimir_grupo("cortas",cortas, nc);
    imprimir_grupo("largas", largas,nl);

    return 0;
}