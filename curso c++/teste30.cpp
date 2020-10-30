#include <iostream>
#include "teste30.h"

using namespace std;

int main(){
/*  int i;

    cout << "selecione [1]AR, [2]SR, [3]Pistol, [4 ou +]Nao tem" << endl;
    cout << "digite: ";
    cin >> i;
*/
    Armas *arm2=new Armas(3);
    Armas *arm1=new Armas(2);// 1 por i para digitar o valor
    Armas *arm3=new Armas(1);
    Armas *arm5=new Armas(4);

    arm1-> impr();
    arm2-> impr();
    arm3-> impr();
    arm5-> impr();

    system("pause");
	return 0;
}
