#include <iostream>
using namespace std;

class Persona{
    private: //atributos
        int edad;
        string nombre;
    public: //metodos
        Persona(int, string);  //contructor
        void leer();
        void correr();
};

Persona::Persona(int _edad, string _nombre){
    edad=_edad;
    nombre=_nombre;
}

void Persona::leer(){
    cout<<"\nSoy "<<nombre<<" y tengo estoy leyendo un libro\n";
}
void Persona::correr(){
    cout<<"\nSoy "<<nombre<<" y tengo estoy corriendo\n";
}
int main(){
    Persona p1=Persona(18,"Julio");
    p1.leer();
    p1.correr();

    return 0;
}