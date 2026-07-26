/*
Leet Code - 628 :- Maximum Product of the three numbers.
So approach was like :-
The maximum product can be achieved either with the largest 3 digits or start 2 smallest and one largest as if the smallest will be both negative then they become postive and we get a large product.
1. Find out the 3 largest and 2 minimum numbers.
2. Return the max of all 3 large number product or minimum numbers and max number product.

Time Complexity : O(n) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
    int n=nums.size();
    int a=INT_MIN;
    int b=INT_MIN;
    int c=INT_MIN;
    int d=INT_MAX;
    int e=INT_MAX;
    for(int i=0;i<n;i++){
        if(nums[i]>=a){
            c=b;
            b=a;
            a=nums[i];
        }
        else if(nums[i]>=b){
            c=b;
            b=nums[i];
        }
        else if(nums[i]>c){
            c=nums[i];
        }
        if(nums[i]<=d){
            e=d;
            d=nums[i];
        }
        else if(nums[i]<e){
            e=nums[i];
        }
    }
    return max((a*d*e),(a*b*c));
    }
};
