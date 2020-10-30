#include <iostream>
#include <vector>

using namespace std;

int main(){//                  0         1         2          3
	vector<string> produtos={"mouse", "teclado", "CPU", "placa de video"};
	vector<string>::iterator it;

	it=produtos.begin();
	cout << *it << "\n\n";

	it=produtos.end()-1;//-1 para CPU,sem nao mostra nada
	cout << *it << "\n\n";

	it=produtos.begin();
	advance(it,2);// advance avanca quantos for definido
	cout << *it << "\n\n";

	it=produtos.begin();
	cout << *next(it,1)<< "\n\n";//proxima a direita

	it=produtos.end();
	cout << *prev(it,1) << "\n\n";// retorma a esquerda

	it=produtos.end();
	cout << *prev(it,2) << "\n\n";// retorma a esquerda

//for para impresao
	for (it=produtos.begin(); it!=produtos.end(); it++){
		cout << *it << endl;
	}

	system("pause");
	return 0;
}
