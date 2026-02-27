//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <fstream>
using namespace std;
struct Estudiante{
    int codigo;
    char nombre[20];
    int nota1;
    int nota2;
    int nota3;
    float promedio;
};


void leerArchivo(const string & nombreArchivo){
    ifstream archivo(nombreArchivo);
    if(!archivo){
        cerr<<"Error al leer notas.txt\n";
        return;
    }
    Estudiante p;
    cout<<"\n";
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
    cout<<"\n";
    while(archivo>>p.codigo>>p.nombre>>p.nota1>>p.nota2>>p.nota3){
        if(p.codigo == codigo){
            p.promedio=(p.nota1 + p.nota2 + p.nota3  )/3;
            return p.promedio;
        }else{ //en caso el codigo este mal escrito
            cerr<<"Este codigo No existe\n";
            return -1;
        }

    }
    archivo.close();
    return -1;
}

void escribirReporte(const string & reporte,const string & nombreArchivo){
    ofstream archivoReporte(reporte, ios::app);
    if(!archivoReporte){
        cerr<<"Error al abrir reporteAlumnos.txt\n";
        return ;

    }
    ifstream archivo(nombreArchivo);
    if(!archivo){
        cerr<<"Error al abrir notas.txt\n";
        return ;

    }
    Estudiante p;
    int cont=0;
    float suma=0;
    float mayorPromedio=0;
    string nombreMayor;
    float menorPromedio=20;
    string nombreMenor;
    archivoReporte<<"Codigo\tNombre\tPromedio\tCondicion\n";
    while(archivo>>p.codigo>>p.nombre>>p.nota1>>p.nota2>>p.nota3){
        p.promedio=(p.nota1 + p.nota2 + p.nota3  )/3;
        archivoReporte<<p.codigo<<"\t"<<p.nombre<<"\t"<<p.promedio;
        if(p.promedio>=10){
            archivoReporte<<"\tAPROBADO\n";
        }
        if(p.promedio<10){
            if(p.nota1 <5 |p.nota2 <5 |p.nota3 <5 ){
            archivoReporte<<"\tDESAPROBADO POR REGLA ACADEMICA\n";
            }else{
            archivoReporte<<"\tDESAPROBADO\n";
            }
            
        }
        
        suma += p.promedio;
        cont++;
        if(menorPromedio>p.promedio){
            menorPromedio=p.promedio;
            nombreMenor=p.nombre;
        }
        if(mayorPromedio<p.promedio){
            mayorPromedio=p.promedio;
            nombreMayor=p.nombre;
        }


    }
    
    
    archivoReporte<<"\n";
    archivoReporte<<"Total de estudiantes: "<<cont<<"\n";
    double promGen=suma/cont;
    archivoReporte<<"Promedio general del Curso: "<<promGen<<"\n";
    archivoReporte<<"El estudiante con mayor promedio: "<<nombreMayor<<"\t"<<mayorPromedio<<"\n"; //aunque hay varios alumnos que tiene 19 de promedio(nombro solo al primero)
    archivoReporte<<"El estudiante con menor promedio: "<<nombreMenor<<"\t"<<menorPromedio<<"\n";
    
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
