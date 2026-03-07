//Autor: Kevin de la Cruz Sanchez
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
double PIvalor=3.14;

class Sensor{
    protected:
        string id;
        double* posicion;

    public:

        Sensor(string id,double x,double y){
            this->id=id;
            posicion=new double[2];
            posicion[0]=x;
            posicion[1]=y;
        }

        Sensor(const Sensor &s){
            id=s.id;
            posicion=new double[2];
            posicion[0]=s.posicion[0];
            posicion[1]=s.posicion[1];
        }

        Sensor& operator=(const Sensor &s){

            if(this!=&s){
                delete[] posicion;

                id=s.id;
                posicion=new double[2];
                posicion[0]=s.posicion[0];
                posicion[1]=s.posicion[1];
            }

            return *this;
        }

        virtual ~Sensor(){
            delete[] posicion;
        }

        virtual double areaCobertura() const =0;
        virtual bool detecta(double x,double y) const =0;
        virtual void imprimir() const =0;
};


class SensorCircular:public Sensor{

    private:
        double radio;

    public:

        SensorCircular(string id,double x,double y,double r) :Sensor(id,x,y){
            radio=r;
        }

        double areaCobertura() const{
            return PIvalor*radio*radio;
        }

        bool detecta(double x,double y) const{

            double dx=x-posicion[0];
            double dy=y-posicion[1];

            double d=sqrt(dx*dx + dy*dy);

            return d<=radio;
        }

        void imprimir() const{

            cout<<"Sensor Circular\n";
            cout<<"ID: "<<id<<endl;
            cout<<"Posicion: ("<<posicion[0]<<","<<posicion[1]<<")\n";
            cout<<"Radio: "<<radio<<endl;
            cout<<"Area: "<<areaCobertura()<<endl;
        }
};


class SensorRectangular:public Sensor{

    private:
        double ancho;
        double alto;

    public:

        SensorRectangular(string id,double x,double y,double a,double h)
            :Sensor(id,x,y){

            ancho=a;
            alto=h;
        }

        double areaCobertura() const{
            return ancho*alto;
        }

        bool detecta(double x,double y) const{

            double xmin=posicion[0]-ancho/2;
            double xmax=posicion[0]+ancho/2;

            double ymin=posicion[1]-alto/2;
            double ymax=posicion[1]+alto/2;

            return (x>=xmin && x<=xmax && y>=ymin && y<=ymax);
        }

        void imprimir() const{

            cout<<"Sensor Rectangular\n";
            cout<<"ID: "<<id<<endl;
            cout<<"Posicion: ("<<posicion[0]<<","<<posicion[1]<<")\n";
            cout<<"Ancho: "<<ancho<<endl;
            cout<<"Alto: "<<alto<<endl;
            cout<<"Area: "<<areaCobertura()<<endl;
        }
};


class SistemaSensores{

    private:
        Sensor** sensores;
        int cantidad;
        int capacidad;

    public:

        SistemaSensores(int cap=5){
            capacidad=cap;
            cantidad=0;
            sensores=new Sensor*[capacidad];
        }

        ~SistemaSensores(){

            for(int i=0;i<cantidad;i++)
                delete sensores[i];

            delete[] sensores;
        }

        void agregarSensor(Sensor* s){

            if(cantidad==capacidad){

                capacidad*=2;

                Sensor** nuevo=new Sensor*[capacidad];

                for(int i=0;i<cantidad;i++)
                    nuevo[i]=sensores[i];

                delete[] sensores;

                sensores=nuevo;
            }

            sensores[cantidad++]=s;
        }

        void mostrarSensores() const{

            for(int i=0;i<cantidad;i++){
                sensores[i]->imprimir();
                cout<<endl;
            }
        }

        double areaTotalCobertura() const{

            double suma=0;

            for(int i=0;i<cantidad;i++)
                suma+=sensores[i]->areaCobertura();

            return suma;
        }

        int sensoresQueDetectan(double x,double y) const{

            int cont=0;

            for(int i=0;i<cantidad;i++){

                if(sensores[i]->detecta(x,y))
                    cont++;
            }

            return cont;
        }

        Sensor* sensorMayorCobertura() const{

            if(cantidad==0) return nullptr;

            int pos=0;

            for(int i=1;i<cantidad;i++){

                if(sensores[i]->areaCobertura()>sensores[pos]->areaCobertura())
                    pos=i;
            }

            return sensores[pos];
        }
};


int main(){

    SistemaSensores sistema;

    int opcion;

    do{

        cout<<"\nMENU\n";
        cout<<"1. Agregar sensor circular\n";
        cout<<"2. Agregar sensor rectangular\n";
        cout<<"3. Mostrar sensores\n";
        cout<<"4. Area total cobertura\n";
        cout<<"5. Sensores que detectan un punto\n";
        cout<<"6. Sensor mayor cobertura\n";
        cout<<"0. Salir\n";

        cin>>opcion;

        if(opcion==1){

            string id;
            double x,y,r;

            cout<<"ID: ";cin>>id;
            cout<<"Posicion x y: ";cin>>x>>y;
            cout<<"Radio: ";cin>>r;

            sistema.agregarSensor(new SensorCircular(id,x,y,r));
        }

        else if(opcion==2){

            string id;
            double x,y,a,h;

            cout<<"ID: ";cin>>id;
            cout<<"Posicion x y: ";cin>>x>>y;
            cout<<"Ancho: ";cin>>a;
            cout<<"Alto: ";cin>>h;

            sistema.agregarSensor(new SensorRectangular(id,x,y,a,h));
        }

        else if(opcion==3){

            sistema.mostrarSensores();
        }

        else if(opcion==4){

            cout<<"Area total: "<<sistema.areaTotalCobertura()<<endl;
        }

        else if(opcion==5){

            double x,y;
            cout<<"Punto x y: ";cin>>x>>y;

            cout<<"Sensores que detectan: "
                <<sistema.sensoresQueDetectan(x,y)<<endl;
        }

        else if(opcion==6){

            Sensor* s=sistema.sensorMayorCobertura();

            if(s)
                s->imprimir();
        }

    }while(opcion!=0);

    return 0;
}
