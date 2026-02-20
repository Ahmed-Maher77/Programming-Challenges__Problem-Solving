// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/672700/problem/G


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> columns(n);
    
    for (int i = 0; i < n; i++) {
        cin >> columns[i];
    }
    
    sort(columns.begin(), columns.end());
    
    for (int i = 0; i < n; i++) {
        cout << columns[i] << " ";
    }
    
    
    return 0;
    
}



/*
# Complexity Analysis:
-- Time Complexity: O(n log n) due to the sorting step.
-- Space Complexity: O(n) for storing the columns in a vector.
*/