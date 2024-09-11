#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define MIN_N 2
#define MIN_K 1
#define SUB1_MAX_N 1000LL
#define SUB2_MAX_N 1'000'000LL
#define SUB3_MAX_N 1'000'000'000LL
#define SUB1_MAX_K 499'500LL
#define SUB2_MAX_K 499'999'500'000LL
#define SUB3_MAX_K 499'999'999'500'000'000LL

using ll = long long;

ll choose_two(ll a) {
    return a * (a - 1) / 2;
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    ll n = inf.readLong(MIN_N, SUB3_MAX_N, "n");
    inf.readEoln();
    ll k = inf.readLong(MIN_K, SUB3_MAX_K, "k");
    inf.readEoln();
    inf.readEof();

    #ifdef SUB1
        ensure(n <= SUB1_MAX_N);
        ensure(k <= SUB1_MAX_K);
    #endif

    #ifdef SUB2
        ensure(n <= SUB2_MAX_N);
        ensure(k <= SUB2_MAX_K);
    #endif
    
    ensure(k <= choose_two(n));
}