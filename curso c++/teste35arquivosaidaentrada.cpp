#include <iostream>
#include <fstream>

using namespace std;

int main(){
    // ofstream sai da aplicacao para o arquivosaida txt
    // ifstream sai do txt para a aplicacao
    // fstream sai e entra mais tem que especificar no .open (ios::out) e (ios::in)

    fstream arquivo;
	char opcao= 's';
	string nome, linha;

	arquivo.open("teste35arquivosaidaentrada.txt",ios::out|ios::app);
		while ((opcao=='s') or (opcao=='S')){
			cout << "digite: ";
			cin >> nome;
			arquivo << nome  <<"\n";
			cout << "digitar o proximo S/N: ";
			cin >> opcao;
		}
	arquivo.close();

	arquivo.open("teste35arquivosaidaentrada.txt",ios::in);
		cout << "digitados" << "\n";
		if (arquivo.is_open()){
			while (getline(arquivo,linha)){
				cout << linha << endl;
			}
		arquivo.close();
		}else{
				cout << "arquivo nao encontrado ou foi apagado";
			}

	system("pause");
	return 0;
}
