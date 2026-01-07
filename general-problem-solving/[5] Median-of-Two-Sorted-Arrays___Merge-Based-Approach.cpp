/*
# Problem:
    Median of Two Sorted Arrays — Merge-Based Approach
# Description:
    You are given two sorted integer arrays nums1 and nums2 with sizes m and n respectively.
    Your task is to determine the median value of the combined data from both arrays.
    The median is defined as:
    -- The middle element when the total number of elements is odd.
    -- The average of the two middle elements when the total number of elements is even.
    Both input arrays are already sorted in non-decreasing order.
    The final median value should be returned as a floating-point number.
*/



// ====================== Solution ======================
// === STEPS ===:
// merge the 2 array
    // 3 indicators => firstLeft = 0, firstRight = 0, currentIndex = 0;
    // create a new array to store the merged arrays => mergedArr
    // while we are inside the 2 arrays => firstLeft < nums1.size() && firstRight < nums2.size()
        // if: nums1[firstLeft] <= nums2[firstRight]
            // T => add nums1[firstLeft] to the mergedArr => firstLeft++
            // F => add nums2[firstRight] to the mergedArr => firsRight++
            // currentIndex++
    // if there are left elements in any of the 2 arrays => add them to the mergedArr
// if the size is odd
    // T => middle element => arr[size/2] => float
    // F => get the average of the 2 middle elements => (arr[size/2] + arr[size/2 - 1]) / 2  => float

class Solution {
    private:
        void mergeArrs(vector <int> &nums1, vector <int> &nums2, int *mergedArr, int size_1, int size_2) {
            int firstLeft = 0, firstRight = 0, currentIndex = 0;    
            while(firstLeft < size_1 && firstRight < size_2) {
                if (nums1[firstLeft] <= nums2[firstRight]) {
                    mergedArr[currentIndex] = nums1[firstLeft];
                    firstLeft++;
                } else {
                    mergedArr[currentIndex] = nums2[firstRight];
                    firstRight++;
                };
                currentIndex++;
            };
            while(firstLeft < size_1) {
                mergedArr[currentIndex] = nums1[firstLeft];
                firstLeft++;
                currentIndex++;
            };
            while(firstRight < size_2) {
                mergedArr[currentIndex] = nums2[firstRight];
                firstRight++;
                currentIndex++;
            }
        };

        float findMidian(int *arr, int size) {
            if (size%2 != 0) {
                return arr[size/2];
            } else {
                float res = (arr[size/2] + arr[(size/2) - 1]) / 2.f;         // 6 / 2 => 3
                return res;
            }
        }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size_1 = nums1.size();
        int size_2 = nums2.size();
        int size =  size_1 + size_2;
        int *mergedArr = new int[size];
        mergeArrs(nums1, nums2, mergedArr, size_1, size_2);
        delete[] mergedArr;

        float median = findMidian(mergedArr, size);
        return median;
    }
};



/*
# Complexity:
    Time => O(m + n)
    Space => O(m + n)
*/