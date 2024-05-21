#include <iostream>
using namespace std;

template <class type>
class forward_list{
    struct node{
        type val;
        node* next=nullptr;
        node()=default;
        explicit node(type v):val(v){}
        node(type v,node* n):val(v),next(n){}
    };
    struct tup{
        node* n; type val;
        tup(node* n,type v):n(n),val(v){}
    };

    node* head=nullptr;
    type null;

    type back(node* n){
        if(!n->next) return n->val;
        return back(n->next);
    }

    node* push_back(type v,node* n){
        if(!n) return new node(v);
        n->next=push_back(v,n->next);
        return n;
    }

    tup pop_back(node* n){
        if(!n->next){
            auto v=n->val;
            delete n;
            n=nullptr;
            return tup(n,v);
        }
        tup t=pop_back(n->next);
        n->next=t.n;
        return tup(n,t.val);
    }

public:
    forward_list()=default;

    explicit forward_list(type v)
    :head(new node(v)){}

    type front(){
        if(!head) return null;
        return head->val;
    }

    type back(){
        if(!head) return null;
        return back(head);
    }

    void push_front(type v){
        auto aux=head;
        head=new node(v);
        head->next=aux;
    }

    void push_back(type v){
        head=push_back(v,head);
    }

    type pop_front(){
        if(!head) return null;
        auto val=head->val;
        auto aux=head;
        head=head->next;
        delete aux;
        return val;
    }

    type pop_back(){
        if(!head) return null;
        tup t=pop_back(head);
        head=t.n;
        return t.val;
    }

    type operator[](int id){
        if(!head) return null;
        auto aux=head;
        while(id--){
            aux=aux->next;
            if(!aux) return null;
        }
        return aux->val;
    }

    bool empty(){
        return !head;
    }

    int size(){
        int s=1;
        auto aux=head;
        while(aux && s++)
            aux=aux->next;
        return s-1;
    }

    void clear(){
        while(head){
            auto aux=head;
            head=head->next;
            delete aux;
        }
    }

    void sort(){
        auto t1=head;
        while(t1){
            auto t2=head;
            while(t2->next){
                if(t2->val>t2->next->val){
                    type aux=t2->val;
                    t2->val=t2->next->val;
                    t2->next->val=aux;
                }
                t2=t2->next;
            }
            t1=t1->next;
        }
    }

    void reverse(){
        if(!head) return;
        auto t1=head;
        head=nullptr;
        while(t1){
            auto t2=t1;
            t1=t1->next;
            t2->next=head;
            head=t2;
        }
    }

    friend ostream& operator<<(ostream &os,forward_list l){
        auto aux=l.head;
        os<<'[';
        while(aux){
            os<<aux->val;
            aux=aux->next;
            if(aux) os<<',';
        }
        return os<<']';
    }

    node* operator+(int id){
        auto aux=head;
        while(id--){
            if(!aux) return nullptr;
            aux=aux->next;
        }
        return aux;
    }
};
