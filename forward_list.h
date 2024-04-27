#ifndef SEM2_FORWARD_LIST_H
#define SEM2_FORWARD_LIST_H
#endif //SEM2_FORWARD_LIST_H

#include <iostream>
using namespace std;

template <class T=int>
struct node{
    T data=0;
    node *next=nullptr;
};

template <class T=int>
class list{
    node<T> *head=nullptr;

public:

    T front();
    T back();
    void pop_front();
    void pop_back();
    void push_front(T);
    void push_back(T);
    T operator[](int);
    node<T>* operator+(int);
    bool empty();
    int size();
    void clear();
    void swap(int,int);
    void sort(); //selection
    void reverse();

    friend ostream& operator<<(ostream &os,const list<T> &l){
        os<<"[";
        auto *aux=l.head;
        while(aux!=nullptr){
            os<<aux->data;
            aux=aux->next;
            if(aux!=nullptr) os<<',';
        }
        os<<']';
        return os;
    }
};

template <class T>
T list<T>::front(){
    if(head==nullptr)
        return -1;
    return head->data;
}

template <class T>
T list<T>::back(){
    if(head==nullptr)
        return -1;
    node<T> *aux=head;
    while(aux->next!=nullptr){
        aux=aux->next;
    }
    return aux->data;
}

template <class T>
void list<T>::pop_front(){
    if(head!=nullptr){
        auto *aux=head;
        head=aux->next;
        delete aux;
    }
}

template <class T>
void list<T>::pop_back(){
    if(head==nullptr)
        return;
    auto *aux=head;
    if(aux->next==nullptr){
        delete aux;
        head=nullptr;
        return;
    }
    while(aux->next->next!=nullptr)
        aux=aux->next;
    delete aux->next;
    aux->next=nullptr;
}

template <class T>
void list<T>::push_front(T data){
    if(head==nullptr){
        head=new node<T>;
        head->data=data;
    }else{
        auto *aux=new node<T>;
        aux->next=head;
        aux->data=data;
        head=aux;
    }
}

template <class T>
void list<T>::push_back(T data){
    if(head==nullptr){
        head=new node<T>;
        head->data=data;
    }else{
        auto *aux=head;
        while(aux->next!=nullptr){
            aux=aux->next;
        }
        auto *last=new node<T>;
        aux->next=last;
        last->data=data;
    }

}

template <class T>
T list<T>::operator[](int id){
    if(head==nullptr)
        return -1;
    else{
        auto *aux=head;
        int data=-1;
        for(int i=0;i<=id;i++){
            if(i!=id && aux->next==nullptr){
                return -1;
            }
            data=aux->data;
            aux=aux->next;
        }
        return data;
    }
}

template <class T>
node<T>* list<T>::operator+(int id){
    if(empty())return nullptr;
    auto *aux=head;
    for(int i=0;i<id;i++){
        if(i!=id-1 && aux->next==nullptr){
            return nullptr;
        }
        aux=aux->next;
    }
    return aux;
}

template <class T>
bool list<T>::empty(){
    return head==nullptr;
}

template <class T>
void list<T>::clear(){
    while(head!=nullptr){
        auto *aux=head;
        head=aux->next;
        delete aux;
    }
}

template <class T>
int list<T>::size(){
    if(head==nullptr)
        return 0;
    int i=1;
    auto *aux=head;
    while(aux->next!=nullptr){
        aux=aux->next;
        i++;
    }
    return i;
}

template <class T>
void list<T>::swap(int i,int j){
    if(head==nullptr) return;
    auto *aux=*this+i;
    auto *auy=*this+j;
    if(aux==nullptr)return;
    if(auy==nullptr)return;
    auto temp=aux->data;
    aux->data=auy->data;
    auy->data=temp;
}

template <class T>
void list<T>::sort(){
    if(head==nullptr) return;
    int s=size();
    for(int i=0;i<s;i++){
        int min=i;
        for(int j=i;j<s;j++)
        {
            if((*this)[j]<(*this)[min])
                min=j;
        }
        swap(i,min);
    }
}

template <class T>
void list<T>::reverse(){
    if(head==nullptr)return;
    node<T> *prev=nullptr,*aux;
    while(head->next!=nullptr){
        aux=head;
        head=head->next;
        aux->next=prev;
        prev=aux;
    }
    head->next=aux;
}