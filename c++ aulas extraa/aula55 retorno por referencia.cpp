#include <iostream>

using namespace std;

struct pessoa {
    string nome;
    int idade;
    double peso, altura;
};

double & c_imc(pessoa & p1) { //retorno por referenfica &
    double resultado = p1.peso / (p1.altura * p1.altura);
    double & imc = resultado;
    
    return imc;
}

int main(int argc, char const *argv[]) {

    pessoa p{"HR",23,65.79,1.80};

    return 0;
}
