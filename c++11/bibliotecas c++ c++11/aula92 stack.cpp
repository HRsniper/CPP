#include <iostream>
#include <stack>//pilha

using namespace std;

int main (){
//----------------------------------------------------------
 //last in ,first out
    stack<int> pilha1;
    stack<int> pilha2;

    pilha1.push(10);
    pilha1.push(20);
    pilha1.push(30);
    pilha1.push(40);
    pilha1.push(50);
    pilha1.emplace(60);

    pilha1.swap(pilha2);

    cout << "tamanho: " << pilha2.size()<< endl;

    while(!pilha2.empty()){
        cout << pilha2.top() << endl;
        pilha2.pop();
    }


    if(pilha2.empty()){
        cout << "pilha vazia" << endl;
    }else{
        cout << "pilha cheia" << endl;
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
