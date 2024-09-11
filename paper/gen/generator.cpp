
#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <sstream>
#include <cassert>

using namespace std;

typedef pair<int, int> pii;

#define MAX_FOLDS 10
const int N = 1100;

#define SMALLL 5
#define MEDIUMM 14
#define LARGEE 20

#define SMALL pii(2, SMALLL)
#define MEDIUM pii(SMALLL + 1, MEDIUMM)
#define LARGE pii(MEDIUMM + 1, LARGEE)

default_random_engine gen(0);
// default_random_engine gen(time(0));

bool debug = false;
const int handcases = 4;
int tests = handcases + 1;
int r1, c1, r2, c2;
int verti[N][N];
int hori[N][N];


int rand_size(pair<int, int> r) {
    uniform_int_distribution<int> rand_size(r.first, r.second);
    return rand_size(gen);
}

string print_grid(bool show = true) {
    assert(r1 == r2 + 1 && c1 + 1 == c2);

    stringstream ss;
    ss << r1 << " " << c2 << endl;

    if (r1 == 0 || c1 == 0) {
        r1 = 0; c1 = 0;
    }
    
    if (r2 == 0 || c2 == 0) {
        r2 = 0; c2 = 0;
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            ss << verti[i][j] << " ";
        }
        ss << endl;
    }
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            ss << hori[i][j] << " ";
        }
        ss << endl;
    }
    if (show) cout << ss.str();
    return ss.str();
}

void copy_grid(string path, bool show = false) {
    string input = print_grid(show);
    ofstream tst(path);
    tst << input;
    tst.close();
}

/*
Input:  a series of folds.
Output: the resultant grid from applying these folds
Begins with the final fold and reflects the current creases across the current fold line.
Does this for all successive fold lines until all fold lines are exhausted.
Kind of like the solution but in reverse.

bool reflective: 
a valid folding will reflect across its central fold line. Turning off will leave the other 
half of the paper blank. Can be turned off to catch people who are not checking both halves 
of the paper?

bool symmetric:
if a folding is reflective then it will invert its creases across the central fold line. 
i.e convert all V -> M and M -> V. Turning symmetric on will copy all V -> V and M -> M, 
which is not a valid folding.

bool central_folds:
turning off will make central fold lines random rather than have uniform Vs or Ms. Might catch
people who are checking only for reflectiveness but not central fold lines

bool last_bit_symmetric:
will make all folds in the recursion fold reflectively until the final fold which is suddenly
symmetrical. Might catch people who are only recursing part of the way?
*/
void simulate_folds(vector<string> folds, bool reflective = true, bool symmetric = false, bool central_folds = true, bool last_bit_symmetric = false) {
    uniform_int_distribution<int> randbit(0, 1);

    auto it = folds.rbegin();
    string fold = *it;
    it++;

    if (fold[0] == 'L') {
        verti[0][0] = fold[1] == 'M' ? 1 : 0;
        r1 = 1; c1 = 1; r2 = 0; c2 = 2;
    } else {
        hori[0][0] = fold[1] == 'M' ? 1 : 0;
        r1 = 2; c1 = 0; r2 = 1; c2 = 1;
    }

    for (int turn = 0; it != folds.rend(); it++, turn++) {
        // print_grid();
        fold = *it;
        if (fold[0] == 'U') {
            r1 *= 2;
            r2 *= 2; r2 += 1;

            int mid = r2 / 2;

            for (int i = 0; i < c2; i++)
                if (central_folds)
                    hori[mid][i] = fold[1] == 'M' ? 1 : 0;
                else
                    hori[mid][i] = randbit(gen);
            
            if (!central_folds && c2 >= 2)
                hori[mid][1] = !hori[mid][0];

            if (!reflective) continue;

            int j = 0, k = r2 - 1;
            for (; j < k; j++, k--) {
                for (int i = 0; i < c2; i++) {
                    hori[k][i] = 
                        (symmetric || (last_bit_symmetric && turn == 0)) ? hori[j][i] : !hori[j][i];
                }
            }

            for (int i = 0; i < c1; i++) {
                j = 0; k = r1 - 1;
                for (; j < k; j++, k--) {
                    verti[k][i] = 
                        (symmetric || (last_bit_symmetric && turn == 0)) ? verti[j][i] : !verti[j][i];
                }
            }
        } else {
            c1 *= 2; c1 += 1;
            c2 *= 2;

            int mid = c1 / 2;

            for (int i = 0; i < r1; i++) {
                if (central_folds)
                    verti[i][mid] = fold[1] == 'M' ? 1 : 0;
                else
                    verti[i][mid] = randbit(gen);
            }

            if (!central_folds && r1 >= 2) {
                verti[1][mid] = !verti[0][mid];
            }

            if (!reflective) continue;

            int j = 0, k = c1 - 1;
            for (; j < k; j++, k--) {
                for (int i = 0; i < r1; i++) {
                    verti[i][k] = 
                        (symmetric || (last_bit_symmetric && turn == 0)) ? verti[i][j] : !verti[i][j];
                }
            }

            for (int i = 0; i < r2; i++) {
                j = 0; k = c2 - 1;
                for (; j < k; j++, k--) {
                    hori[i][k] = 
                        (symmetric || (last_bit_symmetric && turn == 0)) ? hori[i][j] : !hori[i][j];
                }
            }
        }
    }
}

void random_folds(int n, bool reflective = true, bool symmetric = false, bool central_folds = true, bool last_bit_symmetric = false, char fold_type = 0) {
    if (n > 20) {
        cerr << "error: grid too big" << endl;
        exit(1);
    }
    uniform_int_distribution<int> randbit(0, 1);

    // turning central_folds off will not change YES instances into NO instances when
    // the folds are all in one direction, since the size of the column will be 1 and
    // picking random bits for fold lines will still make them uniform Vs or Ms, so
    // I restricted the column and row length for central_folds to be >= 2. Probably
    // didn't need to do this for reflective and symmetric too, but here we are.

    // the total number of UP and LEFT folds must sum to n to create n random folds,
    // but also 0 <= |UP|, |LEFT| <= MAX_FOLDS = 10 since row and column lengths are 
    // bounded by 2^10, hence all this weird inequality max, min stuff. 
    int l, r;
    if (reflective && !symmetric && central_folds) {
        l = max(0, n - MAX_FOLDS);
        r = min(n, MAX_FOLDS);
    }
    else {
        l = max(2, n - MAX_FOLDS);
        r = min(n - 2, MAX_FOLDS);
    }

    uniform_int_distribution<int> randfolds(l, r);

    int ups = randfolds(gen);
    int lefts = n - ups;
    if (ups + lefts == 0) lefts++;

    vector<string> folds;
    for (int i = 0; ups + lefts > 0; i++) {

        char dir;
        uniform_int_distribution<int> randdir(1, ups + lefts);
        if (randdir(gen) > ups) {
            dir = 'L';
            lefts--;
        } else {
            dir = 'U';
            ups--;
        }

        if (!fold_type) 
            folds.push_back({dir, (randbit(gen) ? 'M' : 'V')});
        else 
            folds.push_back({dir, (fold_type)});
    } 

    simulate_folds(folds, reflective, symmetric, central_folds, last_bit_symmetric);
}

void random_folds_not_reflective(int n) {
    random_folds(n, false);
}

void random_folds_too_symmetric(int n) {
    random_folds(n, false, true);
}

void random_folds_no_central_folds(int n) {
    random_folds(n, true, false, false);
}

void random_folds_last_bit_too_symmetric(int n) {
    random_folds(n, true, false, true, true);
}

void random_folds_fold_type(int n, char type) {
    random_folds(n, true, false, true, false, type);
}

// flips k random bits in the grid, hopefully turning YES instances into NO instances
void flip_random(int k = 1) {
    while (k--) {
        uniform_int_distribution<int> randcoord(0, r1 * c1 + r2 * c2);
        int num = randcoord(gen);
        if (num >= r1 * c1) {
            num -= r1 * c1;
            int r = num / c2;
            int c = num % c2;
            hori[r][c] = !hori[r][c];
        } else {
            int r = num / c1;
            int c = num % c1;
            verti[r][c] = !verti[r][c];
        }
    }
}

string get_path(int testcase) {
    return "../data/random/"+to_string(testcase)+".in";
}

void generate_all_mountains() {
    string name = "all_mountains";
    if (debug) cout << name << ": " << tests;

    for (int i = 0; i < 1; i++) {
        random_folds_fold_type(rand_size(SMALL), 'M');
        copy_grid(get_path(tests++));
    }

    for (int i = 0; i < 1; i++) {
        random_folds_fold_type(rand_size(MEDIUM), 'M');
        copy_grid(get_path(tests++));
    }

    for (int i = 0; i < 1; i++) {
        random_folds_fold_type(rand_size(LARGE), 'M');
        copy_grid(get_path(tests++));
    }
    if (debug) cout << " - " << tests - 1 << endl;

}

void generate_all_valleys() {
    string name = "all_valleys";
    if (debug) cout << name << ": " << tests;

    for (int i = 0; i < 1; i++) {
        random_folds_fold_type(rand_size(SMALL), 'V');
        copy_grid(get_path(tests++));
    }

    for (int i = 0; i < 1; i++) {
        random_folds_fold_type(rand_size(MEDIUM), 'V');
        copy_grid(get_path(tests++));
    }

    for (int i = 0; i < 1; i++) {
        random_folds_fold_type(rand_size(LARGE), 'V');
        copy_grid(get_path(tests++));
    }

    if (debug) cout << " - " << tests - 1 << endl;
}

void generate_random_yes() {
    string name = "yes";
    if (debug) cout << name << ": " << tests;
    for (int i = 0; i < 2; i++) {
        random_folds(rand_size(SMALL));
        copy_grid(get_path(tests++));
    }

    for (int i = 0; i < 2; i++) {
        random_folds(rand_size(MEDIUM));
        copy_grid(get_path(tests++));
    }

    for (int i = 0; i < 2; i++) {
        random_folds(rand_size(LARGE));
        copy_grid(get_path(tests++));        
    }
    if (debug) cout << " - " << tests - 1 << endl;
}

void generate_one_flip() {
    string name = "one_flip";
    if (debug) cout << name << ": " << tests;

    for (int i = 0; i < 1; i++) {
        random_folds(rand_size(MEDIUM));
        flip_random();
        copy_grid(get_path(tests++));        
    }

    for (int i = 0; i < 1; i++) {
        random_folds(rand_size(LARGE));
        flip_random();
        copy_grid(get_path(tests++));        
    }

    if (debug) cout << " - " << tests - 1 << endl;
}

void generate_few_flips() {
    string name = "few_flips";
    if (debug) cout << name << ": " << tests;

    int perc = 10;

    for (int i = 0; i < 2; i++) {
        random_folds(rand_size(MEDIUM));
        flip_random((r1 * c1 + r2 + c2) / perc + 1);
        copy_grid(get_path(tests++));        
    }

    for (int i = 0; i < 2; i++) {
        random_folds(rand_size(LARGE));
        flip_random((r1 * c1 + r2 + c2) / perc + 1);
        copy_grid(get_path(tests++));        
    }
    if (debug) cout << " - " << tests - 1 << endl;
}

void generate_not_reflective() {
    string name = "not_reflective";
    if (debug) cout << name << ": " << tests;

    for (int i = 0; i < 1; i++) {
        random_folds_not_reflective(rand_size(MEDIUM));
        copy_grid(get_path(tests++));        
    }
    
    for (int i = 0; i < 1; i++) {
        random_folds_not_reflective(rand_size(LARGE));
        copy_grid(get_path(tests++));        
    }
    if (debug) cout << " - " << tests - 1 << endl;
}

void generate_too_symmetric() {
    string name = "too_symmetric";
    if (debug) cout << name << ": " << tests;

    for (int i = 0; i < 1; i++) {
        random_folds_too_symmetric(rand_size(MEDIUM));
        copy_grid(get_path(tests++));        
    }
    
    for (int i = 0; i < 1; i++) {
        random_folds_too_symmetric(rand_size(LARGE));
        copy_grid(get_path(tests++));        
    }

    if (debug) cout << " - " << tests - 1 << endl;
}

void generate_no_central_folds() {
    string name = "no_central_folds";
    if (debug) cout << name << ": " << tests;

    for (int i = 0; i < 1; i++) {
        random_folds_no_central_folds(rand_size(MEDIUM));
        copy_grid(get_path(tests++));
    }
    
    for (int i = 0; i < 1; i++) {
        random_folds_no_central_folds(rand_size(LARGE));
        copy_grid(get_path(tests++));
    }
    if (debug) cout << " - " << tests - 1 << endl;
}

void generate_last_bit_too_symmetric() {
    string name = "last_bit_too_symmetric";
    if (debug) cout << name << ": " << tests;

    for (int i = 0; i < 1; i++) {
        random_folds_last_bit_too_symmetric(rand_size(MEDIUM));
        copy_grid(get_path(tests++));
    }
    
    for (int i = 0; i < 1; i++) {
        random_folds_last_bit_too_symmetric(rand_size(LARGE));
        copy_grid(get_path(tests++));
    }
    if (debug) cout << " - " << tests - 1 << endl;
}

/*
test ideas:
    - make paper folding simulator
    - close to valid fold but random bits are flipped
        - ONE random bit is flipped
        - MANY random bits are flipped
        - somehow the final bit to check is flipped
    - paper is reflective but doesnt have central fold lines
    - paper has central fold lines until but isnt reflective
    - all folds only mountains, valleys
    - all folds one direction only mountains, valleys
*/
int main () {
    debug = true;
    generate_all_mountains();
    generate_all_valleys();
    generate_random_yes();
    generate_one_flip();
    generate_few_flips();
    generate_not_reflective();
    generate_too_symmetric();
    generate_no_central_folds();
    generate_last_bit_too_symmetric();
}
