#include <iostream>
#include "aula36 class template e pilha.h"

using namespace std;

int main(int argc, char *argv[])
{
	Pilha<const char*> p(100);

	p.empilhar("python");
	p.empilhar("haskell");
	p.empilhar("C++");
	//p.desempilhar();
	if(p.vazia())
		cout << "Pilha vazia!\n";
	else
		cout << "Pilha NAO vazia!\n";
	if(p.getTopo() != NULL)
		cout << "Topo: " << p.getTopo() << endl;
	else
		cout << "A pilha esta vazia!!\n";
	return 0;
}