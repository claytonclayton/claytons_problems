#include <bits/stdc++.h>
using namespace std;

char X[100005], Y[100005];
int main() {
    cin >> X >> Y;
    cin >> X >> Y;
    int x = 0;
    for (int y = 0; y < strlen(Y); y++) {
        if (x < strlen(X) && X[x] == Y[y]) x++;
    }
    cout << (x >= strlen(X) ? "YES" : "NO") << "\n";
}