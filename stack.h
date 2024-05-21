const int cap=1e5;
template <class type>
class stack{
    type list[cap]={};
    int tip=-1;
    type null;
public:
    stack()=default;
    explicit stack(type val){
        *list=val;
        tip++;
    }
    bool isempty(){
        return tip==-1;
    }
    bool isfull(){
        return tip==cap-1;
    }
    type top(){
        if(tip==-1) return null;
        return list[tip];
    }
    void push(type val){
        if(tip==cap-1) return;
        list[1+tip++]=val;
    }
    type pop(){
        if(tip==-1) return null;
        return list[tip--];
    }
};