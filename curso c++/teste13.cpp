#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
//argv[0] nome so programa
int main(int argc , char *argv[]){

    if (argc > 1){
        if (!strcmp (argv[1] , "chuva" )){
            cout << "esta chuvendo\n";
        }
        else if (!strcmp (argv[1] , "sol" )){
            cout << "o sol esta ranchado\n";
        }
        else{
            cout << "ficar na cama dormindo\n";
        }
    }

    cout << "esta dicidido\n\n";

    system("pause");
    return 0;
}
