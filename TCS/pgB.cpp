#include <bits/stdc++.h>
using namespace std;

int main() {
    int initial, n;
    cin >> initial >> n;
    int balance = initial;
    vector<pair<string,int>> transactions;
    vector<int> commitPoints;
    for (int i = 0; i < n; i++) {
        string op; cin >> op;
        if (op == "read") {
            cout << balance << "\n";
        } else if (op == "credit") {
            int x; cin >> x;
            balance += x;
            transactions.push_back({"credit", x});
        } else if (op == "debit") {
            int x; cin >> x;
            balance -= x;
            transactions.push_back({"debit", x});
        } else if (op == "abort") {
            int x; cin >> x;
            if (x <= (int)transactions.size()) {
                int idx = x-1;
                if (transactions[idx].first != "committed") {
                    if (transactions[idx].first == "credit") balance -= transactions[idx].second;
                    else balance += transactions[idx].second;
                    transactions[idx].first = "aborted";
                }
            }
        } else if (op == "commit") {
            commitPoints.push_back(balance);
            for (auto &t : transactions)
                if (t.first == "credit" || t.first == "debit")
                    t.first = "committed";
        } else if (op == "rollback") {
            int x; cin >> x;
            if (x <= (int)commitPoints.size()) {
                balance = commitPoints[x-1];
                transactions.clear();
                commitPoints.resize(x);
            }
        }
    }
    return 0;
}
