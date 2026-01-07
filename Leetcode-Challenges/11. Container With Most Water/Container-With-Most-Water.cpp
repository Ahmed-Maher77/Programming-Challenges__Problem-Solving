// Challenge Link: https://leetcode.com/problems/container-with-most-water/


// ===================== Solution ===================== //
// Using Two Pointers

// ===== Steps =====:
// leftPointer = 0, rightPointer = size-1
// maxArea = 0

// while loop => leftPointer < rightPointer
    // get the smallestPointerVal, width = rightPointer - leftPointer
    // area = smallestPointerVal * width    
    // if: area > maxArea
        // T => update the maxArea with area
        // F => nothing
    
    // move the pointer used in calculating area:
        // if: smallestPointerVal == height[leftPointer]
            // T => leftPointer moves right (++)
            // F => rightPointer moves left (--)
// return maxArea

class Solution {
    protected:
        int getSmallest(int n1, int n2) {
            if (n1 < n2)
                return n1;
            else 
                return n2;
        }
    public:
        int maxArea(vector<int>& height) {
            int leftPointer = 0, rightPointer = height.size()-1;
            int maxArea = 0;

            while(leftPointer < rightPointer) {
                int smallestPointerVal = getSmallest(height[leftPointer], height[rightPointer]);
                int width = rightPointer - leftPointer;
                int area = smallestPointerVal * width;
                if (area > maxArea) {
                    maxArea = area;
                }
                if (smallestPointerVal == height[leftPointer])
                    leftPointer++; 
                else
                    rightPointer--;
            };
            return maxArea;
    }
};



/*
# Complexity
---- Time: O(n)
---- Space: O(1)
*/
