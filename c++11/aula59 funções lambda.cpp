#include <iostream>
#include <vector>

using namespace std;

int main(){
//______________________________________________________________
    //funçao lambda                //tipo do retorno
    auto maior= [](int n1, int n2)->int{
        //if/else normal
        /*if (n1>n2){
            return n1;
        }
        else{
            return n2;
        }*/
        //if ternario
        return(n1>n2) ?n1 :n2;
    };

    cout << maior (2,6) << endl;
    cout << maior (10,5) << endl;
//______________________________________________________________
    cout << endl;
//______________________________________________________________
    auto maiorV= [](vector<int>vec)->int{
        int valor=0;
        for (int indice:vec){
            valor=(valor>indice) ?valor :indice;
        }
        return valor;
    };
    cout << maiorV({13,1351,111,18,894,497,4}) << "\n\n";
//______________________________________________________________
    //captura de variavis
    int x1, x2, x3;     x1=10; x2=20; x3=30;
        //soma=[=] captura todas variaveis
    auto soma=[x1, x2, x3]()->int{
        return x1+x2+x3;
    };
    cout << soma() << "\n";
//______________________________________________________________
    cout << endl;
    system("pause");
    return 0;
}
