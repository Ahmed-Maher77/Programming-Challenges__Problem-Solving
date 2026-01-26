// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/665354/problem/C



// ===================== Solution 1 =====================
// using: brute-force + bubble sort
#include <iostream>
#include <vector>
using namespace std;


void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void bubble_sort(vector<int>& arr) { 
    for (int i = 0; i < arr.size() - 1; i++)
        for (int j = 0; j < arr.size() - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
        }
    }
}


int main() {
    // take: num_tv_at_sale, num_tv_can_carry
    int num_tv_at_sale, num_tv_can_carry;
    // tvs = []
    vector<int> tvs; 
    cin >> num_tv_at_sale >> num_tv_can_carry;
    
    // loop => 0:num_tv_at_sale
    for (int i = 0; i < num_tv_at_sale; i++) { 
        // get a tv then push in tvs[]
        int givenTv;
        cin >> givenTv;
        tvs.push_back(givenTv);
    }
    
    // sort the tvs in ASC order
    bubble_sort(tvs);
    
    // sum_money = 0
    int sum_money = 0;
    // loop => 0:num_tv_can_carry, special case: num_tv_can_carry > num_tv_at_sale
    for (int i = 0; i < num_tv_can_carry && i < num_tv_at_sale; i++) {
        // negative price => sum_money += -tvs[i]
        if (tvs[i] < 0)
            sum_money += -tvs[i];
    }
    
    // print sum_money
    cout << sum_money;

    return 0;
}


/*
# Complexity Analysis:
-- Time: O(n^2), where n is num_tv_at_sale
--------- bubble_sort() is O(n^2), where n is num_tv_at_sale
--------- taking input is O(n), where n is num_tv_at_sale
--------- summing up the negative prices is O(m), where m is num_tv_can_carry
-- Space: O(n), where n is num_tv_at_sale
--------- storing the tv prices in a vector takes O(n) space
*/


// ===================== Solution 2 =====================
// using: Filtering negatives early + sort() from STL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0) v.push_back(x);
    }

    sort(v.begin(), v.end());

    int sum = 0;
    for (int i = 0; i < v.size() && i < m; i++)
        sum += -v[i];

    cout << sum;
}


/*
# Complexity Analysis:
-- Time: O(n log n), where n is num_tv_at_sale
--------- taking input is O(n), where n is num_tv_at_sale
--------- sorting the negative prices takes O(k log k), where k is the number of negative prices; because sort() applies Heapsort or Quicksort internally
--------- summing up the negative prices is O(m), where m is num_tv_can_carry
-- Space: O(k), where k is the number of negative prices
--------- storing the negative tv prices in a vector takes O(k) space
*/