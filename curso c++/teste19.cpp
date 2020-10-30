#include <iostream>
#include <list>

using namespace std;

int main(){

	list <string> nomes;
	list <string>::iterator nome2;

	// verificacao
	if (nomes.empty()){
	    cout << "pilha vazia\n";
	}else{
        cout << "pilha cheia\n";
	}

	nomes.push_back("ciri");
	nomes.push_back("yennifer");
	nomes.push_back("geralt");
	nomes.push_front("the wither");

	if (nomes.empty()){
	    cout << "pilha vazia\n\n";
	}else{
        cout << "pilha cheia\n\n";
	}

	cout << "tamanho da pilha de nomes: " << nomes.size() << "\n";

	cout << "nome do topo: " << nomes.front() << "\n";

	nomes.pop_front();
	cout << "tamanho da pilha de nomes depois de tira 1: " << nomes.size() << "\n";

	cout << "novo nome do topo: " << nomes.front() << "\n";

	cout << endl;

	/*nome2 = nomes.begin();
	advance(nome2,3);
	nomes.insert(nome2,0);*/

	//nomes.clear();
    //apagando pilhha
	while(!nomes.empty()){
        cout << "nome do topo: " << nomes.front() << "\n";
        nomes.pop_front();
	}

	cout << "tamanho da pilha de nomes restantes: " << nomes.size() << "\n";

	system("pause");return 0;
}
