#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool isValidSudoku(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        set<int> rowSet, colSet;
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] != 0 && !rowSet.insert(grid[i][j]).second) {
                return false;
            }
            if (grid[j][i] != 0 && !colSet.insert(grid[j][i]).second) {
                return false;
            }
        }
    }

    for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            set<int> boxSet;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = grid[row + i][col + j];
                    if (num != 0 && !boxSet.insert(num).second) {
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}

int main() {
    int grid[9][9];
    vector<pair<int, int>> errors;
    vector<int> hintList;
    int K;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> grid[i][j];
        }
    }

    int hintLen;
    cin >> hintLen;
    hintList.resize(hintLen);
    for (int i = 0; i < hintLen; i++) {
        cin >> hintList[i];
    }

    cin >> K;

    if (!isValidSudoku(grid)) {
        cout << "Impossible" << endl;
    } else {
        if (errors.size() == 0) {
            cout << "Won" << endl;
        } else if (static_cast<int>(errors.size()) <= K) {  // Cast size to int for comparison
            for (auto& err : errors) {
                cout << err.first << " " << err.second << endl;
            }
        } else {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}
