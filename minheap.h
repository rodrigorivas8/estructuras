#include <iostream>
using namespace std;

const int cap=1e8;
template <class type>
class minheap{
    type arr[cap]={};
    int n=0;

    void heapify_down(int i){
        if(i>n/2-1) return;
        int min=i,
            l=2*i+1,
            r=2*i+2;

        if(r==n) r=i;
        if(arr[l]<arr[min]) min=l;
        if(arr[r]<arr[min]) min=r;
        if(min==i) return;

        type temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;

        heapify_down(min);
    }
    void heapify_up(int i){
        if(i==0) return;
        int p=(i-1)/2;
        if(arr[i]>=arr[p]) return;
        type temp=arr[i];
        arr[i]=arr[p];
        arr[p]=temp;
        heapify_up(p);
    }

public:
    minheap()=default;
    minheap(type *l,int s){
        n=s; s=-1;
        while(s++<n)
            arr[s]=l[s];

    }

    type top(){return *arr;}
    int size(){return n;}

    type pop(){
        type temp=arr[0];
        arr[0]=arr[n-1];
        arr[n---1]=temp;
        heapify_down(0);
        return temp;
    }

    void insert(type val){
        arr[n]=val;
        heapify_up(n++);
    }

    void fix(){
        int aux=(n-2)/2;
        for(int i=aux;i>=0;i--){
            heapify_down(i);
        }
    }

    void sort(){
        fix();
        int s=n;
        cout<<this;
        while(n--) pop();
        n=s;
    }

    friend ostream& operator<<(ostream& os,minheap* h){
        os<<'[';
        int size=h->n;
        for(int i=0;i<size;i++){
            os<<h->arr[i];
            if(i<size-1) os<<',';
        }
        return os<<']';
    }
};