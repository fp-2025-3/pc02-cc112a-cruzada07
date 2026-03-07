//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <fstream>
using namespace std;
struct Estudiante{
    int codigo;
    char nombre[20];
    int nota1;
    int nota2;
    int nota3; //quito el float promedio
};


void leerArchivo(const string & nombreArchivo){
    ifstream archivo(nombreArchivo);
    if(!archivo){
        cerr<<"Error al leer notas.txt\n";
        return;
    }
    Estudiante p;
    cout<<"\nLISTA DE ESTUDIANTES\n\n";
    while(archivo>>p.codigo>>p.nombre>>p.nota1>>p.nota2>>p.nota3){
        cout<<"Codigo: "<<p.codigo<<"\tNombre: "<<p.nombre<<"\tNota1: "<<p.nota1<<"\tNota2: "<<p.nota2<<"\tNota 3: "<<p.nota3<<"\n";
    }
    archivo.close();

}

float calcularPromedio(const string & nombreArchivo, int codigo){
    ifstream archivo(nombreArchivo);
    if(!archivo){
        cerr<<"Error al leer notas.txt\n";
        return -1;
    }
    Estudiante p;
    while(archivo>>p.codigo>>p.nombre>>p.nota1>>p.nota2>>p.nota3){
        if(p.codigo == codigo){

            archivo.close();
            return (p.nota1+p.nota2+p.nota3)/3.00; //cambio de 3 a 3.00 
        }
    }

    archivo.close();
    return -1;
}

void escribirReporte(const string & reporte,const string & nombreArchivo){
    
    ifstream archivo(nombreArchivo);
    if(!archivo){
        cerr<<"Error al abrir notas.txt\n";
        return ;

    }

    ofstream archivoReporte(reporte);  //cambio orden, ifstream antes del ofstream 
    if(!archivoReporte){
        cerr<<"Error al abrir reporteAlumnos.txt\n";
        return ;

    }

    Estudiante p;
    int cont=0;
    float suma=0;
    float mayorPromedio=-1;  //cambio de 0 a -1
    string nombreMayor;
    float menorPromedio=21;  //cambio de 20 a 21
    string nombreMenor;
    archivoReporte<<"Codigo\tNombre\tPromedio\tCondicion\n";
    while(archivo>>p.codigo>>p.nombre>>p.nota1>>p.nota2>>p.nota3){

        float promedio = calcularPromedio(nombreArchivo, p.codigo); //usamos la funcion correcta de promedio

        archivoReporte<<p.codigo<<"\t"<<p.nombre<<"\t"<<promedio<<"\t";
        
        if(p.nota1<5 || p.nota2<5 || p.nota3<5){ //cambio de | a ||
            archivoReporte<<"DESAPROBADO POR REGLA ACADEMICA\n";
        }
        else if(promedio>=10){
            archivoReporte<<"APROBADO\n";
        }
        else{
            archivoReporte<<"DESAPROBADO\n";
        }
        
        suma += promedio;
        cont++;
        if(promedio>mayorPromedio){
            mayorPromedio=promedio;
            nombreMayor=p.nombre;
        }

        if(promedio<menorPromedio){
            menorPromedio=promedio;
            nombreMenor=p.nombre;
        }


    }
    
    
    archivoReporte<<"\n";
    


    if(cont>0){  //usamos if
        archivoReporte<<"Total de estudiantes: "<<cont<<"\n";
        archivoReporte<<"Promedio general del curso: "<<suma/cont<<"\n";
        archivoReporte<<"Mayor promedio: "<<nombreMayor<<" "<<mayorPromedio<<"\n";
        archivoReporte<<"Menor promedio: "<<nombreMenor<<" "<<menorPromedio<<"\n";
    }
    
    archivo.close();
    archivoReporte.close();
    


}

int main(){

    string nombreArchivo="notas.txt";
    string reporte = "reporteAlumnos.txt";

    leerArchivo(nombreArchivo);
    escribirReporte(reporte, nombreArchivo);
    return 0;
}
