#include <iostream>
using namespace std;

class Libro {
    private:
        string titulo;
        string autor;
        int paginas;
    public:
        //constructor:
        Libro(string t, string a, int p):titulo(t), autor(a), paginas(p){
            cout<<"Se ejecuto el constructor con parametros\n";
        };
        Libro(){
            cout<<"Constructor por defecto\n";
        };
        //destructor:
        ~Libro(){

        };
        //getter:
        string getTitulo() const {
            return titulo;
        }
        
        //setter:
        void setTitulo(string t){
            titulo=t;
        }
        void mostrarInfo(){
            cout<<"Titulo: "<<titulo<<", Autor: "<<autor<<", Paginas: "<<paginas<<"\n";
        }
    
};




int main(){

    Libro libro1("El prinicipito", "Antonie", 100);
    Libro libro2("Don quijote", "Cervantes", 800);

    //cada objeto tiene su propio estado
    libro1.mostrarInfo();
    libro2.mostrarInfo();
    return 0;
}