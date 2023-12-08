#include <iostream>

#include "board.h"
#include "solver.h"

int main(){
    Board b; 
    Solver s(b,"engmix.txt");
    std::cout<<b<<std::endl;
    s.print_words();
}

