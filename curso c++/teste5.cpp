#include <iostream>

using namespace std;
int main (){

    int n1=5;
    cout << "valor inicial: " << n1 << endl;
    cout << "\n\n";
inicial:
    cout << "digita o valor: ";
    cin >> n1;

    if( (n1>=5 && n1>=5 ) || (n1>6 && n1<=9 ) ){
        cout << "valor maior de 5 verdadeiro\n";
    }else{
        cout << "valor menor a 5\n";
    }
goto inicial;


    return 0 ;

}
