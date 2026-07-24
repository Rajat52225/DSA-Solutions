/*
Leet Code - 1004 :- Max Consecutive Ones III.
So approach was to use sliding window here basically dynamic sliding window.
1. We start by take i and j at 0th index and take a  counter for zeroes and one variable for length.
2. Now we move i and keep updating value of counter if zero occurs.
3. When the counter becomes > k then we start to shrink the window by moving j and shrinks until count is again less than or equal to k.
4. We also keep saving the max length in the variable we took.
5. Finally return the answer.

Time Complexity : O(n) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int ans=0;
        int count=0;
        while(i<nums.size()){
             if(nums[i]==0){
                count++;
             }
                i++;
           if(count>k){
            while(count>k){
                if(nums[j]==0){
                    count--;
                    j++;
                }
                else{
                  j++;
                }
            }
           }
           ans=max(ans,i-j);
        }
        return ans;
    }
};
