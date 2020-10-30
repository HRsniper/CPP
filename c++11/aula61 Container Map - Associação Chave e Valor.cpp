#include <iostream>
#include <map>

using namespace std;

int main(){
//---------------------------------------------------------------
	//chave,valor
	map<int,string>itens;
	//chave   //valor
	itens[0]="Espada";
	itens[1]="Escudo";
	itens[2]="Bag";
	itens[3]="Gold";
/*      //for normal
		for (int i=0;i<4;i++){
			cout << itens[i] << " - ";//imprimir o valor
		}
*/
/*      //for com iterator
        //auto= map<int,string>::iterator
		for (auto it=itens.begin();it!=itens.end();it++){
			cout << it->first << " - ";//imprimir chave
			cout << it->second << " - ";//imprimir valor
		}
*/
        //for range declaration
        for (auto it:itens){
			cout << it.first << " - " << it.second << "\n";
			//cout << it.first << " - ";//imprimir chave
			//cout << it.second << " - ";//imprimir valor
		}
//---------------------------------------------------------------
    cout << endl;
//---------------------------------------------------------------
	 //chave,valor
	map<int,string>itens2;
                                //chave //valor
	itens2.insert(pair<int,string>(10,"Cajado"));
	itens2.insert(pair<int,string>(20,"Maca"));
	itens2.insert(pair<int,string>(30,"Orbe Magica"));
	itens2.insert(pair<int,string>(40,"Machado"));

	itens2.erase(20);//apaga de acordo com a chave
	//itens2.erase(itens2.begin(),itens2.find(30));//apaga do começo ate 30 ou em uma faixa itens2.find(20),itens2.find(40),
	//itens2.clear();//apaga tudo no map

        //for range declaration
        for (auto it:itens2){
			cout << it.first << " - " << it.second << "\n";
		}
//---------------------------------------------------------------
    cout << endl;
//---------------------------------------------------------------
    //find mais facil com iterator
    map<int,string>::iterator itmap;
    //itens2.insert(pair<int,string>(10,"Cajado")); //USANDO INSERT DECIMA
    itmap=itens2.find(30);
        if(itmap==itens2.end()){
            cout << "item nao encontrado" << endl;
        }else{
            cout << "item emcontrado" << endl;
            cout << "chave: " << itmap->first << " - " << "valor: " << itmap->second << "\n";
        }
//---------------------------------------------------------------

	cout << endl;
	system("pause");
	return 0;
}
