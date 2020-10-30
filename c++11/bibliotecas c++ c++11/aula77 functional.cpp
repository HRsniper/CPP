#include <iostream>
#include <functional>

using namespace std;

int soma(int n1, int n2){//bind
    return n1+n2;
}

class classe{
public:
    int num;
    classe(int n):num(n){};
    int dobro(){
        return num*2;
    }
};

int main(){
//----------------------------------------
    auto n1{10};
    auto n2{5};

    auto s1=bind(soma,n1,n2);
        cout << s1() << endl;
//----------------------------------------
    auto n3=20;
    auto n4=cref(n3);
        cout << n4 << "\n";
//----------------------------------------
    classe n5{100};
    classe n6{300};

    auto dobro2=mem_fn(&classe::dobro);
        cout << dobro2(n5) << endl;

    system("pause");
    return 0;
}
