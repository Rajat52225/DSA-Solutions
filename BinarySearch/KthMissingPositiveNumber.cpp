/*
Leet Code - 1539 :- Find kth missing positive number.
So approach was not intuitive.
1. We did like we noticed that if we minus the value with its index then we get to know the number of missing numbers there.
2. So for this we will check missing index at at mid value untill low<=high .
3. And we will do like subtract miss from k and add it to index of low and we get answer or we can do like high+k+1.

Time Complexity : O(logn) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int l=0;
       int r=arr.size()-1;
       while(l<=r){
        int mid=l+(r-l)/2;
        int miss=arr[mid]-(mid+1);
        if(miss<k){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
       }
       return (r+k+1);
    }
};
