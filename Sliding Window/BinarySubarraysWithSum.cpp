/*
Leet Code - 930 :- Binary subarrays with sum.
So in this also approach was of sliding window .
1. What we do here is using sliding window we count all the subarrays having sum less than equal to the given goal.
2. This we achieve by taking i and j as 0 and count and sum as 0.
3. Then what we do is we keep adding in sum the nums[i] untill the sum>goal if sum>goal then we subtract nums[j] from sum until its <=goal again.
4. For each iteration we add the length of window to count.
5. In the main function we minus <=goal-1 count from <=goal count as that gives exact count for ==goal.

Time Complexity : O(n) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int goala(vector<int>& nums,int goal){
        if(goal<0){
            return 0;
        }
        int i=0;
        int j=0;
        int count=0;
        int sum=0;
        while(i<nums.size()){
            sum+=nums[i];
            while(sum>goal){
                sum-=nums[j];
                j++;
            }
            i++;
            count+=i-j;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      return goala(nums,goal)-goala(nums,goal-1);
    }
};
