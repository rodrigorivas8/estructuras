#include <iostream>
using namespace std;

const int len=1e8;
template <class type>
class maxheap{
    type arr[len]={};
    int n=0;

    void heapify_down(int i) {
        if(i>n/2-1) return;
        int max=i,
            l=2*i+1,
            r=2*i+2;

        if(r==n) r=i;
        if(arr[l]>arr[max]) max=l;
        if(arr[r]>arr[max]) max=r;
        if(max==i) return;

        type aux=arr[i];
        arr[i]=arr[max];
        arr[max]=aux;

        heapify_down(max);
    }
    void heapify_up(int i){
        if(i==0) return;

        int p=(i-1)/2;
        if(arr[i]<=arr[p]) return;

        type temp=arr[i];
        arr[i]=arr[p];
        arr[p]=temp;

        heapify_up(p);
    }

public:
    maxheap()=default;
    maxheap(type l[],int s){
        n=s; s=-1;
        while(s++!=n)
            arr[s]=*(l++);
    }

    void fix(){
        int aux=(n-2)/2;
        for(int i=aux;i>=0;i--)
            heapify_down(i);
    }

    int size(){return n;}

    void insert(type val){
        arr[n]=val;
        heapify_up(n++);
    }

    type top(){
        return *arr;
    }

    type pop(){
        type temp=arr[0];
        arr[0]=arr[n-1];
        arr[n---1]=temp;
        heapify_down(0);
        return temp;
    }

    void sort(){
        fix();
        int s=n;
        while(n) pop();
        n=s;
    }

    friend ostream& operator<<(ostream& os,maxheap* h){
        int size=h->n;
        os<<'[';
        for(int i=0;i<size;i++){
            os<<h->arr[i];
            if(i<size-1) os<<',';
        }
        return os<<']';
    }
};