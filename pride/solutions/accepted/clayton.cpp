
#include <iostream>

using namespace std;

const int N = 110;

int n, m;
int out[N];
int in[N];

string solve() {
    if (n != m+1) return "SLAY";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (++out[u] > 1 || ++in[v] > 1) 
            return "SLAY";
    }
    return "NAY";
}

int main() {
    cin >> n >> m;
    cout << solve() << endl;
}