/*
Leet Code-33:- Search for target in Rotated Array - I.
So this question was like there is a sorted array and its rotated at some index towards left and we have to check using logn complexity if target element is in the array or not.
So ofc as soon as we saw that its sorted as well as time complexity required is O(logn) so we have to apply binary search for sure.
I approached it like:-
1. Just find out the mid element then check if target element is equal to it or it lies on its left side or right side.
2. Check out which one is sorted side and apply binary search again on that part.

Time Complexity : O(logn) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
                if(nums[mid]==target){
                    return mid;
                }
                if(nums[l]<=nums[mid]){
                    if(target>=nums[l] && target<nums[mid]){
                        r=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
                else{
                    if(target>nums[mid] && target<=nums[r]){
                        l=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }
        }
        return -1;
    }
};
