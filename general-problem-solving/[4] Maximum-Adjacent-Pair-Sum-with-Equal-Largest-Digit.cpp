/*
# Problem: 
    Maximum Adjacent Pair Sum with Equal Largest Digit

# Problem Description:
    You are given an integer array nums.
    Your task is to find the maximum sum of two adjacent elements in the array such that the largest digit of both numbers is equal.
    The largest digit of a number is defined as the maximum digit appearing in its decimal representation.
    Return the maximum sum of any valid adjacent pair.
    If no such adjacent pair exists, return -1.
*/



class Solution {
public:
    int maxSum(vector<int>& nums) {

        // Track indices of the current and next adjacent elements
        int curr = 0;
        int nxt = 1;

        // Store the maximum valid adjacent pair sum
        int sum = -1;

        // Iterate over adjacent pairs in the array
        for (int i = 0; i < nums.size() - 1; i++) {

            // Find the largest digit of the current element
            int digitCurr = findMaxDigit(nums[curr]);

            // Find the largest digit of the next element
            int digitNxt = findMaxDigit(nums[nxt]);

            // If both elements share the same largest digit
            if (digitCurr == digitNxt) {

                // Compute the sum of the adjacent pair
                int currentSum = nums[curr] + nums[nxt];

                // Update the maximum sum if a larger one is found
                if (currentSum > sum) {
                    sum = currentSum;
                }
            }

            // Move to the next adjacent pair
            curr++;
            nxt++;
        }

        // Return the maximum sum or -1 if no valid pair exists
        return sum;
    }

private:
    int findMaxDigit(int num) {

        // Convert the number to a string for digit inspection
        std::string numStr = std::to_string(num);

        // Initialize the largest digit using the first character
        int biggestDigit = numStr[0] - '0';

        // Traverse remaining digits to find the maximum
        for (int i = 1; i < numStr.size(); i++) {
            int currentDigit = numStr[i] - '0';
            if (currentDigit > biggestDigit) {
                biggestDigit = currentDigit;
            }
        }

        // Return the largest digit found
        return biggestDigit;
    }
};

