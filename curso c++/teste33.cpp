#include <iostream>
#include "teste33.h"

using namespace std;

int main(){

    Base1 *obj1=new Base1();
    Base2 *obj2=new Base2();
    Base3 *obj3=new Base3();
        Classe4 *obj4=new Classe4();

    obj1->impb1();
    obj2->impb2();
    obj3->impb3();

    cout << endl;

        obj4->impb1();
        obj4->impb2();
        obj4->impb3();

    system("pause");
	return 0;
}
