/*
# Problem:
    Max Pair Sum in an Array

# Description:
    You are given an integer array nums. You have to find the maximum sum of a pair of numbers from nums such that the largest digit in both numbers is equal.
    For example, 2373 is made up of three distinct digits: 2, 3, and 7, where 7 is the largest among them.
    Return the maximum sum or -1 if no such pair exists.
*/



class Solution {
public:
    int maxSum(vector<int>& nums) {
        // Initialize the maximum sum of valid pairs
        int sum = -1;

        // Iterate over each element as the first element of the pair
        for (int i = 0; i < nums.size() - 1; i++) {

            // Find the largest digit of the first element
            int digit_I = findMaxDigit(nums[i]);

            // Iterate over subsequent elements to form a pair
            for (int j = i + 1; j < nums.size(); j++) {

                // Find the largest digit of the second element
                int digit_J = findMaxDigit(nums[j]);

                // If both elements share the same largest digit
                if (digit_I == digit_J) {

                    // Compute the sum of the pair
                    int currentSum = nums[i] + nums[j];

                    // Update maximum sum if current sum is larger
                    if (currentSum > sum) {
                        sum = currentSum;
                    }
                }
            }
        }

        // Return the maximum sum or -1 if no valid pair exists
        return sum;
    }

private:
    int findMaxDigit(int num) {
        // Convert number to string to inspect digits
        std::string numStr = std::to_string(num);

        // Initialize the largest digit with the first character
        int biggestDigit = numStr[0] - '0';

        // Traverse remaining digits to find the maximum
        for (int i = 1; i < numStr.size(); i++) {
            int currentDigit = numStr[i] - '0';
            if (currentDigit > biggestDigit) {
                biggestDigit = currentDigit;
            }
        }

        // Return the largest digit
        return biggestDigit;
    }
};
