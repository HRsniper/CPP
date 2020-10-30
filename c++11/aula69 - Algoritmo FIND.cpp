#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <utility>
#include <string>

using namespace std;

int main(){
//----------------------------------------------------
    int arrayvetor[]={6,1,7,9,8,4,5};//vetor
    int *p;
    size_t tam= sizeof arrayvetor/4;
    p=find(arrayvetor,arrayvetor+tam,7);
        if(p!=arrayvetor+tam){
            cout << "N. encontrado: " << *p << endl;
        }else{
            cout << "N. nao encontrado" << "\n";
        }
//----------------------------------------------------
cout << endl;
//----------------------------------------------------
    vector<int> vec={6,1,7,9,8,4,5};//vector
    auto it=find(vec.begin(),vec.end(),8);// iterator= it
        if(it!=vec.end()){
            cout << "N. encontrado: " << *it << endl;
        }else{
            cout << "N. nao encontrado" << "\n";
        }
//----------------------------------------------------
cout << endl;
//----------------------------------------------------
    list<int> lis={6,1,7,9,8,4,5};//list
    auto itl=find(lis.begin(),lis.end(),5);// iterator= itl
        if(itl!=lis.end()){
            cout << "N. encontrado: " << *itl << endl;
        }else{
            cout << "N. nao encontrado" << "\n";
        }
//----------------------------------------------------
cout << endl;
//----------------------------------------------------
    //inserir numeros no vector sem repitir
    vector<int> vec1;//vector
    vector<int>::iterator itv;
    int num, qtde=10;

    while(qtde>0){//loop para verificar enquanto qtde for maior que 0 o loop vi ser executado
        cout << "digite um N.: ";
        cin >> num;

        itv=find(vec1.begin(),vec1.end(),num);
        if(itv!=vec1.end()){
            cout << "N. ja existe no vector " << endl;
        }else{
            vec1.push_back(num);//se noa for repitido ele vai colocar no vector
            qtde--;//vai tirand a quantidade ate ser igual a 0 o loop para
        }
    }
//----------------------------------------------------
cout << endl;
//----------------------------------------------------
    //map com metdo find de map
    map<int,string>mapa;
    map<int,string>::iterator itmap;
    mapa.insert(pair<int,string>(10,"Cajado"));
    mapa.insert(pair<int,string>(20,"machado"));
    mapa.insert(pair<int,string>(30,"arco"));
    mapa.insert(pair<int,string>(40,"sword")); //USANDO INSERT DECIMA

    itmap=mapa.find(30);
        if(itmap==mapa.end()){
            cout << "item nao encontrado" << endl;
        }else{
            cout << "item emcontrado" << endl;
            cout << "chave: " << itmap->first << " - " << "valor: " << itmap->second << "\n";
        }
//----------------------------------------------------
cout << endl;
//----------------------------------------------------
    //find com string
    string texto="hhnrhi nhrnh n HRsniper ohnrn rro hn nrt";
    size_t enc=texto.find ("HRsniper");
    //size_t armazena tamanho
     if(enc!=string::npos){
            cout << "encontrado: " << enc << endl;
        }else{
            cout << "nao emcontrado" << endl;
        }
//----------------------------------------------------

    cout << endl;
    system("pause");
	return 0;
}
