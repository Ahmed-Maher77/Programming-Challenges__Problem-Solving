// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/672700/problem/C


#include <iostream>
#include <string>
using namespace std;

int getCount(string str, int max_len, char target) {
    int ptrL, ptrR;
    ptrL = ptrR = 0;
    int maxLen = 0, changes = 0;
    
    while(ptrR < str.length()) {
        if (str[ptrR] != target)
            changes++;
        while (changes > max_len) {
            if (str[ptrL] != target)
                changes--;
            ptrL++;
        }
        maxLen = max(maxLen, ptrR - ptrL + 1);
        ptrR++;
        }
    return maxLen;
}


int main() {
    int str_len, max_len;
    string str;
    cin >> str_len >> max_len;
    
    for (int i = 0; i < str_len; i++) {
        cin >> str;
    }
    
    int max_len_a = getCount(str, max_len, 'a');
    int max_len_b = getCount(str, max_len, 'b');
    
    cout << (max_len_a > max_len_b? max_len_a : max_len_b) << endl;
    return 0;
}


/*
# Complexity Analysis:
-- Time complexity: O(n)
-- Space complexity: O(1)
*/