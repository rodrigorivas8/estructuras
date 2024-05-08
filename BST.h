#include <iostream>
//#include "queue.h"
using namespace std;

template <class type>
class BST{
    struct node{
        type data;
        node *left=nullptr;
        node *right=nullptr;
        explicit node(type x):data(x){};
        node(type x,node* l,node* r):
                data(x),left(l),right(r){};
    };

    node* root=nullptr;

    void inorder(node* aux){
        if(!aux) return;
        inorder(aux->left);
        cout<<aux->data<<' ';
        inorder(aux->right);
    };
    type pop(node* aux,node* node::*side){
        if(!aux) return aux->data;
        if(!(aux->*side)) return aux->data;
        while((aux->*side)->*side)
            aux=aux->*side;
        auto temp=(aux->*side);
        auto data=temp->data;
        aux->*side=nullptr;
        delete temp;
        return data;
    }
    bool remove(node* aux,type data){
        if(!aux) return false;
        if(data==aux->data){
            if(!aux->left && !aux->right){
                delete aux;
                return true;
            }
            if(aux->left){
                aux->data=pop(aux->left,&node::right);
                if(aux->data==aux->left->data){
                    delete aux->left;
                    aux->left=nullptr;
                }
            }
            else{
                aux->data=pop(aux->right,&node::left);
                if(aux->data==aux->right->data){
                    delete aux->right;
                    aux->right=nullptr;
                }
            }
            return false;
        }
        if(data<aux->data)
            if(remove(aux->left,data))
                aux->left=nullptr;
        if(data>aux->data)
            if(remove(aux->right,data))
                aux->right=nullptr;
        return false;
    }
    type limit(node* aux,node* node::*side){
        while(aux->*side) aux=aux->*side;
        return aux->data;
    }

public:
    void insert(type data){
        auto aux=root,prev=aux;
        bool left=true;
        while(aux){
            prev=aux;
            auto temp=aux->data;
            if(data==temp) return;

            left=data<temp;
            if(left) aux=aux->left;
            else aux=aux->right;
        }
        auto item=new node(data);
        if(!prev){root=item;return;}
        if(left) prev->left=item;
        else prev->right=item;
    }
    bool find(type data){
        auto aux=root;
        while(aux){
            type temp=aux->data;
            if(data==temp)
                return true;
            if(data<temp)
                aux=aux->left;
            else
                aux=aux->right;
        }
        return false;
    }
    void remove(type data){
        remove(root,data);
    };
    void inorder(){
        inorder(root);
    };

    type popmin(){
        return pop(root,&node::left);
    };
    type popmax(){
        return pop(root,&node::right);
    };

    type max(){
        return limit(root,&node::right);
    };
    type min(){
        return limit(root,&node::left);
    }

    type predecessor(){
        return limit(root->left,&node::right);
    };
    type successor(){
        return limit(root->right,&node::left);
    };

    type seed(){
        return root->data;
    }

    /*
    friend ostream& operator<<(ostream& os,BST t){
        queue<node*> q1(1000);
        q1.enqueue(t.root);
        int count=1;
        os<<t.root->data;
        while(!q1.empty()){
            os<<endl;
            int temp=0;
            while(count--){
                auto aux=q1.dequeue();
                os<<'(';
                if(aux->left){
                    q1.enqueue(aux->left);
                    os<<aux->left->data;
                    temp++;
                }
                if(aux->right){
                    q1.enqueue(aux->right);
                    if(aux->left)os<<',';
                    os<<aux->right->data;
                    temp++;
                }
                os<<')';
            }
            count=temp;
        }
        return os;
    }
    */
};