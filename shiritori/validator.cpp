#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MIN_N = 1, MAX_N = 100, MIN_LEN = 1, MAX_LEN = 20;
map<string, bool> seen; 

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(MIN_N, MAX_N);
    inf.readEoln();
    for (int i = 1; i <= N; i++) {
        string s = inf.readToken("[a-z]{1,20}");
        #ifdef SUB1
            ensuref(!seen[s], "repeated word");
            seen[s] = true;
        #endif
        inf.readEoln();
    }
    inf.readEof();
}