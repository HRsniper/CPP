#include <iostream>
using namespace std;
int n1,n2; //variaveis globais
int main (){
    int n3,n4; // variaveis locais
    int resto,resto1,resto2,resto3;

    n1= 23;
    n2= 816;
    n3= 77;
    n4= 2;

    cout << "valor de n1: " << n1 << endl;
    cout << "valor de n2: " << n2 << endl;
    cout << "valor de n3: " << n3 << endl;
    cout << "valor de n4: " << n4 << endl << endl;

    resto=n1+n2+n3+n4;
    cout << "soma das variaveis: " << resto << "\n\n";

    resto1=(n1*n4)+n3+n2;
    cout << "multiplicacao + soma das variaveis: " << resto1 << "\n\n";

    resto2=n2/n1;
    cout << "divisao das variaveis: " << resto2 << "\n\n";

    resto3=n2%n1;
    cout << "resto da divisao das variaveis: " << resto3 << "\n\n";

    system("pause");
    return 0;
}
