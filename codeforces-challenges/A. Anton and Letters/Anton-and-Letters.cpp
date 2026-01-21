// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/665354/problem/A



// =================== Solution 1 ===================
// using: hashTable (unordered_map in C++)
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    // take a string in this format: {a, b, c}
    string givenLetters;
    
    // create a hashTable to track frequency
    unordered_map<char, int> freqTable;
    getline(cin, givenLetters);
    
    // loop through the string => selecting only the characters
    for (int i = 0; i < givenLetters.size(); i++) {
        if (givenLetters[i] >= 'a' && givenLetters[i] <= 'z') {
            // hashTable[str[i]]++
            freqTable[givenLetters[i]]++;
        }
    }

    cout << freqTable.size();
    return 0;
}


/*
# Complexity Analysis:
-- Time: O(n)
-------- loop through the string => O(n), where n is the length of the string
-------- hashTable insertion and lookup => O(1) on average
-- Space: O(k) => can be O(1) since k <= 26
-------- freqTable to store unique characters => O(k), where k is the number of unique characters
*/




// =================== Solution 2 ===================
// using: frequency array
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // take a string in this format: {a, b, c}
    string givenLetters;
    
    // create a freqArray to track frequency => index: letter, value: freq
    int freqArray[26] = {0};
    getline(cin, givenLetters);
    
    // loop through the string => selecting only the characters
    for (int i = 0; i < givenLetters.size(); i++) {
        if (givenLetters[i] >= 'a' && givenLetters[i] <= 'z') {
            const int freqArr_index = givenLetters[i] - 'a';    // a => index 0
            freqArray[freqArr_index]++;
        }
    }
    
    // loop through freqArray => count the chars appeared at least one time (val >= 1)
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (freqArray[i] >= 1)
            count++;
    }
    
    cout << count;    
    return 0;
}




/*
# Complexity Analysis:
-- Time: O(n)
-------- loop through the string => O(n), where n is the length of the string
-------- freqArray insertion => O(1)
-- Space: O(1)
-------- freqArray to store unique characters => O(1) because k = 26 (constant)
*/

