#include <iostream>
#include <cstdlib>
#include <ctime>// time para time(null)

using namespace std;

int main(){

    double n;
    char c[20];

    cin>>c;
    n=atof(c);// atof vai converter char em double no caderno tem mais exemplos
    cout << n <<"\n\n";

    srand(time(NULL));//vai gerar novos numeros para rand a cada inicializacao
    for(int i=0;i<10;i++){
        cout << rand()%100 << endl;//rand gera numeros aleatorios,somente na 1 vez
    }

cout << endl;

    int tam=10,num;
    int *vetor;
    vetor=(int*)malloc(sizeof(int));

    srand(time(NULL));
    for(int i=0;i<10;i++){
        vetor[i]=rand()%100;
        cout << vetor[i] << endl;
    }

    system("pause");
    return 0;
}
