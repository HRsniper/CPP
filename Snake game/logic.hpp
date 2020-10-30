#ifndef LOGIC_HPP_INCLUDED
#define LOGIC_HPP_INCLUDED

void Logic() {
    int prevCoordinateX = tailX[0];
    int prevCoordinateY = tailY[0];
    int prevCoordinate2X, prevCoordinate2Y;

    tailX[0] = X;
    tailY[0] = Y;

    for (size_t i = 1; i < tailLength; i++) {
        prevCoordinate2X = tailX[i];//1,2,3,...
        prevCoordinate2Y = tailY[i];

        tailX[i] = prevCoordinateX;
        tailY[i] = prevCoordinateY;

        prevCoordinateX = prevCoordinate2X;
        prevCoordinateY = prevCoordinate2Y;
    }
    

    switch (direction) {
            case LEFT:
                X--;
                break;
            case RIGHT:
                X++;
                break;
            case UP:
                Y--;
                break;
            case DOWN:
                Y++;
                break;

            default:
                break;
    }

    // wall kill
    /* if(X > width || X < 0 || Y > height || Y < 0) {
        gameOver = true;
        std::cout << "GAME OVER" << std::endl;
        system("pause");
    } */

    // wall not kill
    if (X >= width) {
        X = 0;
    }
    else if (X < 0) {
        X = width - 1;
    }

    if (Y >= height) {
        Y = 0;
    }
    else if (Y < 0) {
        Y = height - 1;
    }

    // tail kill
    for (size_t i = 0; i < tailLength; i++) {
        if (tailX[i] == X && tailY[i] == Y) {
            gameOver = true;
        }
    }
    
    if(X == fruitX && Y == fruitY) {
        score += 10;
        fruitX = std::rand() % width;
        fruitY = std::rand() % height;
        tailLength++;
    }
    
}

#endif // LOGIC_HPP_INCLUDED
