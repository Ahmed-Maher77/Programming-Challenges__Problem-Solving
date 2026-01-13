// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/663127/problem/B



// =================== Solution ===================
// using hash Table (unordered_map)

#include <iostream>
#include <unordered_map>
#include <cctype>
using namespace std;

int main()
{
    int word_length;
    string word;
    cin >> word_length;
    cin >> word;
    
    // special case =>      string length < 26  => NO
    if (word_length < 26) {
        cout << "NO";
    } else {
        // create a hash Table contains the all alphapitic characters and the count/value is 0
        unordered_map<char, int> hashTable;
        string allChars = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0; i < 26; i++)
            hashTable[allChars[i]] = 0;
        
        // loop over the string chars
        for (char c: word) {
            // search for the current_char in the hash Table
            bool isFound = (hashTable.find(std::tolower(c)) != hashTable.end());
            // found (case insensitive) => remove it
            if (isFound)
                hashTable.erase(tolower(c));
        }
        
        // check if the size of hashTable != 0 => NO otherwise YES
        if (hashTable.size() > 0)
            cout << "NO";
        else
            cout << "YES";
    }
        
    
    return 0;
}




/*
Complexity Analysis:
-- Time Complexity: O(N) where N is the length of the input string.
        => Fill the hash table takes O(1) since it's fixed size (26 letters),
        => Looping through the string takes O(N)
        => Each hash table operation (find, erase) takes O(1) on average.
-- Space Complexity: O(1) since the hash table size is fixed (26 letters).
*/