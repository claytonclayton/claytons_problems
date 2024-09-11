#include <bits/stdc++.h>
using namespace std;

int R, C, v[1505][1505], h[1505][1505];
vector<string> ans;

bool u(bool mountain) {
    if (R == 1) return false;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C-1; j++) {
            if (v[i][j] == v[R-i+1][j]) return false;
        }
    }
    for (int i = 1; i <= R-1; i++) {
        for (int j = 1; j <= C; j++) {
            if (i == R-i) {
                if (h[i][j] != mountain) return false;
            } else {
                if (h[i][j] == h[R-i][j]) return false;
            }
        }
    }
    ans.push_back(mountain ? "UM" : "UV");
    R /= 2;
    return true;
}

bool l(bool mountain) {
    if (C == 1) return false;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C-1; j++) {
            if (j == C-j) {
                if (v[i][j] != mountain) return false;
            } else {
                if (v[i][j] == v[i][C-j]) return false;
            }
        }
    }
    for (int i = 1; i <= R-1; i++) {
        for (int j = 1; j <= C; j++) {
            if (h[i][j] == h[i][C-j+1]) return false;
        }
    }
    ans.push_back(mountain ? "LM" : "LV");
    C /= 2;
    return true;
}

int main() {
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C-1; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 1; i <= R-1; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> h[i][j];
        }
    }
    while (u(0) || u(1) || l(0) || l(1));
    if (R == 1 && C == 1) {
        cout << "YES\n";
        for (string x: ans) {
            cout << x << "\n";
        }
    } else {
        cout << "NO\n";
    }
}