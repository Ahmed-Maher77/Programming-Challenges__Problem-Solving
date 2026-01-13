// Challenge Link: https://codeforces.com/gym/662071/problem/A


// ==================== Solution 1 ==================== //
// using: string

#include <iostream>
#include <string>
using namespace std;

int main() {
    // create a distinct_Chars [string] / array
    string username, distinct_Chars = "";
    cin >> username;
    
    
    // loop through the name characters
    for (int i = 0; i < username.length(); i++) {
        char currrent_char = username[i];
        // if char exists in distinct_Chars        // T => ignore    // F => add it
        if (distinct_Chars.find(currrent_char) == std::string::npos)   
            distinct_Chars += currrent_char;
    }
    
    // print the length of distinct_Chars
    bool isOdd = distinct_Chars.length() % 2 != 0;
    cout << (isOdd? "IGNORE HIM!" : "CHAT WITH HER!");

    return 0;
}



// ==================== Solution 2 ==================== //
// using: set

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    // create a SET (saves distinct chars)
    string username;
    unordered_set<char> unique_chars;
    
    cin >> username;
    
    // loop over the string chars
    for (int i = 0; i < username.length(); i++) {
        // store in the SET
        char currrent_char = username[i];
        unique_chars.insert(currrent_char);
    }
    
    bool isOdd = unique_chars.size() % 2 != 0;
    cout << (isOdd? "IGNORE HIM!" : "CHAT WITH HER!");

    return 0;
}


/*
# Complexity => solution 1
---- Time: O(n^2)
        loop over the string chars => O(n)
        find() searches linearly => O(n)
---- Space: O(n)
        distinct_Chars => O(n)


# Complexity => solution 2
---- Time: average: O(n) & worst: O(n^2)
        loop over the string chars => O(n)
        insert() => average: O(1) & worst: O(n)
---- Space: O(n)
        distinct_Chars => O(n)    
        or: O(1) because we have limited count of lowercase English letters [26] 
            and Even if the username has 1000 characters like "aaaa...bbb...ccc...", the set will never need more than 26 slots.
*/