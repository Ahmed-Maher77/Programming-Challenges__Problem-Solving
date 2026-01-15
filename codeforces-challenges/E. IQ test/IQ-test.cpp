// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/663127/problem/E



// ================ Solution Code ================
#include <iostream>
using namespace std;

int main() {
    // get count of numbers
    int nums_count;
    int even_count = 0, odd_count = 0, lastEven_index = -1, lastOdd_index = -1;
    cin >> nums_count;

    // loop => 0 : < count
    for (int i = 0; i < nums_count; i++) {
        // get the number
        int current_num;
        cin >> current_num;

        // track the counts
        if (current_num % 2 != 0) {
            odd_count++;
            lastOdd_index = i + 1;
        } else {
            even_count++;
            lastEven_index = i + 1;
        }
    }

    // output the index of the different number => came once
    cout << (even_count == 1 ? lastEven_index : lastOdd_index);
    return 0;
}




/*
# Complexity Analysis:
-- Time Complexity: O(n), where n is the number of integers in the input list.
-- Space Complexity: O(1)
*/