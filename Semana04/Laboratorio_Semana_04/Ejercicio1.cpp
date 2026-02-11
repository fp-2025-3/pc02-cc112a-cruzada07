#include <iostream>
#include<cstring>
#include <cctype>
using namespace std;
//1y2
char* leerfrase(){
    char temp[100];
    cout<<"Ingrese frase: ";
    cin.getline(temp,100);
    //realizar asignacion dinameica
    //Hola
    int len= strlen(temp);
    char* frase = new char[len+1];
    strcpy( frase,temp);
    
    return frase;
} 
// bienvenido    a  la capital    del peru
// bienvenidoalacapitaldelperu



//3
char* normalizarFrase(char* frase){
    int len= strlen(frase);
    char* temp=new char[len+1];
    int j=0;
    bool esEspacio = true;
    for(int i=0; frase[i] != '\0';i++){
        if(!isspace(frase[i])){
            temp[j]= tolower(frase[i]);
            j++;
            esEspacio=false;
        }else{
            if(!esEspacio){
                temp[j]=' ';
                j++;
                esEspacio=true;
            }
        }
    }   
    if(j>0 && temp[j-1] == ' '){
        j--;
    }
    temp[j] = '\0';
    char* normalizada = new char[j+1];
    strcpy(normalizada, temp);

    delete[] temp;
    return normalizada;





    /*
    while(frase[i] != '\0'){
        if(!isspace(frase[i])){
            temp[j]= tolower(frase[i]);
            j++;
        }else{
            temp[j]=' ';
            j++;
        }
        i++;
    }
        temp[j] ='\0';
    char* normalizada = new char[j+1];
    strcpy(normalizada, temp);
    return normalizada;
    */
    
}
//toupper
//tolower lo vuelve min todo


//4
int contarPalabras(char* frase){
    if(strlen(frase) == 0 ){
        return 0;
    }
    int contador =0;
    bool enPalabra = false;
    for(int i=0; frase[i] != '\0';i++ ){
        if(frase[i] != ' '   &&  !enPalabra){
            enPalabra = true;
            contador++;
        } else if(frase[i] == ' '){
            enPalabra = false;
        }


    }
    return contador;
}


//5
char** ArregloPalabras(char* frase, int num){
    char**lista = new char*[num];
    char temp[100];
    strcpy(temp, frase);
    char* token = strtok(temp, " ");
    int i=0;
    while(token != NULL){
        int len = strlen(token);
        lista[i]=new char[len+1];
        strcpy(lista[i], token);


        token = strtok(NULL, " ");
        i++;
    }
    return lista;
}









int main(){
    char* MIFRASE = leerfrase();
    cout<<"\nFrase original: "<<MIFRASE<<"\n";
    char* fraseN = normalizarFrase(MIFRASE);
    cout<<"Frase normalizada: "<<fraseN<<"\n";
    delete[] MIFRASE;
    int cantidad = contarPalabras(fraseN);
    cout<<"Cantidad de palabras: "<<cantidad<<"\n";

    if(cantidad >0){
        char** listaPalabras = ArregloPalabras(fraseN, cantidad);
        cout<<"LISTA DE PALABRAS:"<<"\n"; 
        for(int i=0; i<cantidad; i++){
            cout<<"Palabra: "<<listaPalabras[i]<<"\n";
            cout<<"Longitud: "<<strlen(listaPalabras[i] ) <<"\n"; 
        }

        //liberamos
        for(int i=0; i<cantidad; i++){
            delete[] listaPalabras[i];
        }
        delete[] listaPalabras;
    }

    delete[] fraseN;
    return 0;
}














