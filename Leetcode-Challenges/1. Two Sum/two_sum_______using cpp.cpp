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


// ===================== Solution 3 ===================== //
// Using brute-force with iterators + std::find

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // loop theough nums array
            // complement = target - nums[i]
            // search for [complement] starting from the next elmenent
            // if: complement exists in nums array
                // T => return [i, complement index]
                // F => nothing
        // not found => return {}

        for (auto it = nums.begin(); it != nums.end(); it++) {
            int complement = target - *it;
            auto complementAddress = find(it+1, nums.end(), complement);
            if (complementAddress != nums.end()) {
                int complementIndex = complementAddress - nums.begin();
                int itIndex = it - nums.begin();
                return {itIndex, complementIndex};
            }
        }
        return {};
    }
};


/*
# Complexity
---- Time: O(n²)
---- Space: O(1)
*/
