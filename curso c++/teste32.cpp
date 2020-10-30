#include <iostream>
#include "teste32.h"

using namespace std;

int main(){

    Carro *c1=new Carro();
    Moto *v1=new Moto();
    Carrosa *cs1=new Carrosa();

    cout << c1->rodas << "\n";
    cout << c1->gettipo() << "\n\n"; // c1->imp();

    c1->imp();
    v1->imp();
    cs1->imp();

    system("pause");
	return 0;
}
