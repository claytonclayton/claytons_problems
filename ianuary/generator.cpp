#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>
using namespace std;

const int N = 10'000;
const int M = 10'000;
int mins[M];
int n, m, maxm, maxn = 0;
const int handcases = 1;

default_random_engine gen(0);

// the ith line of mins is the minimum array size
// required to make i Ianuarian Triples
void read_min_file() {
    ifstream minfile("mins");

    int line, i;
    for (i = 1; i <= M && (minfile >> line); i++) {
        mins[i] = line;
        maxn = max(maxn, line);
    }
    maxm = i;
    minfile.close();
}

int main (void) {
    read_min_file();

    ofstream tst("data/handcases/1.in");
    tst << 100 << endl;
    for (int i = 1; i <= 100; i++) {

        tst << mins[i]     << " " << i << endl;
        tst << mins[i] - 1 << " " << i << endl;
    }

    tst.close();

    int t = 1;
    for (int j = handcases + 1; j < handcases + 3; j++) {
        ofstream tst("data/random/"+to_string(j)+".in");

        t *= 100;
        tst << t << endl;
        for (int i = 0; i < t / 3 + 1; i++) {
            uniform_int_distribution<> randm(1, maxm);
            uniform_int_distribution<> randn(1, maxn);
            int m = randm(gen);
            int n = randn(gen);

            // Testcase 1:
            // Since mins[m] is the minimum array size s to make m Ianuarian Triples,
            // then (mins[m], m) should always output YES
            // 
            // Testcase 2:
            // For the same reason as above, (mins[m] - 1, m) should always output NO 
            //
            // Testcase 3:
            // Choose a random number n and test (n, m)

            tst << mins[m]     << " " << m << endl;
            tst << mins[m] - 1 << " " << m << endl;
            tst << n           << " " << m << endl;
        }

        tst.close();
        maxm = M;
        maxn = N;
    }
}
