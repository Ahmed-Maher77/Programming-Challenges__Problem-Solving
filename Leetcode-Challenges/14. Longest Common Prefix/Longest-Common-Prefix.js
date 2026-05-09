// Challenge Link: https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150


// ===================== Solution ===================== //
// ====== STEPS: ======
// finalPrefix = ''
    // outer loop: over strs[0] => i
        // inner loop: y = 1
            // strs[y][i] === strs[0][i]
                // yes => nothing
                // no => return finalPrefix
        // js specific: isMatching = strs.every((str) => str[i] === strs[0][i])   => isMatching => finalPrefix += strs[0][i]
        // finalPrefix += strs[0][i]
    // return finalPrefix


/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let finalPrefix = "";
    for (let i = 0; i < strs[0].length; i++) {     // O(m) => m = length of the first string
        for (let j = 1; j < strs.length; j++) {    // O(n) => n = number of strings in the array
            if (strs[j][i] !== strs[0][i]) {
                return finalPrefix;
            }
        }
        finalPrefix += strs[0][i];
    }
    return finalPrefix;
};




/*
# Complexity Analysis
---- Time: O(m * n)
    O(m): to loop over the first string
    O(n): to loop over the rest of the strings
---- Space: O(1)
*/