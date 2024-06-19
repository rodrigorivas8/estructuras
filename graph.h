#include "queue.h"
#include "stack.h"
#include "list.h"
#include "vector"

class graph{
    vector<vector<int>> list;
    vector<bool> flag;
    int nodes;

    void bfs(int i){
        auto q0=queue<int>(nodes);
        flag[i]=true;
        cout<<i<<endl;
        q0.enqueue(i);
        while(!q0.empty()){
            i=q0.dequeue();
            for(int j:list[i]){
                if(!flag[j]){
                    q0.enqueue(j);
                    flag[j]=true;
                    cout<<j<<endl;
                }
            }
        }
    };

    void dfs(int i){
        auto s0=stack<int>(nodes);
        flag[i]=true;
        s0.push(i);
        while(!s0.empty()){
            i=s0.pop();
            for(int j:list[i]){
                if(!flag[j])
                    s0.push(j);
                flag[j]=true;
            }
        }
    };

public:

    graph(const vector<vector<int>>& edges,int n){
        nodes=n;
        list.resize(n);

        for(auto p:edges)
            list[p[0]].push_back(p[1]);
    }

    void bfs(){
        for(auto f:flag) f=false;
        for(int i=0;i<nodes;i++)
            if(!flag[i]) bfs(i);
    };

    void dfs(){
        for(auto f:flag) f=false;
        for(int i=0;i<nodes;i++)
            if(!flag[i]) dfs(i);
    };

    void shortest_path(int a,int b){
        for(auto f:flag) f=false;

    }

};