// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/672700/problem/B


#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n, m;
    vector<int> minutes;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        minutes.push_back(x);
    }
    
    int curr_minutes_sum = 0, max_n_books = 0, n_books = 0;
    int L, R;
    L = R = 0;
    
    while (R < n) {
        curr_minutes_sum += minutes[R];
        while (curr_minutes_sum > m) {
            curr_minutes_sum -= minutes[L];    
            L++;
        }
        
        max_n_books = max(max_n_books, R - L + 1);
        R++;
    }
    
    cout << max_n_books;

    return 0;
}


/*
# Complexity Analysis
-- Time Complexity: O(n), where n is the number of books
-------- getting the number of books => O(n)
-- Space Complexity: O(1)
-------- curr_minutes_sum, max_n_books, n_books, L, R => O(1)
*/