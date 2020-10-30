/*  queue - FIFO = fist in , first out
    priority queue = fila de prioridade
 */
#include <iostream>
#include <queue>
using namespace std;

class Pessoa {
private:
	string nomep;
	int idadep;

public:
	Pessoa(string nome, int idade) {
		this->nomep = nome;
		this->idadep = idade;
	}

	string getNome() {
		return nomep;
	}

	int getIdade() {
		return idadep;
	}
};

struct CompIdade
{
	bool operator()(Pessoa& p1, Pessoa& p2)
	{
		return p1.getIdade() < p2.getIdade();
	}
};

int main(int argc, char *argv[])
{
	priority_queue<Pessoa, vector<Pessoa>, CompIdade> pqueue;

	Pessoa p1("Joao", 40), p2("Maria", 59), p3("Pedro", 60);

	pqueue.push(p1);
	pqueue.push(p2);
	pqueue.push(p3);

	Pessoa Ppessoa = pqueue.top();

	cout << "Nome: " << Ppessoa.getNome() << endl;
	cout << "Idade: " << Ppessoa.getIdade() << endl;

	return 0;
}
