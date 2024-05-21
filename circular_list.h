#include <iostream>
using namespace std;

template <class type>
class circular_list{
    struct node{
        type val;
        node* next=nullptr,
            * prev=nullptr;
        node()=default;
        explicit node(type v):val(v){}
        node(type v,node* p,node* n)
        :val(v),prev(p),next(n){}
    };
    node* head=nullptr;
    type null;

public:

    circular_list(){
        head=new node;
        head->next=head;
        head->prev=head;
    }

    circular_list(type v){
        head=new node;
        auto item=new node(v);
        head->prev=item;
        head->next=item;
        item->prev=head;
        item->next=head;
    }

    type front(){
        return head->next->val;
    }

    type back(){
        return head->prev->val;
    }

    void push_front(type v){
        auto item=new node(v);
        head->next->prev=item;
        item->next=head->next;
        head->next=item;
        item->prev=head;
    }

    void push_back(type v){
        auto item=new node(v);
        head->prev->next=item;
        item->prev=head->prev;
        head->prev=item;
        item->next=head;
    }

    type pop_front(){
        auto temp=head->next;
        auto val=temp->val;
        head->next=temp->next;
        temp->next->prev=head;
        delete temp;
        return val;
    }

    type pop_back(){
        auto temp=head->prev;
        auto val=temp->val;
        head->prev=temp->prev;
        temp->prev->next=head;
        delete temp;
        return val;
    }

    void insert(type v,int id){
        auto aux=head;
        while(id--){
            aux=aux->next;
            if(aux==head) return;
        }
        auto item=new node(v);
        aux->next->prev=item;
        item->next=aux->next;
        aux->next=item;
        item->prev=aux;
    }

    void remove(int id){
        auto aux=head->next;
        while(id--){
            aux=aux->next;
            if(aux==head) return;
        }
        aux->next->prev=aux->prev;
        aux->prev->next=aux->next;
        delete aux;
    }

    type operator[](int id){
        auto aux=head->next;
        while(id-- && aux->next!=head)
            aux=aux->next;
        return aux->val;
    }

    bool empty(){
        return head==head->next;
    }

    int size(){
        auto aux=head->next;
        int s=1;
        while(aux!=head && s++)
            aux=aux->next;
        return s-1;
    }

    void clear(){
        auto aux=head->next;
        head->next=head;
        head->prev=head;
        while(aux!=head){
            auto temp=aux;
            aux=aux->next;
            delete temp;
        }
    }

    void reverse(){
        auto t1=head->next,
             t2=head->prev;
        while(t1!=t2 && t1->prev!=t2){
            auto aux=t1->val;
            t1->val=t2->val;
            t2->val=aux;
            t1=t1->next;
            t2=t2->prev;
        }
    }

    friend ostream& operator<<(ostream& os,circular_list l){
        auto aux=l.head->next;
        os<<'[';
        while(aux!=l.head){
            os<<aux->val;
            aux=aux->next;
            if(aux!=l.head) os<<',';
        }
        return os<<']';
    }
};