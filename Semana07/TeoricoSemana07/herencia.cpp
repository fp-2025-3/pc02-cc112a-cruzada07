#include<iostream>
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
class LibroDigital : public Libro {
    string formato;//pdf,epub,...
};


int main(){




    return 0;

}