#include <iostream>
using namespace std;

void imprimirTabla(){
    cout<<"Dec\tChar"<<endl;
    cout<<"--------"<<endl;

    for(int i = 32; i <= 126; i++){
        
        cout<<i<<"\t"<<(char)i<<endl;
    }
}

int main(){

    imprimirTabla();



    return 0;
}