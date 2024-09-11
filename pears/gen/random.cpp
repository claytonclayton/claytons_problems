#include "../../testlib.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MIN_N = 2;
const ll MIN_K = 1;
const ll SUB1_MAX_N = 1000LL;
const ll SUB2_MAX_N = 1'000'000LL;
const ll SUB3_MAX_N = 1'000'000'000LL;
const ll SUB1_MAX_K = 499'500LL;
const ll SUB2_MAX_K = 499'999'500'000LL;
const ll SUB3_MAX_K = 499'999'999'500'000'000LL;

ll n, k;

ll choose_two(ll a) {
    return a * (a - 1) / 2;
}

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int sub = stoi(argv[1]);
    bool boundary = stoi(argv[2]);
    bool seed = stoi(argv[3]);

    assert(1 <= sub && sub <= 3);

    ll nl, nr;
    if (sub == 1) {
        nl = MIN_N; nr = SUB1_MAX_N;
    }
    else if (sub == 2) {
        nl = SUB1_MAX_N + 1; nr = SUB2_MAX_N;
    }
    else {
        nl = SUB2_MAX_N + 1; nr = SUB3_MAX_N;
    }

    n = rnd.next(nl, nr);
    if (boundary) {
        ll t = rnd.next(rnd.next(1LL, n - 1));
        k = choose_two(n) - choose_two(t);
    } else {
        k = rnd.next(1LL, choose_two(n));
    }
    
    cout << n << '\n' << k << '\n';
}