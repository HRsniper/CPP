#include <iostream>
#include <vector>

using namespace std;

int main(){

	vector <int> num1;
	vector <int> num2;
	int tam; // int tam, i;

	num1.push_back(1);
	num1.push_back(2);
	num1.push_back(3);
	num1.push_back(4);

	num2.push_back(5);
	num2.push_back(6);
	num2.push_back(7);
	num2.push_back(8);
	num2.push_back(9);

	//num1.swap(num2);//trocar de valores

	num1.insert(num1.begin(),1000);//insere no começo
	num1.insert(num1.end(),100);//insere no final
	num1.erase(num1.end()-1);// apagou o 100

	cout << "primeiro valor do vector1: " << num1.front() << "\n";
	cout << "ultimo valor do vector1: " << num1.back() << "\n";
	cout << "valor do meio vector1: " << num1.at(num1.size()/2) << "\n\n";

	tam=num1.size();// se tirar essa linha, no cout coloca-se num1.size()
	cout << "tamanho do vector1: " << tam << endl;
//for (i=0; i<tam; i++)
	for (int i=0; i<tam; i++){
		cout << "valores do vector1: " << num1[i] << "\n";
	}

	cout << "\n\n";

        tam=num2.size();
        cout << "tamanho do vector2: " << tam << endl;

        for (int i=0; i<tam; i++){
            cout << "valores do vector2: " << num2[i] << "\n";
        }



	system("pause");
	return 0;
}
