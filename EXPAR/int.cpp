#include <iostream>
using namespace std;
void crearfun(  char*p, int n         ){
    char* inc = p;
    while( n );
}









int main(){

    int n;
    cout<<"Ingrese el tamaño: "; cin>>n;
    char* corredores = new char[n];


    delete[] corredores;

    return 0;
}
/*
#include <iostream>

using namespace std;

// Usamos Punteros Dobles (int**) para los arreglos
// y Punteros Simples (int*) para las variables numéricas (cantidad, capacidad)
void agregarEstudiante(int** codigos, float** promedios, int* cantidad, int* capacidad, int nuevoCodigo, float nuevoPromedio) {
    
    // Accedemos al valor de cantidad usando el operador *
    if (*cantidad == *capacidad) {
        
        int nuevaCap = (*capacidad) * 2;
        
        // Creamos los nuevos arreglos
        int* tempCodigos = new int[nuevaCap];
        float* tempPromedios = new float[nuevaCap];

        // Copiamos datos del arreglo viejo al nuevo
        // Nota: (*codigos)[i] accede al arreglo original
        for (int i = 0; i < *cantidad; i++) {
            tempCodigos[i] = (*codigos)[i];
            tempPromedios[i] = (*promedios)[i];
        }

        // Liberamos la memoria vieja
        delete[] *codigos;
        delete[] *promedios;

        // ASIGNACION CRITICA:
        // Hacemos que el puntero original apunte a la nueva dirección
        *codigos = tempCodigos;
        *promedios = tempPromedios;
        
        // Actualizamos la capacidad
        *capacidad = nuevaCap;
    }

    // Agregamos el nuevo estudiante
    (*codigos)[*cantidad] = nuevoCodigo;
    (*promedios)[*cantidad] = nuevoPromedio;
    
    // Aumentamos la cantidad
    (*cantidad)++; 
}

void filtrarYRedimensionar(int** codigos, float** promedios, int* cantidad, int* capacidad) {
    
    int cantAprobados = 0;
    // Contamos aprobados
    for (int i = 0; i < *cantidad; i++) {
        if ((*promedios)[i] >= 10.0) {
            cantAprobados++;
        }
    }

    // Creamos arreglos del tamaño exacto
    int* nuevosCodigos = new int[cantAprobados];
    float* nuevosPromedios = new float[cantAprobados];

    int indice = 0;
    for (int i = 0; i < *cantidad; i++) {
        if ((*promedios)[i] >= 10.0) {
            nuevosCodigos[indice] = (*codigos)[i];
            nuevosPromedios[indice] = (*promedios)[i];
            indice++;
        }
    }

    // Borramos memoria vieja
    delete[] *codigos;
    delete[] *promedios;

    // Actualizamos los punteros originales
    *codigos = nuevosCodigos;
    *promedios = nuevosPromedios;
    
    // Actualizamos las variables de control
    *cantidad = cantAprobados;
    *capacidad = cantAprobados;
}

void mostrarEstudiantes(int* codigos, float* promedios, int cantidad) {
    // Aqui NO necesitamos punteros dobles porque solo leemos datos, no cambiamos tamaños
    if (cantidad == 0) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }
    
    for (int i = 0; i < cantidad; i++) {
        cout << "Codigo: " << codigos[i] << " Promedio: " << promedios[i] << endl;
    }
    cout << endl;
}

int main() {
    int capacidad = 2;
    int cantidad = 0;

    // Inicialización dinámica normal
    int* codigos = new int[capacidad];
    float* promedios = new float[capacidad];

    // ALERTA: Pasamos la dirección de los punteros (&codigos)
    // Esto es necesario para poder modificarlos dentro de la función sin usar referencias C++
    agregarEstudiante(&codigos, &promedios, &cantidad, &capacidad, 101, 14.5);
    agregarEstudiante(&codigos, &promedios, &cantidad, &capacidad, 102, 8.0);
    agregarEstudiante(&codigos, &promedios, &cantidad, &capacidad, 103, 16.2);
    agregarEstudiante(&codigos, &promedios, &cantidad, &capacidad, 104, 9.5); 
    agregarEstudiante(&codigos, &promedios, &cantidad, &capacidad, 105, 12.3);

    cout << "Estudiantes registrados:" << endl;
    mostrarEstudiantes(codigos, promedios, cantidad);

    cout << "Filtrando estudiantes desaprobados...." << endl << endl;
    
    // Nuevamente pasamos las direcciones
    filtrarYRedimensionar(&codigos, &promedios, &cantidad, &capacidad);

    cout << "Estudiantes Aprobados:" << endl;
    mostrarEstudiantes(codigos, promedios, cantidad);

    delete[] codigos;
    delete[] promedios;

    return 0;
}
*/








































/*
#include <iostream>

using namespace std;

// Funcion para agregar estudiante
// Recibe punteros por referencia (*&) porque la direccion de memoria puede cambiar al redimensionar
void agregarEstudiante(int*& codigos, float*& promedios, int& cantidad, int& capacidad, int nuevoCodigo, float nuevoPromedio) {
    
    // 1. Verificar si el arreglo esta lleno
    if (cantidad == capacidad) {
        // A. Duplicar capacidad
        capacidad = capacidad * 2; 
        
        // B. Crear nuevos arreglos temporales con la nueva capacidad
        int* tempCodigos = new int[capacidad];
        float* tempPromedios = new float[capacidad];

        // C. Copiar los datos de los arreglos viejos a los nuevos
        for (int i = 0; i < cantidad; i++) {
            tempCodigos[i] = codigos[i];
            tempPromedios[i] = promedios[i];
        }

        // D. Liberar la memoria de los arreglos viejos
        delete[] codigos;
        delete[] promedios;

        // E. Actualizar los punteros originales para que apunten a los nuevos
        codigos = tempCodigos;
        promedios = tempPromedios;
        
        // (Opcional) Mensaje para ver que esta ocurriendo internamente
        // cout << "[DEBUG] Capacidad duplicada a: " << capacidad << endl;
    }

    // 2. Agregar el nuevo estudiante
    codigos[cantidad] = nuevoCodigo;
    promedios[cantidad] = nuevoPromedio;
    
    // 3. Aumentar el contador de estudiantes
    cantidad++;
}

// Funcion para filtrar y ajustar al tamaño exacto
void filtrarYRedimensionar(int*& codigos, float*& promedios, int& cantidad, int& capacidad) {
    
    // 1. Contar cuantos aprobaron para saber el tamaño exacto necesario
    int cantidadAprobados = 0;
    for (int i = 0; i < cantidad; i++) {
        if (promedios[i] >= 10.0) {
            cantidadAprobados++;
        }
    }

    // Si nadie aprobo, o todos aprobaron, igual hacemos el proceso para ajustar/limpiar
    // (o podriamos optimizar, pero seguiremos la instruccion de redimensionar exacto)

    // 2. Crear arreglos del tamaño EXACTO
    int* nuevosCodigos = new int[cantidadAprobados];
    float* nuevosPromedios = new float[cantidadAprobados];

    // 3. Copiar solo los aprobados
    int indiceNuevo = 0;
    for (int i = 0; i < cantidad; i++) {
        if (promedios[i] >= 10.0) {
            nuevosCodigos[indiceNuevo] = codigos[i];
            nuevosPromedios[indiceNuevo] = promedios[i];
            indiceNuevo++;
        }
    }

    // 4. Liberar memoria vieja
    delete[] codigos;
    delete[] promedios;

    // 5. Actualizar punteros y variables de control
    codigos = nuevosCodigos;
    promedios = nuevosPromedios;
    
    cantidad = cantidadAprobados;
    capacidad = cantidadAprobados; // La capacidad ahora es exactamente igual a la cantidad
}

void mostrarEstudiantes(int* codigos, float* promedios, int cantidad) {
    if (cantidad == 0) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }
    
    for (int i = 0; i < cantidad; i++) {
        cout << "Codigo: " << codigos[i] << " Promedio: " << promedios[i] << endl;
    }
    cout << endl;
}

int main() {
    // Inicializacion Dinamica
    int capacidad = 2; // Empezamos pequeño para forzar que se duplique
    int cantidad = 0;

    int* codigos = new int[capacidad];
    float* promedios = new float[capacidad];

    // Agregamos estudiantes (se duplicara la capacidad internamente)
    agregarEstudiante(codigos, promedios, cantidad, capacidad, 101, 14.5);
    agregarEstudiante(codigos, promedios, cantidad, capacidad, 102, 8.0);
    agregarEstudiante(codigos, promedios, cantidad, capacidad, 103, 16.2); // Aqui se duplica capacidad a 4
    agregarEstudiante(codigos, promedios, cantidad, capacidad, 104, 9.5); 
    agregarEstudiante(codigos, promedios, cantidad, capacidad, 105, 12.3); // Aqui se duplica capacidad a 8

    cout << "Estudiantes registrados (" << cantidad << " de " << capacidad << " espacios):" << endl;
    mostrarEstudiantes(codigos, promedios, cantidad);

    cout << "Filtrando estudiantes desaprobados...." << endl << endl;
    filtrarYRedimensionar(codigos, promedios, cantidad, capacidad);

    cout << "Estudiantes Aprobados (" << cantidad << " de " << capacidad << " espacios):" << endl;
    mostrarEstudiantes(codigos, promedios, cantidad);

    // Buena practica: Liberar memoria al final del programa
    delete[] codigos;
    delete[] promedios;

    return 0;
}
*/
























/*

#include <iostream>
using namespace std;

int buscarBinario(int arr[], int n, int objetivo) {
    int izq = 0;           // Extremo izquierdo
    int der = n - 1;       // Extremo derecho

    while (izq <= der) {
        // Calculamos el punto medio
        int medio = izq + (der - izq) / 2;

        // Caso 1: ¡Lo encontramos en la mitad!
        if (arr[medio] == objetivo) {
            return medio;
        }

        // Caso 2: El objetivo es mayor que el medio
        // Entonces descartamos toda la mitad izquierda
        if (arr[medio] < objetivo) {
            izq = medio + 1;
        } 
        // Caso 3: El objetivo es menor que el medio
        // Entonces descartamos toda la mitad derecha
        else {
            der = medio - 1;
        }
    }
    return -1; // No se encontró después de dividir la lista
}

int main() {
    // NOTA: El arreglo ESTÁ ordenado
    int datos[] = {2, 5, 8, 14, 33}; 
    int n = 5;
    int buscar = 14;

    int indice = buscarBinario(datos, n, buscar);

    if (indice != -1)
        cout << "Binaria: Encontrado en indice " << indice << endl;
    else
        cout << "Binaria: No encontrado" << endl;

    return 0;
}
*/




