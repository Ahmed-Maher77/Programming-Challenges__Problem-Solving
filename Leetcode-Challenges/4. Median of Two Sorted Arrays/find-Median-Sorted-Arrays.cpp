/*
# Problem:
    Median of Two Sorted Arrays
# Description:
    Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
    The overall run time complexity should be O(log (m+n)).
    Example 1:
        Input: nums1 = [1,3], nums2 = [2]
        Output: 2.00000
        Explanation: merged array = [1,2,3] and median is 2.
    Example 2:
        Input: nums1 = [1,2], nums2 = [3,4]
        Output: 2.50000
        Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/



// =============== Solution ===============
/*
nums1 = [1,3], nums2 = [2]

swap
nums1 = [2], nums2 = [1,3]

[2] | []
[1] | [3]

max(2, 1) => 2
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // choose the smallest array to apply BinarySearch on
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        int x = nums1.size();
        int y = nums2.size();

        int low = 0, high = x;

        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;

            int maxLeftX  = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            int maxLeftY  = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) +
                            min(minRightX, minRightY)) / 2.0;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            }
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            }
            else {
                low = partitionX + 1;
            }
        }

        return 0.0; // will never reach here
    }
};



/*
# Complexity:
    Time: O(log(min(m, n)))
    Space: O(1)
*/