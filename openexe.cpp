#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main(){

    //ShellExecuteA(NULL,"open","C:/Users/PCprincipal/Documents/Testes DEV/curso c++/teste.exe",NULL,NULL,SW_SHOWDEFAULT);
    ShellExecuteA(NULL,"open","C:/Windows/system32/cmd.exe",NULL,NULL,SW_SHOWDEFAULT);

    string link{"cd C:/Users/PCprincipal/Documents/Testes DEV/knn"};
    string link2{"main.exe < dataset.txt"};

	system("pause");
	return 0;
}
