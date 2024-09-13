
#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include "../../testlib.h"

using namespace std;

default_random_engine gen(0);

typedef long long ll;

enum choice {
    FACTOR, PRODUCT, RANDOM
};

const int READABLE = 10;
const int SMALL = 100;
const int MEDIUM = 1'000;
const int LARGE = 5'000;
const int LARGEST = 10'000;

const ll FOURTH_ROOT_LLMAX = 31'600;

ll random_from_array(vector<ll> arr) {
    return rnd.any(arr);
}

ll random_product(vector<ll> arr) {
    return rnd.any(arr) * rnd.any(arr);
}

choice choose(int w1, int w2, int w3) {
    int perc = rnd.next(1, 100);

    double mult = 100 / (w1 + w2 + w3);

    if (perc <= w3 * mult) return RANDOM;
    if (perc <= (w1 + w3) * mult) return FACTOR;
    return PRODUCT;
}

void generate_array_from_factors(int n, int factor_weight, int product_weight, int rand_weight, vector<ll> factors) {
    cout << n << endl;

    for (int i = 0; i < n; i++) {
        choice c = choose(factor_weight, product_weight, rand_weight);

        if (c == FACTOR)
            cout << random_from_array(factors) << " ";
        else if (c == PRODUCT)
            cout << random_product(factors) << " ";
        else
            cout << rnd.next(1LL, FOURTH_ROOT_LLMAX) << " ";
    }
    cout << endl;
}

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    int n = stoi(argv[1]);
    int factor_weight = stoi(argv[2]);
    int product_weight = stoi(argv[3]);
    int rand_weight = stoi(argv[4]);

    vector<ll> factors;
    for (int i = 5; i < argc; i++)
        factors.push_back(stoi(argv[i]));

    generate_array_from_factors(n, factor_weight, product_weight, rand_weight, factors);
}
