#ifndef SOLVER_H
#define SOLVER_H

#include <unordered_set>
#include <string>
#include <vector>
#include <memory>

#include "board.h"
#include "trie.h"

class Solver{
public:
    Solver(Board &b, std::string dict_file);
    //Prints out all of the words found on the Boggle board that were also in `dict_file`
    void print_words() const;
private:
    std::unordered_set<std::string> dict;
    std::vector<std::vector<int>> adj;
    Board *b;
    std::unique_ptr<Trie> t;

    static const unsigned int MIN_WORD_LENGTH = 3;

    //Initializes the adjacency matrix adj according to the Boggle board
    void init_adj();
    //Recursively searches the board to find words. The current position is `node` and all
    //of the previous nodes visited on the path before reaching the current node are indicated by the
    //elements in `path`.
    void DFS_path(int node, std::vector<int> path);
    //Retrieves the word indicated by the values in `positions`
    std::string get_word(const std::vector<int> &positions) const;
};

#endif // SOLVER_H
