#ifndef INPUT_HPP_INCLUDED
#define INPUT_HPP_INCLUDED

#include <conio.h>
// conio.h é para desenhar tela, e é para dos/windows (as funções do conio são úteis para manipular caracteres na tela, especificar cor de carácter e de fundo.)
/* Funções:
kbhit	Determina se uma tecla do teclado foi pressionada ou não.
getch	Obtenha a entrada char do console.
    https://code-reference.com/c/conio.h
*/
const int XgameOver = 0x78;

void Input() {
    if(kbhit()) {
        switch (getch()) {
            case A:
                direction = LEFT;
                break;
            case D:
                direction = RIGHT;
                break;
            case W:
                direction = UP;
                break;
            case S:
                direction = DOWN;
                break;
            case XgameOver:
                gameOver = true;
                break;

            default:
                break;
        }
    }
}

#endif // INPUT_HPP_INCLUDED
