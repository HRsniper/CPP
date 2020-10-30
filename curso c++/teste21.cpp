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
        cout << "Nome: " << nome << "||" << "Ano: " << ano << "||" << "Tipo: " << tipo << "||" << "Cilindrada: " << cili << "||" << "potencia: " << pot << "||" << "velocidade maxima: " << velmax << "\n\n";
    }
};

int main(){

	Carros car1;
	Carros car2;
	Carros car3;

	car1.insere("Chevrolet Camaro SS", 1969, "Esportivo", 6478, 330, 201);
    car2.insere("BMW X6 xDrive50i", 2015, "Luxo", 4395, 450, 250);
    car3.insere("Fiat Strada 1.8", 2014, "Pickup", 1910, 80, 163);

    car1.exibir();
    car2.exibir();
    car3.exibir();

    /*
	car1.nome= "Chevrolet Camaro SS";
	car1.ano= "1969";
	car1.tipo= "Esportivo";
	car1.cili= 6478;
	car1.pot= 330;
	car1.velmax= 201;

	car2.nome= "BMW X6 xDrive50i";
	car2.ano= "2015";
	car2.tipo= "Luxo";
	car2.cili= 4395;
	car2.pot= 450;
	car2.velmax= 250;

	car3.nome= "Fiat Strada 1.8";
	car3.ano= "2004";
	car3.tipo= "Pickup";
	car3.cili= 1910;
	car3.pot= 80;
	car3.velmax= 163;

	cout << "Nome: " << car1.nome << "||" << "Ano: " << car1.ano << "||" << "Tipo: " << car1.tipo << "||" << "Cilindrada: " << car1.cili << "||" << "potencia: " << car1.pot << "||" << "velocidade maxima: " << car1.velmax << "\n\n";

	cout << "Nome: " << car2.nome << "||" << "Ano: " << car2.ano << "||" << "Tipo: " << car2.tipo << "||" << "Cilindrada: " << car2.cili << "||" << "potencia: " << car2.pot << "||" << "velocidade maxima: " << car2.velmax << "\n\n";

	cout << "Nome: " << car3.nome << "||" << "Ano: " << car3.ano << "||" << "Tipo: " << car3.tipo << "||" << "Cilindrada: " << car3.cili << "||" << "potencia: " << car3.pot << "||" << "velocidade maxima: " << car3.velmax << "\n";
*/
	system("pause");return 0;
}
