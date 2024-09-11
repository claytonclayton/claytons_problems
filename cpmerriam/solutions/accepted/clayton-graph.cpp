
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

const int N = 20'010;
int n;

unordered_map<string, int> indexer;
vector<string> adjs[N];
vector<int> adj[N];
bool seen[N];
bool active[N];
bool cycled[N];

// All cycles or ancestors of cycles will not be learnable
void dfs(int cur) {
    if (seen[cur]) return;
    seen[cur] = true;
    active[cur] = true;

    for (int next : adj[cur]) {
        dfs(next);
        if (active[next] || cycled[next]) 
            cycled[cur] = true;
    }

    active[cur] = false;
}

int main() {
    cin >> n;
    vector<int> lens(n + 1);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        lens[i] = a;
    }

    for (int i = 1; i <= n; i++) {
        string word;
        cin >> word;
        word.pop_back();

        indexer[word] = i;

        for (int j = 0; j < lens[i] - 1; j++) {
            string cur; cin >> cur;
            adjs[i].push_back(cur);
        }
    }

    for (int i = 0; i <= n; i++) {
        for (auto s : adjs[i]) {
            if (indexer[s] != 0) 
                adj[i].push_back(indexer[s]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!seen[i]) 
            dfs(i);
    }

    int sol = 0;
    for (int i = 1; i <= n; i++) {
        sol += cycled[i] == 0;
    }
    cout << sol << endl;
}