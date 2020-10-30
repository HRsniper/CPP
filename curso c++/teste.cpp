#include <iostream>
#include <cstdio>
#include <cstdlib>
#define extraminucao 300
#define ini cout << "inimigos vivos 53";
using namespace std;
int main(){
    int life=100;
    int colete=150;
    int municao=30;

    cout << "life: " << life <<"\n" << "colete: " << colete <<"\n" << "municao: " << municao << "\n\n";

    cout << "life restante: ";
    cin >> life;
    cout << "colete restante: ";
    cin >> colete;
    cout << "municao restante: ";
    cin >> municao;
    cout << extraminucao << " de municao extra" << endl << endl;
    ini
    cout << "\n\n";
    system("pause");
    system("ping 8.8.8.8");
    return 0;
}
