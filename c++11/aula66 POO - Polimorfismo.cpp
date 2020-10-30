#include <iostream>

using namespace std;

class veiculos{
public:
    int pot;
    //const char* = string
    const char* tipo;
    //novo metodo construtor dentro da classe
    veiculos(const char* t, int p):tipo(t),pot(p){//lista de inicializacao
           if (p<=100){
                this->velmax=150;
                //this->setvelmax(150);
            }else if (p<=200){
                this->velmax=225;
                //this->setvelmax(225);
            }else{
                this->velmax=320;
                //this->setvelmax(320);
            }
    }

	veiculos(){
		pot=400;
		velmax=500;
		tipo="Rancing";
	}

	int getvelmax(){
		return this->velmax;
	}

private:
    int velmax;
/*  void setvelmax(int vm){//se velmax ja vai ser usado na classe nao e necessario setvelmax
    this->velmax=vm;
    }
*/

protected:
    //code
};

int main(){

    // veiculos()
    veiculos carro1;
    cout << "carro1 tipo:" << carro1.tipo << " - " << "pot:" << carro1.pot << " - "<< "velmax:" << carro1.getvelmax() << endl;

cout << endl;

    //veiculos(const char* t, int p)
    veiculos carro2{"fiat",200};
    cout << "carro2 tipo:" << carro2.tipo << " - " << "pot:" << carro2.pot << " - "<< "velmax:" << carro2.getvelmax() << endl;

    cout << endl;
    system("pause");
    return 0;
}
