
/*
You are given a grid of numbers written on a sheet of paper. You fold the paper so that when you unfold it, all numbers are surrounded by fold lines (corner numbers have two adjacent fold lines, edge numbers have 3 adjacent fold lines and inner numbers are surrounded on all sides by 4 adjacent fold lines). For each number you add to it the number of mountain folds it is adjacent to. Is there a series of folds so that all numbers in the resulting grid are even?

Subtask-1 - Assume the paper is always folded with alternating folds starting with U i.e U -> L -> U -> L ... 
Subtask-2 - The paper can be folded with arbitrary folds
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int N = 1500;

int r, c, u, v;
int grid[N][N];
char parity_grid[N][N];
int vert[N][N];
int hori[N][N];
vector<string> folds;

void show() {
    for (int j = 0; j < c - 1; j++) {
        cout << " " << vert[0][j];
    }
    cout << endl;
    for (int i = 1; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << hori[i - 1][j] << " ";
        }
        cout << endl;
        for (int j = 0; j < c - 1; j++) {
            cout << " " << vert[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

/*
Case 1 - R == C and grid[0][0] is even
    Then grid[0][0] should be surrounded by 2 mountain fold lines.
    Since R == C then the final fold is LM and the second last fold is UM.
    Then we know the top left 1 x 2 grid looks like 
    __|__
Case 2 - R == C and grid[0][0] is odd
    Then grid[0][0] should be surrounded by 1 mountain fold lines.
    Since R == C then the final fold is L. Lets say final and second last folds are LV and UM.
    Then we know the top left 1 x 2 grid looks like 
    __ __
Case 3 - R < C and grid[0][0] is even
    Then grid[0][0] should be surrounded by 2 mountain fold lines.
    Since R < C then the final fold is UM and the second last fold is LM.
    Then we know the top left 2 x 1 grid looks like 
    __|
      |
Case 4 - R < C and grid[0][0] is odd
    Then grid[0][0] should be surrounded by 1 mountain fold lines.
    Since R < C then the final fold is L. Lets say final and second last folds are UV and LM.
    Then we know the top left 2 x 1 grid looks like 
      |
      |
*/
void init_folds() {
    if (r == c) {
        hori[0][0] = 1;
        hori[0][1] = 1;
        vert[0][0] = grid[0][0] % 2 == 0;
        u = 1; v = 2;
    } else {
        vert[0][0] = 1;
        vert[1][0] = 1;
        hori[0][0] = grid[0][0] % 2 == 0;
        u = 2; v = 1;
    }
}

void unfold() {
    for (int k = u < v; u <= r && v <= c; k++) {
        if (k % 2 == 1) {
            u *= 2;
            for (int j = 0; j < v - 1; j += 2) {
                for (int i1 = 0, i2 = u - 1; i1 < i2; i1++, i2--) {
                    vert[i2][j] = !vert[i1][j];
                }
            }
            for (int j = 0; j < v; j++) {
                for (int i1 = 0, i2 = u - 2; i1 < i2; i1+=2, i2-=2) {
                    hori[i2][j] = !hori[i1][j];
                }
            }
        } else {
            v *= 2;
            for (int i = 0; i < u; i++) {
                for (int j1 = 0, j2 = v - 2; j1 < j2; j1+=2, j2-=2) {
                    vert[i][j2] = !vert[i][j1];
                }
            }
            for (int i = 0; i < u - 1; i+=2) {
                for (int j1 = 0, j2 = v - 1; j1 < j2; j1++, j2--) {
                    hori[i][j2] = !hori[i][j1];
                }
            }
        }
    }
}

void extract_folds() {
    u = r / 2; v = c / 2;
    int i = 0;
    for (; u > 1 || v > 1; i++) {
        if (i % 2 == 0) {
            int sur = vert[u - 1][0] + hori[u - 1][0] + hori[u - 2][0];
            if ((sur + grid[u - 1][0]) % 2 == 0) 
                folds.push_back("UV");
            else
                folds.push_back("UM");
            u /= 2;
        } else {
            int sur = hori[0][v - 1] + vert[0][v - 1] + vert[0][v - 2];
            if ((sur + grid[0][v - 1]) % 2 == 0) 
                folds.push_back("LV");
            else
                folds.push_back("LM");
            v /= 2;
        }
    }

    if (i % 2 == 0) {
        folds.push_back("UM");
        folds.push_back(grid[0][0] % 2 == 0 ? "LM" : "LV");
    } else {
        folds.push_back("LM");
        folds.push_back(grid[0][0] % 2 == 0 ? "UM" : "UV");
    }
}

void simulate_folds() {
    u = 1; v = 1;
    for (auto it = folds.rbegin(); it != folds.rend(); it++) {
        string fold = *it;
        if (fold[0] == 'U') {
            u *= 2;
            for (int j = 0; j < v; j++) {
                hori[u/2 - 1][j] = fold[1] == 'M';
            }
            for (int i1 = 0, i2 = u - 2; i1 < i2; i1++, i2--) {
                for (int j = 0; j < v; j++) {
                    hori[i2][j] = !hori[i1][j];
                }
            }
            for (int j = 0; j < v - 1; j++) {
                for (int i1 = 0, i2 = u - 1; i1 < i2; i1++, i2--) {
                    vert[i2][j] = !vert[i1][j];
                }
            }
        } else {
            v *= 2;
            for (int i = 0; i < u; i++) {
                vert[i][v/2 - 1] = fold[1] == 'M';
            }
            for (int j1 = 0, j2 = v - 2; j1 < j2; j1++, j2--) {
                for (int i = 0; i < u; i++) {
                    vert[i][j2] = !vert[i][j1];
                }
            }
            for (int i = 0; i < u - 1; i++) {
                for (int j1 = 0, j2 = v - 1; j1 < j2; j1++, j2--) {
                    hori[i][j2] = !hori[i][j1];
                }
            }
        }
    }
}

bool check() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int sur = 0;
            sur += i < r - 1 ? hori[i][j] : 0;
            sur += j < c - 1 ? vert[i][j] : 0;
            sur += i - 1 >= 0 ? hori[i - 1][j] : 0;
            sur += j - 1 >= 0 ? vert[i][j - 1] : 0;
            if ((sur + grid[i][j]) % 2 == 1) {
                return false;
                // cout << i << " " << j << " " << sur << endl;
            }
        }
    }
    return true;
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    init_folds();
    unfold();
    extract_folds();
    simulate_folds();    

    // for (string s : folds) {
    //     cout << s << endl;
    // }

    if (check()) {
        cout << "YES" << endl;
        cout << folds.size() << endl;
        for (string s : folds) {
            cout << s << endl;
        }
    } else {
        cout << "NO" << endl;
    }
}