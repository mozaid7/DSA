#include <bits/stdc++.h>
using namespace std;

int main() {
    int S;
    cin >> S;
    vector<string> grid(S);
    for (int i = 0; i < S; i++) cin >> grid[i];

    int overlaps = 0;
    char topBand = 0;
    bool impossible = false;

    auto inside = [&](int x, int y) {
        return x >= 0 && x < S && y >= 0 && y < S;
    };

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            char c = grid[i][j];
            if (c == '1' || c == '2') {
                char other = (c == '1' ? '2' : '1');

                bool vertical = false, horizontal = false;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (!inside(ni, nj)) continue;
                    if (grid[ni][nj] == c) {
                        if (d < 2) vertical = true;
                        else horizontal = true;
                    }
                }
                bool otherV = false, otherH = false;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (!inside(ni, nj)) continue;
                    if (grid[ni][nj] == other) {
                        if (d < 2) otherV = true;
                        else otherH = true;
                    }
                }

                if ((vertical && otherH) || (horizontal && otherV)) {
                    overlaps++;
                    if (!topBand) topBand = c;
                    else if (topBand != c) impossible = true;
                }
            }
        }
    }

    if (impossible) cout << "Impossible\n";
    else cout << overlaps << "\n";

    return 0;
}
