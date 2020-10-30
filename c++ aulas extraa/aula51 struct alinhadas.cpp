#include <iostream>
#include <cstring>
using namespace std;

/* typedef */ struct Curso {
	char nome[50];
	double preco;

};// t_curso;//typedef

/* typedef */ struct Estudante {
	char nome[50];
	Curso curso;//struct alinhada
};// t_estudante;//typedef

int main(int argc, char *argv[]) {

	Estudante e;

	strcpy(e.nome,"HR");
	strcpy(e.curso.nome,"C++");
	e.curso.preco= 10;

	cout << "nome: " << e.nome << endl;
	cout << "curso: " << e.curso.nome << endl;
	cout << "preco: " << e.curso.preco << endl;

	return 0;
}