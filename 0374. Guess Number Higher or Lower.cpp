/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int N) {
        int low = 1, high = N;
        while(low <= high){
            int mid = int((long(low) + high) / 2), g = guess(mid);
            if(g == 0) return mid;
            if(g == 1) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
