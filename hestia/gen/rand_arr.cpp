
#include <iostream>
#include <vector>
#include "../../testlib.h"

using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    int n = stoi(argv[1]);
    int l = stoi(argv[2]);
    int r = stoi(argv[3]);

    for (int i = 0; i < n; i++) {
        cout << rnd.next(l, r) << " ";
    }    
    cout << endl;
}
