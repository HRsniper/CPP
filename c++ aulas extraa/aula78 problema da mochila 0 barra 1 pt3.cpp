// problema da mochila 0/1 (knapsack problem)

#include <iostream>

using namespace std;

int mochila(int W_max, int w_each[], int Vb_each[], int n_element) {
	// tabela que será preenchida
	int V[n_element + 1][W_max + 1];

	// inicializando a primeira linha e primeira coluna com 0
	for(int w = 0; w <= W_max; w++) {
		V[0][w] = 0;
	}
	for(int i = 1; i <= n_element; i++) {
		V[i][0] = 0;
	}

	for(int i = 1; i <= n_element; i++)	{
		for(int w = 1; w <= W_max; w++)	{
			// elemento pode fazer parte da solução
			if(w_each[i - 1] <= w) {
				// max...
				if((Vb_each[i - 1] + V[i - 1][w - w_each[i - 1]]) > V[i - 1][w]) {
					V[i][w] = Vb_each[i - 1] + V[i - 1][w - w_each[i - 1]];
				}
				else {
					V[i][w] = V[i - 1][w];
				}
			}
			else {
				V[i][w] = V[i - 1][w]; // wi > w
			}
		}
	}

	// retorna o valor máximo colocado na mochila
	return V[n_element][W_max];
}

int main(int argc, char *argv[]) {
	// capacidade máxima da mochila: W //W_max
	int W = 20;

	// número de elementos //n_element
	int n = 5;

	// vetor com os valores (benefício) de cada elemento //Vb_each
	int b[] = {3, 5, 8, 4, 10};

	// vetor com os pesos de cada elemento // w_each
	int wt[] = {2, 4, 5, 3, 9};

	// obtém o máximo valor que pode ser colocado na mochila
	int max_valor = mochila(W, wt, b, n);

	cout << "Valor maximo: " << max_valor << endl;

	return 0;
}
