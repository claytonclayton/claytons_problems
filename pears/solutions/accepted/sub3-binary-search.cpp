
#include <iostream>

using namespace std;

using ll = long long; 

// 1'000'000'000C2 = 499'999'999'500'000'000 < 10^18
ll n, k, nc2; 

ll choose_two(ll a) {
    return a * (a - 1) / 2;
}

// pairs less than
ll lt(ll i) {
    return nc2 - choose_two(n - i);
}

// O(log(n)) binary search solution
// Effectively binary search over the array made in sub2.cpp
// There is one pair with first value n - 1, (n - 1, n),
// two pairs with first value n - 2, (n - 2, n - 1), (n - 2, n),
// and so on. Thus there are (i + 1)C2 pairs with first value 
// greater than or equal to n - i. In other words there are 
// nC2 - (n - i)C2 pairs with first value less than or
// equal to i. This is monotonic in i. Binary search!!1!1!!
int main() {
    cin >> n >> k;
    nc2 = choose_two(n);

    int l = 1, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (k <= lt(mid)) r = mid;
        else l = mid + 1;
    }
    
    ll a = l;
    ll b = a + k - lt(a - 1);
    cout << a << " " << b << endl;
}

