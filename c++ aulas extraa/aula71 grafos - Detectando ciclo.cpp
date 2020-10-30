// Grafos - Verifica se um grafo direcionado tem ciclo

#include <iostream>
#include <list>
#include <stack> // pilha para usar na DFS

using namespace std;

class Grafo {
private:
	int Vertices; // número de vertices
	list<int> *adj;

public:
	Grafo(int V);
	void adicionarAresta(int v1, int v2);

	// faz uma DFS a partir de um vértice, retorna se achou ciclo ou não
	bool dfs(int v);

	// verifica se o grafo direcionado tem ciclo
	bool temCiclo();
};

Grafo::Grafo(int V) {
	this->Vertices = V;
	adj = new list<int>[V];
}

void Grafo::adicionarAresta(int v1, int v2) {
	adj[v1].push_back(v2);
}

bool Grafo::dfs(int v)
{
	stack<int> pilha;
	bool visitados[Vertices], pilha_rec[Vertices];

	// inicializa visitados e pilha_rec com false
	for(int i = 0; i < Vertices; i++) {
		visitados[i] = pilha_rec[i] = false;
	}
	// faz uma DFS
	while(true) {
		bool achou_vizinho = false;
		list<int>::iterator it;

		if(!visitados[v]) {
			pilha.push(v);
			visitados[v] = pilha_rec[v] = true;
		}

		for(it = adj[v].begin(); it != adj[v].end(); it++) {
			// se o vizinho já está na pilha é porque existe ciclo
			if(pilha_rec[*it]) {
				return true;
			}
			else if(!visitados[*it]) {
				// se não está na pilha e não foi visitado, indica que achou
				achou_vizinho = true;
				break;
			}
		}

		if(!achou_vizinho) {
			pilha_rec[pilha.top()] = false; // marca que saiu da pilha
			pilha.pop(); // remove da pilha

			if(pilha.empty()) {
				break;
            }
        v = pilha.top();
		}
		else {
			v = *it;
		}
	}

	return false;
}

bool Grafo::temCiclo() {
	for(int i = 0; i < Vertices; i++) {
		if(dfs(i)) {
			return true;
		}
	}
	return false;
}

int main(int argc, char *argv[]) {

/*
	0 → 1
	↓ \	↓
	2	3
*/

	Grafo grafo(4);

	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 2);
	grafo.adicionarAresta(1, 3);
	grafo.adicionarAresta(3, 0);

	if(grafo.temCiclo()) {
		cout << "Contem ciclo\n\n";
	}
	else {
		cout << "NAO contem ciclo\n\n";
	}
/*
    if(grafo.dfs(2))
		cout << "Contem ciclo\n";
	else
		cout << "NAO contem ciclo\n";
*/

	system("pause");
	return 0;
}
