#include <iostream>
#include <fstream>

using namespace std;

int main(){
    // ofstream sai da aplica�ao para o arquivosaida txt
    // ifstream sai do txt para a aplicacao

	ofstream arquivo;
	arquivo.open("teste34arquivosaida.txt");
	//arquivo.open("teste34arquivosaida.txt", ios::app);
	arquivo << "HRsniper\n";
	arquivo << "Scar-h\n";
	arquivo << "ChayTec M200\n";
	arquivo.close();

	system("pause");
	return 0;
}
