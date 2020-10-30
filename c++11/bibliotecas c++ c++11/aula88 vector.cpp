#include <iostream>
#include <vector>

using namespace std;

int main (){
//----------------------------------------------------------
    vector<int> vec={1,2,3,6,5,4,7,8,9,10};

    for (auto &&i : vec){//for range declaration
        cout << i << " - ";
    }

/*  //for (auto it=vec.rbegin(); it!=vec.rend(); it++){//reverse iterator
    for (auto it=vec.begin(); it!=vec.end(); it++){//iterator
        cout << *it << endl;
    }
*/
//----------------------------------------------------------
cout << endl;
//----------------------------------------------------------
    cout << vec.size() << endl;//tamanho
    cout << vec.max_size() << "\n";//tamanho maximos de elementos
//----------------------------------------------------------
    if (vec.empty())//verificar se esta vazio
    {
        cout << "vector vazio" << endl;
    }
    else
    {
        cout << "vector cheio" << "\n";
    }

//----------------------------------------------------------
    //.resize();//muda o tamhno do vctor
    //.capacity();//mostra a capacidade do vector
    cout << vec[9] << endl;
    cout << vec.at(8) << endl;
    cout << vec.front() << endl;
    cout << vec.back() << endl;
    //.shrink_to_fit();//redimencionar a capacidade
    //.push_back()
    //.pop_back()
    //.insert()//insere o valor em determinao lugar mlehor uso com iteator .insert(it,5); .insert(it,5,9)
    //.erase()
    //.clear()
//----------------------------------------------------------
    vector<int> vec2;

   vec2.assign(10,2);//atribui elemento dentro do vector
      for (auto i : vec2)
        {
          cout << i << " - ";
        }
//----------------------------------------------------------
cout << endl;
//----------------------------------------------------------
    vec.swap(vec2);//troca de valor
        for (auto i : vec2)
        {
            cout << i << " - ";
        }
    cout << endl;
         for (auto i : vec){
        cout << i << " - ";
    }
//----------------------------------------------------------
   vector<int> vect={1,1,1,1};

   vect.emplace(vect.begin()+1,5);//emplece() informa onde começa adiciona o elemento sem apagar ou substituir outro
    for (auto i : vect){
        cout << i << " - ";
    }
cout << endl;

    vect.emplace_back(9);//emplece() adiciona o elemento no final sem apagar ou substituir outro
    for (auto i : vect){
        cout << i << " - ";
    }
cout << endl;
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------
    cout << endl;
    system ("pause");
    return 0;
}
