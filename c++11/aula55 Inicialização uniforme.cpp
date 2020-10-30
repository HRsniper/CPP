#include <iostream>
#include <vector>//biblioteca para vector
#include <map>// biblioteca para o map

using namespace std;

//****************************************************************************
struct pessoaV{
    string nome;
    int idade;
};
//****************************************************************************
class veiculoV{//novo metodo nao precisa de construtor, se coloca na inicializaçao
public:
    int tipo;
    string nome;
};
//****************************************************************************

int main(){

//****************************************************************************
    //-std=c++98 (1998) A de antigo
    int numA=10;
    //-std=c++11 (2011) V de novo
    int numV{10};//inicializacao uniforme

    cout << numV << "\n";
//****************************************************************************
    string nomeA= "HRsniper";

    string nomeV{"HRsniper"};//inicializacao uniforme

    cout << nomeV << "\n";
//****************************************************************************
    vector<int> vectorA; vectorA.push_back(100); vectorA.push_back(200); vectorA.push_back(300); vectorA.push_back(400); vectorA.push_back(500);

    vector<int> vectorV{1,2,3,4,5};//inicializacao uniforme

    for(vector<int>::iterator it=vectorA.begin();it!=vectorA.end();it++){
        cout << *it << "\n";
    }

    for(vector<int>::iterator it=vectorV.begin();it!=vectorV.end();it++){
        cout << *it << "\n";
    }
//****************************************************************************
    int vetorA[5]; vetorA[0]=101; vetorA[1]=201; vetorA[2]=301; vetorA[3]=401; vetorA[4]=501;

    cout << vetorA[0] << "\n";

    int vetorV[]{11,22,33,44,55};//inicializacao uniforme

    cout << vetorV[0] << "\n";
    /*for(int i=0;i<5;i++){
        cout << vetor[i] << "\n";
    }*/
//****************************************************************************
    map<string,string>capV{{"RO","Rondonia"}};//inicializacao uniforme

    for(map<string,string>::iterator it=capV.begin();it!=capV.end();it++){
        cout << it->first << " - " << it->second << "\n";
    }
//****************************************************************************
    pessoaV pV1{"HR",23};//inicializacao uniforme

    cout << pV1.nome << " - " << pV1.idade << "\n";
//****************************************************************************
    veiculoV vV1{1,"carro"};//inicializacao uniforme

    cout << vV1.tipo << " - " << vV1.nome << "\n";
//****************************************************************************

    system("pause");
	return 0;
}
