#include "../../testlib.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <cassert>

using namespace std;

const int N = 2010;
const int MAX_CELL = 100;
int grid[N][N];
int vert[N][N];
int hori[N][N];
int r, c, u, v;
vector<string> folds;

default_random_engine gen(0);

void show_folds(int u=r, int v=c) {
    for (int j = 0; j < v - 1; j++) {
        cout << " " << vert[0][j];
    }
    cout << endl;
    for (int i = 1; i < u; i++) {
        for (int j = 0; j < v; j++) {
            cout << hori[i - 1][j] << " ";
        }
        cout << endl;
        for (int j = 0; j < v - 1; j++) {
            cout << " " << vert[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for (string s : folds) {
        cout << s << " ";
    } cout << endl;
}

void show_grid() {
    cout << r << " " << c << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void simulate_folds() {
    u = 1; v = 1;
    auto it = folds.rbegin();
    for (;it != folds.rend(); it++) {
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

void generate_grid(double flip_chance, bool is_simple) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int sur = 0;
            if (i < r - 1) sur += hori[i][j];
            if (j < c - 1) sur += vert[i][j];
            if (i - 1 >= 0) sur += hori[i - 1][j];
            if (j - 1 >= 0) sur += vert[i][j - 1];
            int parity = sur % 2 == 1;
            
            if (rnd.next() < flip_chance || (flip_chance > 0 && i == r - 1 && j == c - 1)) 
                parity = !parity;
        
            if (is_simple) 
                grid[i][j] = parity;
            else if (parity % 2 == 0)
                grid[i][j] = rnd.next(0, MAX_CELL / 2) * 2;
            else
                grid[i][j] = rnd.next(0, MAX_CELL / 2 - 1) * 2 + 1;
        }
    }
}

vector<bool> get_dirs(int n, bool is_alternating) {
    vector<bool> dirs;
    if (is_alternating) {
        for (int i = 0; i < n; i++)
            dirs.push_back(i % 2 == 1);
    } else {
        dirs = {0, 1};
        for (int i = 2; i < n; i++) {
            dirs.push_back(rnd.next(0, 1));
        }
        shuffle(dirs.begin(), dirs.end());
    }
    return dirs;
}

void rand_folds(int n, bool is_alternating) {
    assert(n >= 2 && n <= 20);
    vector<bool> dirs = get_dirs(n, is_alternating);
    folds = vector<string>();
    r = 1; c = 1;
    for (bool d : dirs) {
        if ((d && c < 1024) || r >= 1024) {
            folds.push_back(rnd.next(0, 1) ? "LM" : "LV");
            c *= 2;
        } else {
            folds.push_back(rnd.next(0, 1) ? "UM" : "UV");
            r *= 2;
        }
    }
}

/*
Test ideas
- copy over simulate_folds and use original paper solution to assert that it works
- grids that adhere to alternating folds with R == C and R > C
- grids that adhere to alternating folds but one number has flipped parity. final number in the grid 
- grids that adhere to alternating folds but multiple numbers have flipped parity
- grids that adhere to alternating folds but all numbers have flipped parity
- for subtask-2 - all above but for random folds
*/
int main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);                  // number of folds
    bool is_alternating = atoi(argv[2]);    // alternating folds
    double flip_chance = atof(argv[3]);     // chance to flip parity of a grid cell
    // bool is_simple = atoi(argv[4]);      // grid cells are only 0 or 1
    bool is_simple = false;

    rand_folds(n, is_alternating);
    simulate_folds();
    generate_grid(flip_chance, is_simple);

    show_grid();
}