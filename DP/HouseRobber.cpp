/*
Leet Code - 198 :- House Robber Problem.
So this we approached using dp ofcourse.
1. we do like two ways either skip or rob .
2. We dont add anything for a skip and add that value for a rob and also keep checking whether it already came in dp .
3. Then we just simply returns the skip and rob whichever is maximum we put that value in dp[n].

Time Complexity : O(n) .
Space Complexity : O(n) .

*/

class Solution {
public:
    int fn(vector<int>& nums,int n,vector<int>& dp){
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int skip=fn(nums,n-1,dp);
        int rob=fn(nums,n-2,dp)+nums[n];
        return dp[n]=max(skip,rob);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return fn(nums,n-1,dp);
    }
};
