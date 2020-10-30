#include <iostream>
#include <array>

using namespace std;

int main (){
//----------------------------------------------------------
    array<int,10> vetor={1,2,3,6,5,4,7,8,9,10};

    for (auto &&i : vetor){//for range declaration
        cout << i << " - ";
    }

/*  //for (auto it=vetor.rbegin(); it!=vetor.rend(); it++){//reverse iterator
    for (auto it=vetor.begin(); it!=vetor.end(); it++){//iterator
        cout << *it << endl;
    }
*/
//----------------------------------------------------------
cout << endl;
//----------------------------------------------------------
    cout << vetor.size() << endl;//tamanho
    cout << vetor.max_size() << "\n";//tamanho maximos de elementos
//----------------------------------------------------------
    if (vetor.empty())//verificar se esta vazio
    {
        cout << "array vazio" << endl;
    }
    else
    {
        cout << "array cheio" << "\n";
    }

//----------------------------------------------------------
    cout << vetor[9] << endl;
    cout << vetor.at(8) << endl;
    cout << vetor.front() << endl;
    cout << vetor.back() << endl;
//----------------------------------------------------------
    array<int,10> vetor2;

    vetor2.fill(1);//fill prenche o vetor com um numero
        for (auto i : vetor2)
        {
            cout << i << " - ";
        }
//----------------------------------------------------------
cout << endl;
//----------------------------------------------------------
    vetor.swap(vetor2);//troca de valor
        for (auto i : vetor2)
        {
            cout << i << " - ";
        }
    cout << endl;
         for (auto i : vetor){
        cout << i << " - ";
    }
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------
    cout << endl;
    system ("pause");
    return 0;
}
