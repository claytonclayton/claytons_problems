
#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <sstream>
#include <cassert>

using namespace std;

typedef pair<int, int> pii;
typedef pair<string, string> pss;

const int N1 = 100;
const int N2 = 1'000;
const int N3 = 100'000;

#define SMALL pii(10, N1)
#define MEDIUM pii(N1 + 1, N2)
#define LARGE pii(N2 + 1, N3)

default_random_engine gen(0);

int handcases = 4;
int tests = handcases + 1;

char rand_char(char nott = 0) {
    char c = nott;
    while (c == nott) {
        uniform_int_distribution<int> rand_ascii(97, 122);
        c = char(rand_ascii(gen));
    }
    return c;
}

string rand_str(int size, char nott = 0) {
    string ret;
    for (int i = 0; i < size; i++)
        ret.push_back(rand_char(nott));
    return ret;
}

int rand_range(int l, int r) {
    uniform_int_distribution<int> rand_r(l, r);
    return rand_r(gen);
}

int rand_size(pii size) {
    return rand_range(size.first, size.second);
}

string get_path(int subtask, int testcase) {
    return "../data/random/subtask"+to_string(subtask)+"-"+to_string(testcase)+".in";
}

// y is composed of only x
pss y_all_x(int size) {
    char c = rand_char();
    string x(1, c);
    string y(size, c);
    return pss(x, y);
}

pss y_all_x(pii size) {
    return y_all_x(rand_size(size));
}

// x is on both ends of y
pss x_outside(int size) {
    string x = {rand_char()};
    string y = x + rand_str(size - 2) + x;
    return pss(x, y);
}

pss x_outside(pii size) {
    return x_outside(rand_size(size));
}

// x is on both ends of y and never in the middle
pss x_outside_only(int size) {
    char c = rand_char();
    string x = {c};
    string y = x + rand_str(size - 2, c) + x;
    return pss(x, y);
}

pss x_outside_only(pii size) {
    return x_outside_only(rand_size(size));
}

// x is only on the left
pss x_left(int size) {
    char c = rand_char();
    string x = {c};
    string y = x + rand_str(size - 1, c);
    return pss(x, y);
}

pss x_left(pii size) {
    return x_left(rand_size(size));
}

// x is only on the right
pss x_right(int size) {
    char c = rand_char();
    string x = {c};
    string y = rand_str(size - 1, c) + x;
    return pss(x, y);
}

pss x_right(pii size) {
    return x_right(rand_size(size));
}

// x is only someplace in the middle 
pss x_middle(int size) {
    assert(size >= 3);
    uniform_int_distribution<int> rand_size(1, size - 2);
    int l = rand_size(gen);
    int r = size - l - 1;
    char c = rand_char();
    string x = {c};
    string y = rand_str(l, c) + x + rand_str(r, c);
    return pss(x, y);
}

pss x_middle(pii size) {
    return x_middle(rand_range(3, size.second));
}

// begin |X| > 1 tests

// x is only at the start
pss start(int xsize, int ysize) {
    assert(xsize < ysize);
    string x = rand_str(xsize);
    string y = rand_str(ysize - xsize - 1);
    char c = rand_char(x.back());
    y += {c};
    return pss(x, x + y);
}

pss start(pii xsize, pii ysize) {
    int x = rand_size(xsize);
    int y = rand_size(ysize);
    return start(min(x, y), max(x, y));
}

// x is only at the end
pss end(int xsize, int ysize) {
    assert(xsize < ysize);
    string x = rand_str(xsize);
    string y = rand_str(ysize - xsize - 1);
    char c = rand_char(x[0]);
    y = string{c} + y;
    return pss(x, y + x);
}

pss end(pii xsize, pii ysize) {
    int x = rand_size(xsize);
    int y = rand_size(ysize);
    return end(min(x, y), max(x, y));
}

// x is split at some point and put on the ends of y
pss good_split(int xsize, int ysize) {
    string x = rand_str(xsize);
    int s = rand_range(1, xsize - 2);
    string y = rand_str(ysize - xsize);
    return pss(x, x.substr(0, s) + y + x.substr(s)); // ??
}

pss good_split(pii xsize, pii ysize) {
    return good_split(rand_size(xsize), rand_size(ysize));
}

// x is split in 3 and the middle part is discarded.
// remaining parts are put on the ends of y
pss bad_split(int xsize, int ysize) {
    string x = rand_str(xsize);
    int l = rand_range(1, xsize - 3);
    int r = rand_range(l + 2, xsize - 3);
    string y = rand_str(ysize - xsize);
    return pss(x, x.substr(0, l) + y + x.substr(r));
}

pss bad_split(pii xsize, pii ysize) {
    return bad_split(rand_size(xsize), rand_size(ysize));
}

// max prefix and suffix of x overlaps  
pss overlap(int xsize, int ysize) {
    string x = rand_str(xsize);
    int l = rand_range(1, xsize - 3);
    int r = rand_range(l + 2, xsize - 3);
    string y = rand_str(ysize - xsize);
    return pss(x, x.substr(0, r) + y + x.substr(l));
}

pss overlap(pii xsize, pii ysize) {
    return overlap(rand_size(xsize), rand_size(ysize));
}

pss random_xy(int xsize, int ysize) {
    string x = rand_str(xsize);
    string y = rand_str(ysize);
    return pss(x, y);
}

pss random_xy(pii xsize, pii ysize) {
    string x = rand_str(rand_size(xsize));
    string y = rand_str(rand_size(ysize));
    return pss(x, y);
}

pss double_insert(int size) {
    char a = rand_char();
    char b = rand_char();
    string thing1 = rand_str(size/3);
    string thing2 = rand_str(size/3);
    string thing3 = rand_str(size-size/3-size/3-2);
    return pss(thing1+thing2+thing3, thing1+a+thing2+b+thing3);
}

pss dumb_1(int size) {
    string X, Y;
    do {
        Y = rand_str(size);
    } while (Y[0] == Y[1]);
    X = "";
    X += Y[1];
    X += Y[Y.size()-1];
    return pss(X, Y);
}

pss dumb_2(int size) {
    string X, Y;
    do {
        Y = rand_str(size);
    } while (Y[Y.size()-1] == Y[Y.size()-2]);
    X = "";
    X += Y[0];
    X += Y[Y.size()-2];
    return pss(X, Y);
}

void generate(pss xy, int subtask, int testcase) {
    if (subtask == 1) {
        assert(xy.first.size() == 1);
        assert(xy.second.size() <= N3);
        if (xy.first.size() <= 100 && xy.second.size() <= 100) subtask = 12;
    }
    if (subtask == 2) {
        assert(xy.first.size() <= N1);
        assert(xy.second.size() <= N2);
        if (xy.first.size() == 1) subtask = 12;
    }
    if (subtask == 2) {
        assert(xy.first.size() <= N3);
        assert(xy.second.size() <= N3);
    }
    ofstream tst(get_path(subtask, testcase));
    tst << xy.first.size() << " " << xy.second.size() << endl;
    tst << xy.first << endl;
    tst << xy.second << endl;
    tst.close();
}

void subtask1() {
    cout << tests << ": " << "y_all_x" << endl;
    generate(y_all_x(LARGE), 1, tests++);
    cout << tests << ": " << "y_all_x" << endl;
    generate(y_all_x(N3), 1, tests++);
    cout << tests << ": " << "x_outside" << endl;
    generate(x_outside(LARGE), 1, tests++);
    cout << tests << ": " << "x_outside" << endl;
    generate(x_outside(N3), 1, tests++);
    cout << tests << ": " << "x_outside_only" << endl;
    generate(x_outside_only(LARGE), 1, tests++);
    cout << tests << ": " << "x_outside_only" << endl;
    generate(x_outside_only(N3), 1, tests++);
    cout << tests << ": " << "x_left" << endl;
    generate(x_left(LARGE), 1, tests++);
    cout << tests << ": " << "x_left" << endl;
    generate(x_left(N3), 1, tests++);
    cout << tests << ": " << "x_right" << endl;
    generate(x_right(LARGE), 1, tests++);
    cout << tests << ": " << "x_right" << endl;
    generate(x_right(N3), 1, tests++);
    cout << tests << ": " << "x_middle" << endl;
    generate(x_middle(LARGE), 1, tests++);
    cout << tests << ": " << "x_middle" << endl;
    generate(x_middle(N3), 1, tests++);
}

void subtask2() {
    cout << tests << ": " << "start" << endl;
    generate(start(SMALL, MEDIUM), 2, tests++);
    cout << tests << ": " << "end" << endl;
    generate(end(SMALL, MEDIUM), 2, tests++);
    cout << tests << ": " << "good_split" << endl;
    generate(good_split(SMALL, MEDIUM), 2, tests++);
    cout << tests << ": " << "bad_split" << endl;
    generate(bad_split(SMALL, MEDIUM), 2, tests++);
    cout << tests << ": " << "overlap" << endl;
    generate(overlap(SMALL, MEDIUM), 2, tests++);
    cout << tests << ": " << "random_xy" << endl;
    generate(random_xy(SMALL, MEDIUM), 2, tests++);
    generate(double_insert(1000), 3, tests++);
    cout << tests << ": " << "dumb_1" << endl;
    generate(dumb_1(1000), 3, tests++);
    cout << tests << ": " << "dumb_2" << endl;
    generate(dumb_2(1000), 3, tests++);
}

void subtask3() {
    cout << tests << ": " << "start" << endl;
    generate(start(LARGE, LARGE), 3, tests++);
    cout << tests << ": " << "end" << endl;
    generate(end(LARGE, LARGE), 3, tests++);
    cout << tests << ": " << "good_split" << endl;
    generate(good_split(LARGE, LARGE), 3, tests++);
    cout << tests << ": " << "bad_split" << endl;
    generate(bad_split(LARGE, LARGE), 3, tests++);
    cout << tests << ": " << "overlap" << endl;
    generate(overlap(LARGE, LARGE), 3, tests++);
    cout << tests << ": " << "random_xy" << endl;
    generate(random_xy(LARGE, LARGE), 3, tests++);
    cout << tests << ": " << "double_insert" << endl;
    generate(double_insert(100000), 3, tests++);
    cout << tests << ": " << "dumb_1" << endl;
    generate(dumb_1(100000), 3, tests++);
    cout << tests << ": " << "dumb_2" << endl;
    generate(dumb_2(100000), 3, tests++);
}

/*
Subtask: |X| = 1, |Y| <= 100
Subtask: |X| <= 100, |Y| <= 1000
Full:    |X|, |Y| <= 100 000

case |X| = 1
- pick a random char for x. 
    - y is all x
    - y begins and ends with x, random in between
    - y only begins with x
    - y only ends with x
    - y has x only somewhere in the middle

case |X| <= 100, 100'000
- x is only at the start
- x is only at the end
- x is split at some point and put on the ends of a random string 
- max prefix and suffix of x overlaps  
*/
int main() {
    subtask1();
    subtask2();
    subtask3();
}