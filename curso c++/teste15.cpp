#include <iostream>

using namespace std;

void contador(int n1, int n2=0);

int main(){

    contador(20);
    // valor de n1
    system("pause");return 0;
}

//n2 e o contador inicial
void contador (int n1, int n2){
    cout << n2 << "\n";
    if (n1>n2){
        contador(n1,++n2);
        //++ preincremento
    }
}
