#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MIN_N = 1;
const int MAX_N = 10'000;
const int FOURTH_ROOT_LLMAX = 31'600;
const ll LLMAX = 9'223'372'036'854'775'807;

int n;
int arr[MAX_N];

void check_constraint() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ensure(arr[i] * arr[j] <= LLMAX);
        }
    }
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    n = inf.readInt(MIN_N, MAX_N, "n");
    inf.readEoln();
    for (int i = 0; i < n; i++) {
        if (i != 0) inf.readSpace();
        arr[i] = inf.readLong(1LL, LLMAX, "a");
    }
    inf.readEoln();
    inf.readEof();
    check_constraint();
}