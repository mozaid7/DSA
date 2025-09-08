#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

struct State {
    pair<int, int> pos1, pos2;
    int steps;
};

pair<pair<int, int>, pair<int, int>> normalize(pair<int, int> p1, pair<int, int> p2) {
    if (p1 > p2) swap(p1, p2);
    return {p1, p2};
}

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<vector<char>> grid(m, vector<char>(n));
    vector<pair<int, int>> sofa_cells, target_cells;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 's') {
                sofa_cells.push_back({i, j});
            } else if (grid[i][j] == 'S') {
                target_cells.push_back({i, j});
            }
        }
    }
    
    if (sofa_cells.size() != 2 || target_cells.size() != 2) {
        cout << "Impossible" << endl;
        return 0;
    }
    
    auto initial = normalize(sofa_cells[0], sofa_cells[1]);
    auto target = normalize(target_cells[0], target_cells[1]);
    
    if (initial == target) {
        cout << 0 << endl;
        return 0;
    }
    
    auto is_valid = [&](int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    };
    
    auto is_free = [&](int r, int c) {
        return is_valid(r, c) && (grid[r][c] == '0' || grid[r][c] == 'S');
    };
    
    queue<State> q;
    set<pair<pair<int, int>, pair<int, int>>> visited;
    
    q.push({initial.first, initial.second, 0});
    visited.insert(initial);
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    while (!q.empty()) {
        State current = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            pair<int, int> new_pos1 = {current.pos1.first + dx[i], current.pos1.second + dy[i]};
            pair<int, int> new_pos2 = {current.pos2.first + dx[i], current.pos2.second + dy[i]};
            
            if (is_free(new_pos1.first, new_pos1.second) && is_free(new_pos2.first, new_pos2.second)) {
                auto next_state = normalize(new_pos1, new_pos2);
                
                if (next_state == target) {
                    cout << current.steps + 1 << endl;
                    return 0;
                }
                
                if (visited.find(next_state) == visited.end()) {
                    visited.insert(next_state);
                    q.push({next_state.first, next_state.second, current.steps + 1});
                }
            }
        }
        
        bool is_horizontal = (current.pos1.first == current.pos2.first);
        
        if (is_horizontal) {
            int r = current.pos1.first;
            int c = min(current.pos1.second, current.pos2.second);
            
            if (is_free(r, c) && is_free(r, c+1) && is_free(r+1, c) && is_free(r+1, c+1)) {
                vector<pair<pair<int, int>, pair<int, int>>> rotations = {
                    normalize({r, c}, {r+1, c}),
                    normalize({r, c+1}, {r+1, c+1})
                };
                
                for (auto& next_state : rotations) {
                    if (next_state == target) {
                        cout << current.steps + 1 << endl;
                        return 0;
                    }
                    if (visited.find(next_state) == visited.end()) {
                        visited.insert(next_state);
                        q.push({next_state.first, next_state.second, current.steps + 1});
                    }
                }
            }
            
            if (is_free(r, c) && is_free(r, c+1) && is_free(r-1, c) && is_free(r-1, c+1)) {
                vector<pair<pair<int, int>, pair<int, int>>> rotations = {
                    normalize({r-1, c}, {r, c}),
                    normalize({r-1, c+1}, {r, c+1})
                };
                
                for (auto& next_state : rotations) {
                    if (next_state == target) {
                        cout << current.steps + 1 << endl;
                        return 0;
                    }
                    if (visited.find(next_state) == visited.end()) {
                        visited.insert(next_state);
                        q.push({next_state.first, next_state.second, current.steps + 1});
                    }
                }
            }
        } else {
            int r = min(current.pos1.first, current.pos2.first);
            int c = current.pos1.second;
            
            if (is_free(r, c) && is_free(r+1, c) && is_free(r, c+1) && is_free(r+1, c+1)) {
                vector<pair<pair<int, int>, pair<int, int>>> rotations = {
                    normalize({r, c}, {r, c+1}),
                    normalize({r+1, c}, {r+1, c+1})
                };
                
                for (auto& next_state : rotations) {
                    if (next_state == target) {
                        cout << current.steps + 1 << endl;
                        return 0;
                    }
                    if (visited.find(next_state) == visited.end()) {
                        visited.insert(next_state);
                        q.push({next_state.first, next_state.second, current.steps + 1});
                    }
                }
            }
            
            if (is_free(r, c) && is_free(r+1, c) && is_free(r, c-1) && is_free(r+1, c-1)) {
                vector<pair<pair<int, int>, pair<int, int>>> rotations = {
                    normalize({r, c-1}, {r, c}),
                    normalize({r+1, c-1}, {r+1, c})
                };
                
                for (auto& next_state : rotations) {
                    if (next_state == target) {
                        cout << current.steps + 1 << endl;
                        return 0;
                    }
                    if (visited.find(next_state) == visited.end()) {
                        visited.insert(next_state);
                        q.push({next_state.first, next_state.second, current.steps + 1});
                    }
                }
            }
        }
    }
    
    cout << "Impossible" << endl;
    return 0;
}