#include <iostream>
#include <fstream>

using namespace std;

int main(){
    // ofstream sai da aplica�ao para o arquivosaida txt
    // ifstream sai do txt para a aplica�ao

/*
    ofstream arquivosaida;
	arquivosaida.open("teste34arquivosaida.txt");
	//arquivosaida.open("teste34arquivosaida.txt", ios::app);
	arquivosaida << "HRsniper\n";
	arquivosaida << "Scar-h\n";
	arquivosaida << "ChayTec M200\n";
	arquivosaida.close();
*/
	ifstream arquivoentra;
	string linha;
	arquivoentra.open("teste34arquivosaida.txt");
        if(arquivoentra.is_open()){
            while(getline(arquivoentra,linha)){
                cout << linha << endl;
            }
		arquivoentra.close();
        }else{
			cout << "O arquivo nao conseguiu ser aberto ou foi apagado" << "\n";
		}


	system("pause");
	return 0;
}
