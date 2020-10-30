#include <iostream>
#include <list>

using namespace std;

bool par (const int& valor){//funçao para remove if
    return (valor%2)==0;
}

int main (){
//----------------------------------------------------------
    list<int> lst1;
    list<int> lst2(10,0);//inseiri 10 vez o 0
    list<int> lst3(lst2);
    list<int> lst4={1,2,3,4};
/*
    for (auto &&i : vec){//for range declaration
        cout << i << " - ";
    }
*/
  //for (auto it=vec.rbegin(); it!=vec.rend(); it++){//reverse iterator
    for (auto it=lst4.begin(); it!=lst4.end(); it++){//iterator
        cout << *it << endl;
    }

//----------------------------------------------------------
cout << endl;
//----------------------------------------------------------
    cout << lst4.size() << endl;//tamanho
    cout << lst4.max_size() << "\n";//tamanho maximos de elementos
//----------------------------------------------------------
    if (lst4.empty())//verificar se esta vazio
    {
        cout << "lista vazio" << endl;
    }
    else
    {
        cout << "lista cheio" << "\n";
    }

//----------------------------------------------------------
    //.resize();//muda o tamhno do vctor
    //.capacity();//mostra a capacidade do vector
   // cout << vec[9] << endl;
   // cout << vec.at(8) << endl;
    cout << lst4.front() << endl;
    cout << lst4.back() << endl;
    //.shrink_to_fit();//redimencionar a capacidade
    //.push_back() insere ultima da lista
    //.push_front() no começo da list
    //.pop_back() remove o ultio da lista
    //.pop_front() remove o primeiro
    //.insert()//insere o valor em determinao lugar mlehor uso com iteator .insert(it,5); .insert(it,5,9)
    //.erase()
    //.clear()
//----------------------------------------------------------
   lst1.assign(10,2);//atribui elemento dentro do vector
      for (auto i : lst1)
        {
          cout << i << " - ";
        }
//----------------------------------------------------------
cout << endl;
//----------------------------------------------------------
    lst1.swap(lst2);//troca de valor
        for (auto i : lst1)
        {
            cout << i << " - ";
        }
    cout << endl;
         for (auto i : lst2){
        cout << i << " - ";
    }
//----------------------------------------------------------
   list<int> vect={1,1,1,1};

   vect.emplace(++ vect.begin(),5);//emplece() informa onde começa adiciona o elemento sem apagar ou substituir outro
    for (auto i : vect){
        cout << i << " - ";
    }
cout << endl;
    //emplace_ front
    vect.emplace_back(9);//emplece() adiciona o elemento no final sem apagar ou substituir outro
    for (auto i : vect){
        cout << i << " - ";
    }
cout << endl << endl;
//----------------------------------------------------------
    list<int> lista={1,1,10,1,61,6,16,1,61,81,68,1,81,681,68,1};
    list<int> lista2={1,681,8616,816,8414};

    lista.remove(1);//remove elementos selecionados

    lista.remove_if(par);//remove dependendo de uma condiçao

    lista.sort();//organiza

    lista.unique();//remove os duplicados

    lista.merge(lista2);//mescla 2 lista

    lista.reverse();//reverte a ordenaçao

    for (auto x:lista)
    {
        cout << x << "  ";
    }

//----------------------------------------------------------
//----------------------------------------------------------
    cout << endl;
    system ("pause");
    return 0;
}
