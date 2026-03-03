#include <iostream>
using namespace std;

class Rectangulo{
    private: //atributos
        float largo;
        float ancho;

    public:  //metodos
        Rectangulo(float,float);
        void perimetro();
        void area();
};
Rectangulo::Rectangulo(float _largo, float _ancho){
    largo=_largo;
    ancho=_ancho;
};
void Rectangulo::perimetro(){
    float per;
    per=2*(largo+ancho);
    cout<<"\nEl perimetro es: "<<per<<"\n";
};
void Rectangulo::area(){
    float ar;
    ar=largo*ancho;
    cout<<"\nArea es: "<<ar<<"\n";
};
int main(){
    Rectangulo r1(12.1,3.4);
    r1.perimetro();
    r1.area();
}