
#include <iostream>

using namespace std;

using ll = long long; 

const int N = 1'000'010;
ll n, k;
ll arr[N]; // 1'000'000C2 = 499'999'500'000 < 10^12 < 10^18

// O(n) solution
// There are n - 1 pairs with first value 1, 
// (1, 2), (1, 3) ... (1, n),
// n - 2 pairs with first value 2,
// (2, 3), (2, 4) ... (2, n) and so on.
// Let P be the sequence, n - 1, n - 2, n - 3 ... 2, 1
// Then the number of pairs with first value less or equal to i
// is just the ith partial sum of this sequence. 
// To find the kth pair, evaluate partial sums until they exceed k
// then the index of the previous partial sum is the first value
// of the kth pair. You do da rest.
int main() {
    cin >> n >> k;

    ll a, b;
    for (int i = 1; i <= n; i++) {
        arr[i] = arr[i - 1] + n - i;
        if (arr[i] >= k) {
            a = i;
            break;
        }
    }

    b = a + k - arr[a - 1];
    cout << a << " " << b << endl;
}