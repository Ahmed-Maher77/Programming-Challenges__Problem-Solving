// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/665354/problem/E



// ================= Solution =================
// using: unordered_map
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // take: num_members, num_members_team
    int num_members, num_members_team;
    cin >> num_members >> num_members_team;
    
    // create a map: uniqueMembers => { rating: index }
    unordered_map<int, int> uniqueMembers;
    
    // loop => num_members
    for (int i = 0; i < num_members; i++) {
        // get the member rating then store in uniqueMembers
        int rating;
        cin >> rating;
        if (uniqueMembers.count(rating) == 0)
            uniqueMembers[rating] = i+1;
    }
    
    // uniqueMembers.size() >= num_members_team
    if (uniqueMembers.size() >= num_members_team) {
        // T => YES => print their indices
        cout << "YES" << endl;
        int count = 0;
        for (auto pair : uniqueMembers) {
            cout << pair.second << " ";
            count++;
            if (count >= num_members_team) break;
        }
    } else {
        // f => NO
        cout<<"NO";
    }
    
    return 0;
}



/*
# Complexity Analysis:
-- Time: O(n), where n is num_members
--------- taking input of n members => O(n), where n is num_members
--------- inserting in unordered_map => O(1) average case
--------- printing the indices of team members => O(k), where k is num_members_team
-- Space: O(n), where n is num_members
--------- unordered_map storing up to n members
--------- count variable => O(1)
*/