#include <iostream>
#include <vector>

using namespace std;

auto soma (double n1, double n2)->double{
//int soma (int n1, int n2){//funçao
	return n1+n2;
}

void soma (){//sem static todos os valores sao 1 nas camada
    //static usa mesmo endereço na memoria
    static auto i=0;    i++;    cout << i << endl;  }


int main(){
// auto: difine automaticamento o tipo da variavel sendo que sempre tem a iniciar o valor
	auto num=10;// int
	auto nome="nome";// string
	auto valord= 10.5;//double

	//int res=soma (10,10);
	auto res=soma (10,10);
	cout << res << "\n";

	cout << "\n";

	vector<int> v{1,2,3,4,5,6};//vector com ini. uniforme
	//for metodo normal
	/*for (vector<int>::iterator it=v.begin(); it!=v.end(); it++){
		cout << *it << "\n";
	}*/
	for (auto it=v.begin(); it!=v.end(); it++){
		cout << *it << "\n";
	}

    cout << "\n";

//pedindo ao processador para registar no processador
    register int valor;
    //exemplo
    for (valor=0;valor<10;valor++){
		cout << valor << "\n";
    }

    cout << "\n";
    soma();
    soma();
    soma();
    soma();

	system("pause");
	return 0;
}
