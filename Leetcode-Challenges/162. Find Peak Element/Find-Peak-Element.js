// Challenge Link: https://leetcode.com/problems/find-peak-element/description/?envType=study-plan-v2&envId=top-interview-150


// ===================== Solution ===================== //
// ====== STEPS: ======
// 1. Initialize two pointers:
//    - left at index 0
//    - right at index nums.length - 1
//
// 2. While left < right:
//    a. Compute middle index
//    b. Compare nums[middle] with nums[middle + 1]
//
// 3. If nums[middle] > nums[middle + 1]:
//    - A peak exists on the left side (including middle)
//    - Move right pointer to middle
//
// 4. Else:
//    - A peak exists on the right side
//    - Move left pointer to middle + 1
//
// 5. When left == right:
//    - The search space is reduced to one element
//    - Return left as the peak index



/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function(nums) {
    let left = 0, right = nums.length - 1;
    let middle;

    while (left < right) {
        middle = Math.floor((left + right) / 2);
        if (nums[middle] > nums[middle + 1]) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }

    return left
};




/*
# Complexity Analysis
---- Time: O(log n)
    At each step, we are halving the search space, so the time complexity is logarithmic.
---- Space: O(1)
    We are using only a constant amount of extra space for the pointers and variables, so the space complexity is O(1).
*/