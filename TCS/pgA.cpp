#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<tuple<int, int>> getDirections(const pair<int, int>& moveRule) {
    vector<tuple<int, int>> directions;

    directions.push_back({moveRule.first, moveRule.second});

    directions.push_back({moveRule.second, -moveRule.first});

    directions.push_back({-moveRule.second, moveRule.first});

    directions.push_back({-moveRule.first, -moveRule.second});

    return directions;
}

int minimumMoves(vector<vector<int>>& grid, pair<int, int> source, pair<int, int> destination, pair<int, int> moveRule) {
    int M = grid.size();
    int N = grid[0].size();
    
    queue<pair<int, int>> q;
    q.push(source);

    vector<vector<int>> dist(M, vector<int>(N, -1));
    dist[source.first][source.second] = 0;

    auto directions = getDirections(moveRule);

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int newX = x + dx;
            int newY = y + dy;

            if (newX >= 0 && newX < M && newY >= 0 && newY < N && grid[newX][newY] == 0) {
                if (dist[newX][newY] == -1) { 
                    dist[newX][newY] = dist[x][y] + 1; 
                    q.push({newX, newY}); 
                }
            }
        }
    }

    return dist[destination.first][destination.second];
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> grid(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    pair<int, int> source, destination, moveRule;
    cin >> source.first >> source.second;
    cin >> destination.first >> destination.second;
    cin >> moveRule.first >> moveRule.second;

    int result = minimumMoves(grid, source, destination, moveRule);
    
    if (result == -1) {
        cout << "Impossible" << endl; 
    } else {
        cout << result << endl; 
    }

    return 0;
}
