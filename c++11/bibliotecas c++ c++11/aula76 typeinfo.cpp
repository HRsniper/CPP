#include <iostream>
#include <typeinfo>

using namespace std;

class classe{};

int main(){

	auto num{10};//int
	auto num1{1111100211};//long int
	auto num2{11111002111};//long long int
	auto num3{10.161};//double
	auto num4{'a'};//char
	auto num5{"Afwfwg"};//string
		cout << "tipo:" << typeid(num).name() << endl;
		cout << "tipo:" << typeid(num1).name() << endl;
		cout << "tipo:" << typeid(num2).name() << endl;
		cout << "tipo:" << typeid(num3).name() << endl;
		cout << "tipo:" << typeid(num4).name() << endl;
		cout << "tipo:" << typeid(num5).name() << endl;

	cout << "tipo:" << typeid(classe).name() << endl;
//----------------------------------------------------------
	if (typeid(int).before(typeid(char))){
		cout << "vem antes" << "\n";
	}else{
		cout << "nao vem" << "\n";
	}



	system("pause");
	return 0;
}
