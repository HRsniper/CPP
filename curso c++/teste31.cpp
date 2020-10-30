#include <iostream>
#include "teste31.h"

using namespace std;

int main(){
/*  int i;

    cout << "selecione [1]AR, [2]SR, [3]Pistol, [4 ou +]Nao tem" << endl;
    cout << "digite: ";
    cin >> i;
*/
    carros *arm1=new carros(1);// 1 por i para digitar o valor
    carros *arm2=new carros(2);
    carros *arm3=new carros(3);

    arm1->setvendido(0);
    arm2->setvendido(1);
    arm3->setvendido(0);

    cout << "getvelmax: " << arm1->getvelmax() << endl;
    cout << "getvelmax: " << arm2->getvelmax() << endl;
    cout << "getvelmax: " << arm3->getvelmax() << endl;

    if(arm1->getvendido()){
        cout << "vendido" << "\n";
    }else{
        cout << "nao vendido" << "\n";
    }

    if(arm2->getvendido()){
        cout << "vendido" << "\n";
    }else{
        cout << "nao vendido" << "\n";
    }

    if(arm3->getvendido()){
        cout << "vendido" << "\n";
    }else{
        cout << "nao vendido" << "\n";
    }

    //arm1-> impr();
    //arm2-> impr();
    //arm3-> impr();

    system("pause");
	return 0;
}
