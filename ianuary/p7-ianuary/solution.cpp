
/*
Ianurarian Triples

Given integers n and m, does there exist an array a of length n, 
composed of only 2s and 4s, such that there are exactly m triples 
1 <= i < j < k <= n such that a_i * a_j = a_k?

If so construct such an array.

Example:
n = 6, m = 2

Answer:
YES
[4, 2, 2, 4, 4, 2]

The array has length 6 and there are exactly 2 Ianuarian Triples:
a_2 * a_3 = a_4
a_2 * a_3 = a_5

Shorter Solution:
The problem reduces to, What is the minimum array size required to 
generate m Ianuarian Triples? 

If we find this minimum array, we can just right pad the solution 
with 2s until the array is size n. Right padding with 2s (or left 
padding with 4s) will not increase the Ianuarian Triple count of
the array (call this icount). If the size of the minumum array is 
greater than n then we can just output NO. 

To find the minimum array, we can think of a candidate solution as 
an array beginning with some number of 2s, ending with a 4, and 
having some number of 4s interspersed throughout.

So solutions without the interspersed 4s will take the form:
2: 224
3: 2224
4: 22224
...
i: 222...224 - where iC2 is maximised but doesnt exceed m

Placing a 4 into a base solution will increase the icount by some 
kC2 where k is equal to the number of 2s to the left of it. 
For each base solution we need to find the minimum number of 
4s required to reach m.

The problem now becomes the "Change-making problem" (see wikipedia). 
Given a number of coin denominations, what is the minimum number of 
coins required to make m amount of change?

The final 4 in each base solution will create an icount of iC2 
and so the target amount is the difference to make m, m - iC2.
Coin denomations are kC2 where 2 <= k <= i. 

We can solve this with dp.
Let dp[i][j] be the minimum number of kC2s where 2 <= k <= i 
required to sum to a target j.

dp[2][0] = 0
dp[i][j] = min(dp[i][j - nC2[k]]) + 1
       2 <= k <= i

For quadratic reasons, the max value of i we need to calculate is
of order O(sqrt(m)) (see long_explanation.txt). Call this value 
mless.

After calculating dp[mless][m - nC2[mless]], since we know the 
length of each base solution, i + 1 (i 2s followed by one 4), then
we can compare the sizes of each candidate solution after adding
the appropriate dp[i][m - iC2] number of 4s. The minimum size array
we find will be the minimum size array required to make m 
Ianuarian Triples.

The solution is finshed!

Time Complexity:
O(m^2 + nlog(n)). Ammortised O(sqrt(m) + nlog(n))! 
(see long_explanation.txt)
*/

#include <iostream>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;

void build_tables(int m);
void solve(int n, int m);
void print_sol(int n, int m, int index, int size);

class state {
public:
    state() {}
    state(int size, int elem, int prev) : size(size), elem(elem), prev(prev) {}
    int size = 0;
    int elem = -1;
    int prev = -1;
};

const int INT_MAX = 1'000'000;
const int N = 10'010;
const int NLESS = 150;

int nc2[N];
state DP[NLESS][N];

int lessify(int i) {
    return (1 + sqrt(1 + 8 * i)) / 2;
}

state dp(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= N) return state();
    int jless = lessify(j);
    if (jless < i) i = jless;
    return DP[i][j];
}

void print_dp(int i, int j) {
    int curr = j;
    while (curr > 0) {
        cout << dp(i, curr).elem << endl;
        curr = dp(i, curr).prev;
    }
}

void build_tables(int m = N) {
    int mless = lessify(m);

    nc2[2] = 1;
    for (int i = 3; i <= mless; i++) {
        nc2[i] = nc2[i - 1] + i - 1;
    }

    for (int i = 2; i <= mless; i++) {
        for (int j = nc2[i]; j <= m - nc2[i]; j++) {

            state next(INT_MAX, 0, 0);
            for (int k = 2; k <= i; k++) {
                if (j - nc2[k] < 0) break;
                state curr = dp(i, j - nc2[k]); 
                if (curr.size < next.size) {
                    next = state(curr.size, nc2[k], j - nc2[k]);
                }
            }
            next.size++;
            DP[i][j] = next;
        }
    }
}

void solve(int n, int m) {
    int mless = lessify(m);

    int index = 0, size = INT_MAX;
    for (int i = 2; i <= mless; i++) {
        state curr = dp(i, m - nc2[i]); 
        if (i + 1 + curr.size <= size) {
            size = curr.size + i + 1; 
            index = i;
        }
    }

    print_sol(n, m, index, size);
}

void print_sol(int n, int m, int index, int size) {
    if (size > n) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(nc2[index]);
    int curr = m - nc2[index];
    while (curr > 0) {
        pq.push(dp(index, curr).elem);
        curr = dp(index, curr).prev;
    }

    string sol = "22";

    int i = 2;
    while (!pq.empty()) {
        if (pq.top() <= nc2[i]) {
            sol += '4';
            pq.pop();
        } else {
            sol += '2';
            i++;
        }
    }

    for (int i = 0; i < n - size; i++) {
        sol += '2';
    }

    cout << sol << endl;
}

int main() {
    build_tables();

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        solve(n, m);
    }
}
