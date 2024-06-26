#include <vector>
#include <algorithm>
using namespace std;

#define inf 1.7976931348623157e+308
#define min(w) min_element(w.begin(),w.end());

class graph_dp{
    vector<vector<pair<double,int>>> list;
    int n;

public:

    vector<double> dijkstra(int i){
        vector<pair<double,int>> w(n,{inf,0});
        for(int k=0;k<n;k++) w[k].first=k;
        for(auto p:list[i]) w[p.second]=p;
        w.erase(w.begin()+i);
        vector<double> d(n,0);
        for(int k=0;k<n;k++){
            auto m=min(w);
            w.erase(m);
            int j=m->second;
            d[j]=m->first;
            for(auto q:list[j]){
                auto y=q.first+d[j];
                if(y>d[q.second])
                    d[q.second]=y;
            }
        }
        return d;
    }

    vector<vector<double>> floyd_warshall(){
        vector<vector<double>> d(n,vector<double>(n,inf));
        for(int i=0;i<n;i++) d[i][i]=0;
        for(int i=0;i<n;i++){}

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){

                }
            }
        }
        return d;
    }

    vector<double> bellman_ford(){

    }
};