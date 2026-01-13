// Challenge Link: https://codeforces.com/contest/4/problem/A


// ===================== Solution ===================== //
#include <iostream>
using namespace std;
int main() {
    // take the weight from the user
    int weight;
    cin >> weight;
    
    // ensure it is even => YES   +  special case => w == 2 => NO
    if (weight % 2 != 0 || weight == 2)
        cout<<"NO";
    else
        cout<<"YES";

    return 0;
}




/*
# Complexity
---- Time: O(1)
---- Space: O(1)
*/