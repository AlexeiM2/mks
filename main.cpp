#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;
int main(){
    srand(time(NULL));
    clock_t t;//define variable de tiempo
    int tamanio=40000;
    int A[tamanio];
    int aux;
    //generar datos
    for(int i=0;i<tamanio;i++){
        A[i]=(1+rand()%(100-1));
    }
    //mostrar datos
    for(int i=0;i<tamanio;i++){
        cout<<A[i]<<" ";
    }
    //ordenar
    auto start = chrono::system_clock::now();//inicio conteo
    for(int i=0;i<tamanio;i++){//recorrer
        for(int j=0; j<(tamanio -1);j++){
            if(A[j]>A[j+1]){
                aux=A[j];
                A[j]=A[j+1];
                A[j+1]=aux;
            }
        }
    }
    auto end = chrono::system_clock::now();//finaloza conteo
    chrono::duration<float,milli> duration = end - start;

    //mostar
    cout<<endl;
    for(int i=0;i<tamanio;i++){
        cout<<A[i]<<" ";
    }
    cout << "\nEl metodo de burbuja se demoro " <<duration.count()<< " "
                "milisegundos en ordenar " << tamanio << " datos." << endl;

    return 0;
}
