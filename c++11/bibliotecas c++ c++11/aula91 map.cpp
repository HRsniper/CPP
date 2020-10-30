#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main (){
//----------------------------------------------------------
    //map<tipo,tipo2>nome;
        //<chave,valor>
    map<int,string>mp;
    map<int,string>::iterator it;

    mp[10]="Branco";
    mp[20]="Preto";
    mp[30]="Vermelho";
    mp[40]="Verde";
    mp[50]="Azul";

        for (auto i:mp){
            cout << i.first << " - " << i.second << endl;
        }
    cout << endl;
        for (it=mp.begin();it!=mp.end();it++){
            cout << it->first << " - " << it->second << endl;
        }

//----------------------------------------------------------
cout << endl;
//----------------------------------------------------------
    cout << mp.size() << endl;
    cout << mp.max_size() << endl;
//----------------------------------------------------------
cout << endl;
//----------------------------------------------------------
    cout << "Chave 10: " << mp[10] << " - " << "Chave 50: " << mp[50] << "\n";
    cout << "Chave 20: " << mp.at(20) << " - " << "Chave 40: " << mp.at(40) << "\n";
//----------------------------------------------------------
cout << endl;
//----------------------------------------------------------
    map<int,string>mp2;
    map<int,string>mp3;

    mp3.insert(pair<int,string>(11,"Laranja"));
    mp3.insert(pair<int,string>(22,"Manga"));
    mp3.insert(pair<int,string>(33,"Pokan"));
    mp3.insert(pair<int,string>(44,"Limao"));
    mp3.insert(pair<int,string>(55,"Banana"));

    it=mp3.find(55);
    mp3.erase(it);

        for (auto i:mp3){
            cout << i.first << " - " << i.second << endl;
        }

    mp3.swap(mp2);

    mp2.emplace_hint(mp2.end(),60,"Banana Maca");
        for (auto i:mp2){
            cout << i.first << " - " << i.second << endl;
        }

    cout << endl;

    if (mp3.empty()){
        cout << "Map 3 esta vazio" << "\n";
    }
    else{
        cout << "Map 3 contem valores" << "\n";
    }

    mp2.clear();

        if (mp2.empty()){
        cout << "Map 2 esta vazio" << "\n";
    }
    else{
        cout << "Map 2 contem valores" << "\n";
    }
//----------------------------------------------------------
    it=mp.find(1);
        cout << it->first << " - " << it->second << endl;
//----------------------------------------------------------
    if(mp.count(2)!=0){
        cout << "Chave 2 esta no Map" << "\n";
    }
//----------------------------------------------------------
    it=mp.lower_bound(3);//.upper_bound
    cout << "Chave 2 esta no Map" << "\n\n";

    mp.erase(it);
        for (auto i:mp){
            cout << i.first << " - " << i.second << endl;
        }
//----------------------------------------------------------
//----------------------------------------------------------

//----------------------------------------------------------
//----------------------------------------------------------

    cout << endl;
    system ("pause");
    return 0;
}
