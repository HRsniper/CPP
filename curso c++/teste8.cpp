#include <iostream>
using namespace std;
int main(){
     int n1=0;

     while (n1<10)
     {
         cout << "valor: " << n1 << "\n";
        // sem o n++ fica num �loop infinito
         n1++;
     }

     while (n1++<20)
     {
         cout << "valor2: " << n1 << "\n";

         if(n1== 10){
            break;
         }
     }


    system("pause");
    return 0;

}
