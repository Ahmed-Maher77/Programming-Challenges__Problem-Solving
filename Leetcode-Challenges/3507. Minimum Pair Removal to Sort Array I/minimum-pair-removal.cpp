/*
# Problem:
    Minimum Pair Removal to Sort Array I
# Description:
    Given an array nums, you can perform the following operation any number of times:
    Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
    Replace the pair with their sum.
    Return the minimum number of operations needed to make the array non-decreasing.
    An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).
*/


class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        // numOperations = 0
        // while (!isSorted)
            // minSum = INT_MAX;  index = 0;
            // loop through the array => 0 : <size-1
                // sum = arr[i] + arr[i+1]  => sum < minSum
                    // T => minSum = sum;  index = i;
                    // F => nothing
            // arr[index] += arr[index+1];
            // remove arr[i+1] from the array
            // numOperations++
        // return numOperations


        int numOperations = 0;
        while (!isSorted(nums)) {
            int minSum = INT_MAX, index = 0;
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i+1];
                if (sum < minSum) {
                    minSum = sum;
                    index = i;
                }
            };
            nums[index] += nums[index+1];
            nums.erase(nums.begin() + index+1);
            numOperations++;
        }
        return numOperations;
    }

private:
    bool isSorted(vector<int> nums) {
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] > nums[i+1]) 
                return false;
        };
        return true;
    }
};



/*
# Complexity Analysis

>> Time Complexity:  𝑂(𝑛^3)
-- isSorted → O(n)
-- find min-sum pair → O(n)
-- erase → O(n)
-- repeated up to n times

>> Space Complexity:   O(1)
-- in-place modification, no extra data structures
*/