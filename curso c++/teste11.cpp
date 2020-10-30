#include <iostream>
using namespace std;
int main (){

    int vetor [5];
    int i;

    // cada vetor tem 4 bytes = 20 entao /4 para dar 2 bytes
    vetor[0]=1;
    vetor[1]=20;
    vetor[2]=3;
    vetor[3]=40;
    vetor[4]=5;


    // for (i=0; i<5; i++ )
    for (i=0; i<sizeof(vetor)/4; i++ ){
    cout << vetor[i] << "\n" ;
    // vetor[i] = vetor[0],vetor[1],vetor[2]......
    }

    system("pause");
    return 0;
}

