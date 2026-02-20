// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/672700/problem/I


#include <iostream>
using namespace std;

int main()
{
    int n, h;
    cin >> n >> h;

    int width = 0;

    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;

        if (x <= h)
            width += 1;
        else
            width += 2;
    }

    cout << width;

    return 0;
}




/*
# Complexity Analysis:
-- Time Complexity: O(n)
    iterates through the list of friends' heights once to calculate the total width needed.
-- Space Complexity: O(1)
    uses a constant amount of extra space to store the width variable and loop index.
    => width, i, x
*/