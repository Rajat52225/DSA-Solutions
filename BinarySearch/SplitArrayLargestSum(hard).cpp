/*
Leet Code - 410 :- Split array largest sum.
So herei approached like:-
1. Created a check function which checked if mid can divide the subarray into k or less than k subarrays .
2. Then we run binary search in range [max element , sum of all ] and we take a mid which is checked .
3. If it passes the check function then we search for a smaller large sum on left half else we search on right half.

Time Complexity : O(nlog[sum-max]) .
Space Complexity : O(1) .

*/

class Solution {
public:
    bool check(vector<int>& nums,int mid,int k){
            int count=1;
            int sum=0;
            for(int i=0;i<nums.size();i++){
                if(sum+nums[i]>mid){
                    count++;
                    sum=nums[i];
                }
              else{
                sum+=nums[i];
              }
            }
            return count<=k;
        }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int sumi=0;
        for(int i=0;i<nums.size();i++){
            sumi+=nums[i];
        }
        int r=sumi;
        int res=INT_MAX;
        while(l<=r){
          int mid=l+(r-l)/2;
          if(check(nums,mid,k)){
            res=min(res,mid);
            r=mid-1;
          }
          else{
            l=mid+1;
          }

        }
        return res;
    }
};
