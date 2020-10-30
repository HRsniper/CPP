/*
    grafos é uma entidade composta de duas partes: vertices(nós) e arestas (linhas)
nos= sao as bolinhas(entidades que quer modelar)
arestas= relaçoes dessas entidades.

ex.: sao paulo <----------> argentina
vertice(nó)	  	  1680km	vertice(nó)
				  aresta
*/
// Grafo - Matriz de adjacência: proximidade ou proximo

#include <iostream>

using namespace std;

int grafo[5][5] = {
/*		A  B  C  D  E	*/		//	 A	   D
/* A */{0, 0, 1, 0, 0},//0		//	  \	  /|
/* B */{0, 0, 1, 0, 0},//1		//		C  |
/* C */{1, 1, 0, 1, 1},//2		//	  /   \|	/*  */
/* D */{0, 0, 1, 0, 1},//3		//	 B	   E
/* E */{0, 0, 1, 1, 0} //4
};

bool tem_ligacao(int v1, int v2) {
	if(grafo[v1][v2]) {
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) {

	cout << "ligacao entre A e B: " <<  tem_ligacao(0, 1) << endl;
	cout << "ligacao entre A e C: " <<  tem_ligacao(0, 2) << endl;
	cout << "ligacao entre A e D: " <<  tem_ligacao(0, 3) << endl;
	cout << "ligacao entre A e E: " <<  tem_ligacao(0, 4) << endl;
	cout << "ligacao entre D e E: " <<  tem_ligacao(3, 4) << endl;

cout << "\n\n";

	for (size_t i=0; i<=4; i++) {
		for (size_t o=0; o<=4; o++) {
			if (tem_ligacao(i,o)) {
				cout << "tem ligacao entre " << i << " e " << o << endl;
			}
			else {
				cout << "nao tem ligacao entre " << i << " e " << o << endl;
			}
		}
	}

cout << "\n\n";

    system("pause");
	return 0;
}
