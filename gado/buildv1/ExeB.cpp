#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){

    int i;
    string dada, linha;

    fstream arquivo;
	arquivo.open("gado.txt", ios::out/*|ios::app*/);

        cout << "Data: ";
        cin >> dada;
        arquivo << "Data: " <<dada << "\n";
        cout << endl;

        cout << "Macho 0-12: ";
        cin >> i;
        arquivo << "Macho 0-12: " << i << "\n";
        cout << "Femea 0-12: ";
        cin >> i;
        arquivo << "Femea 0-12: " << i << "\n";

		cout << "Macho 13-24: ";
        cin >> i;
        arquivo << "Macho 13-24: " << i << "\n";
        cout << "Femea 13-24: ";
        cin >> i;
        arquivo << "Femea 13-24: " << i << "\n";

		cout << "Macho 25-32: ";
        cin >> i;
        arquivo << "Macho 25-32: " << i << "\n";
        cout << "Femea 25-32: ";
        cin >> i;
        arquivo << "Femea 25-32: " << i << "\n";

		cout << "Macho 36+: ";
        cin >> i;
        arquivo << "Macho 36+: " << i << "\n";
        cout << "Femea 36+: ";
        cin >> i;
        arquivo << "Femea 36+: " << i << "\n";

        system("cls");
        cout << endl;

	arquivo.close();


	arquivo.open("gado.txt",ios::in);
        if(arquivo.is_open()){
            while(getline(arquivo,linha)){
                cout << linha << endl;
            }
    arquivo.close();
        }else{
			cout << "O arquivo nao conseguiu ser aberto ou foi apagado" << "\n";
		}
     cout << endl;


	system("pause");
	return 0;
}
