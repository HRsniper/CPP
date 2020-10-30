#include <iostream>
#include <stack>

using namespace std;

int main(){

	stack <string> nomes;
	// verificacao
	if (nomes.empty()){
	    cout << "pilha vazia\n";
	}else{
        cout << "pilha cheia\n";
	}

	nomes.push("ciri");//1 a entra ultimo a sair
	nomes.push("yennifer");
	nomes.push("geralt");
	nomes.push("the wither");//ultimo a entra 1 a sair

	if (nomes.empty()){
	    cout << "pilha vazia\n\n";
	}else{
        cout << "pilha cheia\n\n";
	}

	cout << "tamanho da pilha de nomes: " << nomes.size() << "\n";

	cout << "nome do topo: " << nomes.top() << "\n";

	nomes.pop();
	cout << "tamanho da pilha de nomes depois de tira 1: " << nomes.size() << "\n";

	cout << "novo nome do topo: " << nomes.top() << "\n";

	cout << endl;
    //apagando pilhha
	while(!nomes.empty()){
        cout << "nome do topo: " << nomes.top() << "\n";
        nomes.pop();
	}

	cout << "tamanho da pilha de nomes restantes: " << nomes.size() << "\n";

	system("pause");return 0;
}
