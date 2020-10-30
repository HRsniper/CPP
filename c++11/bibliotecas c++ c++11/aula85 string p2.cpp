#include <iostream>
#include <string>

using namespace std;

int main(){
//----------------------------------------
	string txt("regHhnh- er- teakim enter rt. tre,t eray");
	int tam=txt.size();

	/*for (int i = 0; i < tam; i++){
		cout << txt[i];
	} */
	cout << txt.at(3) << endl;

	cout << txt.back() << endl;

		txt.back()='Z';
		cout << txt.back() << endl;

	cout << txt.front() << endl;
		txt.front()='T';
		cout << txt.front() << endl;


	cout << endl;
//----------------------------------------
	string txt1("rgherheh");
	//txt1="gwrju"//substitui o primeiro valor
	txt1+=" eheheuuu";// juntando ao primeiro valor
	cout << txt1 << endl;
//----------------------------------------
	txt1.append(" rjhriyi");
	cout << txt1 << endl;
//----------------------------------------
	txt1.push_back('Z');
	cout << txt1 << endl;
//----------------------------------------
	txt1.assign("blablalbalAZZZZZZZZZA");
	cout << txt1 << endl;
//----------------------------------------
	txt1.pop_back();
	cout << txt1 << endl;
//----------------------------------------
	txt1.insert(5," - ");
	cout << txt1 << endl;
//----------------------------------------
	txt1.erase(15,5);
	cout << txt1 << endl;
//----------------------------------------
	string txt2="visual";
	txt1.replace(3,7,txt2);
	cout << txt1 << endl;
//----------------------------------------
	string txt3="troca";
	txt2.swap(txt3);
	cout << txt2 << endl;
	cout << txt3 << endl;
//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
	system("pause");
	return 0;
}
/*
funçoes
=
+=
.assign() > substitui a string original .assing("blala")
.at() > retorna o elemento indicado na possiçao .at(1)
.back() > retorna para o ultimo elemento ou mudar ele .back()='a'
.front() > retorna para o primeiro elemento ou podendo mudar ele .front()='T'
.append() > junta a string primaria .ppend("hwh")
.push_back() > adiciona uma caracte ao final .push_back('B')
.push_front()
.pop_back() > retira o ultimo caractere da string
.pop_front()
.insert() > insere uma letra ou string em determinado espaço
.erase() > remove caracte de um ponto inicial e quantos quer
.replace() > substitue parte da string ponto inicial , a quantidade eo quer substuir
.swap() > troca os valores
*/
