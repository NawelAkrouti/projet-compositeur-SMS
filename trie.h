#ifndef TRIE_H
#define TRIE_H
#include <vector>
#include <map>
#include <string>

constexpr int Size = 10000;

class Trie{
public:
    Trie();
    Trie(std::vector<std::string> v);
    ~Trie();
    Trie* NewNode();
    std::string charToInt(std::string prefix);
    void AddWord(std::string prefix, Trie* FirstNode);
    std::vector<std::string> Find(std::string prefix, Trie* FirstNode);

    Trie* children[Size];
    std::vector<std::string> ListWords;
    bool isEnd;
};

static std::map<char, char> Keyboard = {
    {'a', '2'}, {'b', '2'}, {'c', '2'},
    {'d', '3'}, {'e', '3'}, {'f', '3'},
    {'g', '4'}, {'h', '4'}, {'i', '4'},
    {'j', '5'}, {'k', '5'}, {'l', '5'},
    {'m', '6'}, {'n', '6'}, {'o', '6'},
    {'p', '7'}, {'q', '7'}, {'r', '7'}, {'s', '7'},
    {'t', '8'}, {'u', '8'}, {'v', '8'},
    {'w', '9'}, {'x', '9'}, {'y', '9'}, {'z', '9'}
};

#endif // TRIE_H
