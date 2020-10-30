#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
//algorithm trabalha com coleções

    vector<int>vt{1,3,48,64,8,4,89,4,7,-2,2,2,15};

    for(auto i:vt){
        cout<< i << "  ";
    }

    cout << endl;

    //all_of - retorna true se o teste retornar true com todas elementos da coleçao
    if(all_of(vt.begin(),vt.end(),[](int o){return o<50;})){
        cout << "todos sao menores que 50" << "\n\n";
    }else{
        cout << "existe 1 ou + elementos maiores que 50"  << "\n\n";
    }

    //any_of - retorna true se o teste retornar true em pelos 1 elementos da coleçao
    if(any_of(vt.begin(),vt.end(),[](int p){return p<15;})){
        cout << "todos sao menores que 15" << "\n\n";
    }else{
        cout << "existe 1 ou + elementos maiores que 15" << "\n\n";
    }

    //none_of - retorna true se o teste retornar true em pelos 1 elementos da coleçao
    if(none_of(vt.begin(),vt.end(),[](int q){return q<0;})){
        cout << "todos positivos" << "\n\n";
    }else{
        cout << "todos negativos" << "\n\n";
    }


    //for each - aplica uma funçao a todos elementos da colecao
    cout << "drobo: ";

    for_each(vt.begin(),vt.end(),[](int l){
       cout << l*2 << " "; 
    });

    cout << "\n\n";

    //find - procura um elemento e retorna um itetator com o resultado
    auto it =find(vt.begin(),vt.end(),15);
    cout << *it << "\n\n";

    //find_if - procura 1 elemento que atenda a uma derminada condiçao e retorna um itetator com o resultado
    auto it2 =find_if(vt.begin(),vt.end(),[](int w){return ((w%2)==1);});
    cout << "1° impar" << *it2 << "\n\n";

    //find_if_ not - procura 1 elemento que NÃO atenda a uma derminada condiçao e retorna um itetator com o resultado
    auto it3 =find_if_not(vt.begin(),vt.end(),[](int e){return ((e%2)==1);});
    cout << "1° par" << *it3 << "\n\n";
    
    //count - quantidade de um determinado elemento
    cout << "quantidade de numeral 2: " << count(vt.begin(),vt.end(),2) << "\n\n";

    //count_if - quantidade de um determinado elemento,que atenda a condiçao
    cout << "quantidade de pares: " << count_if(vt.begin(),vt.end(),[](int r){return ((r%2)==2);}) << "\n\n";














	system("pause");
	return 0;
}
