#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
const int N = 1e4 + 5;

ll n, m;
ll sum(ll num) {
    return num * (num - 1) / 2;
}
ll sum(ll left, ll right) {
    return sum(right) - sum(left - 1);
}
signed main() {
    // input
    cin >> n >> m;
    // i, [i+1 - n]
    ll l = 1, r = n, res = 1;
    while (l <= r) {
        ll mid = (l+r)/2;
        ll cur = sum(mid, n);
        if (cur >= m) {
            res = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    ll cur = sum(res+1, n);
    cout << (n-res+1)  << ' ' << (n-res+1) +m-cur << '\n'; 
}