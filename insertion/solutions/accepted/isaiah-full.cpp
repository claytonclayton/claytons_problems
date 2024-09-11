#include <bits/stdc++.h>
using namespace std;

int maxpre, maxsuf;
char X[100005], Y[100005];
int main() {
    cin >> X >> Y;
    cin >> X >> Y;
    if (strlen(X) > strlen(Y)) {
        printf("NO\n");
        return 0;
    }
    for (int i = 0; i < strlen(X); i++) {
        if (X[i] == Y[i]) maxpre++;
        else break;
    }
    for (int i = 0; i < strlen(X); i++) {
        if (X[strlen(X)-i-1] == Y[strlen(Y)-i-1]) maxsuf++;
        else break;
    }
    cout << (maxpre + maxsuf >= strlen(X) ? "YES" : "NO") << "\n";
}