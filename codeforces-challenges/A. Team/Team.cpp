// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/663127/problem/A



// ===================== Solution =====================
// using: Brute Force

#include <iostream>
using namespace std;

int main()
{
    // create solutions_counter = 0
    int n;
    cin >> n;
    int solutions_counter = 0;
    
    // outer loop => n
    for (int i = 0; i < n; i++) {
        // participants_sum to track the count of acceptance
        int participants_sum = 0;
        // inner loop => 3 participants
        for (int j = 0; j < 3; j++) {
           int isAccept;
           cin >> isAccept;
           participants_sum += isAccept;
        }   
        // add 1 if solved, otherwise 0
        solutions_counter += (participants_sum >= 2)? 1 : 0;
    }
    
    
    cout<< solutions_counter;
 
    return 0;
}




/*
# Complexity Analysis:
-- Time Complexity: O(n)
        => Looping through the number of problems => O(n)
        => Looping through the participants of each problem 3 times => O(3) => O(1)
-- Space Complexity: O(1)
        => Using only a constant amount of extra space (solutions_counter, participants_sum, isAccept)
*/