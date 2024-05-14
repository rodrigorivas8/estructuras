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

    bool empty()const{
        return head==tail;
    }

    bool full()const{
        int h=int(head-list),
                t=int(tail-list);
        return h==(t+1)%max;
    }

    type front()const{
        if(head==tail)
            return -1;
        return *head;
    }

    void enqueue(type data){
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

    type dequeue(){
        int h=int(head-list),
                t=int(tail-list);
        type r=*head;
        if(h==t) return nullptr;
        h=(h+1)%max;
        head=list+h;
        return r;
    }
};