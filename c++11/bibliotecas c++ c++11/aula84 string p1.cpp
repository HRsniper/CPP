#include <iostream>
#include <string>

using namespace std;

int main(){
    string txt("ter uue ityi rye - eueu");
    string::iterator it;
    it=txt.begin();
    cout << *it << endl;
//----------------------------------------
    cout << txt.size() << endl;//tamanho
    cout << txt.length() << endl;//tamanho
//----------------------------------------
    cout << txt.max_size() << endl;//tamanho maximo
//----------------------------------------
    txt.resize(10);//redimenciona o tamanho da string
    cout << txt.length() << endl;//tamanho
    cout << txt << endl;
//----------------------------------------
    cout << txt.capacity() << endl;//tamanho alocado para string
//----------------------------------------
    txt.clear();//limpa a string
    cout << txt << endl;
//----------------------------------------
    if (txt.empty())
    {
        cout<< "vazia" <<"\n";
    }
    else
    {
        cout<<"cheia"<<"\n";
    }

//----------------------------------------
    string txt1("gheehe ehehteeuue ityi rye - eueu");
    cout << txt1 << endl;
    cout << txt1.capacity() << endl;
    txt1.resize(10);
    txt1.shrink_to_fit();//reduz tamanho alocado para o tamnnho da string // minimo 15
    cout << txt1.capacity() << endl;
    cout << txt1 << endl;
//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
	system("pause");
	return 0;
}
