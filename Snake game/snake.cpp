#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

// #include <iostream>
// #include <cstdlib>

#include "setup.hpp"
#include "draw.hpp"
#include "input.hpp"
#include "logic.hpp"

// using namespace std;

int main() {

    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        // Sleep(10); //dar slow no game
    }

    return 0;
}