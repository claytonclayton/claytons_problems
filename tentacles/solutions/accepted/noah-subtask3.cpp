/**
 * Solution for tentactle
 * time complexity: O(N^2)
 * should pass subtasks 1, 2, and 3.
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 200'005;
int nums[N];

int n, k, val = 1, inversionCount;

void add(int l, int r, int id) {
    int numberCount = 0;
    for (int i = l; i <= r; i++) 
        numberCount += (nums[i] > nums[id]);
    
    inversionCount += numberCount;
}
void remove(int l, int r, int id) {
    int numberCount = 0;
    for (int i = l; i <= r; i++) 
        numberCount += (nums[i] < nums[id]);
    
    inversionCount -= numberCount;
}

int main() {
    cin >> n >> k;
    set <int> vals;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        vals.insert(nums[i]);
    }
    map <int, int> compressedValue;
    for (auto& x : vals) compressedValue[x] = val++;

    for (int i = 1; i <= n; i++) nums[i] = compressedValue[nums[i]];
    int ans = 0;
    for (int l = 1, r = 1; r <= n; r++) {
        add(l, r, r);
        while (inversionCount > k) remove(l, r, l++);
        ans = max(ans, r-l+1);
    }
    cout << n-ans << "\n";
}