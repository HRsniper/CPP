#include <iostream>
#include <memory>//para smart pointer Unique_ptr

using namespace std;

class veiculos{
public:
    int pot;
    int velmax;
    //const char* = string
    const char* tipo;
    //novo metodo construtor dentro da classe
/*
    veiculos(const char* t, int p){
        this->pot=p;
        this->tipo=t;
*/
    veiculos(const char* t, int p):tipo(t),pot(p){//lista de inicializacao
           if (p<=100){
                this->velmax=150;
            }else if (p<=200){
                this->velmax=225;
            }else{
                this->velmax=320;
            }
    }

private:
    //code
protected:
    //code
};

int main(){

    // chamada do metodo normal antigo
    veiculos *carro1=new veiculos("fiat",200);
    cout << "metodo normal:" << endl;
    cout << "carro1 tipo:" << carro1->tipo << " - " << "pot:" << carro1->pot << " - "<< "velmax:" << carro1->velmax << endl;
    delete carro1;

cout << endl;

    //com lista de inicializacao
    veiculos carro2{"fiat",200};
    cout << "metodo com lista de inicializacao:" << endl;
    cout << "carro2 tipo:" << carro2.tipo << " - " << "pot:" << carro2.pot << " - "<< "velmax:" << carro2.velmax << endl;

cout << endl;

    //smart pointer
    unique_ptr<veiculos> carro3(new veiculos{"fiat",200});
    cout << "metodo com smart pointer:" << endl;
    cout << "carro3 tipo:" << carro3->tipo << " - " << "pot:" << carro3->pot << " - "<< "velmax:" << carro3->velmax << endl;

    cout << endl;
    system("pause");
    return 0;
}
