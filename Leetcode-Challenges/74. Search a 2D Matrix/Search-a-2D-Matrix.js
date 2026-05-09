// Challenge Link: https://leetcode.com/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-interview-150


// ===================== Solution ===================== //
// ====== STEPS: ======
// find target's row
    // left, right
    // middle (floor) => left + right / 2
    // while (left <= right)
        // update middle
        // if: target >= matrix[middle][0] && target <= matrix[middle][rowLength]  ===> return middle
        // if: target > matrix[middle][0]  ===> left = middle + 1
        // if: target < matrix[middle][0]  ===> right = middle - 1
    // return -1

// find target in its row
    // left, right
    // middle (floor) => left + right / 2
    // while (left <= right)
        // update middle
        // if: matrix[rowNum][middle] === target  ===> return true
        // if: target > matrix[rowNum][middle]  ===> left = middle + 1
        // if: target < matrix[rowNum][middle]  ===> right = middle - 1
    // return false



/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */

function findTargetRow(matrix, target) {
    let left = 0, right = matrix.length - 1;
    let middle;
    let rowLength;

    while (left <= right) {
        middle = Math.floor((left + right) / 2);
        rowLength = matrix[middle].length - 1;
        if (target >= matrix[middle][0] && target <= matrix[middle][rowLength]) {
            return middle;
        }
        if (target > matrix[middle][0]) {
            left = middle + 1
        } else {
            right = middle - 1
        }
    }
    
    return -1;
}

var searchMatrix = function(matrix, target) {
    const rowNum = findTargetRow(matrix, target);
    if (rowNum === -1) return false;

    let left = 0, right = matrix[rowNum].length - 1;
    let middle;

    while (left <= right) {
        middle = Math.floor((left + right) / 2);
        if (matrix[rowNum][middle] === target) {
            return true
        }
        if (target > matrix[rowNum][middle]) {
            left = middle + 1
        } else {
            right = middle - 1
        }
    }
    return false;
    
};







/*
# Complexity Analysis:
-- Time: O(log m*n)
    O(log m): to find the target's row using binary search
    O(log n): to find the target in its row using binary search
-- Space: O(1)
    The algorithm uses a constant amount of space for the left, right, and middle pointers, regardless of the input size.
*/