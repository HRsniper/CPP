#include <iostream>
#include <fstream> // ofstream e ifstream
using namespace std;

class Pessoa
{
private:
	string nome;
	int idade;

public:
	string& getNome()
	{
		return nome;
	}

	int getIdade()
	{
		return idade;
	}

	void setNome(string& nome)
	{
		this->nome = nome;
	}

	void setIdade(int idade)
	{
		this->idade = idade;
	}

	// sobrecarga do operador de inserção de dados <<
	// ostream = output stream
	friend ostream& operator<<(ostream& os, const Pessoa& p)
	{
		// escrever cada membro
		os << "\n" << p.nome << "\n";
		os << p.idade;
		return os;
	}

	// sobrecarga do operador de extração de dados >>
	// istream = input stream
	friend istream& operator>>(istream& is, Pessoa& p)
	{
		// ler cada membro
		is >> p.nome >> p.idade;
		return is;
	}
};

char menu()
{
	char resp;

	cout << "Digite 1 para inserir pessoas\n";
	cout << "Digite 2 para listar as pessoas\n";
	cout << "Digite 0 para sair\n";
	cout << "Opcao: ";
	cin >> resp;
	return resp;
}

int main(int argc, char *argv[])
{
	char resp;

	while(true)
	{
		resp = menu();
		if(resp == '1')
		{
			Pessoa pessoa;
			string nome;
			int idade;

			// app = append (adiciona ao final do arquivo)
			ofstream ofs("arquivo.txt", fstream::app);

			cout << "\nDigite o nome da pessoa: ";
			cin >> nome;
			cout << "Digite a idade da pessoa: ";
			cin >> idade;
			cout << endl;

			// seta o nome e a idade
			pessoa.setNome(nome);
			pessoa.setIdade(idade);

			ofs << pessoa;

			ofs.close();
		}
		else if(resp == '2')
		{
			Pessoa p;
			ifstream ifs("arquivo.txt");

			cout << "\nListando pessoas...\n\n";

			// verifca se o arquivo existe e se é possível ler
			if(ifs.good())
			{
				// eof = end of file
				// enquanto NÃO chegar ao final do arquivo
				while(!ifs.eof())
				{
					ifs >> p; // faz a extração dos dados

					// mostrar os dados
					cout << "Nome: " << p.getNome() << "\n";
					cout << "Idade: " << p.getIdade() << "\n\n";
				}
				ifs.close();
			}
			else
			{
				cout << "Falha ao abrir o arquivo!\n\n";
			}
		}
		else if(resp == '0')
		{
			cout << "\nBye! Visite: www.geeksbr.com ;-)\n";
			break;
		}
		else
		{
			cout << "\nOpcao invalida. Tente novamente...\n\n";
		}
	}

	return 0;
}
