#include <iostream>
#include <vector>

using namespace std;

int main(){
    //vetor
    int vetorX[10]{11,22,33,44,55,66,77,88,99,111};
    //vector
    vector<int>vectorY{111,222,333,444,555,666,777,888,999,1111};
    //for normal
    for (int i=0; i<10; i++){
        cout << vetorX[i] << "  ";
        //cout << vectorY[i] << "  "; mesmo coisa com vector
    }

    cout << endl;


    //for range declaration
            //i:vetorX
    for (int i:vectorY){
        cout << i << "  ";
    }


    cout << endl;
    system("pause");
    return 0;
}
