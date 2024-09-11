/**
 * Solution for tentactle
 * time complexity: O(N^3)
 * should pass subtasks 1 and 2.
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 200'005;
int nums[N];

int n, k, val = 1, inversionCount;

int getInversionCount(int l, int r) {
    int inversionCount = 0;
    for (int i = l; i <= r; i++)
    for (int j = i+1; j <= r; j++) {
        if (nums[i] > nums[j]) {
            inversionCount++;
        }
    }
    return inversionCount;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    int ans = 0;
    for (int l = 1, r = 1; r <= n; r++) {
        while (getInversionCount(l, r) > k) l++;
        ans = max(ans, r-l+1);
    }
    cout << n-ans << "\n";
}