/*
LeetCode - 4 :- Median of Two Sorted Arrays
I approached it like :-
1. Used binary search on the smaller array.
2. First, I make sure that `nums1` is always the smaller array so that binary search is performed on the minimum search space.
3. I divide both arrays into two parts using `cut1` and `cut2`. The left half contains half of the total elements.
4. For the correct partition:
   left1 <= right2 and left2 <= right1.
   If left1 > right2, I move towards the left by decreasing high.
5. Otherwise, I move towards the right by increasing low.
  After finding the correct partition:
  If the total number of elements is even, the median is the average of the maximum element from the left side and the minimum element from the right side.
  If the total number of elements is odd, the median is the maximum element from the left side.

Time Complexity: O(log(min(n1, n2))) .
Space Complexity: O(1) .

*/  


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2,nums1);
       int n1=nums1.size();
       int n2=nums2.size();
       int low=0;
       int high=n1;
       while(low<=high){
        int cut1=(low+high)>>1;
        int cut2=(n1+n2+1)/2-cut1;
        int left1= cut1==0?INT_MIN:nums1[cut1-1];
        int left2= cut2==0?INT_MIN:nums2[cut2-1];

        int right1= cut1==n1?INT_MAX:nums1[cut1];
        int right2= cut2==n2?INT_MAX:nums2[cut2];

        if(left1<=right2 && left2<=right1){
            if((n1+n2)%2==0){
                return (max(left1,left2)+min(right1,right2))/2.0;
            }
            else{
                return (max(left1,left2));
            }
        }
        else if(left1>right2){
                high=cut1-1;
            }
            else{
                low=cut1+1;
            }
       }
       return 0.0;
    }
};
```
