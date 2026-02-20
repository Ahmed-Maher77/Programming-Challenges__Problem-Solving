// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/665354/problem/F



// =================== Solution ===================
#include <iostream>
using namespace std;

int main()
{
    int matrix[5][5];
    int i, j;    // store: position of 1
    
    // take the matrix from the user
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            int num;
            cin >> num;
            // detect the position of 1
            if (num == 1) {
                i = r; j = c;
            }
        }
    }
    
    // calculate the difference between [i,j] and [2,2]
    int numOfMoves = abs(i-2) + abs(j-2);
    
    cout << numOfMoves;

    return 0;
}




/*
# Complexity Analysis
-- Time: O(1)
------- filling a 5x5 matrix takes constant time
-- Space: O(1)
------- using a fixed size matrix
------- i, j, numOfMoves use constant space
*/