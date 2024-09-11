
#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

void print_sol(int n, int m);

class sol {
public:
    sol() {}
    sol(int size, int set) : size(size), set(set) {}
    int size = 0;
    int set = 0;
};

int max_arr_len = 27;
int sols_printed = 1500;

const int N = 10'010;
int nc2[N];
sol sols[N];

int n, m, t, indec = 1, jindec = 0;

int lessify(int i) {
    return (1 + sqrt(1 + 8 * i)) / 2;
}

void build_tables() {
    int nless = lessify(N);

    nc2[2] = 1;
    for (int i = 3; i < nless; i++) {
        nc2[i] = nc2[i - 1] + i - 1;
    }

    sols[0] = sol(3, 0);
    sols[1] = sol(3, 4);
}

void search() {
    if (sols[m].size != 0) {
        print_sol(n, m);
        return;
    }

    for (int i = indec; i < max_arr_len; i++) {
        for (int j = jindec; j < pow(2, i); j++) {
            int sett = j;
            int sum = 0;
            int twos = 2;

            for (int k = 0; k < i; k++) {
                if (sett & 1) sum += nc2[twos];
                else twos++;
                sett >>= 1;
            }
            sum += nc2[twos];

            // if (sols[sum].size == 0 || sols[sum].size <= i + 3)
            if (sols[sum].size == 0) {
                sols[sum] = sol(i + 3, (j + (1 << i)) << 2);
                
                if (sum == m) {
                    print_sol(n, m);
                    indec = i;
                    jindec = j + 1;
                    return;
                }
            }
        }
        jindec = 0;
    }
    cout << "NO" << endl;
}

void print_sol(int n, int m) {

    if (sols[m].size > n) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    // cout << sols[m].size << " " << sols[m].set << endl;

    int sett = sols[m].set;
    for (int i = 0; i < sols[m].size; i++) {
        cout << (sett & 1 ? '4' : '2');
        sett >>= 1;
    }

    for (int i = 0; i < n - sols[m].size; i++) {
        cout << '2';
    }
    cout << endl;
}

void print_all() {
    for (int i = 1; i <= sols_printed; i++) {
        cout << (i < 10 ? " " : "");
        cout << (i < 100 ? " " : "");
        cout << i << ": ";
        int sett = sols[i].set;
        for (int j = 0; j < sols[i].size; j++) {
            cout << (sett & 1 ? '4' : '2');
            sett >>= 1;
        }
        cout << ":" <<  sols[i].size << " ";
        cout << endl;
    }
}

int main() {
    build_tables();

    cin >> t;
    while (t--) {
        cin >> n >> m;
        search();
    }
}
