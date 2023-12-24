#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Node.h"
#include <fstream>
using namespace std;

class Dictionary
{
private:
    //all words
    string *words;
    //the number of all words
    int numWord;
    //the capacity of the words array
    int arrayCapacity;
    //the hashmap for all words
    Node** slots;
    //the size for the hashmap
    int numSlot;

private:
    //calculate the hash
    int hash(const string& word);

public:
    //constructor
    Dictionary(int numSlot);
    //destructor
    ~Dictionary();
    //whether contains this word
    bool contains(string word);
    //whether a valid word
    bool isValid(string word);
    //insert a word
    bool insert(string word);
    //read words from file
    bool read(string fileName);
    //get the token of a word
    int tokenize(string word);
    //get the word of a token
    string retrieve(int token);
    //get words from input
    void stok();
    //get tokens from input
    void toks();
    //print the chain of the map
    void print(int slotIndex);
};


#endif
