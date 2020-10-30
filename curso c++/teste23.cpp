#include <iostream>

using namespace std;

int main(){

    string weapons= "scar-h";
    string *ponteiro;
    ponteiro=&weapons;

    cout << "Endereco na memoria: " << ponteiro << "\n";// sem * p= & de endereço
    cout << "valor de weapons: " << *ponteiro << "\n";// com * e o valor 

    cout << endl;

    *ponteiro="sniper";
    cout << "Endereco na memoria: " << ponteiro << "\n";
    cout << "valor de weapons: " << *ponteiro << "\n";

    system("pause");
    return 0;
}
