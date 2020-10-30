#include <iostream>
#include <cstring>

using namespace std;


int main(){
//-------------------------------------------------------------------
	char *tx;
	char txt2[]{"CFB Cursos"};
	char pesquisa= 'u';
	tx=(char*)memchr(txt2,pesquisa,strlen(txt2));
		if (tx!=NULL)
		{														//posicao na string
			cout << "letra: " << pesquisa << " encontrada em: " << tx-txt2+1 << endl;
		}
		else
		{
			cout << "letra: " << pesquisa << " nao encontrada" << endl;
		}


//-------------------------------------------------------------------
	char *c;
	char pesquisa1='C';
	c=strchr(txt2,pesquisa1);
	cout << "pos: " << c-txt2/* c-txt2+1 */ << "\n";
//-------------------------------------------------------------------
	char texto[]{"youtube facebook js c++ "};
	char chave[]{"f+"};
	int i;
	i=strcspn(texto,chave);
		cout << "pos: " << i/* i+1 */ << " - " << texto[i] << "\n";
//-------------------------------------------------------------------
    char texto1[]{"youtube- facebook, js c++ f"};
	char *c1;
	char  pesquisa2='f';
	c1=strrchr(texto1,pesquisa2);
        cout << "pos: " << c1-texto1 << "\n";
//-------------------------------------------------------------------
    char texto2[]{"youtube- facebook, js c++ f"};
	char *c2;
    c2=strtok(texto2,"-,");
        while(c2!=NULL){
            cout << c2 << endl;
            c2=strtok(NULL,"-,");
        }
//-------------------------------------------------------------------


	system("pause");
	return 0;
}
/*
Funções:
memchr > localiza determinada caracte no bloco de memoria
strchr > localiza 1 primeira caract em uma string
strcspn > localiza dentro de uma string uma chave
strrchr > o ultimo elemento na string
strtok >   divide a string em determinado fatorres . , -
strlen > retorna o tamnho da string indicada strlen(string)


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
