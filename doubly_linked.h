#include <iostream>
using namespace std;

template <class type>
class doubly_linked{
    struct node{
        type val;
        node* prev=nullptr,
            * next=nullptr;
        node()=default;
        node(type v):val(v){}
        node(type v,node* p,node* n)
        :val(v),prev(p),next(n){}
    };
    type null;
    node* head=nullptr,
        * tail=nullptr;

public:
    doubly_linked()=default;

    explicit doubly_linked(type v):
    head(new node(v)),tail(head){}

    type front(){
        if(!head) return null;
        return head->val;
    }

    type back(){
        if(!head) return null;
        return tail->val;
    }

    void push_front(type v){
        auto aux=head;
        head=new node(v);
        head->next=aux;
        if(aux) aux->prev=head;
        if(!tail) tail=head;
    }

    void push_back(type v){
        auto aux=tail;
        tail=new node(v);
        tail->prev=aux;
        if(aux) aux->next=tail;
        if(!head) head=tail;
    }

    type pop_front(){
        auto val=head->val;
        auto temp=head;
        head=head->next;
        head->prev=nullptr;
        delete temp;
        return val;
    }

    type pop_back(){
        auto val=tail->val;
        auto temp=tail;
        tail=tail->prev;
        tail->next=nullptr;
        delete temp;
        return val;
    }

    void insert(type val,int id){
        if(!head && id!=0) return;
        if(id==0){
            auto aux=head;
            head=new node(val);
            head->next=aux;
            aux->prev=head;
            return;
        }
        auto aux=head;
        while(id--){
            aux=aux->next;
            if(!aux) return;
        }
        auto item=new node(val);
        item->prev=aux->prev;
        item->next=aux;
        aux->prev->next=item;
        aux->prev=item;
    }

    void remove(int id){
        if(!head) return;
        if(id==0){
            auto aux=head;
            head=head->next;
            head->prev=nullptr;
            delete aux;
            return;
        }
        auto aux=head;
        while(id--){
            aux=aux->next;
            if(!aux) return;
        }
        aux->prev->next=aux->next;
        aux->next->prev=aux->prev;
        delete aux;
    }

    type operator[](int id){
        auto aux=head;
        while(id-- && aux)
            aux=aux->next;
        if(!aux) return null;
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

    void reverse(){
        auto t1=head,t2=tail;
        while(t1){
            if(t1==t2 || t1->prev==t2)
                return;

            auto aux=t1->val;
            t1->val=t2->val;
            t2->val=aux;

            t1=t1->next;
            t2=t2->prev;
        }
    }

    friend ostream& operator<<(ostream &os,doubly_linked l){
        auto aux=l.head;
        os<<'[';
        while(aux){
            os<<aux->val;
            aux=aux->next;
            if(aux) os<<',';
        }
        return os<<']';
    }
};