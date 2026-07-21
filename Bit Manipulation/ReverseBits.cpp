/*
LeetCode - 190 :- Reverse Bits.

Approach :-
1. We extract the last bit of the given number using (n & 1).
2. Before inserting this bit into the answer, we left shift the answer by one
   position so that there is space for the new bit.
3. We insert the extracted bit into the answer using the OR (|) operator.
4. Then we right shift the given number to remove the last bit and move to
   the next bit.
5. Since the input is a 32-bit unsigned integer, we repeat this process exactly
   32 times.
6. At the end, the answer contains the bits in reverse order.

Time Complexity : O(32) = O(1).
Space Complexity : O(1).

*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            ans |= (n & 1);
            n >>= 1;
        }

        return ans;
    }
};
