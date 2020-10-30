#include <iostream>

using namespace std;

int main(){

	int *p;
	int vetor[5];

	p=vetor;
	cout << "Endereco vetor[0]: " << p  << "\n";

	p=&vetor[0];
	cout << "Endereco vetor[0]: " << p  << "\n";
	
	*p=10;
	cout << "valor de vetor[0]: " << *p << "\n";
	cout << "valor de vetor[0]: " << vetor[0] << "\n";

    cout << "\n";

	/* p=&vetor[1];
	cout << "Endereco: " << p  << "\n"; */ // 0x6dfedc
	*(p++);//vetor[1]
	cout << "Endereco vetor[1]: " << p  << "\n"; // 0x6dfedc
	*p=11;
	cout << "valor de vetor[1]: " << *p << "\n";

	cout << endl;

	*(p++);//vetor[2]
	cout << "Endereco vetor[2]: " << p  << "\n";
    *p=12;
	cout << "valor de vetor[2]: " << *p << "\n";

	system("pause");
	return 0;
}
