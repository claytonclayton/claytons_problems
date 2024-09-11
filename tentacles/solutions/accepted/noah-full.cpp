/**
 * Solution for tentactle
 * time complexity: O(NlogN)
 * should pass all test cases
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 200'005;
const int M = 4*N;
int nums[N];
long long node[M];

void update(int l, int r, int id, int val, int head) {
    if (l == r) {
        node[head] += val;
        return;
    }
    int mid = (l+r) / 2;
    if (id <= mid) 
        update(l, mid, id, val, head*2+1);
    else 
        update(mid+1, r, id, val, head*2+2);
    node[head] = node[head*2+1] + node[head*2+2];
}

int query(int l, int r, int L, int R, int head) {
    if (l > R || r < L || L > R) return 0;
    if (L <= l && r <= R) return node[head];
    int mid = (l+r)/2;
    return (
        query(l, mid, L, R, head*2+1) + 
        query(mid+1, r, L, R, head*2+2)
    );
}


int n, k, compressHelper = 1, inversionCount;

void add(int id) {
    int numberCount = query(1, compressHelper, nums[id]+1, compressHelper, 0);
    inversionCount += numberCount;
    update(1, compressHelper, nums[id], 1, 0);
}
void remove(int id) {
    int numberCount = query(1, compressHelper, 1, nums[id]-1, 0);
    inversionCount -= numberCount;
    update(1, compressHelper, nums[id], -1, 0);
}

int main() {
    cin >> n >> k;
    set <int> vals;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        vals.insert(nums[i]);
    }
    map <int, int> compressedValue;
    for (auto& x : vals) compressedValue[x] = compressHelper++;

    for (int i = 1; i <= n; i++) nums[i] = compressedValue[nums[i]];
    int ans = 0;
    for (int l = 1, r = 1; r <= n; r++) {
        add(r);
        while (inversionCount > k) remove(l++);
        ans = max(ans, r-l+1);
    }
    cout << n-ans << "\n";
}