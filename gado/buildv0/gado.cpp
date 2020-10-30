#include <iostream>
using namespace std;
int main(){

    // int matriz[1][8];
    string matriz[1][8];
    int l,c;
    int n;
    int n1,n2,n3,n4,n5,n6,n7,n8;

    string m0="[1] M 0-12 |";
    string f0="[2] F 0-12 |";
    string m1="[3] M 13-24 |";
    string f1="[4] M 13-24 |";
    string m2="[5] M 25-32 |";
    string f2="[6] M 25-32 |";
    string m3="[7] M 36+ |";
    string f3="[8] F 36+ |\n";

    /* matriz[0][0]=0;
    matriz[0][1]=0;
    matriz[0][2]=1;
    matriz[0][3]=1;
    matriz[0][4]=2;
    matriz[0][5]=2;
    matriz[0][6]=3;
    matriz[0][7]=3; */

    matriz[0][0]=m0;
    matriz[0][1]=f0;
    matriz[0][2]=m1;
    matriz[0][3]=f1;
    matriz[0][4]=m2;
    matriz[0][5]=f2;
    matriz[0][6]=m3;
    matriz[0][7]=f3;

    for(l=0; l<=0; l++){
        for(c=0; c<=7; c++){
            cout << matriz[l][c] << "";
        }
    }

    cout << "digite o numero de cabecas de gado: " ;
    cin >> n;
    switch(n){
        case 1:
            cout << "digite machos 0-12: ";
            cin >> n1;
            //cout << n1 << " wgwg" ;

        case 2:
            cout << "digite femeas 0-12: " ;
            cin >> n2;

        case 3:
            cout << "digite machos 13-24: " ;
            cin >> n3;

        case 4:
            cout << "digite femeas 13-24: " ;
            cin >> n4;

        case 5:
            cout << "digite femeas 25-32: " ;
            cin >> n5;

        case 6:
            cout << "digite femeas 25-32: " ;
            cin >> n6;

        case 7:
            cout << "digite machos 36+: " ;
            cin >> n7;

        case 8:
            cout << "digite femeas 36+: " ;
            cin >> n8;


        }

    for(l=0; l<=0; l++){
        for(c=0; c<=7; c++){
            cout << matriz[l][c] << "";
        }
    }
    cout << "     " << n1 << "     " << "     " << n2 << "     " << "     " << n3 << "     " << "     " << n4 << "     " << "     " << n5 << "     " << "     " << n6 << "     "<< "     " << n7 << "     " << "     " << n8 << "     ";


    return 0;
}
