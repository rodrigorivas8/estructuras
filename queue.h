template <class type>
class queue{
    int max;
    type *list=nullptr;
    type *head=nullptr;
    type *tail=nullptr;

public:
    queue(int m):max(m+1){
        list=new type[max];
        head=list;
        tail=head;
    };

    bool empty() const;
    bool full() const;
    type front() const;
    void enqueue(type);
    type dequeue();
};

template <class type>
bool queue<type>::empty()const{
    return head==tail;
}

template <class type>
bool queue<type>::full()const{
    int h=int(head-list),
        t=int(tail-list);
    return h==(t+1)%max;
}

template <class type>
type queue<type>::front()const{
    if(head==tail)
        return -1;
    return *head;
}

template <class type>
void queue<type>::enqueue(type data){
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

template <class type>
type queue<type>::dequeue(){
    int h=int(head-list),
        t=int(tail-list);
    type r=*head;
    if(h==t) return nullptr;
    h=(h+1)%max;
    head=list+h;
    return r;
}