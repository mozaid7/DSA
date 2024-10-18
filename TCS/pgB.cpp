#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool checkSubstring(const string& src, const string& X, int i, int len) {
    if (static_cast<std::string::size_type>(i + len) > X.size()) return false;
    return X.substr(i, len) == src.substr(0, len);
}

int main() {
    string X, Y;
    int S, R;
    cin >> X >> Y;
    cin >> S >> R;
    int n = X.size();
    int m = Y.size();
    string revY = Y;
    reverse(revY.begin(), revY.end());

    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;


    for (int i = 0; i < n; ++i) {
        for (int len = 1; len <= m && i + len <= n; ++len) {
            if (checkSubstring(Y, X, i, len)) {
                dp[i + len] = min(dp[i + len], dp[i] + S);
            }
            if (checkSubstring(revY, X, i, len)) {
                dp[i + len] = min(dp[i + len], dp[i] + R);
            }
        }
    }
    if (dp[n] == 1e9) {
        cout << "Impossible" << endl;
    } else {
        cout << dp[n] << endl;
    }

    return 0;
}