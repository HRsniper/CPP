#include <iostream>
#include <string>

using namespace std;

int main(){
//----------------------------------------
    string txt1("visual studio c++");
    string txt2;

    size_t encontra=txt1.find("c++");
    //se nao encontra ele retorna valor maximo igual ao npos

    if(encontra!=string::npos){//npos e constante que contem o valor maximo de size_t
        cout << "encotrado: " << encontra << endl;
    }else{
        cout << " nao econtrada" << endl;
    }

    cout << encontra << endl;
//----------------------------------------
    txt2=txt1.substr(7,6);
    cout << txt2 << endl;
//----------------------------------------
    string txt3("visual studio c++");
    if (txt3.compare(txt1)==0){
        cout << "iguais" << endl;
    }else{
        cout << "difrentes" << endl;
    }

//----------------------------------------
    string txt4("20"), txt5;
    int ano=2040,res;

    res=ano-stoi(txt4);
        cout << res << endl;

    txt5=to_string(res);
        cout << txt5 << endl;

//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
	system("pause");
	return 0;
}
/*
.find() > encontra dentro da string e retorn sua posiçao
.substr()> retorna uma nova string de acordo com a posiçao indica na string .substr(1,5)ponto inical,quantos buscar
.compare() > compara 2 string

converçao
stoi > string para int
to_string() > coverte numeral para string
stol > string para long int
stoll > string para long long int
stoul > string para ousing long int
stooull string para ousing long long int
stod >  string para double
stof > string para float
stold > string long double

*/
