#ifndef SEM4_DEQUE_H
#define SEM4_DEQUE_H
#endif

#include <iostream>
using namespace std;

class deque{
    int max;
    int *list=new int[max];
    int *head=list,
            *tail=list;

public:
    deque(int m):max(m+1){};
    bool insertFront(int);
    bool insertLast(int);
    bool deleteFront();
    bool deleteLast();
    int getFront();
    int getLast();
    bool isEmpty();
    bool isFull();
};

bool deque::insertFront(int data){
    int h=int(head-list),
            t=int(tail-list);
    if(h==(t+1)%max) return false;
    h=(h+max-1)%max;
    head=list+h;
    *head=data;
    return true;
}

bool deque::insertLast(int data){
    int h=int(head-list),
            t=int(tail-list);
    t=(t+1)%max;
    if(h==t) return false;
    *tail=data;
    tail=list+t;
    return true;
}

bool deque::deleteFront(){
    if(head==tail) return false;
    int h=int(head-list);
    h=(h+1)%max;
    head=list+h;
    return true;
}

bool deque::deleteLast(){
    if(head==tail) return false;
    int t=int(tail-list);
    t=(t+max-1)%max;
    tail=list+t;
    return true;
}

int deque::getFront(){
    if(head==tail) return -1;
    return *head;
}

int deque::getLast(){
    if(head==tail) return -1;
    int t=int(tail-list);
    t=(t+max-1)%max;
    return *(list+t);
}

bool deque::isEmpty(){
    return head==tail;
}

bool deque::isFull(){
    int t=int(tail-list);
    t=(t+1)%max;
    return head==list+t;
}