#include <iostream>
#include <cstdlib>
#include <locale>

using namespace std;

int main(){

    setlocale(LC_ALL,"portuguese");

    system("title Desligar Automatícamente");

    int n;

    cout << "Em Quanto Tempo Deseja Desligar o SISTEMA \n\n";
    cout << "[0] 30 Minutos || [1] 1 Hora || [2] 2 Horas || [3] 3 Horas || [4] 4 Horas || [5] 5 Horas || [6] 6 Horas \n\n";
    cout << "[9] Para Cancelar o Desligamento \n\n";
    cout << "Digite a Opção: ";
    cin >> n;

    //60 segundos x 60 minutos = 3600 segundos e igual a 1 hora

    switch(n){
        case 0:
            cout << "\nDesligando Em 30 Minutos \n";
            system("Shutdown /s /t 1800");
            break;
        case 1:
            cout << "\nDesligando Em 1 Hora \n";
            system("Shutdown /s /t 3600");
            break;
        case 2:
            cout << "\nDesligando Em 2 Horas \n";
            system("Shutdown /s /t 7200");
            break;
        case 3:
            cout << "\nDesligando Em 3 Horas \n";
            system("Shutdown /s /t 10800");
            break;
        case 4:
            cout << "\nDesligando Em 4 Horas \n";
            system("Shutdown /s /t 14400");
            break;
        case 5:
            cout << "\nDesligando Em 5 Horas \n";
            system("Shutdown /s /t 18000");
            break;
        case 6:
            cout << "\nDesligando Em 6 Horas \n";
            system("Shutdown /s /t 21600");
            break;
        case 9:
            cout << "\nCancelando Desligamento \n";
            system("Shutdown /a");
            break;

        default:
            cout << "Número Invalido \n";
    }

    cout << endl;

	system("pause");
	return 0;
}
