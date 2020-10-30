#ifndef SETUP_HPP_INCLUDED
#define SETUP_HPP_INCLUDED

#include <iostream>

// #define W 0x57;
const int W = 0x77;
// #define A 0x41;
const int A = 0x61;
// #define S 0x53;
const int S = 0x73;
// #define D 0x44;
const int D = 0x64;
// https://web.fe.up.pt/~ee96100/projecto/Tabela%20ascii.htm

bool gameOver;
const int width = 40;
const int height = 20;
int X, Y, fruitX, fruitY, score;

int tailX[100], tailY[100];
int tailLength;

enum eDirection {
    STOP = 0,
    UP,
    LEFT,
    DOWN,
    RIGHT
};
eDirection direction;

void Setup() {
    gameOver = false;
    // gameOver = true;
    direction = STOP;
    X = width / 2;
    Y = height / 2;
    fruitX = std::rand() % width;
    fruitY = std::rand() % height;
    score = 0;
}

/* 0x57 = w
0x44 = d
0x53 = s
0x41 = a */

#endif // SETUP_HPP_INCLUDED
