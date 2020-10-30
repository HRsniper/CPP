#include <iostream>
#include <cstdlib>
#include <locale>

using namespace std;

void fim(){
    cout << "final pode sair" << "\n";
};
int comparacao(const void* a1, const void* b2){
    return( *(int*) a1 - *(int*) b2);
    /*
    0 -> a1=b2
    >0 -> a1=b2
    <0 -> a1=b2
    */
}

int main(int argc, char* argv[]){
    setlocale(0,"portuguese");

//  funçoes de ambiente
//  abort();//finaliza o programa
//  exit(int);//finaliza o programa
//  atexit(funcao)//chama uma fun�ao no final do programa
//  quick_exit//finaliza o programa
//  at_quick_exit(funcao)//chama uma fun�ao no final do prorama
//  getenv(const char*)//obtem as variaveis de ambiente do sistema OS(windowns)
//  system("comando")//roda uma comando ou programa do sistema
//  _Exit(int)//finaliza o programa

//  Fun��es para Pesquisa e ordena��o de vetores
//bsearch(&elementoApesq,vetor/array,tamanhodovetor,sizeof(int),funcaodecomparacao)//faz a busca no array
//qsort(vetor/array,tamanhodovetor,sizeof(int),funcaodecomparacao)//faz a ordena�ao no array
//-----------------------------------------------------------------------
    atexit(fim);

    int vetor[]={861,113,161,181,118,11,61,21,36,18};
    for(int i=0;i<10;i++){
        if(i<5){
            cout<< vetor[i] <<endl;
        }else{
            //exit(0);
            cout<< vetor[i] <<endl;
        }
    }
//-----------------------------------------------------------------------
cout<<endl;
//-----------------------------------------------------------------------
    const char* pa;
    pa=getenv("PATH");
    cout << pa << endl;
//-----------------------------------------------------------------------
cout<<endl;
//-----------------------------------------------------------------------
    int vetor1[]={1861,113,161,181,118,11,61,21,36,18};
    int pesquisa=21;
    int *posicao;

    qsort(vetor1,sizeof(vetor1)/4,sizeof(int),comparacao);
        for(int i=0;i<10;i++){
            cout<< vetor1[i] <<endl;
        }
    posicao=(int*)bsearch(&pesquisa,vetor1,sizeof(vetor1)/4,sizeof(int),comparacao);
        cout << "pesquisado: " << pesquisa << " posicao no vetor: " << *posicao << endl;
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

	system("pause");
	return 0;
}
