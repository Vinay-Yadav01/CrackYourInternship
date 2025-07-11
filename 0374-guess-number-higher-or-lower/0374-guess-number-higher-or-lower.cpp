/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is higher than the picked number
 *               1 if num is lower than the picked number
 *               0 if num is equal to the picked number
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;    
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int result = guess(mid);
            
            if (result == 0) {
                return mid;
            } else if (result == -1) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
