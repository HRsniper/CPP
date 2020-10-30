#include <iostream>
using namespace std;

void nada();
void nada1();
void soma(int n1, int n2);
int valor(int n1, int n2);
void vaicom(string qual[4]);

int main (){
    int res;
    string veiculo[4]= ("carro", "moto", "barco", "pe");

    nada();

    for(int indice=0 ; indice<5 ; indice++){
        nada1();
    }

    cout << "\n";

    soma(20,3);

    cout << "\n";

    res=valor(300,1);
    cout << "resultado do Valor: " << res << "\n";
    cout << "resultado do Valor: " << valor(200,1) << "\n";

    cout << "\n";

    vaicom(veiculo);

    system("pause");
    system("pause");
}
void nada(){
    cout << "testes para funcaoes por no prototipo\n\n";
}
void nada1(){
    cout << "testes para funcaoes por no prototipo e loop no for\n";
}
void soma(int n1, int n2){
    cout << "soma dos valores: " << n1+n2 << "\n";
}
// n1 e n2 nao é o mesmo de void soma
int valor(int n1, int n2){
    return n1+n2;
}
void vaicom(string qual[4]){
    for(int indice=0; indice<4; indice++){
        cout << qual[indice] << "\n";
    }
}
