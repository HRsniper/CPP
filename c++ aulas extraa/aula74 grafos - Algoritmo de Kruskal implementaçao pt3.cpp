/*
	Implementação do algoritmo de Kruskal
	Para detectar ciclos iremos utilizar o algoritmo Union-Find que detecta
	ciclos em grafos NÃO direcionados.
*/

#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <cstring> // memset

using namespace std;

class Aresta {
private:
	int Avertice1, Avertice2, Apeso;

public:
	//contrutor
	Aresta(int v1, int v2, int peso) {
		Avertice1 = v1;
		Avertice2 = v2;
		this->Apeso = peso;
	}

	//obter Avertice1
	int getAv1()	{
		return Avertice1;
	}
	////obter Avertice2
	int getAv2()	{
		return Avertice2;
	}
	//obter Apeso
	int getApeso()	{
		return Apeso;
	}

	// sobrescrita do operador "<" //aresta2 é outra aresta
	bool operator < (const Aresta &aresta2) const {
		return (Apeso < aresta2.Apeso);
	}
};

class Grafo {
private:
	int Vertices; // número de vértices
	vector<Aresta> arestas; // vetor de arestas

public:
	//construtor
	Grafo(int V) {
		this->Vertices = V;
	}

	// função que adiciona uma aresta
	void adicionarAresta(int v3, int v4, int pesoG) {
		Aresta addaresta(v3, v4, pesoG);
		arestas.push_back(addaresta);
	}
	//union-find
	// função que busca o subconjunto de um elemento "u"
	int buscar(int subset[], int u)	{
		if(subset[u] == -1) {
			return u;
		}
		return buscar(subset, subset[u]);
	}

	// função para unir dois subconjuntos em um único subconjunto
	void unir(int subset[], int v5, int v6)	{
		int v1_set = buscar(subset, v5);
		int v2_set = buscar(subset, v6);
		subset[v1_set] = v2_set;
	}
	//fim union-find

	// função que roda o algoritmo de Kruskal
	void kruskal() {
		vector<Aresta> arvore;
		int size_arestas = arestas.size();

		// ordena as arestas pelo menor peso
		sort(arestas.begin(), arestas.end());

		// aloca memória para criar "Vertices" subconjuntos
		int * subset = new int[Vertices];

		// inicializa todos os subconjuntos como conjuntos de um único elemento
		memset(subset, -1, sizeof(int) * Vertices);

		for(int i = 0; i < size_arestas; i++) {
			int Atv1 = buscar(subset, arestas[i].getAv1());
			int Atv2 = buscar(subset, arestas[i].getAv2());

			if(Atv1 != Atv2) {
				// se forem diferentes é porque NÃO forma ciclo, insere no vetor
				arvore.push_back(arestas[i]);
				unir(subset, Atv1, Atv2); // faz a união
			}
		}

		int size_arvore = arvore.size();
		// mostra as arestas selecionadas com seus respectivos pesos
		for(int o = 0; o < size_arvore; o++) {
			char Arv1 = 'A' + arvore[o].getAv1();
			char Arv2 = 'A' + arvore[o].getAv2();
			cout << "(" << Arv1 << ", " << Arv2 << ") = " << arvore[o].getApeso() << endl;
		}
	}
};

int main(int argc, char *argv[]) {

/*

     A     C
     |\7 8/|    
    5|  B  |5
     |/9 7\|
     D-15--E
      \6 8/|
        F  |9
       11\ |
          G

*/
/*

      A    C
     | \7  |    
    5|  B  |5
     |  7\ |
     D     E
      \6   |
       F   |9
           |
           G

*/
//	A=0	B=1	C=2	D=3	E=4	F=5 G=6

	Grafo g(7); // grafo
	
	// adiciona as arestas
	g.adicionarAresta(0, 1, 7);
	g.adicionarAresta(0, 3, 5);
	g.adicionarAresta(1, 2, 8);
	g.adicionarAresta(1, 3, 9);
	g.adicionarAresta(1, 4, 7);
	g.adicionarAresta(2, 4, 5);
	g.adicionarAresta(3, 4, 15);
	g.adicionarAresta(3, 5, 6);
	g.adicionarAresta(4, 5, 8);
	g.adicionarAresta(4, 6, 9);
	g.adicionarAresta(5, 6, 11);
	
	g.kruskal(); // roda o algoritmo de Kruskal
	
	return 0;
}