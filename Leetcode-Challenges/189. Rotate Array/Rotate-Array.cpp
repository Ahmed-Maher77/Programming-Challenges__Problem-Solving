// Challenge Link: https://leetcode.com/problems/rotate-array/


// ==================== Solution Method 1 (Solution Method using Extra Array) =====================
// ===== STEPS =====
// ensure k is not negative => if negative => return the same nums;
// if: k = 0 => return the same array
// create a newArray
// loop through the array
    // add each element to a position [3+its original index] in the newArray ensuring not exceding the limit
// update the elements of the givenArray with the elements of newArray
// release the location of the newArray

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k < 0) return;
        if (k == 0) return;

        int arraySize = nums.size();
        int *newArray = new int[arraySize];
        for (int i = 0; i < arraySize; i++) {
            int newPosition = (i + k) % arraySize;
            newArray[newPosition] = nums[i];
        };
        
        for (int i = 0; i < arraySize; i++) {
            nums[i] = newArray[i];
        }
        delete[] newArray;
    }
};

/*
# Complexity:
>> Time:
    filling the newArray => O(n)
    copying back to nums => O(n)
    Total: O(n), where n = nums.size()
>> Space:
    newArray => O(n)
    Total: O(n), where n = nums.size()
*/




// ================= Solution Method 2 (using Cyclic Replacement) =================
// ==== STEPS ====
// if: k <= 0 => return the same array
// currentIndex = 0
// count = 0
// startIndex = 0
// while (cout < size)    
    // currentIndex = startIndex++;
    // oldValue = nums[currentIndex];
    // loop through the array => while (true)
        // newPosition = (currentIndex + k) % size => ensuring not exceding the limit
        // save the old value of the newPosition
        // add element to a its newPosition => arr[newPosition] = arr[currentIndex]
        // currentIndex = newPosition
        // count++
        // if: currentIndex == startIndex => break
    // startIndex++;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0) return;
        k %= size;
        if (k == 0) return;

        int currIndex = 0, startIndex = 0, count = 0, oldValue = nums[currIndex];
        while (count < nums.size()) {
            currIndex = startIndex;
            oldValue = nums[currIndex];
            while(true) {       
                int newPosition = (currIndex + k) % nums.size();
                int newPosition_oldValue = nums[newPosition];   
                nums[newPosition] = oldValue;                   
                oldValue = newPosition_oldValue;                   
                currIndex = newPosition;
                count++;
                if (currIndex == startIndex) break;
            };
            startIndex++;
        }
        
    }
};

/*
# Complexity:
>> Time:
    2 loops => O(n^2)
    Total: O(n^2), where n = nums.size()
>> Space:
    Total: O(1)
*/