#include "Dictionary.h"

int main()
{
    Dictionary* dictionary=NULL;
    while(true)
    {
        string command;
        cin>>command;
        //create dictionary
        if(command=="M")
        {
            int m;
            cin>>m;
            dictionary=new Dictionary(m);
            cout<<"success"<<endl;
        }
        //insert a word
        else if(command=="INSERT")
        {
            string word;
            cin>>word;
            if(dictionary->insert(word)) cout<<"success"<<endl;
            else cout<<"failure"<<endl;
        }
        //read from file
        else if(command=="READ")
        {
            string filename;
            cin>>filename;
            if(dictionary->read(filename)) cout<<"success"<<endl;
            else cout<<"failure"<<endl;
        }
        //tokenize a word
        else if(command=="TOKENIZE")
        {
            string word;
            cin>>word;
            cout<<dictionary->tokenize(word)<<endl;
        }
        //retrieve the token from word
        else if(command=="RETRIEVE")
        {
            int token;
            cin>>token;
            cout<<dictionary->retrieve(token)<<endl;
        }
        //read a series of words
        else if(command=="STOK")
        {
            dictionary->stok();
        }
        //read a series of tokens
        else if(command=="TOKS")
        {
            dictionary->toks();
        }
        //output
        else if(command=="PRINT")
        {
            int k;
            cin>>k;
            dictionary->print(k);
        }
        //exit
        else if(command=="EXIT") break;
    }
    //release
    delete dictionary;

    return 0;
}