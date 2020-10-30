#include <iostream>
#include <set>

using namespace std;

int main (){
//----------------------------------------------------------
    set<int> st1={9,1,0,2,8,3,7,4,6,5};
    set<int>::iterator it;

    for (auto i:st1){
        cout << i << "  ";
    }

//----------------------------------------------------------
cout << endl;
//----------------------------------------------------------
    set<int> st2={60,50,70,90,80,40};

    it=st2.begin();
    st2.insert(it,100);//.erase() tambem funciona
    it=st2.end();
    st2.insert(it,110);
    it= ++ ++ ++ st2.begin();

    for (auto i:st2){
        cout << i << "  ";
    }
//----------------------------------------------------------
cout << endl;
//----------------------------------------------------------
    st2.emplace_hint(st2.begin(),120);//incere numero ,mas se ele ja existir ele nao incere
    st2.emplace_hint(st2.begin(),120);

    for (auto i:st2){
        cout << i << "  ";
    }
//----------------------------------------------------------
cout << endl;
//----------------------------------------------------------
    it=st1.find(8);
    cout << *it;
//----------------------------------------------------------
    set<int>st3={1,1,1,1,1,1,11,6186,18,616,186,13,135,13,151,3};
        for (auto i : st3){
            cout << i << "  ";
        }
    cout << "\n";
        //.count conta quantos elementos de um determinado numero tem no container,usado normalmente para verificar se o elemento existe no container
    if(st3.count(1)!=0){
        cout << "esta no container" << endl;
    }else
    {
        cout << "nao esta no container" << endl;
    }

//----------------------------------------------------------
cout << endl;
//----------------------------------------------------------
    it=st1.upper_bound(8);//retorna elemento da borda
    cout << *it << "\n";
    it=st1.lower_bound(2);//upper ou lower verificndo se esta no conatainer
    cout << *it << endl;
//----------------------------------------------------------
cout << endl;
//----------------------------------------------------------
//----------------------------------------------------------
    cout << endl;
    system ("pause");
    return 0;
}
