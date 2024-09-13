#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

using ll = long long;

gp_hash_table<int, int> m;
ll csum[10005][10005];

int main() {

    std::ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<ll> arr, remap;

    for (int i = 0; i < n; i++) {
        ll temp; cin >> temp;
        arr.push_back(temp);
        remap.push_back(temp);
    }

    sort(remap.begin(), remap.end());
    remap.resize(unique(remap.begin(), remap.end()) - remap.begin());

    for (int i = 0; i < remap.size(); i++) {
        m[remap[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        csum[m[arr[i]]][i]++;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < remap.size(); j++) {
            csum[j][i] += csum[j][i + 1];
        }
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            ll sum = arr[i] * arr[j];
            if (m.find(sum) == m.end()) continue;
            ll remapped = m[sum];

            ans += csum[remapped][j + 1];
        }
    }

    cout << ans;
}