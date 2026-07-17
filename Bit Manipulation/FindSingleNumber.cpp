/*
Leet Code - 136 :- Find the number appearing single.
So approach is like we know that xor of a number with itself gives zero and in question all numbers except the answer one are appearing twice .
1. Take xor of the entire array.
2. The the resulting answer will be single element.

Time Complexity : O(n) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mor=0;
        for(int i=0;i<nums.size();i++){
            mor=mor^nums[i];
        }
        return mor;
    }
};
