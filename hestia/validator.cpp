#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define MIN_N 1
#define MAX_N 20'000
#define SUB1_MAX_N 1000
#define MIN_WORDS 2
#define MAX_WORDS 10
#define MIN_CHARS 1
#define MAX_CHARS 10

string chars_bound() {
    return "{" + to_string(MIN_CHARS) + "," + to_string(MAX_CHARS) + "}";
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N, MAX_N, "n");
    #ifdef SUB1
        ensure(n <= SUB1_MAX_N);
    #endif
    vector<int> lines;
    inf.readEoln();
    for (int i = 0; i < n; i++) {
        int a = inf.readInt(MIN_WORDS, MAX_WORDS, "a");
        if (i != n - 1) inf.readSpace();
        lines.push_back(a);
    }
    inf.readEoln();

    for (int i = 0; i < n; i++) {
        inf.readToken("[a-z]" + chars_bound() + ":", "s");
        inf.readSpace();
        for (int j = 0; j < lines[i] - 1; j++) {
            inf.readToken("[a-z]" + chars_bound(), "s");
            if (j != lines[i] - 2) inf.readSpace();
        }
        inf.readEoln();
    }
    inf.readEof();
}