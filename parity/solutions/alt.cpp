
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int N = 1500;

int r, c, u, v;
int grid[N][N];
bool parity[N][N];
vector<string> folds;

void show() {
    for (int i = 0; i < u; i++) {
        for (int j = 0; j < v; j++) {
            cout << parity[i][j] << " ";
        } cout << endl;
    }
}

void show_folds() {
    cout << folds.size() << endl;
    for (auto it = folds.rbegin(); it != folds.rend(); it++) {
            cout << *it << endl;
    }
}

int get_sur(int i, int j) {
    // if corner
    if ((i == 0 || i == u - 1) && (j == 0 || j == v - 1))
        return 2;
    // if edge
    if (i == 0 || i == u - 1 || j == 0 || j == v - 1)
        return 3;
    // if middle
    return 4;
}

void unfold() {
    u = 1, v = 1;
    for (int t = r > c; u < r || v < c; t++) {
        if (t % 2 == 0) {
            if (grid[0][v - 1] != parity[0][v - 1]) {
                folds.push_back("LM");
                for (int i = 0; i < u; i++)
                    parity[i][v - 1] = !parity[i][v - 1];
            } else {
                folds.push_back("LV");
            }
            for (int i = 0; i < u; i++) {
                for (int j1 = 0, j2 = 2*v - 1; j1 < j2; j1++, j2--) {
                    int sur = get_sur(i, j1) - (v == 1 && v < u);
                    parity[i][j2] = sur % 2 == 0 ? parity[i][j1] : !parity[i][j1];
                }
            }
            v *= 2;
        }
        else {
            if (grid[u - 1][0] != parity[u - 1][0]) {
                folds.push_back("UM");
                for (int j = 0; j < v; j++)
                    parity[u - 1][j] = !parity[u - 1][j];
            } else {
                folds.push_back("UV");
            }
            for (int j = 0; j < v; j++) {
                for (int i1 = 0, i2 = 2*u - 1; i1 < i2; i1++, i2--) {
                    int sur = get_sur(i1, j) - (u == 1 && u < v);
                    parity[i2][j] =  sur % 2 == 0 ? parity[i1][j] : !parity[i1][j];
                }
            }
            u *= 2;
        }
    }
}

bool check() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] != parity[i][j]) return false;
        }
    }
    return true;
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            grid[i][j] %= 2;
        }
    }
    unfold();
    
    if (!check()) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    show_folds();
}