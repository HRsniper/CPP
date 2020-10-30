#include <iostream>
//#include <locale.h>
#include <locale>

using namespace std;

int main(){

    setlocale(LC_ALL,"portuguese");
    cout << "é ç õ Ô è " << "\n";

    system("pause");
	return 0;
}
