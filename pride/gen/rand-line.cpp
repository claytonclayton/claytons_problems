#include "../../testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    vector<int> nodes;
    vector<pair<int, int>> edges;
    for (int i = 1; i <= n; i++)
        nodes.push_back(i);
    shuffle(nodes.begin(), nodes.end());
    for (int i = 0; i < n - 1; i++)
        edges.emplace_back(nodes[i], nodes[i + 1]);
    shuffle(edges.begin(), edges.end());

    cout << n << " " << n - 1 << endl;
    for (auto[u, v]:edges) {
        cout << u << ' ' << v << endl;
    }
}