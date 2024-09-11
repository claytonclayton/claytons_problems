/**
 * Solution for tentactle
 * time complexity: O(N^4)
 * should pass subtasks 1
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 200'005;
int n, k;
int nums[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    int ans = 0;
    for (int l = 1; l <= n; l++)
    for (int r = l+1; r <= n; r++) {
        int inversionCount = 0;
        for (int i = l; i <= r; i++)
        for (int j = i+1; j <= r; j++) {
            if (nums[i] > nums[j]) {
                inversionCount++;
            }
        }
        if (inversionCount <= k) ans = max(ans, r-l+1);
    }
    cout << n-ans << "\n";
}