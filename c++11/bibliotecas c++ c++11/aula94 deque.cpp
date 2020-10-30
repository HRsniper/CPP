#include <iostream>
#include <deque>//fila dupla
// implemeta iterator
//poe ser acessado dos 2 lados no inicio ou no final

using namespace std;

void impdeque(deque<int>d);
void linha(int tam,string txt);

int main (){
//----------------------------------------------------------
//first in ,fisrt out
     deque<int> dq1;
     deque<int> dq2(10,5);//quantidades,valor
     deque<int> dq3(dq2);
     deque<int> dq4{0,1,2,3,4,5,6,7,8,9};

    for (auto it=dq4.begin(); it!=dq4.end(); it++){
        cout <<  *it << "  ";
    }

cout << endl;

    linha(35,"capacidade");

    cout << "tamanho: " << dq4.size()<< endl;
    cout << "capacidade maxima: " << dq4.max_size()<< endl;
    dq4.resize(15,10);//altera o tamanho para 15 e preenche novos espaços com 10
    cout << "capacidade alterada: " << dq4.size()<< endl;
    dq4.resize(20);//altera o tamanho para 20 e preenche novos espaços com 0
    cout << "capacidade alterada novamente: " << dq4.size()<< endl;

    impdeque(dq4);

cout << endl;

    linha(35,"acesso");

    cout << "terceiro elemento: " << dq4[4]<< endl;
    cout << "quarto elemento: " << dq4.at(3)<< endl;
    cout << "primeiro elemento: " << dq4.front()<< endl;
    cout << "ultimo elemento: " << dq4.back()<< endl;
    
cout << endl;

    linha(35,"modificadoras");
    //substitui
    dq2.assign(10,0);//quantidade,valor
    impdeque(dq2);
    cout << endl;

    dq2.assign(dq4.begin(),dq4.end());//quantidade,valor
    impdeque(dq2);
    cout << endl;
    
    dq2.push_back(99);
    impdeque(dq2);
    cout << endl;

    dq2.push_front(11);
    impdeque(dq2);
    cout << endl;

    dq2.pop_back();
    dq2.pop_front();
    impdeque(dq2);
    cout << endl;

    dq2.assign(10,0);//quantidade,valor
    impdeque(dq2);
    cout << endl;

    deque<int>::iterator it;

    it=dq2.begin();
    dq2.insert(it,88);
    impdeque(dq2);
    cout << endl;

    it=dq2.begin();
    dq2.erase(it);
    it=dq2.end();
    dq2.erase(it);
    it=dq2.begin()+5;
    dq2.erase(it);
    impdeque(dq2);
    cout << endl;

    dq2.swap(dq4);
    dq4.clear();

    dq2.emplace(dq2.begin()+2,22);//adiciona sem substituir outro
    dq2.emplace_back(33);
    dq2.emplace_front(44);
//----------------------------------------------------------
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

void linha(int tam,string txt){
    cout <<"\n- - " << txt;
    for (int i = 0; i < tam; i++){
        cout << " - ";
    }
    cout << "\n\n";
}

void impdeque(deque<int>d){
    for (auto i : d){
    cout << i << "  ";
    }

}
