#include <iostream>
using namespace std;

class Vehiculo{
    protected:   // Cambiado de private a protected
        int ruedas;
        string color;

    public:
        Vehiculo(int r, string c): ruedas(r), color(c){}

        void mostrarInfo(){
            cout << "Numero de ruedas del vehiculo: " << ruedas << "\n";
            cout << "Color del vehiculo: " << color << "\n";
        }

        // Destructor
        ~Vehiculo(){
        }
};

// Clase derivada
class Coche : public Vehiculo{
    private:
        int numeroPuertas;

    public:
        Coche(int r, string c, int np) 
            : Vehiculo(r, c), numeroPuertas(np) {}

        void mostrarCoche(){
            cout << "Numero de puertas de la moto: " << numeroPuertas << "\n";
            cout << "Color de la moto: " << color << "\n";
            cout << "Numero de ruedas de la moto: " << ruedas << "\n";
        }
};

class Moto : public Vehiculo{
    private:
        bool concasco;

    public:
        Moto(int r, string c, bool casco) 
            : Vehiculo(r, c), concasco(casco) {}

        void mostrarMoto(){
            cout << "Casco lleva moto: " << concasco << "\n";
            cout << "Color del coche: " << color << "\n";
            cout << "Numero de ruedas del coche: " << ruedas << "\n";
        }
        ~Moto(){

        }
};


int main(){
    Coche miCoche(4, "Rojo", 5);
    Moto m1(2,"Negro", true);
    cout << "Informacion general del vehiculo:\n";
    miCoche.mostrarInfo();

    cout << "\nInformacion especifica del coche:\n";
    miCoche.mostrarCoche();



    cout << "Informacion general del vehiculo:\n";
    m1.mostrarInfo();

    cout << "\nInformacion especifica de la moto:\n";
    m1.mostrarMoto();
    
    return 0;
}