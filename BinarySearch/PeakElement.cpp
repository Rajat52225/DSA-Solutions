/*
Leet Code - 162 :- Find the peak element in array.
The approach is like:-
1. We set l=0 and r=size-1 and mid is found check if its greater than both prev and next element then its peak element.
2. Else we do like check if next element is smaller than mid elment that it means peak is on left half .
3. if next element is greater than peak element is on right half .

Time Complexity : O(logn) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[mid + 1]) {
                r = mid;    
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};
