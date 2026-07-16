/*
Leet Code - 2220 :- Minimum flips required to convert to a number.
Approach was like:-
1. Do like take the xor of both start and end.
2. By doing so the digits which needs to be flipped are converted to 1.
3. Then simply count the number of 1s thats our answer.

Time Complexity : O(1) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start^goal;
        int count=0;
        for(int i=0;i<32;i++){
             if(x&(1<<i))
             count ++;
        }
        return count;
    }
};
