#include <iostream>
#include <utility>

using namespace std;

int main(){

	pair<int,int>p1;
	pair<string,int>p2;

	p1=make_pair(1,2);
	p2=make_pair("fwfwf",1561);

	cout << p1.first << " - " << p1.second << "\n";
	cout << p1.first << " - " << p1.second << endl;

	int a=1,b=5;
	swap(a,b);
	cout << a << " - " << b << endl;


	system("pause");
	return 0;
}
