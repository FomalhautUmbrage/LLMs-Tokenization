#include "Dictionary.h"

//constructor
Dictionary::Dictionary(int numSlot)
{
    this->numSlot=numSlot;
    //create the map array and initialize each slot to be empty
    this->slots=new Node*[numSlot];
    for(int i=0;i<numSlot;i++) slots[i]=NULL;
    //create the word array with initial capacity
    arrayCapacity=100;
    numWord=0;
    words=new string[arrayCapacity];
}

//destructor
Dictionary::~Dictionary()
{
    for(int i=0;i<numSlot;i++)
    {
        //release each chain
        Node* node=slots[i];
        while(node)
        {
            Node* nex=node->getNext();
            delete node;
            node=nex;
        }
    }
    //release the slots
    delete []slots;
    //release word array
    delete []words;
}

bool Dictionary::contains(string word)
{
    //get the location of the word if it is existed
    int i=hash(word)%numSlot;
    Node* node=slots[i];
    //check each node
    while(node)
    {
        if(node->getWord()==word) return true;
        node=node->getNext();
    }
    return false;
}

bool Dictionary::isValid(string word)
{
    for(int i=0;i<word.size();i++)
    {
        char x=word[i];
        if((x>='a' && x<='z') || (x>='A'&& x<='Z')) continue;
        else return false;
    }
    return true;
}

//insert a word
bool Dictionary::insert(string word)
{
    if (word.length() > 100) return false;
    for(int i=0;i<word.length();i++)
        if (word[i] <= 0) return false;
    //the word is duplicated
    if(contains(word)) return false;
    //the word contains non-alpha character
    if(!isValid(word)) return false;
    //the word array is full, expand it first
    if(arrayCapacity==numWord)
    {
        //a new array and backup the original words
        string* words2=new string[arrayCapacity*2];
        for(int i=0;i<numWord;i++) words2[i]=words[i];
        //release original array and double the capacity
        delete []words;
        words=words2;
        arrayCapacity*=2;
    }
    //store the word into word array
    words[numWord]=word;
    numWord++;
    //store the word into the map
    int token=numWord;
    Node* node=new Node(word, token);
    //calculate hash and location in map
    int i=hash(word)%numSlot;
    node->setNext(slots[i]);
    slots[i]=node;
    return true;
}

int Dictionary::hash(const string& word)
{
    int sum=0;
    //get the character sum
    for(int i=0;i<word.size();i++)
    {
        sum+=word[i];
    }
    return sum;
}

//read words from file
bool Dictionary::read(string fileName)
{
    ifstream file(fileName);
    //the number of words inserted
    int numWord=0;
    string word;
    while(file>>word)
    {
        bool result=insert(word);
        if(result) numWord++;
    }
    file.close();
    //success if any word is inserted
    if(numWord>0) return true;
    else return false;
}

//get the token of a word
int Dictionary::tokenize(string word)
{
    //get the location of the word if it is existed
    int i=hash(word)%numSlot;
    Node* node=slots[i];
    //check each node
    while(node)
    {
        if(node->getWord()==word) return node->getToken();
        node=node->getNext();
    }
    return 0;
}

//get the word of a token
string Dictionary::retrieve(int token)
{
    //convert it to an index
    int i=token-1;
    if(i<0 || i>numWord-1) return "UNKNOWN";
    else return words[i];
}

//get words from input
void Dictionary::stok()
{
    string word;
    int num=0;
    while(cin>>word)
    {
        //end of the input
        if(word=="_DONE_")
        {
            cout<<endl;
            break;
        }
        //try to find the token
        int token= tokenize(word);
        //the number of words input
        num++;
        //the first word does not have space before it
        if(num==1) cout<<token;
        else cout<<" "<<token;
    }
}

//get tokens from input
void Dictionary::toks()
{
    int token;
    int num=0;
    while(cin>>token)
    {
        //end of the input
        if(token==-1)
        {
            cout<<endl;
            break;
        }
        //try to get the word
        string word= retrieve(token);
        num++;
        //the first word does not have space before it
        if(num==1) cout<<word;
        else cout<<" "<<word;
    }
}

//print the chain of the map
void Dictionary::print(int slotIndex)
{
    Node* node=slots[slotIndex];
    //empty chain
    if(node==NULL)
    {
        cout<<"chain is empty"<<endl;
        return;
    }
    //output each one
    //the first one does not have space before it
    cout<< hash(node->getWord());
    //the remainings
    node=node->getNext();
    while(node)
    {
        cout<<" "<<hash(node->getWord());
        node=node->getNext();
    }
}
