#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1001;

vector<int> adj[MAXN];
bool visited[MAXN];
vector<int> component;
vector<int> expertise;

void dfs(int u) {
    visited[u] = true;
    component.push_back(u);
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, c;
    cin >> n >> c;

    for (int i = 0; i < c; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1); 
        adj[v - 1].push_back(u - 1);
    }

    expertise.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> expertise[i];
    }

    memset(visited, false, sizeof(visited));
    
    int max_expertise = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            component.clear();
            dfs(i); 

            int component_expertise = 0;
            for (int emp : component) {
                component_expertise += expertise[emp];
            }

            max_expertise = max(max_expertise, component_expertise);
        }
    }

    cout << max_expertise << endl;

    return 0;
}
