#include <iostream>
#include <cctype>

using namespace std;

int main(){
		//container de string
	char str[]=">> 1hr-sniper <<";
	int i=0;
	while (str[i]){
		if (isdigit(str[i])){
			cout << "cara.: " << str[i] << " alfabetico " << endl;
		}
		else{
			cout << "cara.: " << str[i] << " nao alfabetico " << endl;
		}
		i++;
		//putchar(toupper(H));
	}


	system("pause");
	return 0;
}
/*
isalnum > verifica se e alfanumericos   quase igual isalpha
isalpha > verifica se e alfabetico      quase igual isalnum
isspace > verifica se e espaco
iscntrl > verifica se e controle	/n
isdigit > verifica se e digito numerico
islower > verifica se e minusculo
isprint > verifica se e char imprimivel /n
ispunct > verifica se e pontuaçao . , ?
isupper > verifica se e maiusculo
isxdigit > verifica se e hexdecimal
tolower > converte todo para minusculo
toupper > converte todo para maiusculo
*/
