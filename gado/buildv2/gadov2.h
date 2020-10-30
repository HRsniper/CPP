#ifndef GADOV2_H_INCLUDED
#define GADOV2_H_INCLUDED

using namespace std;

class Idade_Sexo {

private:
    string Idade;
    string Sexo;

public:
    void setIdade(string& I) {
        this->Idade = I;
    }

    void setSexo(string& S) {
        this->Sexo = S;
    }

    string& getIdade() {
        return Idade;
    }

    string& getSexo() {
        return Sexo;
    }

    friend ostream& operator<<(ostream& os,const Idade_Sexo& IS1){
        os << "\n" << IS1.Idade << "\n";
        os << IS1.Sexo;
        return os;
    }

    friend istream& operator>>(istream& is,Idade_Sexo& IS1){
        is >> IS1.Idade >> IS1.Sexo;
        return is;
    }

};

char menu() {

    char R;

	cout << "Digite 1 Para Inserir Cabeças\n";
	cout << "Digite 2 Para Listar a Relação\n";
	cout << "Digite 0 Para Sair\n";
	cout << "Opção: ";
	cin >> R;

	return R;
}
#endif // GADOV2_H_INCLUDED
