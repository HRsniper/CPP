#include <iostream>

using namespace std;

int fatorial(int fatn);
int fibonacci(int fibn);

int main(){
    int valor,resultado;

    valor=10;

    resultado=fatorial(valor);
    cout << "valor do fatorial de " << valor << ": " << resultado;

    cout << "\n\nresultado dos valores do fibonacci " << valor << ": ";
    for(int indice=0; indice<valor; indice++){
        cout << fibonacci(indice+1) << ", ";
    }

    cout << "\n";

    return 0;
}

//valor= int fatn
//10! = 10 * 9 * 8 * 7 * 6 * 5 * 4* 3 * 2 * 1 = 3.628.800
int fatorial(int fatn){
    if (fatn==0){
        return 1;
    }
    return fatn*fatorial(fatn-1);
}

//0,1, 1, 2, 3, 5, 8, 13, 21, 34, 55,
int fibonacci(int fibn){
    if (fibn==1 || fibn==2){
        return 1;
    }else{
        return fibonacci(fibn-1) + fibonacci(fibn-2);
    }
}
