// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/665354/problem/D



// ==================== Solution =====================
#include <iostream>
#include <set>
using namespace std;


int main() {
    // take: num_segments, upper_bound
    int num_segments, upper_bound;
    cin >> num_segments >> upper_bound;
    
    // avilable_segments = {} => fill 1:upper_bound
    set<int> avilable_segments;
    for (int i = 1; i <= upper_bound; i++) {      
        avilable_segments.insert(i);
    }
    
    // loop => num_segments
    for (int i = 0; i < num_segments; i++) {
        int l, r;
        cin >> l >> r;
        // erase the segment range from avilable_segments
        auto it1 = avilable_segments.lower_bound(l);
        auto it2 = avilable_segments.upper_bound(r);
        avilable_segments.erase(it1, it2);  
    }
    
    // left_points   => are left in avilable_segments
    cout << avilable_segments.size() << endl;
    
    // left_segments => left_points seperated with " "
    for (auto point: avilable_segments) {
        cout << point << " ";
    }
    
    return 0;
}


/*
# Complexity Analysis:
-- Time: O(n + k log n), where n is the upper_bound, k is the num_segments
------- fill the avilable_segments takes: O(n), where n is the upper_bound
------- taking segments input and erasing the ranges: O(k log n), where n is the upper_bound, k is the num_segments
--------------- taking segments input takes: O(k), where k is num_segments
--------------- erasing ranges takes: O(m log n), set is balanced BST, O(log n) => to find a value, where n is the size of the set, m is the number of points in the range to be erased
--------------- summing up the left points takes: O(m), m is the number of left points
-- Space: O(n), where n is the upper_bound
--------------- storing the avilable_segments takes: O(n), where n is the upper_bound
--------------- storing iterators takes: O(1)
*/