/*
Leet Code - 1283 :- Find the smallest divisor.
So appraoch is like:-
1. Make a function which checks if the number is satisfying the threshold condition.
2. We will apply binary search in range [1,max element].
3. If the mid value is satisfying the check then we will look for a smaller value on left half.
4. Else we will look in right half.

Time Complexity : O(nlog max element) .
Space Complexity : O(1) .

*/

class Solution {
public:
    bool checks(vector<int>& nums,int mid,int threshold){
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=(nums[i]+mid-1)/mid;
        }
        if(count<=threshold){
            return true;
        }
        else{
            return false;
        }
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int res=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(checks(nums,mid,threshold)){
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
