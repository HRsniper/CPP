#include <iostream>

using namespace std;

int main(){

    char nome[20];
    char n,m;
/*
    cout << "imprimi no console" << endl;
    cin >> nome;//colote os dados digitados
*/
/*
    cin.get(nome,20);//le letra por letra,recomendado para console
    cout << nome << endl;
*/
/*
    cin.getline(nome,20);//le linha por linha,,recomendado para arquivos
    cout << nome << endl;
*/
/*
    cin.get(nome,20);
    cout << "digitado: " << nome << " - " << cin.gcount();//gcount conta os numeros de caractere digitdos
*/
    n=cin.get();//coletar primeira letra da pelavra
    cin.ignore(20,' ');//ignora o que tiver entre '
    m=cin.get();
    cout << n << " - " << m << "\n";

    system("pause");
    return 0;
}
