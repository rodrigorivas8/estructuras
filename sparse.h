#include <iostream>
#include <vector>
using namespace std;

template <class type>
class sparse{
    struct node{
        type key;
        int row,col;
        node* next=this,
            * down=this;

        node(int i,int j,type k):
        row(i),col(j),key(k){};
    };

    int n,m,filled=0;
    vector<node*> rows,cols;

public:

    sparse(int n,int m):n(n),m(m){
        rows.resize(n);
        cols.resize(m);
    }

    void insert(int i,int j,type k){
        if(!k) return;
        if(i>n-1) return;
        if(j>m-1) return;

        auto item=new node(i,j,k);
        int R=0,C=0;
        if(!rows[i]) rows[i+R++]=item;
        if(!cols[j]) cols[j+C++]=item;
        if(R && C) return;

        auto r=rows[i];
        auto c=cols[j];

        while(!R){
            if(r->col==j){
                r->key=k;
                delete item;
                return;
            }
            if(r->next->col>j){
                item->next=r->next;
                r->next=item;
                break;
            }
            if(r->next==rows[i]){
                item->next=rows[i];
                r->next=item;
                break;
            }
            r=r->next;
        }

        while(!C){
            if(c->down->row>i){
                item->down=c->down;
                c->down=item;
                break;
            }
            if(c->down==cols[j]){
                item->down=cols[j];
                c->down=item;
                break;
            }
            c=c->down;
        }
    }

    void remove(int i,int j){
        if(i>n-1) return;
        if(j>m-1) return;

        auto r=rows[i];
        auto c=cols[j];

        while(r->next->col!=j){
            r=r->next;
            if(r==rows[i]) return;
        }

        while(c->down->row!=i)
            c=c->down;

        if(r->next==r)
            rows[i]=nullptr;
        if(c->down==c)
            cols[j]=nullptr;

        if(r->next==rows[i]){
            rows[i]=rows[i]->next;
            cols[j]=cols[j]->down;
        }

        auto item=r->next;
        r->next=item->next;
        item->next=nullptr;

        c->down=item->down;
        item->down=nullptr;
        delete item;
    }

    friend ostream& operator<<(ostream& os,sparse s){

        for(auto r:s.rows){
            node* aux=r;
            for(int j=0;j<s.m;j++){
                if(aux && j==aux->col){
                    os<<aux->key<<'\t';
                    aux=aux->next;
                }else os<<'0'<<'\t';
            }
            os<<endl;
        }
        return os;
    }
};