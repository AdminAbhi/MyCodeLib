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
    int guessNumber(int n) {
        long long l=0;
        while(l <= n){
            long long m = (l+n)/2;
            long long res = guess(m);
            if(res == 0) return m;
            else if(res > 0) l = m+1;
            else n = m-1;
        }
        return -1;
    }
};
