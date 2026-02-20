// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/672700/problem/H



#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int A_count = 0, D_count = 0;

    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;

        if (x == 'A')
            A_count++;
        else
            D_count++;
    }

    if (A_count > D_count)
        cout << "Anton";
    else if (A_count < D_count)
        cout << "Danik";
    else
        cout << "Friendship";

    return 0;
}




/*
# Complexity Analysis:
-- Time Complexity: O(n),
   since we iterate through all n games once.

-- Space Complexity: O(1),
   because we only use a constant amount of extra memory.
*/