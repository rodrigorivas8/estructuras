#ifndef SEM4_STACK_H
#define SEM4_STACK_H
#endif

class stack{
    int max;
    int *list=new int[max];
    int *tip=list-1;
public:
    stack(int m):max(m){}
    bool push(int);
    int pop();
    int top();
    bool empty();
    bool full();
};

bool stack::push(int data){
    if(tip==list+max-1) return false;
    tip++;
    *tip=data;
    return true;
}

int stack::pop(){
    if(tip==list-1) return -1;
    tip--;
    return *(tip+1);
}

int stack::top(){
    if(tip==list-1) return -1;
    return *tip;
}

bool stack::empty(){
    return tip==list-1;
}

bool stack::full(){
    return tip==list+max-1;
}