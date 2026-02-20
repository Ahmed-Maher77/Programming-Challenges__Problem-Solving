// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/672700/problem/D


#include <iostream>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    // Count total distinct pokemon types
    set<char> types(s.begin(), s.end());
    int totalTypes = types.size();

    unordered_map<char, int> freq;
    int left = 0;
    int distinctCount = 0;
    int minLength = n;

    // Sliding window
    for (int right = 0; right < n; right++)
    {
        freq[s[right]]++;

        if (freq[s[right]] == 1)
            distinctCount++;

        while (distinctCount == totalTypes)
        {
            minLength = min(minLength, right - left + 1);

            freq[s[left]]--;
            if (freq[s[left]] == 0)
                distinctCount--;

            left++;
        }
    }

    cout << minLength;

    return 0;
}
