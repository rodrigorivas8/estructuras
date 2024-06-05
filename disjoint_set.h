using namespace std;

class disjoint_set{
    int len;
    int* par;
    int* rank;
    int sets=0;
public:
    disjoint_set(){
        len=1e5;
        par=new int[len]();
        rank=new int[len]();
    }

    explicit disjoint_set(int n):len(n){
        par=new int[n]();
        rank=new int[n]();
    };

    void make(int n){
        if(par[n]) return;
        par[n]=n;
        rank[n]=0;
        sets++;
    }

    int find(int n){
        if(par[n]!=n)
            par[n]=find(par[n]);
        return par[n];
    }

    void join(int n,int m){
        n=find(n),
        m=find(m);
        if(rank[n]==rank[m])
            rank[n]++;
        if(rank[n]>rank[m])
            par[m]=n;
        else par[n]=m;
        sets--;
    }
    int count(){return sets;}
};