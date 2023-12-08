
#include <stdio.h>

#include "trie_node.h"

Trie_Node::Trie_Node(char c){
    this->c = c;
    ends_word = false;
    for(int i = 0; i < 26; ++i){
        adj[i] = nullptr;
    }
}
