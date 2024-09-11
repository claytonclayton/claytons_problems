#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MIN_N = 1, MAX_N = 500, MIN_VAL = 1, MAX_VAL = 1'000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(MIN_N, MAX_N, "N");
    #ifdef SUB1
        ensuref(N <= 5, "violates N <= 5");
    #endif
    inf.readEoln();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int VAL = inf.readInt(MIN_VAL, MAX_VAL, "VAL");
            if (j != N) inf.readSpace();
        }
        inf.readEoln();
    }
    inf.readEof();
}