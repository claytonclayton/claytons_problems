
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 10'010;

int n;
ll a[N];

int main() {
    cin >> n;

    if (n > 1000) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll sol = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                sol += a[i] * a[j] == a[k];
            }
        }
    }

    cout << sol << endl;
}
