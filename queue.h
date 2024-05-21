const int cap=1e5;
template <class type>
class queue{
    int head=0,
        tail=0;
    type list[cap]={};
    type null;
public:
    queue()=default;
    explicit queue(type val){
        *list=val;
        tail++;
    }
    bool empty(){
        return head==tail;
    }
    bool full(){
        return head==(tail+1)%cap;
    }
    type front(){
        if(empty()) return null;
        return list[(head+1)%cap];
    }
    void enqueue(type val){
        if(full()) return;
        tail=(tail+1)%cap;
        list[tail]=val;
    }
    type dequeue(){
        if(empty()) return null;
        head=(head+1)%cap;
        return list[head];
    }
};