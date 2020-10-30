// Sublista contígua de soma máxima //linear
/* 
Tipicamente, a lista de números a ser computada como entrada deve ter números positivos e negativos. Dessa forma, ao encontrar um número negativo vizinho a uma sublista de maior soma computada até então, uma das dificuldades do problema no decorrer da sua resolução é avaliar se esse número negativo deve ser acrescido à sublista ou não. Essa avaliação é necessária porque depois de um número negativo poderão vir na seqüência um ou mais números positivos que compensem o decréscimo resultante da inclusão daquele número negativo. Por outro lado, esse mesmo número negativo vizinho poderá não ser incorporado à sublista de maior soma, pois o resultado final seria uma soma menor do que a obtida até então.
Para uma lista que contenha apenas números positivos, o resultado de maior soma será simplesmente a lista inteira dada como entrada.
Nos algoritmos que serão apresentados a seguir, quando uma lista de números negativos é dada como entrada ou ainda se uma sublista parcial computada ao longo da resolução do problema resultar numa soma negativa, o resultado deverá ser zero, ou seja, o equivalente a obter como resposta uma lista vazia.
 */
#include <iostream>
#include <vector>

using namespace std;

void kadane(vector<int> &vet) {
	int max_atual = 0, max_total = -1;
	int size_vet = vet.size();

	for(int i = 0; i < size_vet; i++) {
		max_atual = max_atual + vet[i];
		
		if(max_atual < 0) {
			max_atual = 0;
        }
		if(max_atual > max_total) {
			max_total = max_atual;
        }
	}
	
	cout << "Soma maxima: " << max_total << endl;
}

int main(int argc, char *argv[]) {
	vector<int> vet(5);

	// vetor: -2, 5, -1, 2, -3
	vet[0] = -2;
	vet[1] = 5;
	vet[2] = -1;
	vet[3] = 2;
	vet[4] = -3;

	kadane(vet);

    system("pause");
	return 0;
}