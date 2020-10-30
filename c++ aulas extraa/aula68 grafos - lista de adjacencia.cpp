// Grafos - Lista de adjacência


/*
    6
     \
      4 -- 5 -\
      |    |   > 1
      3 -- 2 -/

lista:
    1 -> 2 -> 5 -o
    2 -> 1 -> 3 -> 5 -o
    3 -> 2 -> 4 -o
    4 -> 3 -> 5 -> 6 -o
    5 -> 1 -> 2 -> 4 -o
    6 -> 4 -o

*/

#include <iostream>
#include <list>
#include <algorithm> // função find

using namespace std;

class Grafo
{
private:
	int Vp; // número de vértices
	list<int> *adj; // ponteiro para um array contendo as listas de adjacências

public:
	Grafo(int V); // construtor
	void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo //conecta v1 ao v2

	// obtém o grau de saída de um dado vértice
	// grau de saída é o número de arcos que saem de "v"
	int obterGrauDeSaida(int v);

	bool existeVizinho(int v3, int v4); // verifica se v3 é vizinho de v4
};

Grafo::Grafo(int V) {
	this->Vp = V; // atribui o número de vértices
	adj = new list<int>[V]; // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2) {
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
}

int Grafo::obterGrauDeSaida(int v) {
	// basta retornar o tamanho da lista que é a quantidade de vizinhos
	return adj[v].size();
}

bool Grafo::existeVizinho(int v3, int v4) {
	if(find(adj[v3].begin(), adj[v3].end(), v4) != adj[v3].end()) {
		return true;
    }
	return false;
}

int main() {
	// criando um grafo de 4 vértices
	Grafo grafo(4);

/* ex.: da aula
    0 → 1
    ↓ / ↓
    3 → 2
*/
	// adicionando as arestas
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 3);
	grafo.adicionarAresta(1, 2);
	grafo.adicionarAresta(3, 1);
	grafo.adicionarAresta(3, 2);

	// mostrando os graus de saída
	cout << "Grau de saida do vertice 0: " << grafo.obterGrauDeSaida(0);
	cout << "\nGrau de saida do vertice 1: " << grafo.obterGrauDeSaida(1);
	cout << "\nGrau de saida do vertice 2: " << grafo.obterGrauDeSaida(2);
	cout << "\nGrau de saida do vertice 3: " << grafo.obterGrauDeSaida(3);

    cout << "\n";

	// verifica se existe vizinhos
	if(grafo.existeVizinho(0, 1))
		cout << "\n\n1 e vizinho de 0\n";
	else
		cout << "\n\n1 NAO e vizinho de 0\n";

	if(grafo.existeVizinho(0, 2))
		cout << "2 e vizinho de 0\n";
	else
		cout << "2 NAO e vizinho de 0\n";

cout << "\n";

    for (size_t i=0; i<=3; i++) {
        for (size_t x=0; x<=3; x++) {
            if (grafo.existeVizinho(i,x)) {
                cout << i << " E vizinho de " << x << endl;
            }
            else {
                cout << i << " NAO vizinho de " << x << endl;
            }
        }
    }

    system("pause");
	return 0;
}
