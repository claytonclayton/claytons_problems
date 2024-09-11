
#include <iostream>
#include <vector>

using namespace std;

string x, y;

int main() {
    cin >> x >> y;
    cin >> x >> y;
    int n = x.size();
    int m = y.size();

    int i = 0;
    for (; i < n; i++) {
        if (y[i] != x[i]) break;
    }

    int j = 1;
    for (; j <= n; j++) {
        if (y[m - j] != x[n - j] || n - j < i) break;
    }
    j--;

    if (i < n - j) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    // for (int k = i; k <= m - j; k++) {
    //     cout << y[k];
    // }
    // cout << endl;
}