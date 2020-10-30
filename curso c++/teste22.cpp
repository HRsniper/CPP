#include <iostream>

using namespace std;

struct Carros{
	string nome;
	int ano;
	string tipo;
	int cili;
	int pot;
	int velmax;

    void insere(string stnome, int stano, string sttipo, int stcili, int stpot, int stvelmax ){
        nome=stnome;
        ano=stano;
        tipo=sttipo;
        cili=stcili;
        pot=stpot;
        velmax=stvelmax;
    }
    void exibir(){
        cout << "\nNome: " << nome << "||" << "Ano: " << ano << "||" << "Tipo: " << tipo << "||" << "Cilindrada: " << cili << "||" << "potencia: " << pot << "||" << "velocidade maxima: " << velmax << "\n";
    }
};

int main(){

    int count=3;// tamanho do vetor

    Carros *vetorcr=new Carros[3];

	Carros car1;
	Carros car2;
	Carros car3;

    vetorcr[0]= car1;
    vetorcr[1]= car2;
    vetorcr[2]= car3;

	vetorcr[0].insere("Chevrolet Camaro SS", 1969, "Esportivo", 6478, 330, 201);
    vetorcr[1].insere("BMW X6 xDrive50i", 2015, "Luxo", 4395, 450, 250);
    vetorcr[2].insere("Fiat Strada 1.8", 2014, "Pickup", 1910, 80, 163);
/*
    vetorcr[0].exibir();
    vetorcr[1].exibir();
    vetorcr[2].exibir();
*/
    for (int i=0; i<count; i++){
        vetorcr[i].exibir();
    }

    cout << endl;
	system("pause");return 0;
}
