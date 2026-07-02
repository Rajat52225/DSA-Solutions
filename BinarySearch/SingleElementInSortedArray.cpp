/*
Leet Code - 540 :- Single element in a sorted array.
So this was approached like:-
1. First edges we need to check if single element is in edge .
2. IF nothing is found on edge then further we set l=1 and r=size-2 and then find mid and check if mid is that element.
3. Otherwise we check what is index if mid:
   ---> if its odd and element prev to it is equal to it then means single element is in right half else left half.
   ---> if its even and next element is equal then it means single element is on right half else on left half.

Time Complexity : O(logn) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int pos;
        if(nums.size()==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2]){
            return nums[nums.size()-1];
        }
        int l=1;
        int r=nums.size()-2;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1]){
                pos=nums[mid];
                break;
            }
           if(mid%2==1){
                if(nums[mid]==nums[mid-1]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
           }
          else if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    l=mid+2;
                }
                else{
                    r=mid-2;
                }
            }
        } 
        return pos;
    }
};
