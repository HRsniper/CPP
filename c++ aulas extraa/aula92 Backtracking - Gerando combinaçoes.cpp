#include <iostream>

// using namespace std;
void combinacao(int _v[], int _bool[], int _indice, int _tamanho);

int main() {

    int vetor[] = {1,2,3,4};
    int tamanho = sizeof(vetor) / sizeof(int);
    int vBool[tamanho];

    for(size_t i = 0; i < tamanho; i++) {
        vBool[i] = false;
    }
    
    combinacao(vetor, vBool, 0, tamanho);
    
    system("pause");
    return 0;
}

void combinacao(int _v[], int _bool[], int _indice, int _tamanho) {
    if(_indice == _tamanho) {
        for(size_t i = 0; i < _tamanho; i++) {
            if(_bool[i] == 1) {
                std::cout << _v[i] << " ";
            }
        }
        std::cout << "\n";
    }
    else {
        _bool[_indice] = true;
        combinacao(_v, _bool, _indice+1, _tamanho);
        _bool[_indice] = false;
        combinacao(_v, _bool, _indice+1, _tamanho);
    }
}