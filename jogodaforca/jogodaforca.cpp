#include <iostream>
#include <cstdlib>

using namespace std;
int main (){

    char palavra[30],secreta[30],letra[1];// secreta[30] e palavra que vai fica escondida /// e palavra[30] vai sendo revelado com as letras digitadas
    int tamanho,indice,chances,acertos;
    bool acertou;

    chances=5;
    tamanho=0;// tamanho da palavra escrita
    indice=0;
    acertou=false;
    acertos=0;

    cout << "digite a palavra secreta: " ;
    cin >> secreta;
    system("cls");

    while (secreta[indice] != '\0'){
    // \0 flag para terminar a string do foi digitado terminou
        indice++;
        tamanho++;
    }

    // for para parte visual para coloca * na palavra escrita
    for (indice=0; indice<30; indice++){
        palavra[indice]='*';
    }

    // informaçoes do jogo
    // loop principal
    while ((chances>0) && (acertos<tamanho)){
        cout << "chances restantes: " << chances << "\n" ;
        cout << "palavra secreta: ";
        for (indice=0; indice<tamanho; indice++){
            cout << palavra[indice];
            // palavra vai ser mostrada ****
        }

        // colher a letra digitada pelo usuario
        cout << "\n digita uma letra: " ;
        cin >> letra[0];

        for(indice=0; indice<tamanho; indice++){
            if (secreta[indice]==letra[0]){
                acertou=true;
                palavra[indice]=secreta[indice];
                // vai pegar secreta para ser revelada no cout<<palavra[indice] no loop principal
                acertos++;
            }
        }
        if(!acertou){
            chances--;
        }
        acertou=false;
        system("cls");
    }

    // vitoria ou derrota
    if(acertos==tamanho){
        cout << "voce ganhou\n";
    }else{
        cout << "voce perdeu\n";
    }

    system("pause");
    return 0;
}
