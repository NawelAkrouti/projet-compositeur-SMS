#include "trie.h"
#include <iostream>
#include <map>
#include<vector>
#include<string>


Trie::Trie(){};
Trie::Trie(std::vector<std::string> v ): ListWords(v),isEnd(false) {}
Trie::~Trie(){
    ListWords.clear();
}

std::string Trie::charToInt(std::string prefix){
    std::string w = "";
    for(char c : prefix){
        w += Keyboard[c];
    }
    return w;
}

Trie *Trie::NewNode()
{
    Trie* trie = new Trie;
    isEnd = false;
    for(int i = 0; i < Size; i++){
        children[i] = nullptr;
    }
    return trie;
}


void Trie::AddWord(std::string prefix, Trie* FirstNode){
    Trie* currentNode = FirstNode;
    std::string ch = prefix;
    prefix = charToInt(prefix);

    for(size_t i = 0; i < prefix.length(); i++){
        int j = prefix[i] - '0';

        if(!currentNode->children[j]){
            currentNode->children[j] = this->NewNode();
        }
        currentNode = currentNode->children[j];
    }
    currentNode->ListWords.push_back(ch);
    currentNode->isEnd = true;
}

std::vector<std::string> Trie::Find(std::string prefix, Trie* FirstNode){
    Trie* currentNode = FirstNode;

    for(size_t i = 0; i < prefix.length(); i++){
        int j = prefix[i] - '0';
        if(!currentNode->children[j]){
            return {};
        }
        currentNode = currentNode->children[j];
    }

    if(currentNode->isEnd){
        std::cout << "Possible words: ";
        for(size_t i = 0; i < currentNode->ListWords.size(); i++){
            std::cout << currentNode->ListWords.at(i) << " ";
        }
        std::cout << "\n";
        return currentNode->ListWords;
    }
    else{
         return {};
    }
}
