#include <iostream>
#include "queue.h"
#include "stack.h"
using namespace std;

template <class type>
class AVL{
    struct node{
        type val;
        int height=1;
        node* left=nullptr;
        node* right=nullptr;

        explicit node(type v){val=v;}
        explicit node(type v,node* l,node* r)
        {val=v; left=l; right=r;}
    };

    node* root=nullptr;

    node* insert(type val,node* aux){
        if(!aux) return new node(val);
        if(val<aux->val) aux->left=insert(val,aux->left);
        else aux->right=insert(val,aux->right);
        return balance(aux);
    }

    node* remove(type val,node* aux){
        if(!aux) return aux;
        if(val==aux->val)
            return erase(aux);
        if(val<aux->val)
            aux->left=remove(val,aux->left);
        else if(val>aux->val)
            aux->right=remove(val,aux->right);
        return balance(aux);
    }

    node* erase(node* aux){
        if(!aux->left && !aux->right){
            delete aux; return nullptr;
        }
        type val;
        if(aux->left){
            val=limit(aux->left,&node::right)->val;
            aux->left=remove(val,aux->left);
        }else{
            val=limit(aux->right,&node::left)->val;
            aux->right=remove(val,aux->right);
        }
        aux->val=val;
        return balance(aux);
    }

    node* limit(node* aux,node* node::*side){
        if(!(aux->*side)) return aux;
        return limit(aux->*side,side);
    }

    node* balance(node* aux){
        int f=factor(aux);
        if(f<-1){
            if(factor(aux->right)==1)
                aux->right=rturn(aux->right);
            return lturn(aux);
        }
        if(f>1){
            if(factor(aux->left)==-1)
                aux->left=lturn(aux->left);
            return rturn(aux);
        }
        return update(aux);
    }

    node* lturn(node* aux){
        auto temp=aux;
        aux=aux->right;
        temp->right=aux->left;
        aux->left=update(temp);
        return update(aux);
    }

    node* rturn(node* aux){
        auto temp=aux;
        aux=aux->left;
        temp->left=aux->right;
        aux->right=update(temp);
        return update(aux);
    }

    node* update(node* aux){
        int hl=height(aux->left),
            hr=height(aux->right);
        aux->height=max(hl,hr)+1;
        return aux;
    }

    int factor(node* aux){
        int hl=height(aux->left),
            hr=height(aux->right);
        return hl-hr;
    }

    int height(node* aux){
        if(!aux) return 0;
        return aux->height;
    }

    int size(node* aux){
        if(!aux) return 0;
        int sl=size(aux->left),
            sr=size(aux->right);
        return sl+sr+1;
    }

public:

    void insert(type val){
        root=insert(val,root);
    }

    void remove(type val){
        root=remove(val,root);
    }

    int size(){
        return size(root);
    }

    void BFS(){
        auto st=new stack<int>(size());

    }

    friend ostream& operator<<(ostream& os,AVL t){

    }

};