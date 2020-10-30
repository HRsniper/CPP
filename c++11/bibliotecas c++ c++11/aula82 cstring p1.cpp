#include <iostream>
#include <cstring>

using namespace std;

struct{
    char nome[30];
}pessoa1,pessoa2;

int main(){

    char txt1[30]{"copinado char para ........."};
    char txt2[30]{};
    char txt3[30]{"copinado de novo"};

    strcpy(txt2,txt1);
        cout << txt2 << endl;

    memcpy(txt2,txt3,sizeof(txt3));
        cout << txt2 << endl;
//-------------------------------------------------------------------
    char meunome[]{"HRsniper"};

    memcpy(pessoa1.nome,meunome,strlen(meunome)+1);
         cout << pessoa1.nome << endl;

    memcpy(pessoa2.nome,pessoa1.nome,sizeof(pessoa1.nome)+1);
         cout << pessoa2.nome  << endl;
//-------------------------------------------------------------------
        //ou *junta
    char junta[30]{"juntando string"};
    //strcat(junta," mais esse texto akiiiiiii");
    strncat(junta," mais esse texto akiiiiiii",20);
    //strcat(junta,junta2);
        cout << junta << endl;
//-------------------------------------------------------------------
    int res;
    res=strcmp(junta,txt1);
        if (res==0){
            cout << "iguais" << endl;
        }
        else{
            cout << "diferentes" << "\n";
        }

//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------


	system("pause");
	return 0;
}
/*
Funções:
memcpy > copia o bloco de memoria   semenlhante strcpy
strcpy > copia uma string de uma determinada origem para outra string
strlen > retorna o tamnho da string indicada strlen(string)
strncpy
strcat > concatena 2 string ou novo conteudo a string
strncap > concatena 2 string ou novo conteudo a string ate maximo de char q quizer strcat(junta,junta2,3)
memcmp > compara os blocos
strcmp > comparacao entre 2 string 0=igual / >0=1>2 / >0=2>1
strncmp > comparacao entre 2 string ate qual vc quiser strncmp(t1,t2,6)
 */