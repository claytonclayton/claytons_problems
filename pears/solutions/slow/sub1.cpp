
#include <iostream>

using namespace std;

int n, k;

// O(n^2) brute force solution.
// Enumerate all pairs and find the kth pair
int main() {
    cin >> n >> k;
    int t = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++, t++) {
            if (t == k) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
}