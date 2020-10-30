#include <iostream>
#include <cstdlib>

void calculo(double *soma, double valor);
void inivetor(float *v);

using namespace std;

int main(){

    double num=0;
    float vetor[3];

    calculo(&num, 15);
    cout << num << endl << endl;

    inivetor(vetor);
    for(int i=0; i<3; i++){
        cout << vetor[i] << "\n";
    }

	system("pause");
    return 0;
}
void calculo(double *soma, double valor){
    *soma+=valor;
}
void inivetor(float *v){
    v[0]=10;
    v[1]=20;
    v[2]=30;
}
