#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> vec{0,1,2,3,4,5};
    //for_each( .begin(), .end(),[]( ){ } );

    for_each(vec.begin(),vec.end(),[](int num){
        cout << num << endl;
    });

    cout << endl;

    for_each(vec.begin(),vec.end(),[](int num){
        num+=10;
        cout << num << endl;
    });

    cout << endl;
    system("pause");
	return 0;
}
