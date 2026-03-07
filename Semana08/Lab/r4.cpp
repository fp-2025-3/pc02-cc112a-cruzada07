//Autor: Kevin de la Cruz Sanchez
#include<iostream>
#include <fstream>
using namespace std;

class Figura{
    private:
        string nombre;
        double* colorRGB;


    public:
    Figura(string nom, double r, double g, double b): nombre(nom){
        colorRGB=new double[3];
        colorRGB[0]=r;
        colorRGB[1]=g;
        colorRGB[2]=b;
    }

    Figura(Figura & otro): nombre(otro.nombre){
        //colorRGB = new double[    ]


    }

    virtual double area() const = 0;
    virtual double perimetro() const =0;
};
int main(){




    return 0;
}