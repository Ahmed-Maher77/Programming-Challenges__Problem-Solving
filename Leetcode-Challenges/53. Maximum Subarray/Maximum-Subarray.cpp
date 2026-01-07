// Challenge Link: https://leetcode.com/problems/maximum-subarray/


// ===================== Solution ===================== //
// ====== STEPS: ======
// maxSum = nums[0]
        // currentSum = nums[0]
        // loop through the nums array => i = 1 : <n
            // if: currentEle > (currentEle + currentSum)
                // T => 
                    // currentSum = currentEle
                    // if: currentSum > maxSum
                        // T => maxSum = currentSum
                // F =>
                    // currentSum = currentEle + currentSum
                    // if: currentSum > maxSum
                        // T => maxSum = currentSum
        // return maxSum;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int currentEle = nums[i];
            currentSum = max(currentEle, currentEle + currentSum);
            maxSum = max(currentSum, maxSum);
        }
        return maxSum;
    }
};



/*
# Complexity
---- Time: O(n)
---- Space: O(1)
*/