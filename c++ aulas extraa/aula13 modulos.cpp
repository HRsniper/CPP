#include <iostream>
#include "aula13 modulos_math.h"

using namespace std;

int main(int argc, char const *argv[]) {

    int num{5};

    cout << "fatorial de " << num << ": " << fatorial(5) << endl;
    cout << "quadrado com lado " << num << ": " << area_quadrado(5) << endl;
    cout << "area retangulo: " << area_retangulo(5,5) << endl;

    system("pause");
    return 0;
}
