// Grafos - BFS (busca em lagura)

/*
      0
     / \
    1   2 __ 6
   / \   \    \
  3   4   5    7
*/

#include <iostream>
#include <list>
#include <queue>  // fila para usar na BFS

using namespace std;

class Grafo {
private:
	int Vertices; // número de vértices
	list<int> *adj; // ponteiro para um array contendo as listas de adjacências

public:
	Grafo(int V); // construtor
	void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo

	//faz uma BFS a apartir de um vertice
	void bfs(int v);

};

Grafo::Grafo(int V) {
	this->Vertices = V; // atribui o número de vértices
	adj = new list<int>[V]; // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2) {
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
}

void Grafo::bfs(int v) {
	queue<int> fila;
	bool visitados[Vertices];//vetor de vizitados

	for (int i=0; i<Vertices; i++) {
		visitados[i] = false;
	}

	cout << "visitando vertice " << v << "...\n";
	visitados[v] = true;//marca como visitado

	while (true) {
		list<int>::iterator it;

		for (it= adj[v].begin(); it!= adj[v].end(); it++) {
			if (!visitados[*it]) {
				cout << "visitando vertice " << *it << "...\n";
				visitados[*it] = true; //marca como vizitado
				fila.push(*it); // insere na fila
			}
		}
		//verifica se a fila nao esta vazia
		if (!fila.empty()) {
			v = fila.front();// obtem o 1 elemento
			fila.pop();// remove da fila
		}
		else {
			break;
		}
	}
}

int main() {
	int V = 8;

	Grafo grafo(V);

/*
      0
     / \
    1   2 __ 6
   / \   \    \
  3   4   5    7
*/

	// adicionando as arestas
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 2);
	grafo.adicionarAresta(1, 3);
	grafo.adicionarAresta(1, 4);
	grafo.adicionarAresta(2, 5);
	grafo.adicionarAresta(2, 6);
	grafo.adicionarAresta(6, 7);

	grafo.bfs(0);//raiz 0

	system("pause");
	return 0;
}
