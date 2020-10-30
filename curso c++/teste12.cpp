#include <iostream>
using namespace std;
int main(){

    int matriz[3][4];
    // 3 linhas 4 colunas

    int linha,coluna;
    //indices

    // prencimento automatico das matriz
     for(linha=0; linha<3; linha++){
        for(coluna=0; coluna<4; coluna++){

             matriz[linha][coluna]=linha;
             /*cin >> matriz[linha][coluna];
            pegar do teclado */
        }
     }

    /*matriz[0][0]=1;
    matriz[0][1]=1;
    matriz[0][2]=1;
    matriz[0][3]=1;
    matriz[1][0]=20;
    matriz[1][1]=20;
    matriz[1][2]=20;
    matriz[1][3]=20;
    matriz[2][0]=3;
    matriz[2][1]=3;
    matriz[2][2]=3;
    matriz[2][3]=3;*/

    // for para linha
    for(linha=0; linha<3; linha++){
        //for para coluna
        for(coluna=0; coluna<4; coluna++){

            cout << matriz[linha][coluna] << "  ";

        }
        cout << "\n";
    }




    system("pause");
    return 0;
}
