/*
Leet Code-153 :- Find minimum in rotated sorted array.
So in this we had to apply binary search ofc.
Approach was like:-
1. We have to check from the mid that its left or right which half is sorted .
2. We take the leftmost element of that half as min element .
3. Then we continue our search in the other half following same patter.
4. This results in the minimum element.

Time Complexity : O(logn) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int m=INT_MAX;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[l]){
               m=min(m,nums[l]);
               l=mid+1;
            }
            else if(nums[mid]<nums[r]){
                m=min(m,nums[mid]);
                r=mid-1;
            }
        }
        return m;
    }
};
