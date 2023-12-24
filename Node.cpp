#include "Node.h"

Node::Node(string word, int token)
{
    this->word=word;
    this->token=token;
    //the next is initialized to be empty
    this->next=NULL;
}

const string &Node::getWord() const
{
    return word;
}

int Node::getToken() const
{
    return token;
}

Node *Node::getNext() const
{
    return next;
}

void Node::setNext(Node *next)
{
    Node::next = next;
}
