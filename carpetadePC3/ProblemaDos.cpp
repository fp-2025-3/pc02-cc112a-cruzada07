#include <iostream>
#include <cstring>
using namespace std;
void fun(char* p,int tam){
    
    int contador=0;
    for(int i=1; i<tam; i++){
        
        if(( p[i-1]==' ' ) &&  (*(p+i)=='a'||*(p+i)=='e'||*(p+i)=='i'||*(p+i)=='o'||*(p+i)=='u'||*(p+i)=='A'||*(p+i)=='E'||*(p+i)=='I'||*(p+i)=='O'||*(p+i)=='U')){
            contador++;
            
        }
        
        
    }
    if(*(p)=='a'||*(p)=='e'||*(p)=='i'||*(p)=='o'||*(p)=='u'||*(p)=='A'||*(p)=='E'||*(p)=='I'||*(p)=='O'||*(p)=='U'){ 
        //esta era la solucion al error que le comente en el examen
        // *p == a||b||c|| d...    MAL
        // *p == a||*p==b ||*p==c|| ....   Correcto
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
