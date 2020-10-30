// Problema do Troco - Algoritmo Guloso
// quantidade de moedas infinita
#include <iostream>
#include <vector>

using namespace std;

int num_moedas(vector<int> &Moedas, int Troco) {
	int qte_moedas = 0;
	int tam_moedas = Moedas.size();
	
    //subtraçao de maior moeda
    //tam_moedas - 1 sem pega a maoir moeda
/*
troco= 26
moedas= 1,5,10,25,50
aux_moedas= 26/20=1
troco= 26-1*20= 26-20=6
qte_moedas= 1

proxima moeda

aux_moedas= 6/10=0 
troco= troco-0= troco= 6
qte_moedas= 1+0= 1

assim por diante até dar =0
*/
	for(int i = tam_moedas - 1; i >= 0; i--) {
		int aux_moedas = Troco / Moedas[i];
		Troco -= aux_moedas * Moedas[i];
		qte_moedas += aux_moedas;
	}	
	return qte_moedas;
}

int main(int argc, char *argv[]) {
	vector<int> moedas;
	int troco;


	// troco = 27;

	moedas.push_back(1);
	moedas.push_back(5);
	moedas.push_back(10);
	moedas.push_back(25);
	moedas.push_back(50);

	// moedas.push_back(1);
	// moedas.push_back(2);
	// moedas.push_back(5);
	// moedas.push_back(10);
	// moedas.push_back(20);
    
    cout << "Digite o Troco: ";
    cin >> troco;

    cout << "Troco: " << troco << endl;
	cout << "Numero de moedas: " << num_moedas(moedas, troco) << endl;

    system("pause");
	return 0;
}