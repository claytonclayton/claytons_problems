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
    
    K_low = 2 * N;
    if (N <= 50) {
        K_high = K_limit / 2;
    }else if (N <= 750) {
        K_high = K_limit / 10;
    } else if(N <= 2000) {
        K_high = K_limit / 50;
    } else {
        K_high = K_limit / 100;
    }

    K = K*rnd.next(K_low, K_high);
    cout << N << ' ' << K << "\n";
    for (int i = 1; i <= N; i++) {
        cout << rnd.next(one, M) << " \n"[i==N]; 
    }
}