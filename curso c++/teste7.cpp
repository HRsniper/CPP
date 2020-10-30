#include <iostream>
using namespace std;
int main(){
    int valor;

    cout << "selecione a cor:\n";
    cout << "[1] vermelho , [2] azul , [3] preto \n";

    cout << "valor digitado: ";
    cin >> valor;


    switch(valor){
    case 1:
        cout << "vermelho OK\n";
        break;
    case 2:
        cout << "azul OK\n";
        break;
    case 3:
        cout << "preto OK\n";
        break;
    default:
        cout << "nao tem cor nesse espectro\n";
    }


    cout << "selecione a cor2:\n";
    cout << "[1] vermelho2 , [2] azul2 , [3] preto2  , [4]verde2\n";

    cout << "valor digitado: ";
    cin >> valor;


    switch(valor){

    case 1:
    case 2:
        cout << "escolhido entre de vermelho2 a azul2: \n";

        switch(valor){
            case 1:
                cout << "vermelho2 OK\n";
                break;
            case 2:
                cout << "azul2 OK\n";
                break;
        }
    break;

    case 3:
    case 4:
        cout << "escolhido entre de preto2 a verde2: \n";

        switch(valor){
            case 3:
                cout << "vermelho2 OK\n";
                break;
            case 4:
                cout << "azul2 OK\n";
                break;
        }
    break;
    default:
        cout << "nao tem cor nesse espectro\n";
    }


    system("pause");
    return 0;
}
