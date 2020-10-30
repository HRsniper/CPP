#include <iostream>

using namespace std;

class veiculo{
public:
	int rodas;
	const char* nome;
private:
	int velmax;
	int pot;
protected:
	int porta;
	const char* cor;
};

class carro:public veiculo{//herdando public e protected
public:
	carro(){
		rodas=4;
		nome="carro";
		//velmax=180;
		//pot=120;
		porta=4;
		cor="preto";


		cout << "rodas   : " << rodas << "\n";
		cout << "nome    : " << nome << "\n";
		//cout << "velmax  : " << velmax << "\n";
		//cout << "pot     : " << pot << "\n";
		cout << "porta   : " << porta << "\n";
		cout << "cor     : " << cor << "\n\n";

	}
};

class moto{
public:
	carro c;//estanciando class carro nao herda private e protected

	moto(){
		c.rodas=2;
		c.nome="moto";
		//velmax=180;
		//pot=120;
		//porta=4;
		//cor="preto";


		cout << "rodas   : " << c.rodas << "\n";
		cout << "nome    : " << c.nome << "\n";
		//cout << "velmax  : " << velmax << "\n";
		//cout << "pot     : " << pot << "\n";
		//cout << "porta  : " << porta << "\n";
		//cout << "cor     : " << cor << "\n\n";

	}
};

int main(){

	carro v1;
		cout << endl;
	moto v2;


	return 0;
}
