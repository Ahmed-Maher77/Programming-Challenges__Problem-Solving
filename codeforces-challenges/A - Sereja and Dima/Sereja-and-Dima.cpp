// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/672700/problem/A



#include <iostream>
#include <vector>
using namespace std;

void updateScore(bool& isSereja_turn, int max_sum, int& sereja_sum, int& dima_sum) {
    if (isSereja_turn) {
        sereja_sum += max_sum;
    } else {
        dima_sum += max_sum;
    }
    isSereja_turn = !isSereja_turn;
}


int main() {
    int n;
    cin >> n;
    vector<int> cards(n);
    
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }
    
    int L = 0, R = n - 1;
    int sereja_sum = 0, dima_sum = 0;
    bool isSereja_turn = true;
    
    while (L <= R) {
        if (cards[L] > cards[R]) {
            updateScore(isSereja_turn, cards[L], sereja_sum, dima_sum);
            L++;
        } else {
            updateScore(isSereja_turn, cards[R], sereja_sum, dima_sum);
            R--;
        }
    }
    
    cout << sereja_sum << " " << dima_sum;
    return 0;
}


/*
# Complexity Analysis:
-- Time complexity: O(n/2) = O(n) since we are iterating through the cards at most once.
-- Space complexity: O(1)
*/