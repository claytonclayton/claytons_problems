#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

long long N, M, K, K_high, K_low, K_limit, one = 1;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    N = atoi(argv[1]);
    M = atoi(argv[2]);
    K = atoi(argv[3]);
    assert(N <= 200'000);
    K_limit = N*(N-1)/2;
    K = K*rnd.next(one, K_limit);
    cout << N << ' ' << K << "\n";
    int start = rnd.next(1, 10);;
    for (int i = 1; i <= N; i++) {
        cout << start << " \n"[i==N]; 
        start += rnd.next(0, 10);
    }
}