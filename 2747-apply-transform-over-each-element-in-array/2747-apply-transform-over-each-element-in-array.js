/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let transformedArr = [];
    let n = arr.length;
    for(let i=0;i<n;i++){
        let val = fn(arr[i], i);
        transformedArr.push(val);
    }
    return transformedArr;
};