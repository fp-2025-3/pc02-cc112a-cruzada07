#include <iostream>
#include <cstring>
using namespace std;
void fun(char* p,int tam){
    
    int contador=0;
    for(int i=1; i<tam; i++){
        
        if(( p[i-1]==' ' ) &&  (*(p+i)=='a'||'e'||'i'||'o'||'u'||'A'||'E'||'I'||'O'||'U')){
            contador++;
            
        }
        
        
    }
    if(*(p)=='a'||'e'||'i'||'o'||'u'||'A'||'E'||'I'||'O'||'U'){
        contador+=1;
    }
    cout<<"Numero de palabras que comiennzan con vocal: "<<contador;
}

int main(){
    char texto[]="Este es     un ejemplo en C++   END";
    int io= strlen(texto);
    //Imprimimos el texto
    cout<<"texto:    ";
    for(int i=0; i<io; i++){
        cout<<*(texto+i);
    }
    cout<<"\n";
    
    fun(texto,io);
    cout<<"\n";
    return 0;
}