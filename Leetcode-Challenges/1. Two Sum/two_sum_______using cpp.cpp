// ========================== Solution 1 ========================== //
// Using Hash Table (unordered_map)  
// Time Complexity: 
    // best/average case => O(n) 
    // worst case: O(n^2)


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create hashTable => {number -> index}
        // loop over the array => 0:<size
            // curr + ? = target  => if [?] exists in hastable 
                                        // T => retrieve its index
                                        // F => add to hashTable

        unordered_map<int, int> hashTable;
        for (int i = 0; i < nums.size(); i++) {         // O(n1)
            int complement = target - nums[i];
            int foundIndex = isExistInHashTable(complement, hashTable);  // O(1)
            if (foundIndex != -1)
                return {foundIndex, i};
            else
                hashTable[nums[i]] = i;
        }
        return {};
    }

    int isExistInHashTable(int ele, unordered_map<int, int> &hashTable) {
        if (hashTable.find(ele) != hashTable.end()) {
            return hashTable[ele];
        };
        return -1;
    }
};





// ========================== Solution 2 ========================== //
// Brute Force => using Loops and conditions
// Time Complexity [best/average/worst]: O(n^2)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // outer loop => i = 0 : <size
        // inner loop => j = i+1 : <size
        // arr[i] + arr[j] == target => return [i, j]

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // return empty vector if no solution is found
    }
};
