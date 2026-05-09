// Challenge Link: https://leetcode.com/problems/integer-to-roman/?envType=study-plan-v2&envId=top-interview-150


// ===================== Solution ===================== //
// ====== STEPS: ======
// result = ""
    // loop over the symbolsMap (in reverse)
        // num >= symbolsMap[i].value    ==> repeat as long as it is valid (2000 - 1000 => adds "M" but without "while" here, it won't check the same symbol again again)
            // result += symbolsMap[i].symbol
            // num -= symbolsMap[i].value
    // return result


/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    const symbolsMap = [
        { symbol: "I", value: 1 },
        { symbol: "IV", value: 4 },
        { symbol: "V", value: 5 },
        { symbol: "IX", value: 9 },
        { symbol: "X", value: 10 },
        { symbol: "XL", value: 40 },
        { symbol: "L", value: 50 },
        { symbol: "XC", value: 90 },
        { symbol: "C", value: 100 },
        { symbol: "CD", value: 400 },
        { symbol: "D", value: 500 },
        { symbol: "CM", value: 900 },
        { symbol: "M", value: 1000 },
    ];

    let result = "";
    for (let i = symbolsMap.length - 1; i >= 0; i--) {
        while (num >= symbolsMap[i].value) {
            result += symbolsMap[i].symbol;
            num -= symbolsMap[i].value;
        }
    }
    return result
};



/*
# Complexity Analysis
---- Time: O(1)
    to iterate over the symbolsMap array which has a constant number of elements (13)
---- Space: O(1)
    symbolsMap array has a constant number of elements (13) => O(1)
    result string can grow up to a certain limit (e.g., for 3999, it would be "MMMCMXCIX") => O(1)
*/