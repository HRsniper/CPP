// Grafos - DFS (busca em profundidade)

/*
      0
     / \
    1   2 __ 6
   / \   \    \
  3   4   5    7
*/

#include <iostream>
#include <list>
#include <algorithm> // função find
#include <stack> // pilha para usar na DFS

using namespace std;

class Grafo {
	int Vertices; // número de vértices
	list<int> *adj; // ponteiro para um array contendo as listas de adjacências

public:
	Grafo(int V); // construtor
	void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo

	// faz uma DFS a partir de um vértice // raiz
	void dfs(int v);
};

Grafo::Grafo(int V) {
	this->Vertices = V; // atribui o número de vértices
	adj = new list<int>[V]; // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2) {
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
}

void Grafo::dfs(int v) {
	stack<int> pilha;
	bool visitados[Vertices]; // vetor de visitados

	// marca todos como não visitados
	for(int i = 0; i < Vertices; i++) {
		visitados[i] = false;
	}

    while(true) {

        if(!visitados[v]) {
            cout << "Visitando vertice " << v << " ...\n";
            visitados[v] = true; // marca como visitado
            pilha.push(v); // insere "v" na pilha
        }

    bool achou = false; // flag
    list<int>::iterator it;

    // busca por um vizinho não visitado
    for(it = adj[v].begin(); it != adj[v].end(); it++) {
        if(!visitados[*it]) {
            achou = true;
            break;
        }
    }

    if(achou) {
        v = *it; // atualiza o "v"
    }
    else {
        // se todos os vizinhos estão visitados ou não existem vizinhos // é folha
        // remove da pilha
        pilha.pop();
        // se a pilha ficar vazia, então terminou a busca
        if(pilha.empty()){
            break;
        }
        // se chegou aqui, é porque pode pegar elemento do topo
        v = pilha.top();
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

	grafo.dfs(0);//raiz 0

    system("pause");
	return 0;
}
