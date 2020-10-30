#include <iostream>
#include <locale>
#include <cstdio>

// template <typename T>
float Convercao(float n) {
    return n*60*60;
}

int main() {

    setlocale(LC_ALL,"portuguese");

    system("title Desligar PC");


    float n;
    //got:

    std::cout << "Digite: ";
        std::cin >> n;

    if (n <=6) {
        std::cout << "Tempo Em Segundos: " << Convercao(n) << std::endl;

        // int convertido = n*60*60;
        // std::printf("numero %d \n", convertido);
    }
    if (Convercao(n) == 3600) {
        std::cout << "1hora";
    }
    // else {
    //     std::cout << "Invalido \n";
    // }

    //goto got;
    //60 segundos x 60 minutos = 3600 segundos e igual a 1 hora


    system("pause");
    return 0;
}
