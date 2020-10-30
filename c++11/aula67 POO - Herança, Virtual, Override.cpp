#include <iostream>

using namespace std;

class veiculos{
public:
	const char* cor;
	//virtual vai dar a funçao que ela poder ser sobreescrita(override) em outra classe

	void setnome(const char* n){
		nome=n;
	}
    void setrodas(int r){
		rodas=r;
	}
	void setvelmax(int v){
		velmax=v;
	}

	const char* getnome(){
		return nome;
	}
	int getrodas(){
		return rodas;
	}
	int getvelmax(){
		return velmax;
	}

	virtual void imp(){
		cout << "nome___: " << nome << "\n";
		cout << "rodas__: " << rodas << "\n";
		cout << "velmax_: " << velmax << "\n";
		cout << "cor____: " << cor << "\n\n";
	}

private:
	//const char* = string
	const char* nome;
	int rodas;
	int velmax;
};

class carro:public veiculos{
public:
	carro(){
		setnome("Carro");
		setvelmax(180);
		setrodas(4);
		cor="preto";
	}
};

class moto:public veiculos{
public:
	moto(){
		setnome("Moto");
		setvelmax(150);
		setrodas(2);
		cor="vermelha";
	}
};

class militar:public veiculos{
public:
    int municao;
    string tipomunicao;
    bool arma;
	militar(bool a, int m, string tm):arma(a), municao(m), tipomunicao(tm){
		setnome("Tank");
		setvelmax(80);
		setrodas(6);
		cor="verde camuflado";
            if(a){//bool true
                municao=m;
                tipomunicao=tm;
            }else{//bool false
                municao=0;
                tipomunicao="sem arma";
            }
	}
	void imp() override{//sobreescreve imp()de veiculos para classe militar
        cout << "nome________: " << getnome() << "\n";
		cout << "rodas_______: " << getrodas() << "\n";
		cout << "velmax______: " << getvelmax() << "\n";
		cout << "cor_________: " << cor << "\n";
		cout << "____________: 1=true/0=false" <<  "\n";
		cout << "arma________: " << arma << "\n";
		cout << "minucao_____: " << municao << "\n";
		cout << "tipomunicao_: " << tipomunicao << "\n\n";
        }
};

int main(){

    carro v1;
    v1.imp();

    moto v2;
    v2.imp();

    militar v3{false,30,"5.56mm"};
    v3.imp();

    militar v4{true,0,"7.62mm"};
    v4.imp();

    militar v5{true,300,".50"};
    v5.imp();

    cout << endl;
    system("pause");
	return 0;
}
