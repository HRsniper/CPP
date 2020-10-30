#include <iostream>
#include <queue>//fila

using namespace std;

int main (){
//----------------------------------------------------------
//first in ,fisrt out
    queue<int> fila1;
    queue<int> fila2;

    fila1.push(10);
    fila1.push(20);
    fila1.push(30);
    fila1.push(40);
    fila1.push(50);
    fila1.emplace(60);

    fila1.swap(fila2);

    cout << "primeiro: " << fila2.front()<< endl;
    cout << "ultimo: " << fila2.back()<< endl;
    cout << "tamanho: " << fila2.size()<< endl;

    while(!fila2.empty()){
        cout << fila2.front() << endl;
        fila2.pop();
    }


    if(fila2.empty()){
        cout << "fila vazia" << endl;
    }else{
        cout << "fila cheia" << endl;
    }
//----------------------------------------------------------
cout << endl;
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------
    cout << endl;
    system ("pause");
    return 0;
}