#ifndef SEM4_QUEUE_H
#define SEM4_QUEUE_H
#endif

class queue{
    int max;
    int *list=nullptr;
    int *head=nullptr;
    int *tail=nullptr;

public:
    queue(int m):max(m+1){
        list=new int[max];
        head=list;
        tail=head;
    };

    bool empty() const;
    bool full() const;
    int front() const;
    void enqueue(int);
    int dequeue();
};

bool queue::empty()const{
    return head==tail;
}

bool queue::full()const{
    int h=int(head-list),
        t=int(tail-list);
    return h==(t+1)%max;
}

int queue::front()const{
    if(head==tail)
        return -1;
    return *head;
}

void queue::enqueue(int data){
    int h=int(head-list),
            t=int(tail-list);
    *tail=data;
    t=(t+1)%max;
    if(h==t){
        h=(h+1)%max;
        head=list+h;
    }
    tail=list+t;
}

int queue::dequeue(){
    int h=int(head-list),
            t=int(tail-list),
            r=*head;
    if(h==t) return -1;
    h=(h+1)%max;
    head=list+h;
    return r;
}