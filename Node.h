#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
using namespace std;

//the node to store word and its token
class Node
{
private:
    string word;
    int token;
    //points to next node
    Node* next;

public:
    //constructor
    Node(string word, int token);
    //get the word stored in node
    const string &getWord() const;
    //get the token stored in node
    int getToken() const;
    //get the next node
    Node *getNext() const;
    //set the next node
    void setNext(Node *next);
};


#endif
