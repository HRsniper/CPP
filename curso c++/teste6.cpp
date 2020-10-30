#include <iostream>
using namespace std;
int main(){
    int n1,n2,n3;
    string r1;

    cout << "digite a primeira nota: ";
    cin >> n1 ;
    cout << "digite a segunda nota: ";
    cin >> n2;

    n3=n1+n2;
    // ?= if   :=else   operaçao simples
    (n3>=60) ? r1="aprovado" : r1="reprovado";
    cout << "situacao: " << r1 << "\n";
    // retorno para r1
    r1=(n3>=60) ? "aprovado" : "reprovado";
    cout << "situacao: " << r1 << "\n";

    system("pause");
    return 0;

}
