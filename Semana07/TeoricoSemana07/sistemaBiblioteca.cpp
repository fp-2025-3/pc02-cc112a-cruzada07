#include <iostream>
#include <fstream>

using namespace std;

const int MAX_LIBROS = 100;

struct Libro {
    int codigo;
    char titulo[50];
    bool prestado;
};

void registrarLibro(Libro libros[], int &n);
int buscarLibro(Libro libros[], int n, int codigo);
void prestarLibro(Libro libros[], int n);
void devolverLibro(Libro libros[], int n);
void guardarEnArchivo(Libro libros[], int n);
void cargarDesdeArchivo(Libro libros[], int &n);
void mostrarLibros(Libro libros[], int n);

int main() {
    Libro misLibros[MAX_LIBROS];
    int cantidadLibros = 0;
    int opcion;

    cargarDesdeArchivo(misLibros, cantidadLibros);

    do {
        cout << "\n--- GESTION DE BIBLIOTECA ---\n";
        cout << "1. Registrar libro\n";
        cout << "2. Prestar libro\n";
        cout << "3. Devolver libro\n";
        cout << "4. Mostrar todos los libros\n";
        cout << "5. Guardar y Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarLibro(misLibros, cantidadLibros);
                break;
            case 2:
                prestarLibro(misLibros, cantidadLibros);
                break;
            case 3:
                devolverLibro(misLibros, cantidadLibros);
                break;
            case 4:
                mostrarLibros(misLibros, cantidadLibros);
                break;
            case 5:
                guardarEnArchivo(misLibros, cantidadLibros);
                cout << "Datos guardados. ¡Hasta pronto!\n";
                break;
            default:
                cout << "Opcion invalida. Intenta de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}

void registrarLibro(Libro libros[], int &n) {
    if (n >= MAX_LIBROS) {
        cout << "Error: La biblioteca esta llena.\n";
        return;
    }
    cout << "Ingrese codigo del libro: ";
    cin >> libros[n].codigo;
    
    cin.ignore();
    
    cout << "Ingrese titulo del libro: ";
    cin.getline(libros[n].titulo, 50);
    
    libros[n].prestado = false;
    n++;
    cout << "Libro registrado con exito.\n";
}

int buscarLibro(Libro libros[], int n, int codigo) {
    for (int i = 0; i < n; i++) {
        if (libros[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void prestarLibro(Libro libros[], int n) {
    int codigo;
    cout << "Ingrese el codigo del libro a prestar: ";
    cin >> codigo;

    int indice = buscarLibro(libros, n, codigo);
    if (indice != -1) {
        if (!libros[indice].prestado) {
            libros[indice].prestado = true;
            cout << "Libro prestado correctamente.\n";
        } else {
            cout << "El libro ya se encuentra prestado.\n";
        }
    } else {
        cout << "Libro no encontrado.\n";
    }
}

void devolverLibro(Libro libros[], int n) {
    int codigo;
    cout << "Ingrese el codigo del libro a devolver: ";
    cin >> codigo;

    int indice = buscarLibro(libros, n, codigo);
    if (indice != -1) {
        if (libros[indice].prestado) {
            libros[indice].prestado = false;
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

}cout << "Libro devuelto correctamente.\n";
        } else {
            cout << "El libro no estaba prestado.\n";
        }
    } else {
        cout << "Libro no encontrado.\n";
    }
}

void mostrarLibros(Libro libros[], int n) {
    if (n == 0) {
        cout << "No hay libros registrados.\n";
        return;
    }
    cout << "\nLISTA DE LIBROS:\n";
    for (int i = 0; i < n; i++) {
        cout << "Codigo: " << libros[i].codigo 
             << " | Titulo: " << libros[i].titulo 
             << " | Estado: " << (libros[i].prestado ? "Prestado" : "Disponible") << "\n";
    }
}

void guardarEnArchivo(Libro libros[], int n) {
    ofstream archivo("biblioteca.bin", ios::out | ios::binary);
    
    if (!archivo) {
        cout << "Error al abrir el archivo para guardar.\n";
        return;
    }

    archivo.write((char*)&n, sizeof(int));
    archivo.write((char*)libros, n * sizeof(Libro));
    
    archivo.close();
}

void cargarDesdeArchivo(Libro libros[], int &n) {
    ifstream archivo("biblioteca.bin", ios::in | ios::binary);
    
    if (!archivo) {
        return; 
    }

    archivo.read((char*)&n, sizeof(int));
    archivo.read((char*)libros, n * sizeof(Libro));
    
    archivo.close();
}