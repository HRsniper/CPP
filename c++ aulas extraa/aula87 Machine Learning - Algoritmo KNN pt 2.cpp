// Implementação do k-NN (k-nearest neighbors algorithm)

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>

using namespace std;

class Individuo {
private:
    string Classe;
    double A,B,C,D;

public:
    //construtor
    Individuo(double a , double b, double c , double d, string classe) {
        this->A=a;
        this->B=b;
        this->C=c;
        this->D=d;
        this->Classe=classe;
    }

    double getA() {
        return A;
    }

    double getB() {
        return B;
    }

    double getC() {
        return C;
    }

    double getD() {
        return D;
    }

    string getClasse() {
        return Classe;
    }
};

// função que retorna a distância euclidiana entre 2 indivíduos
double getDistanciaEuclidiania(Individuo ind1, Individuo ind2) {
/*    a distância euclidiana é a raiz quadrada da soma das
      diferenças dos valores dos atributos elevado ao quadrado    */
    double distE = pow((ind1.getA() - ind2.getA()), 2) +
                   pow((ind1.getB() - ind2.getB()), 2) +
                   pow((ind1.getC() - ind2.getC()), 2) +
                   pow((ind1.getD() - ind2.getD()), 2);

    return sqrt(distE);
}

// essa função classifica uma nova amostra
string classificarAmostra(vector <Individuo> &individuos, Individuo newExemplo, int K) {
    //se K for Par,decrementa
    if(K%2 == 0) {
        K--;

        if(K <= 0) {
            K=1;
        }
    }

    //obtem o tamnhado do vector
    int sizeVector = individuos.size();

/*    set de pairs da distância de cada indivíduo
      do conjunto de treinamento para o novo exemplo
      cada pair é composto pela distância e o índice
      do indivíduo no vetor    */
    set <pair<double, int> > distIndividuos;

/*    calcula-se a distância euclidiana do novo exemplo
      para cada amostra do conjunto de treinamento    */
    for (size_t i=0; i<sizeVector; i++) {
        double dist = getDistanciaEuclidiania(individuos[i], newExemplo);
        distIndividuos.insert(make_pair(dist, i));
    }
    
/*    para decidir a qual classe pertence o novo exemplo,
      basta verificar a classe mais frequente dos K
      vizinhos mais próximos    */
    set <pair<double, int> >::iterator it;

/*    o contador de Iris-setosa estará no índice 0,
      o contador de Iris-versicolor estará no índice 1
      e o contador de Iris-virginica estará no índice 2    */
    vector <int> contClasses(3);

    int contK = 0;

    for (it=distIndividuos.begin(); it!=distIndividuos.end(); it++) {
        if (contK == K) {
            break;
        }
        string classe = individuos[it->second].getClasse();
        
        if (classe == "Iris-setosa") {
             contClasses[0]++;
        }
        else if (classe == "Iris-versicolor") {
            contClasses[1]++;
        }
        else /* Iris-virginica */ {
            contClasses[2]++;
        }
        contK++;
    }
    
    string classeDeClassificacao;
    if (contClasses[0] >= contClasses[1] && contClasses[0] >= contClasses[2]) {
        classeDeClassificacao = "Iris-setosa";
    }
    else if (contClasses[1] >= contClasses[0] && contClasses[1] >= contClasses[2]) {
        classeDeClassificacao = "Iris-versicolor";
    }
    else {
        classeDeClassificacao = "Iris-virginica";
    }
    return classeDeClassificacao;
}

int main() {

    vector <Individuo> individuos;

/*    o K é a quantidade de vizinhos que serão
      levados em conta para classificação de um
      novo dado, é recomendável que seja ímpar
      para que não possa haver empate    */
    int K = 3;

    //tamanho do conjunto de dados de treinamento,recomendado 70% dos dados
    int treinamento = 105;

/*    o processo de treinamento consiste em apenas
      armazenar o conjunto de dados de treinamento    */
    for (size_t i=0; i<treinamento; i++) {
        string classe;
        double a,b,c,d;

        cin >> a >> b >> c >> d >> classe;
        individuos.push_back(Individuo(a,b,c,d,classe));
    }
    
    int acertos = 0;
    //tamanho do numeros de dados para serem testados
    int testes = 150 - treinamento;

    // processo de classificação
    for(int i=0; i<testes; i++) {
        string classe;
        double a,b,c,d;
        
        cin >> a >> b >> c >> d >> classe;

        Individuo ind(a,b,c,d,classe);
        string classeObtida = classificarAmostra(individuos,ind,K);

        cout << "Classe Esperada: " << classe << "\n";
        cout << "Classe Obtida: " << classeObtida << "\n\n";

        if(classe == classeObtida) {
            acertos++;
        }
    }

    cout << acertos << " acertos de um total de " << testes << " testes.\n";

    system("pause");
    return 0;
}









































