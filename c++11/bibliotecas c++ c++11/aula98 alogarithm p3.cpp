#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
//algorithm trabalha com coleções

    //replace_if - substitui valores da coleçao que atenda a determinada condiçao
    cout << "replace_if" << endl;
    vector<int>vt1{1,2,3,4,5,6,7,8,9,0};
    replace_if(vt1.begin(),vt1.end(),[](int i){return i<5;},10);
    for(auto i:vt1){
        cout << i << " ";
    }

    cout << "\n\n";

    //fill - prenche uma coleçao com um vlaor especifico
    cout << "fill" << endl;
    vector<int>vt2(10);
    fill(vt2.begin(),vt2.end(),10);
    for(auto i:vt2){
        cout << i << " ";
    }

    cout << "\n\n";

    //remove - remove um valore indentificado da coleçao // para diminur quando vi removendo cria-se uma rotina , se nao ela remove mas imprime os elementos de novo
    cout << "remove" << endl;
    vector<double> vt3{1,2,1,3,4,5,6,1,7,8,9};
    int qtde=count(vt3.begin(),vt3.end(),1);

    remove(vt3.begin(),vt3.end(),1);
    vt3.resize(vt3.size() -qtde);
    vt3.shrink_to_fit();
    for(auto i:vt3){
        cout << i << " ";
    }

    cout << "\n\n";

    //unique - remove elementos duplicados consecutivos na colecao
    cout << "unique" << "\n";
    vector<int> vt4{0,1,2,3,4,5,5,5,6,5,7,8,9};
    vector<int>::iterator it;
    it=unique(vt4.begin(),vt4.end());
    vt4.resize(distance(vt4.begin(),it));
    for(auto i:vt4){
        cout << i << " ";
    }

    cout << "\n\n";

    //reverse - inverte a ordem dos elementos
    cout << "reverse" << "\n";
    vector<int> vt5{0,1,2,3,4,5,6,7,8,9};
    reverse(vt5.begin(),vt5.end());
    for(auto i:vt5){
        cout << i << " ";
    }

    cout << "\n\n";

    //sort - ordena os elementos da coleçao
    cout << "sort" << "\n";
    vector<int> vt6{9,8,6,7,4,5,1,2,3};
    sort(vt6.begin(),vt6.end());
    for(auto i:vt6){
        cout << i << " ";
    }

    cout << "\n\n";

    //is_sort - verifica se a colecao esta ordenada
    cout << "is_sort" << "\n";
    vector<int> vt7{9,8,6,7,4,5,1,2,3};
    if(is_sorted(vt7.begin(),vt7.end())){
        cout << "ordenada";
    }else{
        cout << "coleçoes nao ordenada";
    }

    cout << "\n\n";

    //merge - mescla duas coleçoes e armazena em um terceira container
    cout << "merge" << endl;
    vector<int> vt8{0,1,2,3,4};
    vector<int> vt9{5,6,7,8,9};
    vector<int> vt10(10);

    merge(vt8.begin(),vt8.end(),vt9.begin(),vt9.end(),vt10.begin());
    for(auto i:vt10){
        cout << i << " ";
    }

    cout << "\n\n";

    //set_union - uni duas coleçoes
    cout << "set_union" << endl;
    vector<int> vt11{0,1,2,3,4};
    vector<int> vt12{5,6,7,8,9};
    vector<int> vt13(10);

    set_union(vt11.begin(),vt11.end(),vt12.begin(),vt12.end(),vt13.begin());
    for(auto i:vt13){
        cout << i << " ";
    }

    cout << "\n\n";

    //set_intersection - interseçao de duas coleçoes // elementos comuns
    cout << "set_intersection" << endl;
    vector<int> vt14{0,1,5,2,3,4};
    vector<int> vt15{5,4,6,7,8,9};
    vector<int> vt16(7);

    set_intersection(vt14.begin(),vt14.end(),vt15.begin(),vt15.end(),vt16.begin());
    for(auto i:vt16){
        cout << i << " ";
    }

    cout << "\n\n";

    //set_diference - retorna a diferenca da primeira colecao a segunda
    cout << "set_diference" << endl;
    vector<int> vt17{5,6,2,3,4};
    vector<int> vt18{5,6,7,3,4};
    vector<int> vt19(10);

    set_difference(vt17.begin(),vt17.end(),vt18.begin(),vt18.end(),vt19.begin());
    for(auto i:vt19){
        cout << i << " ";
    }

    cout << "\n\n";

    //min e max e minmax nao funcionam com colecao //somente para preparacao

    cout << "min e max" << endl;
    int n1{10},n2{20};
    cout << "min: " << min(n1,n2) << endl;
    cout << "max: " << max(n1,n2) << endl;

    cout << "minmax" << endl;
    int n3=11,n4=12,n5=13,n6=14;
    auto res=minmax({n3,n4,n5,n6});
    cout << "min: " << res.first << " max: " << res.second << "\n\n";

    //min_element , max_element , minmax_element  //ela trabalha com coleçoes  
    cout << "min_element , max_element , minmax_element" << endl;
    vector<int>vt20{5,89,8,48,45,1,16,31};
    vector<int>::iterator it1,it2;

    it1=min_element(vt20.begin(),vt20.end());
    it2=max_element(vt20.begin(),vt20.end());
    auto res2=minmax_element(vt20.begin(),vt20.end());

    cout << "min: " << *it1 << " max: " << *it2 << "\n";
    cout << "min: " << *res2.first << " max: " << *res2.second << "\n\n";

	system("pause");
	return 0;
}
