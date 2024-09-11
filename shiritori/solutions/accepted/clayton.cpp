
#include <iostream>
#include <map>

using namespace std;

const int N = 1010;

int n;
string cur;
std::map<string, bool> seen;
char c;

string solve() {
    for (int i = 0; i < n; i++) {
        cin >> cur;
        if (i != 0 && cur[0] != c || seen[cur])
            return cur;
        seen[cur] = true;
        c = cur.back();
    }
    return "-1";
}

int main() {
    cin >> n; 
    cout << solve() << endl;
}