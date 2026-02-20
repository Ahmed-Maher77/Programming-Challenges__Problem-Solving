// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/672700/problem/F



#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    
    for (char &c : str1)
        c = tolower(c);

    for (char &c : str2)
        c = tolower(c);

    if (str1 == str2)
        cout << 0;
    else if (str1 > str2)
        cout << 1;
    else
        cout << -1;

    return 0;
}




/*
# Complexity Analysis:
-- Time Complexity: O(n), where n is the length of the input strings. We need to iterate through each character of both strings to convert them to lowercase and compare them.
-- Space Complexity: O(1), as we are modifying the strings in place and not using any additional data structures that grow with the input size.
*/