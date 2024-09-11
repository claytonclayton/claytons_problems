#include "../../testlib.h"
#include <bits/stdc++.h>
using namespace std;

string rand_word(int s) {
    return rnd.next(format("[a-z]{%d}", s));
}

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    double ratio = atof(argv[2]);
    int repeat = atoi(argv[3]);
    string cur, prev = rand_word(1);
    vector<string> words;
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        if (rnd.next() >= ratio) { 
            do {
                cur = prev + rand_word(rnd.next(0, 19));
            } while (find(words.begin(), words.end(), cur) != words.end());
        } else {
            do {
                cur = rand_word(rnd.next(1, 20));
            } while (find(words.begin(), words.end(), cur) != words.end());
        }
        words.push_back(cur);
        if (repeat && i == n) {
            cout << words[rnd.next(0, n-2)] << '\n';
        } else {
            cout << cur << '\n';
            prev = cur.back();
        }
    }
}