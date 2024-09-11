#include "../../testlib.h"
#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;

const int N = 20'000, MAX_WORDS = 10, CHAR_LEN = 4;
int n, c;
double m, t;
string words[N + 10];
map<string, vector<string>> dict;
map<string, bool> seen;

// currently prints in alphabetical order. could shuffle
void show_dict() {
    cout << dict.size() << endl;
    int i = 0;
    for (auto&[k, v] : dict) {
        cout << v.size() + 1;
        if (i != n - 1) cout << " ";
        i++;
    }
    cout << endl;

    for (auto[k, v] : dict) {
        cout << k << ": ";
        int i = 0;
        for (auto w : v) {
            cout << w;
            if (i != v.size() - 1) cout << " ";
            i++;
        }
        cout << endl;
    }
}

string rand_string() {
    string sol = rnd.next("[a-z]{" + to_string(CHAR_LEN) +  "}");
    if (dict.count(sol) > 0) return rand_string();
    return sol;
}

bool choose_edge_or_obvious() {
    double p = rnd.next(1.0);
    if (p < m) return true;
    if (p < m + t) return false;
    else return choose_edge_or_obvious();
}

void add_edge(int u) {
    int v = rnd.next(u + 1, n - 1);
    dict[words[u]].push_back(words[v]);
    // cout << words[u] << endl;
}

void add_obvious(int u) {
    string r = rand_string();
    // cout << r << endl;
    dict[words[u]].push_back(r);
}

void rand_dag() {
    // add n entries to the dictionary
    for (int i = 0; i < n; i++) {
        words[i] = rand_string();
        dict[words[i]] = vector<string>();
    }

    vector<int> from;
    for (int i = 0; i < dict.size() - 1; i++)
        from.push_back(i);

    // select an entry and add to its defintion either another 
    // word from the dictionary or an obvious word. 
    // if the number of words in the entry's definition exceeds
    // MAX_WORDS then it is removed from "from" and exlcuded
    // from future selections.
    for (int i = 0; i < (m + t) * n * MAX_WORDS && from.size() > 0; i++) {
        int u = rnd.any(from);
        
        if (choose_edge_or_obvious()) add_edge(u);
        else add_obvious(u);

        // lmao binary search to make things marginally faster
        if (dict[words[u]].size() >= MAX_WORDS - 1)
            from.erase(lower_bound(from.begin(), from.end(), u));
    }

    // all entries must have at least one word in their definition.
    // find all entries currently with empty definitions and add one
    // obvious word
    for (auto&[k, v] : dict) {
        if (v.size() > 0) continue;
        dict[k].push_back(rand_string());
    }
}

void dfs(string cur, vector<string>& path) {
    if ((seen.count(cur) && seen[cur]) || dict.count(cur) == 0) return;
    seen[cur] = true;
    if (dict[cur].size() < MAX_WORDS - 1) 
        path.push_back(cur);
    for (auto next : dict[cur]) {
        if (path.empty())
            return dfs(next, path);
        dfs(next, path);
    }
}

// finds a random path in the graph and chooses a random point
// on the path to loop back to the start
void make_cycle() {
    seen = map<string, bool>();
    vector<string> path;
    vector<string> nodes;
    for (auto[k, v]: dict)
        nodes.push_back(k);
    string temp = rnd.any(nodes);
    dfs(temp, path);
    if (path.size() == 0) return make_cycle(); // SUSSY
    string tmp = rnd.any(path);
    dict[tmp].push_back(temp);
}

void make_cycles(int c) {
    if (m == 1) return;
    for (int i = 0; i < c; i++) 
        make_cycle();
}

// makes a dictionary of n entries with a total of m * n * MAX_WORDS 
// number of words across all definitions (0 <= m <= 1). also adds 
// t * n * MAX_WORDS number of obvious words to defintions (0 <= t <= 1).
// this creates a DAG with n nodes and m * n * MAX_WORDS edges.
// then adds c cycles. 
// At most input files will have n * MAX_WORDS * (CHAR_LEN + 1) number of 
// characters, 20'000 * 10 * 5 = 1'000'000 chars ~ 1MB. sorryyyy
int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    n = stoi(argv[1]);
    m = stof(argv[2]);
    t = stof(argv[3]);
    c = stoi(argv[4]);

    assert(0 <= m && m <= 1);
    assert(0 <= t && t <= 1);
    assert(m + t <= 1);
    
    rand_dag();
    make_cycles(c);
    show_dict();
}
