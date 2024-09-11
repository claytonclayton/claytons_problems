
#include <iostream>
#include <vector>

using namespace std;

const int N = 10'000;

int r1, c1, r2, c2;
bool is_big_hori, is_big_verti;
int verti[N][N];
int hori[N][N];
vector<int> folds; 

bool check_fold_hori(bool push = true) {
    int mid = r2 / 2;
    int prev = hori[mid][0];
    if (push) folds.push_back(prev); 
    for (int i = 0; i < c2; i++) {
        if (hori[mid][i] != prev) return false;
        prev = hori[mid][i];
    }
    return true;
}

bool check_fold_verti(bool push = true) {
    int mid = c1 / 2;
    int prev = verti[0][mid];
    if (push) folds.push_back(prev);
    for (int i = 0; i < r1; i++) {
        if (verti[i][mid] != prev) return false;
        prev = verti[i][mid];
    }
    return true;
}

bool is_verti_symmetric() {
    int i = 0, j = r2 - 1;
    for (; i < j; i++, j--) {
        for (int k = 0; k < c2; k++) {
            if (hori[i][k] == hori[j][k]) return false;
        }
    }
    
    for (int k = 0; k < c1; k++) {
        i = 0; j = r1 - 1;
        for (; i < j; i++, j--) {
            if (verti[i][k] == verti[j][k]) return false;
        }
    }

    return true;
}

bool is_hori_symmetric() {
    int i, j;

    for (int k = 0; k < r2; k++) {
        i = 0; j = c2 - 1;
        for (; i < j; i++, j--) {
            if (hori[k][i] == hori[k][j]) return false;
        }
    }
    
    i = 0; j = c1 - 1;
    for (; i < j; i++, j--) {
        for (int k = 0; k < r1; k++) {
            if (verti[k][i] == verti[k][j]) return false;
        }
    }

    return true;
}

bool solve() {
    is_big_hori = check_fold_hori(false);
    is_big_verti = check_fold_verti(false);

    if (!is_big_hori && !is_big_verti)
        return false;

    for (int turn = is_big_verti; r1 + c1 > 1; turn++) {
        if (turn % 2 == 0) {
            if (!check_fold_hori() || !is_verti_symmetric())
                return false;
            r1 /= 2; r2 /= 2;
        } else {
            if (!check_fold_verti() || !is_hori_symmetric())
                return false;
            c1 /= 2; c2 /= 2;
        }
    }
    return true;
}

int main() {
    cin >> r1 >> c1 >> r2 >> c2;

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> verti[i][j];

    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> hori[i][j];

    if (!solve()) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << folds.size() << endl;
    for (auto i : folds) {
        cout << i << endl;
    }
}