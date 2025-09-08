#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double polygonArea(vector<Point>& poly) {
    int n = poly.size();
    double area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += poly[i].x * poly[j].y - poly[j].x * poly[i].y;
    }
    return fabs(area) / 2.0;
}

double distance(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main() {
    int N; 
    cin >> N;
    vector<pair<Point, Point>> sticks(N);
    for (int i = 0; i < N; i++) {
        cin >> sticks[i].first.x >> sticks[i].first.y 
            >> sticks[i].second.x >> sticks[i].second.y;
    }

    // Step 1: Build adjacency map
    map<pair<double,double>, vector<pair<double,double>>> adj;
    for (auto& s : sticks) {
        adj[{s.first.x, s.first.y}].push_back({s.second.x, s.second.y});
        adj[{s.second.x, s.second.y}].push_back({s.first.x, s.first.y});
    }

    // Step 2: Try to find a cycle (polygon)
    set<pair<double,double>> visited;
    vector<Point> poly;
    function<bool(pair<double,double>, pair<double,double>)> dfs = [&](auto u, auto parent) {
        if (visited.count(u)) return false;
        visited.insert(u);
        poly.push_back({u.first, u.second});
        for (auto v : adj[u]) {
            if (v == parent) continue;
            if (!visited.count(v)) {
                if (dfs(v, u)) return true;
            } else {
                poly.push_back({v.first, v.second}); // cycle found
                return true;
            }
        }
        poly.pop_back();
        return false;
    };

    bool found = false;
    for (auto& [u, neigh] : adj) {
        if (!visited.count(u)) {
            if (dfs(u, {-1,-1})) {
                found = true;
                break;
            }
        }
    }

    if (!found || poly.size() < 3) {
        cout << "No\n";
        return 0;
    }

    // Step 3: Compute area using shoelace
    double area = polygonArea(poly);

    // Step 4: Check Arjun's possibility
    double polygonPerimeter = 0;
    for (int i = 0; i < (int)poly.size()-1; i++) {
        polygonPerimeter += distance(poly[i], poly[i+1]);
    }

    double totalStickLength = 0;
    for (auto& s : sticks) {
        totalStickLength += distance(s.first, s.second);
    }

    double leftover = totalStickLength - polygonPerimeter;
    cout << "Yes\n";
    if (leftover + 1e-6 >= polygonPerimeter) cout << "Yes\n";
    else cout << "No\n";
    cout << fixed << setprecision(2) << area << "\n";

    return 0;
}
