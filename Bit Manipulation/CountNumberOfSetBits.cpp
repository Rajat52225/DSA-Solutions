/*
Aim :- To count the number of set bits.
So approach was like:-
1. Run a loop until n exists and l and a variable count are set to zero initially.
2. Then check if kth bit of n is 1.
3. If its one then toggle the bit and increase count.
4. Increase the k also by one on each iteration whether kth bit is 1 or not.

Time Complexity : O(1).
Space Complexity : O(1) .

*/

class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        int k = 0;

        while (n && k < 32) {
            if (n & (1 << k)) {
                n ^= (1 << k);
                count++;
            }
            k++;
        }

        return count;
    }
};
