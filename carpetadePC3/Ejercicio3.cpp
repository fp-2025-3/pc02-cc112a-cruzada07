#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void mostrar(int (*m)[9]){
    for(int i=0; i<9;i++){
        for(int j=0;j<9;j++){
            cout<<*(*(m+i)+j)<<" ";

        }

        cout<<"\n";
    }

}

void generarMatrices(int (*m)[9], int f, int c){
    if(f==-1){  //primera matriz
        for(int i=0;i< 9;i++){

            for(int j=0;j<9;j++){
                *(*(m+i)+j)=j+1;
            }
            
            for(int j=8;j>0;j--){

                int r=rand()%(j+1);
                int temp=*(*(m+i)+j);
                *(*(m+i)+j)=*(*(m+i)+r);
                *(*(m+i)+r)=temp;

            }


        }
    }else{  //segunda matriz
        int objetivo=*(*(m+ (f-1))+(c-1));
        
        for(int i=0;i<9;i++){
            int posActual=0;
            int *filaActual=*(m+i);


            for(int j=0;j<9;j++){
                
                if(*(filaActual+j)==objetivo){
                    posActual=j;
                    break;

                }

            }
            
            int mov=c-1-posActual;
            if(mov<0){
                mov=mov+9;
            }
            
            for(int p=0;p<mov;p++){
                int ultimo= *(filaActual+8);
                for(int j=8;j>0;j--){
                    *(filaActual+j) =*(filaActual+(j-1));

                }

                *(filaActual + 0) = ultimo;
            }


        }
    }

}

int main(){
    srand(time(NULL));
    int mat[9][9];
    int f;
    int c;

    generarMatrices(mat,-1,0);
    cout<<"Matriz inicial:"<<"\n";

    mostrar(mat);
    
    cout<<"\nFila (1-9): "; cin>>f;
    cout<<"Columna (1-9): "; cin>>c;
    cout<<"Valor seleccionado: "<<*(*(mat+(f-1))+c-1)<<"\n";
    generarMatrices(mat,f,c);
    
    cout<<"\nMatriz final:"<<"\n";
    mostrar(mat);

    return 0;
}