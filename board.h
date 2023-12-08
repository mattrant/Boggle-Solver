#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <memory>

#include "die.h"

class Board{

public:
    Board();

    static const int WIDTH = 4;
    static const int LENGTH = 4;

    //Sets up the board for a new game
    void shake();
    //Returns the top face of the die at position (i,j) where the top left corner of the board is (0,0)
    std::string spot(int i, int j) const;

private:
    std::vector<std::unique_ptr<Die>> dice;
};

std::ostream& operator<<(std::ostream& os, const Board &b);

#endif
