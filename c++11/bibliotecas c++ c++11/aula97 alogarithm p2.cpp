#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
//algorithm trabalha com coleções

    vector<int>vt1{1,2,3,4,5,6,7,8,9,0};
    vector<int>vt2{1,2,3,4,5,6,7,8,9,0};
    vector<int>vt3{0,1,2,3,4,5,6,7,8,9};
    vector<int>vt4{4,5,6};
    vector<int>vt5{10,11,12};
    vector<int>::iterator it;

    //equal - verifica se os elementos de uma coleçao sao iguais a outra //sendo na mesma ordem
    cout << "equal" << endl;
    if (equal(vt1.begin(),vt1.end(),vt2.begin())){
        cout << "colecoes iguais" << endl;
    }
    else{
        cout << "colecoes diferentes" << endl;
    }

    cout << "\n";

    //search - pesquisa se uma coleçao esta em outra //sendo na mesma ordem
    cout << "search" << endl;
    it=search(vt1.begin(),vt1.end(),vt4.begin(),vt4.end());
    if (it!=vt1.end()){
        cout << "colecao encontrada na posicao: " << it-vt1.begin() << endl;
    }
    else{
        cout << "colecao nao encontrada " << endl;
    }

    cout << "\n";

    //copy - copia elementos de uma colecao  para outra,mas nao cria novos posiçoes ele substitui
    cout << "copy" << endl;
    copy(vt5.begin(),vt5.end(),vt3.begin());
    for(auto i:vt3){
        cout << i << " ";
    }

    cout << "\n\n";

    //copy - copia elementos de uma colecao para outra que atendam uma condicao, mas nao cria novos posiçoes ele substitui
    cout << "copy_if" << endl;
    copy_if(vt5.begin(),vt5.end(),vt1.begin(),[](int i){return (i%2)==0;});//copia somente pares
    for(auto i:vt1){
        cout << i << " ";
    }

    cout << "\n\n";

    //move - move elementos de uma coleçao para outra
    cout << "move" << endl;
    vt4=move(vt1);
    for (auto &&i : vt4){
        cout << i << " ";
    }

    cout << "\n";

    for (auto &&i : vt1){//vt1 esta vazia porque moveu para vt4
        cout << i << " ";
    }

    cout << "\n\n";

    //swap - trocar elementos das coleçoes
    swap(vt2,vt1);

    //transform - aplica uma funçao que altera os valores de uma coleçao
    cout << "transform" << endl;
    transform(vt5.begin(),vt5.end(),vt5.begin(),[](int i){return i*100;});
    for(auto i:vt5){
        cout << i << " ";
    }

    cout << "\n\n";

    //replace - substitui um desterminado valor de uma coleçao por outro
    replace(vt5.begin(),vt5.end(),1000,500);//susbstituindo 5 por 500
    for(auto i:vt5){
        cout << i << " ";
    }

    cout << "\n";

	system("pause");
	return 0;
}
