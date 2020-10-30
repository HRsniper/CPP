#include <iostream>
#include <iomanip>

using namespace std;

int main(){
///////////////////////////////////////////////////////////////////////////////////////////
    //setbase - base = decimal , hexaecimal , octal

    cout << setbase(16);
    cout << 10 << "\n";

    cout << setbase(10);
    cout << 10 << "\n";

cout << endl;
///////////////////////////////////////////////////////////////////////////////////////////
    //setw - lagura do campo // espaço entre textos

    cout << setw(20);
    cout << "cfb";

    cout << setw(10);
    cout << "cursos";

    cout << setw(40);
    cout << "curso de c++" << "\n\n";

///////////////////////////////////////////////////////////////////////////////////////////

    //setfill - preenchimento do campo

    cout << "canal:" << setw(15) << setfill('.') << "cfb cursos" << "\n\n";

///////////////////////////////////////////////////////////////////////////////////////////

    //setprecision -  calcular precisao dos valores float e double, casos decimais

    double pi=3.141592;//conta com o .
    cout << setprecision(3) << pi << "\n\n";//3.14

///////////////////////////////////////////////////////////////////////////////////////////

	system("pause");
	return 0;
}
