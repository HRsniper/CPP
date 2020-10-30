#include <iostream>

template <class Type>
class Pilha {
private:
	Type* vet;
	int max_tam;
	int topo;
public:
	//construtor
	Pilha(int tam) {
		vet = new Type[tam];
		max_tam = tam - 1;
		topo = -1;
	}

	//destrutor
	~Pilha() {
		delete[] vet;
	}
	void empilhar(Type e) {
		if(topo == max_tam)
			std::cout << "Pilha cheia!" << std::endl;
		else
			vet[++topo] = e;
	}
	void desempilhar() {
		if(topo == -1)
			std::cout << "Pilha vazia!!" << std::endl;
		else
			topo--;
	}
	Type getTopo() {
		if(topo != -1)
			return vet[topo];
		return NULL;
	}
	int vazia() {
		return (topo == -1);
	}
};