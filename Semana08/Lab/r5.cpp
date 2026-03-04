//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <fstream>

using namespace std;

// 1. Clase Abstracta Figura
class Figura {
private:
    string nombre;
    double* colorRGB; // Arreglo dinámico de 3 valores

public:
    // Constructor
    Figura(string nom, double r, double g, double b) : nombre(nom) {
        colorRGB = new double[3];
        colorRGB[0] = r; colorRGB[1] = g; colorRGB[2] = b;
    }

    // Constructor de copia (Deep Copy / Copia Profunda)
    Figura(const Figura& otro) : nombre(otro.nombre) {
        colorRGB = new double[3];
        for (int i = 0; i < 3; i++) colorRGB[i] = otro.colorRGB[i];
    }

    // Operador de asignación
    Figura& operator=(const Figura& otro) {
        if (this != &otro) {
            nombre = otro.nombre;
            // No olvidemos copiar el contenido del arreglo, no el puntero
            for (int i = 0; i < 3; i++) colorRGB[i] = otro.colorRGB[i];
        }
        return *this;
    }
//que entiendes por etructura
//se tiene tal clase ecriba el prototipo del constructor
//escriba el destructor de una clase
    // Destructor Virtual (Vital en POO para evitar fugas de memoria)
    virtual ~Figura() {
        delete[] colorRGB;
    }

    // Métodos virtuales puros
    virtual double area() const = 0;
    virtual double perimetro() const = 0;
    virtual void imprimir() const {
        cout << "Figura: " << nombre << " [RGB: " << colorRGB[0] 
             << "," << colorRGB[1] << "," << colorRGB[2] << "]";
    }

    string getNombre() const { return nombre; }
};

// 2. Clases Derivadas
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(string nom, double r, double g, double b, double rad) 
        : Figura(nom, r, g, b), radio(rad) {}

    double area() const override { return 3.14159 * radio * radio; }
    double perimetro() const override { return 2 * 3.14159 * radio; }
    
    void imprimir() const override {
        Figura::imprimir();
        cout << " - Circulo (Radio: " << radio << ")" << endl;
    }
};

class Rectangulo : public Figura {
private:
    double base, altura;
public:
    Rectangulo(string nom, double r, double g, double b, double bse, double alt)
        : Figura(nom, r, g, b), base(bse), altura(alt) {}

    double area() const override { return base * altura; }
    double perimetro() const override { return 2 * (base + altura); }

    void imprimir() const override {
        Figura::imprimir();
        cout << " - Rectangulo (Base: " << base << ", Altura: " << altura << ")" << endl;
    }
};

// 3. Clase Gestor de Figuras
class GestorFiguras {
private:
    Figura** figuras; // Arreglo dinámico de punteros a Figura
    int cantidad;
    int capacidad;

    void redimensionar() {
        capacidad *= 2;
        Figura** nuevo = new Figura*[capacidad];
        for (int i = 0; i < cantidad; i++) nuevo[i] = figuras[i];
        delete[] figuras;
        figuras = nuevo;
    }

public:
    GestorFiguras(int capInicial = 2) : cantidad(0), capacidad(capInicial) {
        figuras = new Figura*[capacidad];
    }

    ~GestorFiguras() {
        for (int i = 0; i < cantidad; i++) delete figuras[i];
        delete[] figuras;
    }

    void agregar(Figura* f) {
        if (cantidad == capacidad) redimensionar();
        figuras[cantidad++] = f;
    }

    void mostrarTodas() const {
        for (int i = 0; i < cantidad; i++) {
            figuras[i]->imprimir();
        }
    }

    double calcularAreaTotal() const {
        double total = 0;
        for (int i = 0; i < cantidad; i++) total += figuras[i]->area();
        return total;
    }

    void guardarEnArchivo(string nombreArchivo) {
        ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            for (int i = 0; i < cantidad; i++) {
                archivo << figuras[i]->getNombre() << "," << figuras[i]->area() << endl;
            }
            archivo.close();
            cout << "Datos guardados en " << nombreArchivo << endl;
        }
    }
};

int main() {
    GestorFiguras miGestor;

    miGestor.agregar(new Circulo("Ojo", 255, 0, 0, 5.0));
    miGestor.agregar(new Rectangulo("Puerta", 0, 255, 0, 4.0, 10.0));

    cout << "--- Listado de Figuras ---" << endl;
    miGestor.mostrarTodas();

    cout << "\nArea Total: " << miGestor.calcularAreaTotal() << endl;
    
    miGestor.guardarEnArchivo("figuras.txt");

    return 0;
}