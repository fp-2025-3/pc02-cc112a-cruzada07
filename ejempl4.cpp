#include <iostream>
using namespace std;

char *my_strcpy(char *destination, const char *source){ //firma
    char *ptr = destination;
    while(*source != '\0'){
        *destination++ = *source++;
    }
    *destination = '\0';
    return ptr;
}

int main(){
    const char* original = "Hola Mundo";
    char copia[20];
    my_strcpy(copia,original);

    cout<<"Original: "<<original<<endl;
    cout<<"Copia:    "<<copia<<endl;

    return 0;
}