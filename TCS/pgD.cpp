#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int M;
    if(!(cin>>M)) return 0;
    vector<vector<long long>> w(M, vector<long long>(M));
    for(int i=0;i<M;i++) for(int j=0;j<M;j++) cin>>w[i][j];
    vector<long long> people(M,0);
    for(int i=1;i<M;i++) cin>>people[i];
    long long C; cin>>C;
    const long long INF = 9e18;
    vector<long long> dist(M, INF);
    dist[0]=0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d!=dist[u]) continue;
        for(int v=0;v<M;v++){
            if(u==v) continue;
            long long nd = d + w[u][v];
            if(nd < dist[v]){
                dist[v]=nd;
                pq.push({nd,v});
            }
        }
    }
    vector<int> parent(M,-1);
    for(int u=1;u<M;u++){
        for(int v=0;v<M;v++){
            if(v==u) continue;
            if(dist[v] + w[v][u] == dist[u]){
                parent[u]=v;
                break;
            }
        }
    }
    vector<vector<int>> children(M);
    for(int i=1;i<M;i++){
        if(parent[i]==-1){ cout<<"Impossible\n"; return 0; }
        children[parent[i]].push_back(i);
    }
    function<long long(int)> dfs = [&](int u)->long long{
        long long s = people[u];
        for(int v: children[u]) s += dfs(v);
        return s;
    };
    long long ans = 0;
    for(int v: children[0]){
        long long s = dfs(v);
        ans += (s + C - 1) / C;
    }
    cout<<ans<<"\n";
    return 0;
}
