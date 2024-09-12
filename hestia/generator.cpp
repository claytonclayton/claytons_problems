
#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>

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

const int handcases = 2;

ll random_from_array(vector<ll> arr) {
    uniform_int_distribution<> randi(0, arr.size() - 1);
    int i = randi(gen);
    return arr[i];
}

ll random_product(vector<ll> arr) {
    uniform_int_distribution<> randi(0, arr.size() - 1);
    uniform_int_distribution<> randj(0, arr.size() - 1);

    int i = randi(gen);
    int j = randj(gen);

    return arr[i] * arr[j];
}

choice choose(int w1, int w2, int w3) {
    uniform_int_distribution<> randperc(1, 100);
    int perc = randperc(gen);

    double mult = 100 / (w1 + w2 + w3);

    if (perc <= w3 * mult) return RANDOM;
    if (perc <= (w1 + w3) * mult) return FACTOR;
    return PRODUCT;
}

void generate_array_from_factors(string path, vector<ll> factors, int n, int factor_weight, int product_weight, int rand_weight) {
    ofstream tst(path);
    tst << n << endl;

    for (int i = 0; i < n; i++) {
        choice c = choose(factor_weight, product_weight, rand_weight);

        if (c == FACTOR) {
            tst << random_from_array(factors) << " ";
        } 
        else if (c == PRODUCT) {
            tst << random_product(factors) << " ";
        }
        else {
            uniform_int_distribution<ll> randll(1, FOURTH_ROOT_LLMAX);
            ll num = randll(gen);
            tst << num << " ";
        }
    }
    tst << endl;

    tst.close();
}

vector<ll> get_random_array(ll l, ll r, int n) {
    vector<ll> arr;

    for (int i = 0; i < n; i++) {
        uniform_int_distribution<ll> elem(l, r);
        ll a = elem(gen);
        arr.push_back(a);
    }

    return arr;
}

void generate_random_array(string path, ll l, ll r, int n) {
    ofstream tst(path);

    vector<ll> arr = get_random_array(l, r, n);

    tst << n << endl;    
    for (ll i : arr) {
        tst << i << " ";
    }
    tst.close();
}

string get_path(int testcase) {
    return "data/random/"+to_string(testcase)+".in";
}

/*
test ideas:
- all 1s
- less than 3 elems.
- generate x random factors, then generate y random products by choosing
  a random pair from the factors. For each element of the array include
  either a factor or a product based on some distribution
- Random n. Choose n random numbers
- definitely should be using long longs
- have factors 1 and LL_MAX, products LL_MAX
- have factors 2, 2 and products 4 (test square numbers)
- test a mix of squares and non squares and 1s
- test 1s and random numbers 
*/
int main (void) {
    int testcases = handcases;

    vector<ll> factors;

    // 3 - 7
    // general test
    factors = {2, 3};
    generate_array_from_factors(get_path(++testcases), factors, READABLE, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, SMALL, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, MEDIUM, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, LARGE, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, LARGEST, 1, 1, 0);

    // 8 - 12
    // tests square numbers
    factors = {6};
    generate_array_from_factors(get_path(++testcases), factors, READABLE, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, SMALL, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, MEDIUM, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, LARGE, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, LARGEST, 1, 1, 0);

    // 13 - 17
    // squares and ones
    factors = {1, 8};
    generate_array_from_factors(get_path(++testcases), factors, READABLE, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, SMALL, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, MEDIUM, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, LARGE, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, LARGEST, 1, 1, 0);

    // 18 - 20
    // only 1s
    factors = {1};
    generate_array_from_factors(get_path(++testcases), factors, SMALL, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, MEDIUM, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, LARGEST, 1, 1, 0);

    // 21 - 23
    // ones and random numbers
    factors = {1};
    generate_array_from_factors(get_path(++testcases), factors, SMALL, 1, 1, 1);
    generate_array_from_factors(get_path(++testcases), factors, MEDIUM, 1, 1, 1);
    generate_array_from_factors(get_path(++testcases), factors, LARGEST, 1, 1, 1);

    // 24 - 26
    // ones and LLONG_MAXs
    factors = {1, FOURTH_ROOT_LLMAX};
    generate_array_from_factors(get_path(++testcases), factors, SMALL, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, MEDIUM, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, LARGEST, 1, 1, 0);

    // 27 - 29
    // random small factors
    factors = get_random_array(1, 100, 10);
    generate_array_from_factors(get_path(++testcases), factors, SMALL, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, MEDIUM, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, LARGEST, 1, 1, 0);

    // 30 - 32
    // random big factors
    factors = get_random_array(10'000, FOURTH_ROOT_LLMAX, 10);
    generate_array_from_factors(get_path(++testcases), factors, SMALL, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, MEDIUM, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, LARGEST, 1, 1, 0);

    // 33 - 35
    // random factors
    factors = get_random_array(1, FOURTH_ROOT_LLMAX, 10);
    generate_array_from_factors(get_path(++testcases), factors, SMALL, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, MEDIUM, 1, 1, 0);
    generate_array_from_factors(get_path(++testcases), factors, LARGEST, 1, 1, 0);

    // 36 - 38
    // random array
    generate_array_from_factors(get_path(++testcases), factors, SMALL, 0, 0, 1);
    generate_array_from_factors(get_path(++testcases), factors, MEDIUM, 0, 0, 1);
    generate_array_from_factors(get_path(++testcases), factors, LARGEST, 0, 0, 1);
}
