// Union-find para detecção de ciclos em grafos não direcionados

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


// função que busca o subconjunto de um elemento "v"
int buscar(int subset[], int v) {
	if(subset[v] == -1) {
		return v;
	}
	return buscar(subset, subset[v]);//chamada recursiva
}

// função para unir dois subconjuntos em um único conjunto
void unir(int subset[], int v1, int v2) {
	int v1_set = buscar(subset, v1);
	int v2_set = buscar(subset, v2);

	subset[v1_set] = v2_set;//atribuir no vetor
}

int tem_ciclo(int grafo[3][3]){
	int * subset = (int*)malloc(3 * sizeof(int));

	// inicializa todos os subconjuntos como conjuntos de um único elemento
	memset(subset, -1, sizeof(int) * 3);

	for(int i = 0; i < 3; i++) {
		for(int j = i; j < 3; j++) {
			if(grafo[i][j] == 1) {
				int v1 = buscar(subset, i);
				int v2 = buscar(subset, j);

				if(v1 == v2) {
					return 1;
				}
				else {
					unir(subset, v1, v2);
				}
			}
		}
	}

	return 0;
}

int main(int argc, char *argv[]) {

/*
	1 → 2
	 \ /
	  3
*/


	int grafo[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	grafo[0][1] = 1;
	grafo[1][0] = 1;
	grafo[1][2] = 1;
	grafo[2][1] = 1;
	grafo[0][2] = 1;
	grafo[2][0] = 1;

	if(tem_ciclo(grafo)) {
		cout << "O grafo tem ciclo!\n\n";
	}
	else {
		cout << "O grafo NAO tem ciclo!\n\n";
	}

	system("pause");
	return 0;
}
