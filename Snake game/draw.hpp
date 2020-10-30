#ifndef DRAW_HPP_INCLUDED
#define DRAW_HPP_INCLUDED

#include <cstdlib>

void Draw() {
    system("cls"); //limpar a scream vai fica piscando a tela para o proximo frame

    // top
    for (size_t i = 0; i < width + 2; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;

    // left e right and empty map
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            if (j == 0) {
                std::cout << "#";
            }

            // snake
            if (i == Y && j == X) {
                std::cout << "@"; //cabeça
            }
            // fruit
            else if (i == fruitY && j == fruitX) {
                std::cout << "F";
            }
            else {
                // tail
                bool printTail = false;
                for (size_t k = 0; k < tailLength; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printTail = true;
                        std::cout << "o";
                    }
                }
                // black space
                if (!printTail) {
                    std::cout << " ";
                }
            }

            if (j == width - 1) {
                std::cout << "#";
            }
        }
        
        std::cout << std::endl;
    }

    // bottom
    for (size_t i = 0; i < width + 2; i++) {
        std::cout << "#";
    }

    std::cout << std::endl;
    std::cout << "SCORE: " << score << std::endl;
}
// https://youtu.be/PSoLD9mVXTA?t=171

#endif // DRAW_HPP_INCLUDED
