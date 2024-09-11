
#include <iostream>
#include <vector>

using namespace std;

const int N = 2000;

int r, c, r1, c1, r2, c2;
bool is_big_hori, is_big_verti;
int verti[N][N];
int hori[N][N];
vector<string> folds;

void print_grid(bool index = false) {
    if (index) cout << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
    cout << "verti" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << verti[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "hori" << endl;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cout << hori[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
}

char get_up_fold(bool push = true) {
    if (!r2) return 0;
    int mid = r2 / 2;
    int prev = hori[mid][0];
    for (int i = 1; i < c2; i++) {
        if (hori[mid][i] != prev) return 0;
        prev = hori[mid][i];
    }
    return prev ? 'M' : 'V';
}

char get_left_fold(bool push = true) {
    if (!c1) return 0;
    int mid = c1 / 2;
    int prev = verti[0][mid];
    for (int i = 1; i < r1; i++) {
        if (verti[i][mid] != prev) return 0;
        prev = verti[i][mid];
    }
    return prev ? 'M' : 'V';
}

string get_fold() {
    char up_fold = get_up_fold();
    char left_fold = get_left_fold();

    if (up_fold) return {'U', up_fold};
    if (left_fold) return {'L', left_fold};
    return "";
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

/*
Divide and conquer method
The next fold in a valid folding must be either an UP or LEFT fold.
An UP fold will be a long line of all V or M creases running
left to right in the center of the horizontal grid.
A LEFT fold will be a long line of all V or M creases running 
top to bottom in center of the vertical grid.
Use this to determine the type and direction of the next fold.
The creases of the paper will "reflect" across this fold line
ie it will appear symmetrical except all creases are inverted 
across the line of symmetry i.e V -> M and M -> V.
So if there is a central fold line, and all creases reflect 
across this fold line, then we can check the next fold by discarding
one of the halves of the paper and recursing. 
Creases will be accessed O(RC + RC/2 + RC/4 + RC/8 ... 1) = O(2RC) = O(RC) times.
Hence the algorithm is O(RC)
*/
bool solve() {
    while (r1 + c1 + r2 + c2 > 1) {

        string fold = get_fold();
        if (fold.empty()) return false;
        folds.push_back(fold);

        if (fold[0] == 'U') {
            if (!is_verti_symmetric()) return false;
            r1 /= 2; r2 /= 2;
        } else {
            if (!is_hori_symmetric()) return false;
            c1 /= 2; c2 /= 2;
        }

        if (r1 == 0 || c1 == 0) {
            r1 = 0; c1 = 0;
        } else if (r2 == 0 || c2 == 0) {
            r2 = 0; c2 = 0;
        }

    }
    return true;
}



int main() {
    cin >> r >> c;
    r1 = r; c1 = c - 1; r2 = r - 1; c2 = c;

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
    for (auto i : folds) {
        cout << i << endl;
    }
}
