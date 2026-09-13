/*
Leet Code - 70 :- Climbing Stairs.
So the approach was of Dp :-
1. We took a vector of size n+1 with all values as -1 and we keep storing whats calculated in vector so that we dont recalculate that.
2. Then we simply return dp[n] if already calculated else we calculate it.
3. We get the final answer this way 

Time Complexity : O(n) .
Space Complexoty : O(n) .

*/

class Solution {
public:
    int fn(int n,vector<int>&dp){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=fn(n-1,dp)+fn(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return fn(n,dp);
    }
};
