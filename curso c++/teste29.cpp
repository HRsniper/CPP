#include <iostream>
#include <cstdlib>//malloc = alocaçao e memorio dinamica
#include <cstdio>//gets = trabalha melhor com char

using namespace std;

int main(){

    char *nome;
    nome= (char *) malloc(sizeof(char));

    cout << "digite..: ";
    gets(nome);

    cout << "digitado: "<< nome;

    cout << endl;

	system("pause");
	return 0;
}
