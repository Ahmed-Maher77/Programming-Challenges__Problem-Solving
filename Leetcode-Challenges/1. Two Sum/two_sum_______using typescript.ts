// =================== Solution 1 =================== //
// using 2 Loops + condition  => O(n^2) 

function twoSum(nums: number[], target: number): number[] {
    // outer loop => i = 0:<size
        // inner loop => j = i+1
            // if: nums[i] + nums[j] === target
                // T => return [i, j]
                // F => continue
    // if no solution is found => return []

    for (let i = 0; i < nums.length; i++) {
        for (let j = i+1; j < nums.length; j++) {
            if (nums[i] + nums[j] === target)
                return [i,j]
            else
                continue;
        }
    };

    return [];  
};



// =================== Solution 2 =================== //
// using Hash Table (Map) => O(n)
function twoSum(nums: number[], target: number): number[] {
    // create a hash table => {ele, index}
    // loop over the array => i = 0:<size
        // nums[i] + ? = target =>  if: ? exists in hastTable
            // T => return its index => return [i, index_hashTable]
            // F => add to hashTable
    // not found => return {}

    let hashTable = new Map<number, number>();
    for (let i:number = 0; i < nums.length; i++) {
        let compelemnt:number = target - nums[i];
        if (hashTable.has(compelemnt)) {
            let index_hashTable:number = hashTable.get(compelemnt);
            return [i, index_hashTable];
        } else {
            hashTable.set(nums[i], i);
        }
    };

    return [];
};