#include <iostream>

// using namespace std;

void troca(int v[], int i, int s) {
    int x = v[i];
    v[i] = v[s];
    v[s] = x;
}

// void permutacao(int *V, int I, int S) {
void permutacao(int V[], int I, int S) {
    if (I == S) {
        for (int index=0; index<=S; index++) {
        std::cout << V[index] << " ";
        }
    // std::cout << std::endl;
    std::cout << "\n";
    }
    else {
        for (int index=I; index<=S; index++) {
            troca(V,I, index);
            permutacao(V,I+1, S);
            troca(V,I, index); //backtracking
        }
    }
}
int main() {

    int vetor[] = {1,2,3,4};
    int tamanho = sizeof(vetor) / sizeof(int);

    permutacao(vetor, 0, tamanho-1);

    system("pause");
    return 0;
}

