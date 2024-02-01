#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <memory>

#include "trie.h"
#include "trie_node.h"

Trie::Trie(std::string file_name)
{
    for(int i = 0;i<26;++i){
        adj[i] = std::make_unique<Trie_Node> (char(i+int('A')));
    }

    std::ifstream infile(file_name);

    if(!infile.is_open()){
        std::cerr<<"Error opening "<<file_name<<std::endl;
        exit(1);
    }
    std::string line;
    while(std::getline(infile,line)){
        //add lines in the file that only contain a-z or A-Z
        if(std::all_of(std::begin(line),std::end(line),[](char c){return std::isalpha(c);})){
            insert(line);
        }   
    }
  
}

void Trie::insert(std::string s)
{
    if(s.size() == 0){
        return;
    }

    std::transform(s.begin(),s.end(),s.begin(),::toupper);

    Trie_Node* curr = adj[int(s[0])-int('A')].get();
    for(unsigned int i =1; i<s.size();++i){
        int index = int(s[i])-int('A');
        if(curr->adj[index] == nullptr){
            curr->adj[index] = std::make_unique<Trie_Node>(s[i]);
        }
        curr = curr->adj[index].get();
    }
    curr->ends_word = true;
}


Trie_Node* Trie::get_node(std::string s) const{

    if(s.size() == 0){
        return nullptr;
    }

    Trie_Node* curr = adj[int(s[0])-int('A')].get();
    for(unsigned int i =1; i<s.size(); ++i){
        int index = int(s[i])-int('A');
        if(curr->adj[index] == nullptr){
            return nullptr;
        }
        curr=curr->adj[index].get();
    }
    return curr;
}


bool Trie::is_present(std::string s) const{
    
    if(s.size() == 0){
        return false;
    }

    std::transform(s.begin(),s.end(),s.begin(),::toupper);
    
    Trie_Node* node = get_node(s);

    return node == nullptr ? false : node->ends_word;

}


bool Trie::prefix_present(std::string s) const{

    if(s.size() == 0){
        return false;
    }

    std::transform(s.begin(),s.end(),s.begin(),::toupper);

    return get_node(s) == nullptr ? false : true;
}
