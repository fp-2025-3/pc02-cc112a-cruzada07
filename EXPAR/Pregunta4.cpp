#include <iostream>
using namespace std;

void agregarEstudiante(int** codigos,float** promedios,int* cantidad,int* capacidad,int nuevoCodigo,float nuevoProm){
    if (*cantidad==*capacidad){


        int nuevaCap=(*capacidad) * 2;
        int* tempCodigos=new int[nuevaCap];
        float* tempPromedios= new float[nuevaCap];

        for(int i=0;i<*cantidad;i++){


            *(  tempCodigos +i ) = *( (*codigos) +i );
            *( tempPromedios + i) = *( (*promedios) +i );
        }


        delete[] *codigos;
        delete[] *promedios;


        *codigos = tempCodigos;

        *promedios = tempPromedios;
        *capacidad = nuevaCap;
    }

    (*codigos)[*cantidad] = nuevoCodigo;
    (*promedios)[*cantidad] = nuevoProm;
    

    (*cantidad)++; 
}

void filtrarjalados(int** codigos,float** promedios,int* cantidad,int* capacidad){
    
    int cantAprobados=0;
    for (int i=0;i<*cantidad;i++){

        if( *( (*promedios) + i)  >= 10.0){
            cantAprobados++;

        }
    }


    int* nuevosCodigos = new int[cantAprobados];
    float* nuevosPromedios = new float[cantAprobados];

    int indice=0;

    for(int i=0;i<*cantidad;i++){


        if(  *((*promedios) + i)  >= 10.0   ){

            nuevosCodigos[indice] = *((*codigos) +i );
            nuevosPromedios[indice] = *((*promedios) + i);
            indice++;
        }
    }


    delete[] *codigos;
    delete[] *promedios;

    *codigos = nuevosCodigos;
    *promedios = nuevosPromedios;
    
    *cantidad = cantAprobados;
    *capacidad = cantAprobados;
}
void imprimirEstudiantes(int* codigos,float* promedios,int cantidad){
    if(cantidad == 0){
        cout<<"No hay estudiantes"<<"\n";
        return;
    }
    
    for(int i=0;i<cantidad;i++){

        cout<<"Codigo: "<<*(codigos+i)<<" Promedio: "<<*(promedios+i)<<"\n";
    }


    cout<<"\n";

}


int main() {

    int capacidad = 2;
    int cantidad = 0;
    int* codigos = new int[capacidad];
    float* promedios = new float[capacidad];


    // &     punteros dobles
    agregarEstudiante(&codigos,&promedios,&cantidad,&capacidad,101,14.5);
    agregarEstudiante(&codigos,&promedios,&cantidad,&capacidad,102,8.0);
    agregarEstudiante(&codigos,&promedios,&cantidad,&capacidad,103,16.2);
    agregarEstudiante(&codigos,&promedios,&cantidad,&capacidad,104,9.5); 
    agregarEstudiante(&codigos,&promedios,&cantidad,&capacidad,105,12.3);



    cout<<"Estudiantes registrados:"<<"\n";
    imprimirEstudiantes(codigos, promedios, cantidad);
    cout<<"Filtrando estudiantes desaprobados...."<<"\n\n";
    filtrarjalados(&codigos,&promedios,&cantidad,&capacidad);
    cout<<"Estudiantes Aprobados:"<<"\n";
    imprimirEstudiantes(codigos,promedios,cantidad);

    //liberamos memoria
    delete[] codigos;
    delete[] promedios;

    return 0;

}
