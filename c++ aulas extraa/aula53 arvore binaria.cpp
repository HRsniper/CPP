/*  arvore binaria de busca ou de pesquisa. 
    elementos da sub-arvore a esquerda sao sempre menores que a raiz, 
    e elemetos da sub-arvore direita sap sempre maiores que a raiz.

        8 raiz
       / \
      3   10 filhos
     / \    \
    1   6   14
       / \    \
      4   7    13 folhas

*/

#include <iostream>
using namespace std;

class No
{
private:
	No *esq, *dir;
	int nochave;

public:
	No(int chave)
	{
		this->nochave = chave;
		esq = NULL;
		dir = NULL;
	}

	int getChave()
	{
		return nochave;
	}
	
	// funções getters e setters

	No* getEsq()//retorna no a esquerda
	{
		return esq;
	}

	No* getDir()//retorna no a direita
	{
		return dir;
	}

	void setEsq(No *no)//setar no a esquerda
	{
		esq = no;
	}

	void setDir(No *no)//setar no a direita
	{
		dir = no;
	}
};

class Arvore
{
private:
	No *raiz;

public:
	Arvore()
	{
		raiz = NULL;
	}

	void inserir(int chave)
	{
		if(raiz == NULL) // verifica se a árvore está vazia
        {
			raiz = new No(chave); // cria um novo nó
        }
        else
        {
			inserirAux(raiz, chave);
        }
	}

	void inserirAux(No *no, int chave)
	{
		// se for menor, então insere à esquerda
		if(chave < no->getChave())
		{
			// verifica se a esquerda é nulo
			if(no->getEsq() == NULL)
			{
				No *novo_no = new No(chave);
				no->setEsq(novo_no); // seta o novo_no à esquerda
			}
			else
			{
				// senão, continua percorrendo recursivamente
				inserirAux(no->getEsq(), chave);
			}
		}
		// se for maior, então insere à direita
		else if(chave > no->getChave())
		{
			// verifica se a direita é nulo
			if(no->getDir() == NULL)
			{
				No *novo_no = new No(chave);
				no->setDir(novo_no); // seta o novo_no à direita
			}
			else
			{
				// senão, continua percorrendo recursivamente
				inserirAux(no->getDir(), chave);
			}
		}
		// se for igual, não vai inserir
		// não pode existir 2 chaves iguais
	}

	No* getRaiz()
	{
		return raiz;
	}

	void emOrdem(No* no)
	{
		if(no != NULL)
		{
			emOrdem(no->getEsq());
			cout << no->getChave() << " ";
			emOrdem(no->getDir());
		}
	}
};

int main(int argc, char *argv[])
{
	Arvore arv;

	// insere as chaves
	arv.inserir(8);
	arv.inserir(3);
	arv.inserir(10);
	arv.inserir(14);
	arv.inserir(13);
	arv.inserir(1);
	arv.inserir(6);
	arv.inserir(4);
	arv.inserir(7);

	// percorre em ordem iniciando da raiz
	cout << "Percorrendo em ordem...\n";
	arv.emOrdem(arv.getRaiz());

	return 0;
} 