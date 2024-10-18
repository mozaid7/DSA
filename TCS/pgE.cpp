#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double calculateHeight(double x, const vector<int>& A, const vector<int>& B) {
    double height = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        height += A[i] * sin(B[i] * x);
    }
    return height;
}

vector<double> findPeaks(int n, const vector<int>& A, const vector<int>& B) {
    vector<double> peaks;
    const double pi = 3.141592653589793;
    const double step = pi / 500.0;
    
    for (double x = 0; x <= 2 * pi; x += step) {
        double currentHeight = calculateHeight(x, A, B);
        double prevHeight = calculateHeight(x - step, A, B);
        double nextHeight = calculateHeight(x + step, A, B);
        
        if (currentHeight > prevHeight && currentHeight > nextHeight) {
            peaks.push_back(x);
        }
    }
    return peaks;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> A(n), B(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    
    vector<double> peaks = findPeaks(n, A, B);
    
    if (peaks.size() < 2) {
        cout << "0.0000" << endl;
        return 0;
    }
    
    double maxValleyWidth = 0;
    int valleyIndex = 0;
    
    for (size_t i = 1; i < peaks.size(); ++i) {
        double valleyWidth = peaks[i] - peaks[i - 1];
        
        if (valleyWidth > maxValleyWidth) {
            maxValleyWidth = valleyWidth;
            valleyIndex = i - 1;
        }
    }
    
    cout << fixed << setprecision(4) << valleyIndex + 1 << endl;
    
    return 0;
}
