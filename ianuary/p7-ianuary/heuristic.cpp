
#include <iostream>
#include <cmath>
#include <tuple>
#include <queue>
#include <unordered_map>

using namespace std;

class state {
public:
    state() {}
    state(int size, int super, int elem, int prev) : size(size), super(super), elem(elem), prev(prev) {}
    int size = 0;
    int super = 0;
    int elem = -1;
    int prev = -1;
};

const int INT_MAX = 1'000'000'000;
const int N = 10'010;

int nc2[N];
state dp[N];

int n, m;

int quadratic(int a, int b, int c) {
    return (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    // return (1 + sqrt(1 + 8 * m)) / 2;
}

void build_tables(int m = N) {
    int mless = quadratic(1, -1, -2 * m);

    nc2[2] = 1;
    for (int i = 3; i <= mless; i++) {
        nc2[i] = nc2[i - 1] + i - 1;
    }

    for (int i = 1; i < m; i++) {
        state next(INT_MAX, INT_MAX, 0, 0);
        for (int j = 2; j <= mless; j++) {
            if (i - nc2[j] < 0) break;
            state curr = dp[i - nc2[j]];
            if (curr.size < next.size || 
               (curr.size == next.size && 
                max(curr.super, nc2[j]) < next.super)) {
                next = state(curr.size, max(curr.super, nc2[j]), nc2[j], i - nc2[j]);
            }
        }
        next.size++;
        dp[i] = next;
    }
}

void solve(int n, int m) {
    int mless = quadratic(1, -1, -2 * m);

    int index = 0, size = INT_MAX;
    for (int i = 2; i <= mless; i++) {

        state curr = dp[m - nc2[i]];
        if (curr.super > nc2[i]) continue;
        if (curr.size + i + 1 < size) {
            index = i;
            size = curr.size + i + 1;
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(nc2[index]);
    int curr = m - nc2[index];
    while (curr > 0) {
        pq.push(dp[curr].elem);
        curr = dp[curr].prev;
    }

    // if (m < 10) cout << ' ';
    // cout << m << ": ";

    int i = 2;
    cout << "22";
    while (!pq.empty()) {
        if (pq.top() <= nc2[i]) {
            cout << '4';
            pq.pop();
        } else {
            cout << '2';
            i++;
        }
    }
    cout << ":" << size;
    cout << endl;
}

void print_dp(int m) {
    int curr = m;
    while (curr > 0) {
        cout << dp[curr].elem << endl;
        curr = dp[curr].prev;
    }
}

int main() {
    build_tables();

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        solve(n, m);
    }
}
