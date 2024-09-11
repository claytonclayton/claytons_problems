/*
See ruslana-input.png
The question reduces to the following.
There are three houses (nodes) and three people (triangles). Each person has a bag containing tiles numbered [1, 2, 3]. Each person draws two tiles t, h (with replacement). They wait t days and then travel to house h. After they arrive at a new house they trade the colour of the house with the colour of their hat. If two people arrive at the same house at the same time, they each draw a tile from their bag and the person with the highest tile wins. If they draw, they play until someone wins. The winner trades their hat colour with the house colour. If someone arrives at their own house then they do not trade their hat colour with the house colour. The question is: After 1 day, what is the chance that the houses form a valid 3-colouring? i.e no two adjacent houses share the same colour. 

This verifier uses a brute-force approach to calculate this probability for the specific input shown in ruslana-input.png
*/

#include <iostream>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

int space[7];   // 1-index
int colour[4];  // 1-index
int people[4];  // 1-index
double sol = 0;
int total = 0;

void show_colour() {
    for (int i = 1; i <= 3; i++) {
        cout << colour[i] << " ";
    } cout << endl;
}

void show_space() {
    for (int i = 1; i <= 6; i++) {
        cout << space[i] << " ";
    } cout << endl;
}

void show_pair(pii p, string name = "") {
    if (!name.empty()) cout << name << ": ";
    cout << p.first << " " << p.second << endl;
}

void show_pair(pii p, int name) {
    show_pair(p, to_string(name));
}


// the time the ith person waits before travelling
int wait(int i) {
    return space[2 * i - 1];
}

// the destination of the ith persons journey
int dest(int i) {
    return space[2 * i];
}

// A valid 3-colouring of a triangle should have exactly one of each colour
double is_valid() {
    for (int i = 1; i <= 3; i++) {
        if (colour[i] != 1) return 0.0;
    }
    show_space();
    return 1.0;
}

// simulates the current choice of tiles
void check() {
    // the frequency of each colour at the end of the simulation.
    // A valid 3-colouring of a triangle should have exactly one of each colour
    for (int i = 1; i <= 3; i++) colour[i] = 0;

    // for each house, check the intentions of the people in the two opposite houses.
    // if only one of these people travels to the current house then that person's colour becomes
    // the colour of the current house, so we can increase the frequency of that colour by 1.
    // if both of the opposing people go the current house then they duel. In a triangle,
    // only 1 duel per day can occur, so we test both futures of the duel at the end of the check.
    // if neither person travels to the current house, we increase the frequency of the colour
    // of the current house by 1. 
    pii duel;
    for (int i = 1; i <= 3; i++) {
        int curr = i;
        int opp1 = i % 3 + 1;
        int opp2 = (i + 1) % 3 + 1;

        pii opp1_go = {wait(opp1), dest(opp1)};
        pii opp2_go = {wait(opp2), dest(opp2)};
        pii here = {1, i};

        if (opp1_go == here && opp2_go == here)
            duel = {people[opp1], people[opp2]};
        else if (opp1_go == here) 
            colour[people[opp1]]++;
        else if (opp2_go == here)
            colour[people[opp2]]++;
        else
            colour[i]++;
    }

    // since all players have the same bag of tiles, then winning a duel is 50/50.
    if (duel.first != 0) {
        colour[duel.first]++;
        sol += is_valid() * 0.5;
        colour[duel.first]--;
        colour[duel.second]++;
        sol += is_valid() * 0.5;
    } else {
        sol += is_valid();
    }
    total += 1;
}

// Each of the 3 people choose 2 numbers so there are 
// 3 ** 6 different futures (+ some more since players can arrive at the same
// house at the same time and duel)
void search(int depth) {
    if (depth > 6) {
        check();
        return;
    }
    for (int i = 1; i <= 3; i++) {
        space[depth] = i;
        search(depth + 1);
    }
}

int main() {
    for (int i = 1; i <= 3; i++) 
        people[i] = i % 3 + 1;

    search(1);

    int num = sol;
    for (int i = 2; i <= sqrt(num); i++) {
        while (num % i == 0 && total % i == 0) {
            num /= i;
            total /= i;
        }
    }
    cout << num << "/" << total << endl;
}
