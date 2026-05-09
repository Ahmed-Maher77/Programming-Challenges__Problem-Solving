// Challenge Link: https://leetcode.com/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-interview-150


// ===================== Solution ===================== //
// ====== STEPS: ======
// 1. Initialize left and right pointers
// 2. While left pointer is less than or equal to right pointer:
//    a. Calculate the middle index
//    b. If the middle element is equal to the target, return the index
//    c. If the target is greater than the middle element, move the left pointer to the right of the middle index
//    d. If the target is less than the middle element, move the right pointer to the left of the middle index
// 3. If the target is not found, return the left pointer as the insertion position
    // why? because: 
        // target > nums[middle] ==> return left = middle + 1
        // target < nums[middle] ==> return right = middle - 1 => max(0, middle {0} - 1) => return left = 0


/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    // left, right
    let left = 0, right = nums.length - 1;
    // find middle (floor)
    let middle;

    // while (left <= right)
    while (left <= right) {
        middle = Math.floor((left + right) / 2);
        if (nums[middle] === target) {
            return middle;
        } 
        if (target > nums[middle]) {
            left = middle + 1;
        } 
        if (target < nums[middle]) {
            right = middle - 1;
        } 
    }

    return left;
};


/*
# Complexity Analysis:
-- Time: O(log n) - Binary search algorithm has a logarithmic time complexity because it halves the search space with each iteration.
-- Space: O(1) - The algorithm uses a constant amount of space for the left, right, and middle pointers, regardless of the input size.
*/