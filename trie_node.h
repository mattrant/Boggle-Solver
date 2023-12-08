#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#include <memory>

class Trie_Node{
public:
    char c;
    bool ends_word;
    std::unique_ptr<Trie_Node> adj[26];
    Trie_Node(char c);
};

#endif
