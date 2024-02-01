#include <algorithm>
#include <memory>

#include "solver.h"
#include "trie.h"

Solver::Solver(Board &b, std::string dict_file): b(&b){
    t = std::make_unique<Trie>(dict_file);
    init_adj();

    for(int i = 0;i<Board::WIDTH*Board::LENGTH;++i){
        std::vector<int> v;
        DFS_path(i,v);
    }
}


std::string Solver::get_word(const std::vector<int> &positions) const {
    std::string s = "";
    for(int i : positions){
        s.append(b->spot(i/Board::LENGTH,i%Board::WIDTH));
    }
    return s;
}


void Solver::DFS_path(int node, std::vector<int> path){
    path.push_back(node);
    std::string word = get_word(path);

    //most paths fail to give actual words after the first few letters so this quickly allows us to disregard many paths quickly
    if(!t->prefix_present(word)){
        return;
    }
    if(word.size() >= MIN_WORD_LENGTH && t->is_present(word)){
        dict.insert(word);
    }
    for(int i : adj[node]){
        //words in boggle must correspond to paths in the graph-theory sense
        if (std::find(path.begin(),path.end(),i) != path.end()){
            continue;
        }
        DFS_path(i,path);
    }
}


void Solver::init_adj(){
    //graph is relatively sparse, so we use adjaceny lists
    for(int i = 0; i < Board::WIDTH*Board::LENGTH; ++i){
        adj.push_back(std::vector<int>());
    }

    for(int i=0; i < Board::LENGTH; ++i){
        for(int j=0; j<Board::WIDTH; ++j){
            //possible offsets of column and row index for valid neighbors of a given die on the board
            for(int k = -1; k<=1 ;++k){
                for(int l=-1; l<=1; ++l){
                    //no self-loops
                    if(k == 0 and l == 0){
                         continue;
                    }
                    else if(j+k >= 0 && j+k < Board::LENGTH && i+l< Board::WIDTH && i+l >= 0){
                        adj[Board::LENGTH*i+j].push_back(Board::LENGTH*(i+l)+(j+k));
                    }
                }
            }
        }
    }
}

//Prints all of the words found on the board
void Solver::print_words() const {
    std::vector<std::string> words[Board::WIDTH*Board::LENGTH+1];

    for(std::string s : dict){
        words[s.size()].push_back(s);
    }

    //Boggle only cares about words of a certain size or larger
    for(int i=MIN_WORD_LENGTH; i <= Board::WIDTH*Board::LENGTH; ++i){
        if(words[i].size() == 0){
            continue;
        }
        std::cout<<"Words of length "<<i<<std::endl;
        std::sort(words[i].begin(),words[i].end());
        for(std::string s : words[i]){
            std::cout<<s<<std::endl;
        }
    }
}
