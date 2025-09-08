#include <bits/stdc++.h>
using namespace std;

int main() {
    string timeStr;
    cin >> timeStr;
    int h = stoi(timeStr.substr(0, timeStr.find(':')));
    int m = stoi(timeStr.substr(timeStr.find(':') + 1));

    int Q; cin >> Q;
    int A, B, X, Y;
    cin >> A >> B >> X >> Y;

    // Initial positions in degrees
    int hourPos = (h % 12) * 30;     // only hours
    int minPos  = m * 6;             // exact minute position

    auto angleBetween = [&](int hA, int mA) {
        int diff = abs(hA - mA);
        return min(diff, 360 - diff);
    };

    long long totalCost = 0;

    while (Q--) {
        int target; cin >> target;
        int curr = angleBetween(hourPos, minPos);

        // Candidate target angles: target or 360 - target
        vector<int> candidates = {target, 360 - target};
        long long best = LLONG_MAX;

        for (int tgt : candidates) {
            int need = abs(curr - tgt);
            if (need == 0) { best = 0; break; }

            // Option 1: Move hour clockwise & minute anticlockwise
            best = min(best, 1LL * need * (A * X + B * Y));

            // Option 2: Move hour anticlockwise & minute clockwise
            best = min(best, 1LL * need * (B * X + A * Y));
        }
        totalCost += best;
    }

    cout << totalCost << "\n";
    return 0;
}
