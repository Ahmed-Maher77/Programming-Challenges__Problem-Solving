// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/672700/problem/J


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    int L = 0, currHeight = 0;
    int minHeight = 1e9;
    int minIndex = 0;

    for (int R = 0; R < n; R++) {
        currHeight += heights[R];

        if (R - L + 1 == k) {
            if (currHeight < minHeight) {
                minHeight = currHeight;
                minIndex = L;
            }

            currHeight -= heights[L];
            L++;
        }
    }

    cout << minIndex + 1;

    return 0;
}



/*
# Complexity Analysis:
-- Time Complexity: O(n)
    iterates through the list of fence heights once to read the input => O(n)
    iterates through the list of fence heights once to calculate the minimum height sum of k consecutive sections => O(n)
-- Space Complexity: O(1)
    uses a constant amount of extra space to store the minHeight variable and loop index.
    => minHeight, minIndex, currHeight, L, R, and the input vector heights are all O(1) space.
*/