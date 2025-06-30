#include <bits/stdc++.h>
using namespace std;

// BFS
vector<int> bfs(vector<vector<int>> &adj) {
    int v = adj.size();
    vector<int> ans;
    queue<int> q;
    bool visited[v] = {false};
    visited[0] = true;
    q.push(0);
    
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        
        for(auto el: adj[u]){
            if(!visited[el]){
                q.push(el);
                visited[el] = true;
            }
        }
    }
    return ans;
}

// Number Of Islands
void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid){
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});
    vector<pair<int, int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    while(!q.empty()){
        int r = grid.size();
        int c = grid[0].size();
        auto [x,y] = q.front();
        q.pop();

        for(auto [dx,dy] : dir){
            int nx = x+dx, ny = y+dy;
            if(nx >= 0 && ny >= 0 && nx < r && ny < c && grid[nx][ny] == '1' && !vis[nx][ny]){
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    int cnt = 0;
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            if(!vis[row][col] && grid[row][col] == '1'){
                cnt++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return cnt;
}

// Undirected Graph Cycle Detection using BFS
bool detect(int src, vector<vector<int>>& adj, vector<int>& vis) {
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push({it, node});
            } else if (it != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    // converting edges to adjacency list
    vector<vector<int>> adj(V);
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        if (u == v) return true; // self-loop check
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (detect(i, adj, vis)) return true;
        }
    }
    return false;
}

// Topo Sort / Kahn's Algorithm BFS
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
    }
    
    int indegree[V] = {0};
    for(int i =0; i<V; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0; i<V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
    
}

// Directed Graph Cycle
bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
    }
    
    int indegree[V] = {0};
    for(int i =0; i<V; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0; i<V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    if(cnt == V) return false;
    return true;
}

// Course Schedule 1
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for(auto it: prerequisites){
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
    }

    vector<int> indegree(numCourses, 0);
    for(int i =0; i<numCourses; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0; i<numCourses; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    if(topo.size() == numCourses) return true;
    return false;
}

// Course Schedule 2
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for(auto it: prerequisites){
        int u = it[1];
        int v = it[0];
        adj[u].push_back(v);
    }

    vector<int> indegree(numCourses, 0);
    for(int i =0; i<numCourses; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0; i<numCourses; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    if(topo.size() == numCourses) return topo;
    return {};
}