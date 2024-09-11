

#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;

ll n, k, nc2;

ll choose_two(ll a) {
    return a * (a - 1) / 2;
}

// pairs less than
ll lt(ll i) {
    return nc2 - choose_two(n - i);
}

// O(1)? closed form solution
// From sub3-binary-search.cpp we know that there are
// nC2 - (n - i)C2 pairs with first value less than
// or equal to i. Let nC2 = N and n - i = t.
// Set this expression to k and solve for t.
// N - t(t - 1)/2 = k
// t^2 - t + 2(k - N) = 0
// t = 1 + sqrt(1^2 - 4 * 1 * 2(k - N)) / 2 * 1 (quadratic formula)
// n - i = 1 + sqrt(1 + 8(N - k)) / 2
// i = ceil(n - (1 + sqrt(1 + 8(N - k))) / 2)
// The expression with the max evaluation is 1 + 8(N - k).
// This is at most
//   8 * nC2 + 1
// = 8 * 1'000'000'000C2 + 1
// = 3'999'999'996'000'000'001 
// < 4 * 10^18 
// < 9 * 10^18 = LL_MAX
int main() {
    cin >> n >> k;
    nc2 = choose_two(n);
    ll a = ceil(n - (1 + sqrt(1 + 8 * (nc2 - k))) / 2);
    ll b = a + k - lt(a - 1);
    cout << a << " " << b << endl;
}