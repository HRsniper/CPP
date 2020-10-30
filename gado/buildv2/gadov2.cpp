#include <iostream>
#include <fstream>
#include <cstdlib>
#include <clocale>
#include <fstream>

#include "gadov2.h"

using namespace std;


int main(int argc, char *argv[]) {

    setlocale(LC_ALL,"portuguese");

    system("title Build v2 De Relação Bovina");

    argv[0] = "Build v2 De Relação Bovina";
    cout << argv[0] << endl;

    char R;

    while(true) {

        R = menu();
        if(R == '1') {

        Idade_Sexo I_S;
        string M_F;
        string Mes;

        ofstream ofs("relacao.txt",fstream::app);

        cout << "\n digite m: ";
        cin >> M_F;
        cout << "\n digite m: ";
        cin >> Mes;
        cout << endl;

        I_S.setIdade(Mes);
        I_S.setSexo(M_F);

        ofs << I_S;

        ofs.close();
        }
        else if(R == '2') {
            Idade_Sexo I_S;
            ifstream ifs;
            ifs.open("relecao.txt");

            cout << "\nlistando\n";

            if (ifs.good()) {
                while (!ifs.eof()) {
                    ifs >> I_S;

                    cout << "Nome: " << I_S.getIdade() << "\n";
					cout << "Idade: " << I_S.getSexo() << "\n\n";
				}
			ifs.close();                
            }
            else {
				cout << "Falha ao abrir o arquivo!\n\n";
		    }
        }
        else if (R == '0') {
            cout << "\nSaindo\n";
            break;
        }
        else {
			cout << "\nOpcao invalida. Tente novamente...\n\n";
		}
    }

    system("pause");
	return 0;
}