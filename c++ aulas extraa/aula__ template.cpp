#include <iostream>

using namespace std;

template <typename T>
T funcao(T n) {
    cout << typeid(n).name() << " - ";

    // if (typeid(n).name() == typeid(int).name()) {
    //     cout << "inteiro - ";
    // }
    
    return n*2;
}

template <class T1>
class aula {
private:
public:
    T1 nome;
    T1 idade;

    aula(T1 n , T1 i){
        this->nome = n;
        this->idade = i;
    }

    // ~aula() {
    //     cout << "destrutor ativo \n";
    // }
};




int main() {

    cout << funcao(10) << endl;
    cout << funcao(10.51) << endl;
    cout << funcao(10.55555) << endl;
    cout << funcao(1000000000000000000) << endl;
    
    aula *carro1=new aula("fiat",200);
    aula p1{"hr", 23};

    system("pause");
    return 0;
}

/* 
Modelos de funções Escrevemos uma função genérica que pode ser usada para diferentes tipos
 de dados. Exemplos de modelos de função são sort (), max (), min (), printArray () e etc. 
template <typename T>

Modelos de classe Como os modelos de função, os modelos de classe são úteis quando uma 
classe define algo que é independente do tipo de dados. Pode ser útil para classes como 
LinkedList, BinaryTree, Stack, Queue, Array, etc.
template <class T>
 */