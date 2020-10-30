#include <iostream>
using namespace std;
int main(){
    int n1,n2,n3,n4;

    n1= 5;
    n2= 10;
    n3= 15;
    n4= 20;

    cout << "valor da variavel n1: " << n1 << endl;
    cout << "valor da variavel n2: " << n2 << endl;
    cout << "valor da variavel n3: " << n3 << endl;
    cout << "valor da variavel n4: " << n4 << endl << endl;

    n1=n1+1;
    cout << "valor depois do n1+1 incremento: " << n1 << endl;
    //codico curto
    n1+=1;
    cout << "valor depois do ll+ll incremento: " << n1 << endl;

    n2=n2+1;
    cout << "valor depois do n2+1 incremento: " << n2 << endl;
    
    n3/=5;
    cout << "valor depois do n3/5 decremento: " << n3 << endl; 

    n4-=19;
    cout << "valor depois do n4-19 decremento: " << n4 << endl; 

    n4/=n1;
    cout << "valor depois do n4/n1: " << n4 << endl;
    
    cout << "valor depois do n1-- decremento: " << n1-- << endl; 
    cout << "valor depois do decremento depois do -- : " << n1 << endl; 

    system ("pause");
    return 0;

}
