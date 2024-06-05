#include <string>
using namespace std;

class trie{
    struct node{
        bool end=false;
        node* next[26]={};

        node()=default;

        void dot(){end=true;}
        bool cut(){
            bool aux=end;
            end=false;
            return aux;
        }
        auto& operator[](char c){
            return next[c-'a'];
        }
    };
    node* head=nullptr;

    void insert(string s,node* aux){
        if(!s[0]) return aux->dot();
        auto&nxt=(*aux)[s[0]];
        if(!nxt) nxt=new node;
        insert(s.substr(1),nxt);
    }

    bool remove(string s,node* aux){
        if(!aux) return false;
        if(!s[0]) return aux->cut();
        auto nxt=(*aux)[s[0]];
        auto rst=s.substr(1);
        if(!remove(rst,nxt))
            return false;
        for(auto x:aux->next)
            if(x) return false;
        delete nxt;
        (*aux)[s[0]]=nullptr;
        return true;
    }

    bool find(string s,node* aux){
        if(!s[0]) return aux->end;
        auto nxt=(*aux)[s[0]];
        if(!nxt) return false;
        return find(s.substr(1),nxt);
    }

public:
    trie():head(new node){}

    void insert(string word){
        insert(word,head);
    }

    bool find(string word){
        return find(word,head);
    }

    void remove(string word){
        remove(word,head);
    }
};