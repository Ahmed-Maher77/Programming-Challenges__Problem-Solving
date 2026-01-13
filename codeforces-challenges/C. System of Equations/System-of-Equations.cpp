// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/663127/problem/C




// ============== Solution ==============
#include <iostream>
#include <cmath>
using namespace std;


int applyEq2(int a, int b) {
    return (b*b) + a;
}

int main() {
    int pairs_count = 0;      // track the count of the pairs
    int n, m, maxNum;
    cin >> n;
    cin >> m;
    
    maxNum = (n > m)? n : m;
    
    // outer loop => determine a => 1 : <sqrt(maxNum)
    for (int a = 0; a*a <= maxNum; a++) {
        // get b from equation 1
        int b = n - (a*a);
        // apply equation 1 & 2   => pairs_count++;
        if (b >= 0 && applyEq2(a, b) == m) {
                pairs_count++;
        }
    }
    
    cout << pairs_count;
}




/*
# Complexity Analysis:
-- Time Complexity: O(√max(n, m))
    => We are iterating 'a' from 0 to √max(n, m)
-- Space Complexity: O(1)
    => We are using a constant amount of space (maxNum, pairs_count, a, b)
*/