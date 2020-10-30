#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main(){
//algorithm trabalha com coleções

    vector<int>vt{1,3,48,64,8,4,89,4,7,-2,2,2,15};
    vector<int>vt2{5,11,4,14};
    vector<int>::iterator it,it1,it2;//para criar o it nao precisa da lib iterator

    for(it=vt.begin(); it!=vt.end(); it++){
        cout<< *it << "  ";
    }

    cout << "\n\n";

    it1=vt.begin();//primeiro
    it2=vt.end()-1;//ultimo

    cout << "primeiro elemento: " << *it1 <<"\nultimo elemento: " << *it2 << endl;

    advance(it1,2);//avança
    cout << "terceiro elemento"  << *it1 << endl;

    advance(it1,-1);
    cout << "penultimo elemento"  << *it1 << endl;

    cout << "valores entre it1 e it2" << distance(it1,it2)-1 <<"\n";//distancia entra 2 iterator

    cout << *it1 << " - antes: " << *prev(it1) << " despois: " << *next(it1) << endl;//*prev retorna elemento anterior apontado pelo iterator //*next retorna elemento posterior apontado pelo iterator

    copy(vt2.begin(),vt2.end(),back_inserter(vt));//back_inserter incere no final
    //copy(vt2.begin(),vt2.end(),front_inserter(vt));//front_inserter incere no inicio
    //copy(vt2.begin(),vt2.end(),inserter(vt,vt.begin()+5));//inserter incere em qualquer lugar
    for(it=vt.begin(); it!=vt.end(); it++){
        cout << *it << " ";
    }

	system("pause");
	return 0;
}
