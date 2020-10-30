#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main(){
//-----------------------------------------------------------
    pair<int,string> par;
        par.first=10;
        par.second="HR";
    cout << "Par: " << par.first << " - " << par.second << "\n\n";

    pair<int,string> par1(10,"HR");
    cout << "Par1: " << par1.first << " - " << par1.second << "\n\n";
//-----------------------------------------------------------
    const int tam=3;
    pair <int,string> par2[tam];//vetor
        par2[0].first=100;
        par2[0].second="HR1";
        par2[1].first=200;
        par2[1].second="HR2";
        par2[2].first=300;
        par2[2].second="HR3";
    cout << "Par2: " << par2[0].first << " - " << par2[0].second << endl;
    cout << "Par2: " << par2[1].first << " - " << par2[1].second << endl;
    cout << "Par2: " << par2[2].first << " - " << par2[2].second << "\n\n";

    //const int tam=3;
    pair <int,string> par3[tam];//vetor
        par3[0]=make_pair(100,"HR1");
        par3[1]=make_pair(200,"HR2");
        par3[2]=make_pair(300,"HR3");
            for (int i=0;i<tam;i++ ){
                cout << "Par3: " << par3[i].first << " - " << par3[i].second << endl;
            }
//-----------------------------------------------------------
    cout << endl;
//-----------------------------------------------------------
    //pair dentro de pair
    //const int tam=3;
    pair <int,pair <string,double>> parp[tam];//vetor
        parp[0]=make_pair(100,make_pair("mouse",45.50));
        parp[1]=make_pair(200,make_pair("mousepad",10.50));
        parp[2]=make_pair(300,make_pair("teclado mecanico",345.50));
            for (int i=0;i<tam;i++ ){
                cout << "ParP: " << parp[i].first << " - " << parp[i].second.first << " - " << parp[i].second.second <<  endl;
            }
//-----------------------------------------------------------
    cout << endl;
//-----------------------------------------------------------
    vector <pair <int,string>> prod;//vector
        prod.push_back(make_pair(100,"mouse"));
        prod.push_back(make_pair(200,"mousepad"));
        prod.push_back(make_pair(300,"teclado mecanico"));
            for(auto i:prod){
                cout << "Vector: " << i.first << " - " << i.second << endl;
            }
//-----------------------------------------------------------
    cout << endl;
    system ("pause");
	return 0;
}
