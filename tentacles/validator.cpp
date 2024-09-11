#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MIN_N = 1, MAX_N = 200'000;
const int MIN_VAL = 1, MAX_VAL = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(MIN_N, MAX_N, "N");
    #ifdef SUB1
        ensuref(N <= 50, "violates 1 <= N <= 50");
    #endif
    #ifdef SUB2
        ensuref(N <= 750, "violates 1 <= N <= 750");
    #endif
    #ifdef SUB3
        ensuref(N <= 5'000, "violates 1 <= N <= 5'000");
    #endif
    inf.readSpace();
    long long K = inf.readLong(0, ((long long) N) * (N-1) / 2, "K");
    inf.readEoln();
    for (int j = 1; j <= N; j++) {
        int num = inf.readInt(MIN_VAL, MAX_VAL, "number");
        if (j != N) inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();
}