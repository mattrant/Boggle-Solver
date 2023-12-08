#include <random>
#include <algorithm>
#include <string>
#include <cassert>
#include <iostream>

#include "board.h"
#include "die.h"

Board::Board(){
    //Possible faces for the dice of a standard english Boggle game
    std::vector<std::string> die_faces = {
    "RIFOBX",
    "IFEHEY",
    "DENOWS",
    "UTOKND",
    "HMSRAO",
    "LUPETS",
    "ACITOA",
    "YLGKUE",
    "QBMJOA",
    "EHISPN",
    "VETIGN",
    "BALIYT",
    "EZAVND",
    "RALESC",
    "UWILRG",
    "PACEMD"
    };

    for(int i = 0 ; i < WIDTH*LENGTH ; ++i){
        dice.push_back(std::unique_ptr<Die>(new Die(die_faces[i])));
    }
    shake();
}

void Board::shake(){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(dice.begin(), dice.end(),g);

    for(auto const &d : dice){
        d->roll();
    }
}


std::string Board::spot(int i, int j) const {

    assert(i < WIDTH && i >= 0 && j < LENGTH && j >= 0);
    
    return dice[WIDTH*i+j]->get_top();
}

std::ostream& operator<<(std::ostream &os, const Board &b){

    for(int i = 0; i < Board::WIDTH; ++i){
        for(int j = 0; j<Board::LENGTH; ++j){
            std::string face = b.spot(i,j);
            //prevents poor printing alignment if the board contains 'QU'
            os<<(face.length() == 1 ? face+" " : face)<<" ";
        }
        if(i != Board::WIDTH-1){
            os<<std::endl;
        }
    }
    return os;
}

