#include <bits/stdc++.h>
using namespace std;

// Array Reconstruction
int numOfArrays(int n, int m, int k) {
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));

    for (int j = 1; j <= m; j++) {
        dp[1][j][1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int c = 1; c <= k; c++) {
                long long sameMax = (1LL * dp[i-1][j][c] * j) % MOD;
                dp[i][j][c] = (dp[i][j][c] + sameMax) % MOD;

                long long newMax = 0;
                for (int p = 1; p < j; p++) {
                    newMax = (newMax + dp[i-1][p][c-1]) % MOD;
                }
                dp[i][j][c] = (dp[i][j][c] + newMax) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int j = 1; j <= m; j++) {
        ans = (ans + dp[n][j][k]) % MOD;
    }
    return ans;
}

// Ancestor Subset
const int MAXN = 100005;
vector<int> adj[MAXN];
long long dp[MAXN][2];
int wt[MAXN];

void dfs(int node, int parent) {
    dp[node][1] = wt[node];
    dp[node][0] = 0;        

    for (int child : adj[node]) {
        if (child == parent) continue;
        dfs(child, node);

        dp[node][0] += max(dp[child][0], dp[child][1]);

        dp[node][1] += dp[child][0];
    }
}

long long findMaximumSum(int tree_nodes, vector<int>& tree_from, vector<int>& tree_to, vector<int>& weight) {
    for (int i = 0; i < tree_nodes; i++) {
        adj[i].clear();
        dp[i][0] = dp[i][1] = 0;
    }

    for (int i = 0; i < (int)tree_from.size(); i++) {
        int u = tree_from[i] - 1;
        int v = tree_to[i] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < tree_nodes; i++) {
        wt[i] = weight[i];
    }

    dfs(0, -1);

    return max(dp[0][0], dp[0][1]);
}

// Maximum Sum Increasing Sub-Sequence
int maximizeScore(vector<int>& arr, int k) {
    priority_queue<int> pq;
    for (int num : arr) pq.push(num);

    int score = 0;

    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();

        if (x <= 0) continue;

        int divideGain = (x + 2) / 3; // ceil(x/3)

        if (k >= divideGain) {
            // Subtract operation
            score += k;
            x -= k;
        } else {
            // Divide operation
            score += divideGain;
            x = (x + 2) / 3;
        }

        if (x > 0) pq.push(x);
    }

    return score;
}

// IPv4 Validation
bool isValidPart(const string &s) {
    if (s.empty() || (s.size() > 1 && s[0] == '0')) return false;
    if (!all_of(s.begin(), s.end(), ::isdigit)) return false;
    int num = stoi(s);
    return (num >= 0 && num <= 255);
}

vector<string> checkIPRegion(string ip) {
    vector<string> result;
    vector<string> parts;
    stringstream ss(ip);
    string part;

    while (getline(ss, part, '.')) parts.push_back(part);

    if (parts.size() != 4 || 
        !all_of(parts.begin(), parts.end(), [&](string &p){ return isValidPart(p); })) {
        result.push_back("Not Valid");
        return result;
    }

    int firstOctet = stoi(parts[0]);

    if (firstOctet <= 127) result.push_back("Region 1");
    else if (firstOctet <= 191) result.push_back("Region 2");
    else if (firstOctet <= 223) result.push_back("Region 3");
    else if (firstOctet <= 239) result.push_back("Region 4");
    else result.push_back("Not Valid"); // Region 5 not allowed

    return result;
}