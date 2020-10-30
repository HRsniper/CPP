// Algoritmos Genéticos - Problema OneMax

#include <iostream>
#include <vector>
#include <cstdlib>//para funçao de numeros aleatorios
#include <ctime>

using namespace std;

// parâmetros do algoritmo genético
int qtde_genes = 100; // quantidade de genes a pontuacao deve ser proximo de qtde_genes
int tam_populacao = 50; // quantidade de indivíduos da população
int tam_cruzamentos = 20; // tamanho dos cruzamentos
int qtde_geracoes = 500; // quantidade de gerações
double prob_mutacao = 0.2; // probabilidade de mutação // em diferentes problemas um maior valor mostra melhores resultados
double prob_cruzamento = 0.7; // probabilidade de cruzamento

//populacao
vector<vector<int> > populacao;

void InicializarPopulacao() {
    for(size_t i=0; i<tam_populacao; i++) {

        vector<int> individuo;

        for (size_t j = 0; j < qtde_genes; j++) {
            int gene = rand() % 2; // escolhe um número no intervalo de 0,1

            individuo.push_back(gene);// insere no vetor do individuo
        }
        
        populacao.push_back(individuo);// insere no vetor da populacao
    }
}

void MostrarPopulacao() {
    for (size_t i = 0; i < tam_populacao; i++) {

        for (size_t j = 0; j < qtde_genes; j++) {
            cout << populacao[i][j] << " ";
            // cout << endl;
        }
    }
}

// retorna a pontuacao do indivíduo e é a soma dos valores dos genes
int ObterPontuacaoIndividuo(vector<int> indiviuoo) {
    int soma = 0;

    for (size_t i = 0; i < qtde_genes; i++) {
        soma += indiviuoo[i];
    }
        return soma;    
}

void Mutacao(vector<int> &individuom) {
    // escolhe um gene aleatoriamente no intervalo de 0,qtde_genes - 1
    int geneM = rand() % qtde_genes;
    // modifica o valor do gene escolhido
    if(individuom[geneM] == 0) {
        //atribui 1
        individuom[geneM] = 1;
    }
    else {
        //atribui 0
        individuom[geneM] = 0;
    }
}

void Cruzamento(int index_pai, int index_mae, vector<int> &index_filho) {
    // escolhe um ponto de cruzamento aleatoriamente no intervalo de 0,qtde_genes - 1
    int pontocruzamento = rand() % qtde_genes;

    for (size_t i = 0; i <= pontocruzamento; i++) {
        //index_pai acessa o indivioduo da populacao , [i] acessa o valor/gene do individuo
        index_filho.push_back(populacao[index_pai][i]);
    }

    for (size_t i = pontocruzamento; i < qtde_genes; i++) {
        //index_mae acessa o indivioduo da populacao , [i] acessa o valor/gene do individuo
        index_filho.push_back(populacao[index_mae][i]);        
    }
}

// retorna o índice do melhor indivíduo da população
int ObterMelhorIndividuo() {
    int melhorindividuo = 0;
    int melhorpontuacao = ObterPontuacaoIndividuo(populacao[0]);//pontuacao do primeiro individuo

    for (size_t i = 1; i < tam_populacao; i++) {
        int pontuacao = ObterPontuacaoIndividuo(populacao[i]);

        if(pontuacao > melhorpontuacao) {
            melhorindividuo = i;
            melhorpontuacao = pontuacao;
        }
    }

    return melhorindividuo;
}



int main() {

    //geraçao de numero aleatorios
    srand(time(NULL));

    InicializarPopulacao();
    MostrarPopulacao();

    for (size_t i = 0; i < qtde_geracoes; i++) {
        
        for (size_t j = 0; j < tam_cruzamentos; j++) {

            // calcula a probabilidade de cruzamento
                                //int rand() para double rand()
            double probabilidade = ((double) rand()) / ((double) RAND_MAX + 1);

            if(probabilidade < prob_cruzamento) {
                // escolha dos pais
                int PAI = rand() % tam_populacao;
                int MAE;


            //garantir que nao sejam os mesmo pais
            do {
                MAE = rand() % tam_populacao;
            } while (PAI == MAE);
                
            vector<int> FILHO;

            Cruzamento(PAI,MAE,FILHO);
                
            // probabilidadem = ((double) rand()) / ((double) RAND_MAX + 1);
            // if (probabilidadem < prob_mutacao) {
            if (probabilidade < prob_mutacao) {
                Mutacao(FILHO);
            }
                
            int pontuacaopai = ObterPontuacaoIndividuo(populacao[PAI]);
            int pontuacaofilho = ObterPontuacaoIndividuo(FILHO);

            if(pontuacaofilho > pontuacaopai) {
                for (size_t k = 0; k < qtde_genes; k++) {
                    // substitui valor do pai pelo do filho
                    populacao[PAI][k] = FILHO[k];
                    }
                }
            }
        }

        cout << " Geracao: " << i+1 << endl;
        cout << " Melhor: ";

        int Omelhorindividuo = ObterMelhorIndividuo();
        int Omelhorpontuacao = ObterPontuacaoIndividuo(populacao[Omelhorindividuo]);

        for (size_t l = 0; l < qtde_genes; l++) {
            cout << populacao[Omelhorindividuo][l] << " ";
        }

        cout << "\n Pontuacao: " << Omelhorpontuacao << "\n\n";

        
        // verifica se encontrou a solução ótima global
        if(Omelhorpontuacao == qtde_genes) {
            break;
        }
    }

    system("pause");
    return 0;
}