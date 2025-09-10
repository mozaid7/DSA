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
        if (!vis[i]) {  // condition if there are disconnected components in Graph
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

// Word Ladder
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string,int>> q;
    q.push({beginWord,1});
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord);

    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word == endWord) return steps;

        for(int i=0; i<word.size(); i++){
            char original = word[i];
            for(char ch = 'a' ; ch <= 'z'; ch++){
                word[i] = ch;
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

// Dijkstra Algorithm
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    vector<vector<pair<int,int>>> adj(V);
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V, 1e9);
    
    dist[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto it: adj[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;
            
            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

// Prim's Algorithm
int spanningTree(int V, vector<vector<int>>& edges) {
    // Build adjacency list
    vector<vector<pair<int,int>>> adj(V);
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }
    
    // Min-heap {weight, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> vis(V, 0);
    
    pq.push({0, 0}); // {weight, startNode}
    int sum = 0;
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;
        
        if(vis[node]) continue;
        
        vis[node] = 1;
        sum += wt;
        
        for(auto el : adj[node]){
            int adjNode = el.first;
            int edW = el.second;
            
            if(!vis[adjNode]){
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}

// Distance to Nearest 1
vector<vector<int>> nearest(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> vis(n, vector<int>(m,0));
    vector<vector<int>> dist(n, vector<int>(m,0));
    queue<pair<pair<int, int>, int>> q;
    vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }
    
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;
        
        for(auto &d : dir) {
            int nx = row + d.first;
            int ny = col + d.second;
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({{nx, ny}, steps + 1});
            }
        }
        
    }
    return dist;
}

// Alien Dictionary
string findOrder(vector<string> &words) {
    int N = words.size();

    unordered_set<char> chars;
    for (auto &w : words) {
        for (auto c : w) chars.insert(c);
    }

    int K = chars.size(); 
    vector<int> adj[26];  

    for (int i = 0; i < N - 1; i++) {
        string s1 = words[i];
        string s2 = words[i + 1];
        int len = min(s1.size(), s2.size());
        for (int ptr = 0; ptr < len; ptr++) {
            if (s1[ptr] != s2[ptr]) {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    vector<int> topo = topoSort(26, adj); // use topo sort function here.

    // Step 4: Build answer string (only for characters present in dict)
    string ans = "";
    unordered_set<char> present(chars.begin(), chars.end());
    for (auto it : topo) {
        char c = char(it + 'a');
        if (present.count(c)) ans += c; // if char is present in set then only include in ans.
    }

    return ans;
}

// Cheapest flight within K
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);
    
    for(auto &it : flights){
        adj[it[0]].push_back({it[1], it[2]});
    }

    queue<pair<int, pair<int,int>>> q;
    q.push({0, {src, 0}}); // {stops, {node, cost}}

    vector<int> dist(n, 1e9);
    dist[src] = 0;

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if(stops > k) continue;

        for(auto iter : adj[node]){
            int adjNode = iter.first;
            int edW = iter.second;

            if(cost + edW < dist[adjNode]){
                dist[adjNode] = cost + edW;
                q.push({stops + 1, {adjNode, cost + edW}});
            }
        }
    }

    return (dist[dst] == 1e9) ? -1 : dist[dst];
}

// Number Of Provinces
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, adj, vis);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<vector<int>> adj(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(isConnected[i][j] == 1 && i != j) {
                adj[i].push_back(j);
            }
        }
    }

    vector<int> vis(n, 0);
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            cnt++;
            dfs(i, adj, vis);
        }
    }
    return cnt;
}

//  Number of Ways to arrive at a destination
int countPaths(int n, vector<vector<int>>& roads) {
    // adjacency list: node -> {neighbor, weight}
    vector<vector<pair<int,long long>>> adj(n);
    for(auto &it : roads){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    using P = pair<long long,int>; // {distance, node}
    priority_queue<P, vector<P>, greater<P>> pq;

    vector<long long> dis(n, 1e18); // store shortest distances
    vector<int> ways(n, 0);        // store number of shortest paths
    dis[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});

    int mod = 1e9 + 7;

    while(!pq.empty()){
        auto [dist, node] = pq.top();
        pq.pop();

        if(dist > dis[node]) continue; // stale entry, skip

        for(auto &it : adj[node]){
            int adjN = it.first;
            long long edW = it.second;

            // Found a strictly shorter path
            if(dist + edW < dis[adjN]){
                dis[adjN] = dist + edW;
                pq.push({dis[adjN], adjN});
                ways[adjN] = ways[node];
            } 
            // Found another shortest path
            else if(dist + edW == dis[adjN]) {
                ways[adjN] = (ways[adjN] + ways[node]) % mod;
            }
        }
    }
    return ways[n-1] % mod;
}

// Bi-Partite Graph
bool bfs(int node, vector<int> &color, vector<vector<int>> &adj){
    queue<int> q;
    q.push(node);
    color[node] = 0;

    while(!q.empty()){
        int top = q.front();
        q.pop();

        for(auto it : adj[top]){
            if(color[it] == -1){
                color[it] = !color[top];
                q.push(it);
            } else if(color[it] == color[top]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);

    for(int i=0; i<n; i++){
        if(color[i] == -1){
            color[i] = 0;
            if(!bfs(i, color, graph)) return false;
        }
    }
    return true;
}

// Flood Fill Algo
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();
    int oldColor = image[sr][sc];

    if(oldColor == color) return image;

    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = color;

    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    while(!q.empty()){
        auto [x,y] = q.front(); // coordinates of sr and sc
        q.pop();

        for(auto [dx,dy] : dirs){
            int nx = x+dx, ny = y+dy;
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && image[nx][ny] == oldColor){
                image[nx][ny] = color;
                q.push({nx, ny});
            }
        }
    }
    return image;
}