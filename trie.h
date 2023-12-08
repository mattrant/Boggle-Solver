#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <memory>

#include "trie_node.h"

class Trie{
public:
    Trie(std::string file_name);
    //Inserts the string `s` into the Trie
    void insert(std::string s);
    //Checks to see if the string `s` is present in the Trie as a word
    bool is_present(std::string s) const;
    //Checks if the string `s` is present as the prefix to a word
    bool prefix_present(std::string s) const;
private:
    std::unique_ptr<Trie_Node> adj[26];
    //Returns the node in the Trie that corresponds to the final letter in `s` if it exists.
    //If it does not exist, it returns nullptr
    Trie_Node* get_node(std::string s) const;
};

#endif
