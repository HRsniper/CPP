#include <iostream>
#include <memory>

using namespace std;

//-----------------------------------------------------
    //class para unique_ptr
class carro{
public:
    int vel=0;
    int getvel(){
        return vel;
        }
void setvel(int v){// funçao para shared_ptr mudar vel
    this->vel=v;
    }
};
//-----------------------------------------------------

int main(){
//-----------------------------------------------------
	//poteiro normal
	//int *pnum;		int num;	num=10;		pnum=&num;//&=endereço
	//ponterio normal versao curta
	int *pnum=new int();    *pnum=10;
	cout<<"*P normal valor: "<<*pnum<<" - "<<"endereco: "<<pnum<<endl;
	delete pnum;
//-----------------------------------------------------
cout << endl;
//-----------------------------------------------------
    //smart pointer
    //unique_ptr<int> stp(new int);		*stp=10;
	unique_ptr <int> stp(new int(10));// ele so poder ser usado um por vez
	cout << "unique_ptr valor: " << *stp << " - " << "endereco: " << &stp << "\n\n";
//-----------------------------------------------------
	shared_ptr <int> stp2(new int(10));// pode ser compartilhado
	shared_ptr <int> stp3=stp2;
	cout << "shared_ptr2 valor: " << *stp2 << " - " << "endereco: " << &stp2 << "\n";
	cout << "shared_ptr3 valor: " << *stp3 << " - " << "endereco: " << &stp3 << "\n";
//-----------------------------------------------------
cout << endl;
//-----------------------------------------------------
/*	//normal
    string *nstring0(new string ("HRsniper"));
	cout << "UNI string valor: " << *nstring0 << " - " << "UNI string tamanho: " << nstring0->size() << "\n";
    delete nstring0;
*/
	unique_ptr <string> nstring(new string ("HRsniper"));
	cout << "UNI string valor: " << *nstring << " - " << "UNI string tamanho: " << nstring->size() << "\n";
//-----------------------------------------------------
cout << endl;
//-----------------------------------------------------
/*    //normal
    carro *c1=new carro();
    cout << "vel: " << c1->getvel() << "\n";
    delete c1;
*/
    unique_ptr <carro> c1(new carro);
    cout << "vel c1: " << c1->getvel() << "\n";
//-----------------------------------------------------
    unique_ptr <carro> c2(new carro);
    c2->setvel(50);
    cout << "vel c2: " << c2->getvel() << "\n";
//-----------------------------------------------------
    cout << endl;
//-----------------------------------------------------
    shared_ptr <carro> c3(new carro);
    shared_ptr <carro> c4=c3;
    c3->setvel(100);
    cout << "vel c3: " << c3->getvel() << "\n";
    cout << "vel c4: " << c4->getvel() << "\n";
//-----------------------------------------------------
//-----------------------------------------------------
	cout << endl;
	system("pause");
	return 0;
}
