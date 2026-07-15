/*
Leet Code - 231 :-  Power of two.
So it was like :-
1. There is property of the number which can be expressed in power of two have exactly one 1 in its binary form .
2. The n-1 if we & it with n then it removes the first set bit and since onnly have one set bit so answer will be 0.
3. Hence if n&n-1 gives zero then it is true and can be represented as power of 2.

Time Complexity : O(1) .
Space Complexity : O(1) .

*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
       if((n & (n-1))==0){
        return true;
       }
       else {
        return false;
       }
    }
};
