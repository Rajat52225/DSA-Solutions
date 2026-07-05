/*
Leet Code - 410 :- Split Array Largest Sum.
So this i approached like :
1. Created a check function which returns true if a particular max sum capacity helps in splitting into <= k subarrays.
2. Then i put binary search on range [max element,total sum of all] :
3. If the mid value satisfy check then we put it as min and check on left half.
4. If the mid value fails check then we check on the other right half.
Time Complexity : O(nlog(sum of elements)) .
Space Complexity : O(1) .
*/
class Solution {
public:
    bool checks(vector<int>& nums,int mid,int k){
       int count = 0;
int subarr = 1;
for(int i = 0; i < nums.size(); i++){
    if(count + nums[i] > mid){
        subarr++;
        count = nums[i];
    }
    else{
        count += nums[i];
    }
}
return subarr <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int l=*max_element(nums.begin(),nums.end());
        int r=sum;
        int res=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(checks(nums,mid,k)){
                res=min(mid,res);
                r=mid-1;
            }
            else{
               l=mid+1;
            }
        }
        return res;
    }
};
