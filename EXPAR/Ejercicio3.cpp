#include <iostream> //borro cstring (no usare)
using namespace std;

const int 4;
bool esFilaDominanteEstricta(int (*M)[N],int f){ //termino la primera funcion
    bool hayM=false;

    for(int j=0;j<N;j++ ){
        int vF= *(*(M+f)+j);
        
        for(int i=0;i<N;i++){
            if(i != f){
                if(vF< *(*(M+i)+j )){
                    return false;
                }
            }
        }

        bool mCol=true;
        for(int i=0;i<N;i++){
            if(i != f && vF<= *(*(M+i)+ j)){
                mCol= false;
            }


        }
        if (mCol){
            hayM = true;

        }

    }
    return hayM;
}






bool esFilaFuertementeDominante(int (*M)[N],int f){ //termino la segunda
    if(!esFilaDominanteEstricta(M,f)){
        return false;

    }

    int sF=0;
    for(int j=0;j<N;j++){
        sF += *(*(M+f)+j);
    }

    for(int i=0;i<N;i++){

        if(i != f){
            int sI=0;
            for(int j=0;j<N;j++){
                sI += *(*(M+i)+j);

            }
            if(sF <= sI){
                return false;
            }
        }


    }
    return true;
}

int main(){
    int M[N][N]={
        {2,3,-1,4},
        {1,2,3,2},
        {5,6,7,8},
        {0,1,2,1}
    };

    cout<<"Fila\tD. Estricta\tF. Dominante"<<"\n";
    cout<<"----------------------------------"<<"\n";

    for(int i=0;i<N;i++){

        bool dE= esFilaDominanteEstricta(M,i);
        bool fD= esFilaFuertementeDominante(M,i);

        cout<<i<<"\t";
        if(dE){
            cout<<"SI\t\t";
        }else{

            cout<<"NO\t\t";
        }
        if(fD){
            cout<<"SI"<<"\n";
        }else{
            cout<<"NO"<<"\n";

        }


    }

    return 0;
}
