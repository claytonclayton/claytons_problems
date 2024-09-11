#include "../../testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int M = 1000;

int n, max_out_degree;
int seen[N + 10];
int active[N + 10];

// randomly selects "degree" number of nodes for node i to branch to
vector<int> rand_choice(int i, int n, int degree) {
    set<int> sol;
    int next = -1;
    while (sol.size() < degree) {
        next = rnd.next(i + 1, n - 1);
        sol.insert(next);
    }
    return vector<int>(sol.begin(), sol.end());
}

// weirdly involved
// nodes are initially ordered in sorted order 1..n
// for each node connect it to a random number of nodes later in the ordering, maxed out by max_out_degree
// to ensure connectedness, for each node not reached make one node earlier in the ordering connect to it
// shuffle the labels on nodes
// shuffle the edges
vector<pair<int, int>> get_edges() {
    vector<pair<int, int>> edges;
    set<int> seen;
    // initially 0-indexed. add 1 to all nodes later
    for (int i = 0; i < n - 1; i++) {
        int degree = rnd.next(i == 0, min(n - i - 1, max_out_degree));
        vector<int> nexts = rand_choice(i, n, degree);
        for (int t : nexts) {
            edges.emplace_back(i, t);
            seen.insert(t);
        }
    }
    for (int i = 1; i < n; i++) {
        if (seen.count(i) > 0) continue;
        edges.emplace_back(rnd.next(0, i - 1), i);
    }

    vector<int> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(i);
    }

    shuffle(nodes.begin(), nodes.end());
    shuffle(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++) {
        auto[u, v] = edges[i];
        // add 1 for 1-indexed nodes.
        edges[i] = make_pair(nodes[u] + 1, nodes[v] + 1);
    }

    return edges;
}

bool has_cycle(int cur, vector<vector<int>>& adj) {
    if (seen[cur]) 
        return active[cur];
    seen[cur] = true;
    active[cur] = true;
    for (int next : adj[cur]) {
        if (has_cycle(next, adj)) return true;
    }
    active[cur] = false;
    return false;
}

// We must ensure input graphs maintain the following attributes
// - connected
// - no cycles
// - for each i in [1, n] there is a node labeled i
// - edges are <= N
void verify(vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n + 1);
    set<int> ends;
    for (auto [u, v] : edges) {
        ends.insert(u);
        ends.insert(v);
        adj[u].push_back(v);
    }

    if (edges.size() > M) {
        cout << n << " " << max_out_degree << endl;
    }
    assert(edges.size() <= M);
    for (int i = 1; i <= n; i++)
        if (!seen[i]) assert(!has_cycle(i, adj));
    for (int i = 1; i <= n; i++)
        assert(ends.count(i) >= 1);
}

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    n = atoi(argv[1]);
    max_out_degree = atoi(argv[2]);

    vector<pair<int, int>> edges = get_edges();
    // for (auto [u,v] : edges) {
    //     cout << u << " " << v << endl;
    // }
    verify(edges);

    cout << n << " " << edges.size() << '\n';
    for (auto p : edges) {
        cout << p.first << " " << p.second << endl;
    }
}