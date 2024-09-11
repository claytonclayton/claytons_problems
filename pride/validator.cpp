#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 8, MIN_VAL = 0, MAX_VAL = 1'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    for (int i = 1; i <= N; i++) {
        int VAL = inf.readInt(MIN_VAL, MAX_VAL, "VAL");
        if (i != N) inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();
}