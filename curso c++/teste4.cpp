#include <iostream>
using namespace std;
int main(){
    int invert=5;

    cout << "valor de invert: " << invert << endl;

    cout << "valor de invert somente nessa linha: " << -invert << endl;
// codico curto invert=-invert
    invert= invert * -1;
    cout << "valor de invert permanente: " << invert << endl;
    
    invert=-invert;
    cout << "valor de invert +: " << invert << endl;
    
    system("pause");
    return 0;
}