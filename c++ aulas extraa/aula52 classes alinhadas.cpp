#include <iostream>
using namespace std;

class A {
public:
    class B {
        private:
            int v;
        public:
            B(int var) {
                this->v = var;
            }
            int getVar() {
                return v;
            }
    };
};

int main(int argc, char *argv[])
{
	A::B obj(10);

	cout << obj.getVar() << endl;

	return 0;
}
