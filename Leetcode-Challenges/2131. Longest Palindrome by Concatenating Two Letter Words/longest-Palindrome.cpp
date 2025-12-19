// Challenge Link: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/



// ===================== Solution =====================
/*
words = ["ab","ba","aa","aa"]


"ab" → 1
"ba" → 1
"aa" → 2


word = "ab" → rev = "ba"
word = "aa" → rev = "aa"


Not Equal reverse =>
    "ab" → 2
    "ba" → 1
    pairs = min(2,1) = 1

    "ab" + "ba" → 4 characters

Equal reverse =>
    "aa" → 3 times
    pairs = 3 / 2 = 1
    length += 4

add any word in center
*/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        int length = 0;
        bool hasCenter = false;

        // Count frequency
        for (auto& w : words)
            freq[w]++;

        // Loop around each unique word => meet each word only once
        for (auto& [word, count] : freq) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            // Case 1: "ab" + "ba"
            if (word != rev) {
                int pairs = min(count, freq[rev]);
                length += pairs * 4;
                freq[rev] -= pairs;
                freq[word] -= pairs;
            }
            // Case 2: "aa", "bb", ...
            else {
                int pairs = count / 2;    // to be always couple
                length += pairs * 4;
                freq[word] -= pairs * 2;

                if (freq[word] > 0)
                    hasCenter = true;
            }
        }

        // One center palindrome allowed
        if (hasCenter)
            length += 2;

        return length;
    }
};


/*
# Compexity
---- Time: O(n)    => Count frequency = O(n), Hash Table{best case} = O(1)
---- Space: O(n)
*/